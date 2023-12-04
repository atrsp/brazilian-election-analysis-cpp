#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "Election.h"
#include "Candidate.h"
#include "Party.h"

class CSVReader {
private:
    std::string candidatesFilePath;
    std::string pollFilePath;

public:
    CSVReader(const std::string& candidatesFilePath, const std::string& pollFilePath) {
        std::ifstream candidatesFile(candidatesFilePath);
        std::ifstream pollFile(pollFilePath);

        if (!candidatesFile.is_open() && pollFile.is_open()) {
            throw std::invalid_argument("Candidates file does not exist!\npath: " + candidatesFilePath);
        } else if (!pollFile.is_open() && candidatesFile.is_open()) {
            throw std::invalid_argument("Poll file does not exist!\npath: " + pollFilePath);
        } else if (!candidatesFile.is_open() && !pollFile.is_open()) {
            throw std::invalid_argument("Both Candidates and Poll files do not exist!\ncandidatesFilePath: " + candidatesFilePath +
                                        "\npollFilePath: " + pollFilePath + "\n");
        }

        this->candidatesFilePath = candidatesFilePath;
        this->pollFilePath = pollFilePath;
    }

    std::string getCandidatesFilePath() const {
        return candidatesFilePath;
    }

    std::string getPollFilePath() const {
        return pollFilePath;
    }

    void candidatesReader(Election& poll) {
        try {
            std::ifstream file(candidatesFilePath);
            std::string line;
            int currentRow = 0;
            int officeOption = poll.getOfficeOption() == "--estadual" ? 7 : 6;

            while (std::getline(file, line)) {
                std::istringstream iss(line);
                std::string token[80];

                for (int i = 0; i < 80 && std::getline(iss, token[i], ';'); i++) {
                    token[i].erase(std::remove(token[i].begin(), token[i].end(), '\"'), token[i].end());
                }

                if (currentRow != 0) { // row != csv header && officeOption == same as command line input
                    if (stringToInt(token[13]) == officeOption) {
                        int partyNumber = stringToInt(token[27]);          /* "NR_PARTIDO" */
                        std::string partyAcronym = token[28];              /* "SG_PARTIDO" */
                        std::string partyName = token[29];                 /* "NM_PARTIDO" */
                        Party p(partyNumber, partyAcronym, partyName);
                        poll.addParty(partyNumber, p);

                        int candidateNumber = stringToInt(token[16]);      /* "NR_CANDIDATO" */
                        std::string candidateBallotName = token[18];       /* "NM_URNA_CANDIDATO" */
                        int federationNumber = stringToInt(token[30]);     /* "NR_FEDERACAO" */
                        std::string birthDate = token[42];                 /* "DT_NASCIMENTO" */
                        int gender = stringToInt(token[45]);               /* "CD_GENERO" */
                        int turnStatus = stringToInt(token[56]);           /* "CD_SIT_TOT_TURNO" */
                        std::string voteDestinationType = token[67];      /* "NM_TIPO_DESTINACAO_VOTOS" */
                        int candidacyCondition = stringToInt(token[68]);   /* "CD_SITUACAO_CANDIDATO_TOT" */

                        if (candidacyCondition == 2 || candidacyCondition == 16) {
                            Candidate c(officeOption, candidateNumber, candidateBallotName, partyNumber, partyAcronym, federationNumber,
                                        birthDate, gender, turnStatus, voteDestinationType, candidacyCondition, poll.getElectionDate());

                            poll.addCandidateToParty(c);
                            poll.addCandidate(candidateNumber, c);
                        } else if (candidacyCondition != 2 && candidacyCondition != 16 && voteDestinationType == "Válido (legenda)") {
                            Candidate c(officeOption, candidateNumber, candidateBallotName, partyNumber, partyAcronym, federationNumber,
                                        birthDate, gender, turnStatus, voteDestinationType, candidacyCondition, poll.getElectionDate());

                            poll.addDismissedCandidateToParty(c);
                        }
                    }
                }
                currentRow++;
            }
        } catch (std::exception& e) {
            std::cerr << "Exception: " << e.what() << std::endl;
        }
    }

    void votesReader(Election& poll) {
        try {
            std::ifstream file(pollFilePath);
            std::string line;
            int currentRow = 0;
            int officeOption = poll.getOfficeOption() == "--estadual" ? 7 : 6;
            std::string officeString = poll.getOfficeOption() == "--estadual" ? "--estadual" : "--federal";

            while (std::getline(file, line)) {
                std::istringstream iss(line);
                std::string token[30];

                for (int i = 0; i < 30 && std::getline(iss, token[i], ';'); i++) {
                    token[i].erase(std::remove(token[i].begin(), token[i].end(), '\"'), token[i].end());
                }

                if (currentRow != 0 && stringToInt(token[17]) == officeOption) { // row != csv header && officeOption == same as command line input
                    int votableNumber = stringToInt(token[19]);  /* "NR_VOTAVEL" */
                    int totalVotes = stringToInt(token[21]);     /* "QT_VOTOS" */

                    if (votableNumber != 95 && votableNumber != 96 && votableNumber != 97 && votableNumber != 98) {
                        poll.addVotes(totalVotes, votableNumber, officeString);
                    }
                }
                currentRow++;
            }

            poll.setTotalVotes();
        } catch (std::exception& e) {
            std::cerr << "Exception: " << e.what() << std::endl;
        }
    }

    int stringToInt(const std::string& str) {
        int value = 0;
        try {
            value = std::stoi(str);
        } catch (const std::invalid_argument& ia) {
            std::cerr << "Invalid argument: " << ia.what() << std::endl;
        } catch (const std::out_of_range& oor) {
            std::cerr << "Out of Range error: " << oor.what() << std::endl;
        }
        return value;
    }
};
