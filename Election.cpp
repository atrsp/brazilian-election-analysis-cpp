#include <unordered_map>
#include <string>
#include <iostream>
#include <list>
#include <algorithm>
#include "Candidate.h"
#include "Party.h"

class Election {
private:
    std::unordered_map<int, Candidate> candidates;
    std::unordered_map<int, Party> parties;
    std::string electionDate;
    std::string officeOption;
    int seats; 
    int listVotes;
    int nominalVotes;
    int totalVotes;

public:
    Election(std::string electionDate, std::string officeOption) : electionDate(electionDate), officeOption(officeOption), seats(0), listVotes(0), nominalVotes(0), totalVotes(0) {}

    std::list<Candidate> getCandidates() {
        std::list<Candidate> candidateList;
        for (const auto& pair : candidates) {
            candidateList.push_back(pair.second);
        }
        return candidateList;
    }

    std::list<Party> getParties() {
        std::list<Party> partyList;
        for (const auto& pair : parties) {
            partyList.push_back(pair.second);
        }
        return partyList;
    }

    Candidate getCandidate(int number) {
        return candidates[number];
    }

    Party getParty(int number) {
        return parties[number];
    }

    void addVotes(int votes, int votableNumber, std::string office) {
        if (hasParty(votableNumber)) {
            Party& p = parties[votableNumber];
            p.addVotes(votes);
            this->listVotes += votes;
        }
        else if (hasCandidate(votableNumber)) {
            Candidate& c = candidates[votableNumber];
            Party& p = parties[c.getPartyNumber()];

            if (c.getVoteDestinationType() == "Válido (legenda)") {
                p.addVotes(votes);
                this->listVotes += votes;
            }
            else {
                if ((c.getCandidacyCondition() == 2 || c.getCandidacyCondition() == 16) && c.getVoteDestinationType() == "Válido") {
                    c.addVotes(totalVotes);
                    p.addCandidateVotes(votes, votableNumber);
                    this->nominalVotes += votes;
                }
            }
        }
        else if (!hasCandidate(votableNumber) && !hasParty(votableNumber)) {
            // votableNumber to string
            std::string numberString = std::to_string(votableNumber);

            // verify if has at least 2 characters
            if (numberString.length() >= 2) {
                // get first 2 digits = party number
                std::string twoDigits = numberString.substr(0, 2);

                // convert twoDigits back to number
                int partyNum = std::stoi(twoDigits);

                if (hasParty(partyNum)) {
                    Party& p = parties[partyNum];

                    if (p.hasDismissedCandidate(votableNumber)) {
                        p.addVotes(votes);
                        this->listVotes += votes;
                    }
                }
            }
        }
    }

    void addParty(int number, Party p) {
        if (!hasParty(number)) {
            parties[number] = p;
        }
    }

    bool hasParty(int number) {
        return parties.find(number) != parties.end();
    }

    void addCandidate(int candidateNumber, Candidate c) {
        if (!hasCandidate(candidateNumber)) {
            candidates[candidateNumber] = c;

            if (c.isElected()) seats += 1;
        }
    }

    bool hasCandidate(int number) {
        return candidates.find(number) != candidates.end();
    }

    void addCandidateToParty(Candidate c) {
        Party& p = parties[c.getPartyNumber()];
        p.addCandidate(c.getCandidateNumber(), c);
    }

    void addDismissedCandidateToParty(Candidate c) {
        Party& p = parties[c.getPartyNumber()];
        p.addDismissedCandidate(c.getCandidateNumber(), c);
    }

    std::string getElectionDate() {
        return electionDate;
    }

    std::string getOfficeOption() {
        return officeOption;
    }

    int getSeats() {
        return seats;
    }

    void setSeats(int seats) {
        this->seats = seats;
    }

    int getListVotes() {
        return listVotes;
    }

    int getNominalVotes() {
        return nominalVotes;
    }

    int getTotalVotes() {
        return totalVotes;
    }

    void setTotalVotes() {
        this->totalVotes = this->listVotes + this->nominalVotes;

        for (auto& p : parties) {
            p.second.setTotalVotes();
        }
    }
};
