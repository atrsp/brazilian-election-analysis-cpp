#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include "Election.h"
#include "Candidate.h"
#include "Party.h"

class Report {
private:
    Election& poll;
    std::vector<Candidate>& sortCandidates;
    std::vector<Party>& sortParties;
    int seats;

public:
    Report(Election& poll) : poll(poll), sortCandidates(poll.getCandidates()), sortParties(poll.getParties()), seats(poll.getSeats()) {
        std::sort(sortCandidates.begin(), sortCandidates.end());
        std::sort(sortParties.begin(), sortParties.end());
    }

    void report1() {
        std::cout << "Número de vagas: " << poll.getSeats() << "\n\n";
    }

    void report2() {
        std::cout << (poll.getOfficeOption() == "--federal" ? "Deputados federais eleitos:" : "Deputados estaduais eleitos:") << std::endl;

        int pos = 1;
        for (const Candidate& c : sortCandidates) {
            if (c.isElected()) {
                std::cout << pos << " - " << c.changeName() << " (" << c.getPartyAcronym() << ", " << poll.portugueseFormat().format(c.getNominalVotes()) << " votos)\n";
                pos++;
            }
        }
        std::cout << "\n";
    }

    void report3() {
        std::cout << "Candidatos mais votados (em ordem decrescente de votação e respeitando número de vagas):" << std::endl;

        int pos = 1;
        for (const Candidate& c : sortCandidates) {
            if (pos > seats) break;
            std::cout << pos << " - " << c.changeName() << " (" << c.getPartyAcronym() << ", " << poll.portugueseFormat().format(c.getNominalVotes()) << " votos)\n";
            pos++;
        }

        std::cout << "\n";
    }

    void report4() {
        std::cout << "Teriam sido eleitos se a votação fosse majoritária, e não foram eleitos:\n(com sua posição no ranking de mais votados)" << std::endl;

        int pos = 1;
        for (const Candidate& c : sortCandidates) {
            if (pos > seats && !c.isElected()) {
                std::cout << pos << " - " << c.changeName() << " (" << c.getPartyAcronym() << ", " << poll.portugueseFormat().format(c.getNominalVotes()) << " votos)\n";
            }
            pos++;
        }

        std::cout << "\n";
    }

    void report5() {
        std::cout << "Eleitos, que se beneficiaram do sistema proporcional:\n(com sua posição no ranking de mais votados)" << std::endl;

        int pos = 1;
        for (const Candidate& c : sortCandidates) {
            if (c.isElected() && pos > seats) {
                std::cout << pos << " - " << c.changeName() << " (" << c.getPartyAcronym() << ", " << poll.portugueseFormat().format(c.getNominalVotes()) << " votos)\n";
            }
            pos++;
        }

        std::cout << "\n";
    }

    void report6() {
        std::cout << "Votação dos partidos e número de candidatos eleitos:" << std::endl;

        int pos = 1;
        for (const Party& p : sortParties) {
            const auto votes = poll.portugueseFormat().format(p.getNominalVotes());
            const auto qtdVotes = poll.portugueseFormat().format(p.getTotalVotes());

            std::cout << pos << " - " << p.getPartyAcronym() << " - " << p.getPartyNumber() << ", " << votes;

            if (qtdVotes == "0") {
                std::cout << " voto (" << votes;
            } else {
                std::cout << " votos (" << votes;
            }

            if (votes == "0") {
                std::cout << " nominal e " << poll.portugueseFormat().format(p.getListVotes()) << " de legenda), " << p.getNumberOfElecteds();
            } else {
                std::cout << " nominais e " << poll.portugueseFormat().format(p.getListVotes()) << " de legenda), " << p.getNumberOfElecteds();
            }

            if (p.getNumberOfElecteds() > 1) {
                std::cout << " candidatos eleitos" << std::endl;
            } else {
                std::cout << " candidato eleito" << std::endl;
            }

            pos++;
        }

        std::cout << "\n";
    }

    void report7() {
        std::cout << "Primeiro e último colocados de cada partido:" << std::endl;

        std::vector<Candidate> mostVoted(sortParties.size());
        std::vector<Candidate> leastVoted(sortParties.size());
        int i = 0;

        for (const Party& p : sortParties) {
            auto partyCandidates = p.getCandidates();

            if (partyCandidates.size() >= 1) {
                std::sort(partyCandidates.begin(), partyCandidates.end());

                if (std::find(partyCandidates.begin(), partyCandidates.end(), partyCandidates[0]) != partyCandidates.end() &&
                    std::find(partyCandidates.begin(), partyCandidates.end(), partyCandidates[partyCandidates.size() - 1]) != partyCandidates.end()) {
                    mostVoted[i] = partyCandidates[0];
                    leastVoted[i] = partyCandidates[partyCandidates.size() - 1];
                    i++;
                }
            }
        }

        int size = i;

        for (int j = 0; j < size; j++) {
            for (int k = j; k < size; k++) {
                if (mostVoted[k].getNominalVotes() > mostVoted[j].getNominalVotes()) {
                    std::swap(mostVoted[j], mostVoted[k]);
                    std::swap(leastVoted[j], leastVoted[k]);
                } else if (mostVoted[k].getNominalVotes() == mostVoted[j].getNominalVotes() && mostVoted[k].getPartyNumber() < mostVoted[j].getPartyNumber()) {
                    std::swap(mostVoted[j], mostVoted[k]);
                    std::swap(leastVoted[j], leastVoted[k]);
                }
            }
        }

        int pos = 1;

        for (int idx = 0; idx < size; idx++) {
            const std::string mostVotesString = (mostVoted[idx].getNominalVotes() > 1) ? "votos" : "voto";
            const std::string leastVotesString = (leastVoted[idx].getNominalVotes() > 1) ? "votos" : "voto";

            std::cout << pos << " - " << mostVoted[idx].getPartyAcronym() << " - " << mostVoted[idx].getPartyNumber() << ", " << mostVoted[idx].getBallotName() << " (" << mostVoted[idx].getCandidateNumber()
                      << ", " << poll.portugueseFormat().format(mostVoted[idx].getNominalVotes()) << " " << mostVotesString << ") / " << leastVoted[idx].getBallotName() << " ("
                      << leastVoted[idx].getCandidateNumber() << ", " << poll.portugueseFormat().format(leastVoted[idx].getNominalVotes()) << " " << leastVotesString << ")\n";

            pos += 1;
        }

        std::cout << "\n";
    }

    void report8() {
        double ageGroupPercentage[5] = {0};
        int ageGroup[5] = {0};
        int sum = 0;

        std::cout << "Eleitos, por faixa etária (na data da eleição):" << std::endl;

        for (const Candidate& c : sortCandidates) {
            if (c.isElected()) {
                int age = c.getAge();

                if (age < 30) {
                    ageGroup[0] += 1;
                } else if (age >= 30 && age < 40) {
                    ageGroup[1] += 1;
                } else if (age >= 40 && age < 50) {
                    ageGroup[2] += 1;
                } else if (age >= 50 && age < 60) {
                    ageGroup[3] += 1;
                } else if (age >= 60) {
                    ageGroup[4] += 1;
                }

                sum += 1;
            }
        }

        for (int i = 0; i < 5; i++) {
            ageGroupPercentage[i] = (static_cast<double>(ageGroup[i]) / static_cast<double>(sum)) * 100;
        }

        std::cout << "      Idade < 30: " << ageGroup[0] << " (" << poll.portugueseFormat().format(ageGroupPercentage[0]) << "%)\n";
        std::cout << "30 <= Idade < 40: " << ageGroup[1] << " (" << poll.portugueseFormat().format(ageGroupPercentage[1]) << "%)\n";
        std::cout << "40 <= Idade < 50: " << ageGroup[2] << " (" << poll.portugueseFormat().format(ageGroupPercentage[2]) << "%)\n";
        std::cout << "50 <= Idade < 60: " << ageGroup[3] << " (" << poll.portugueseFormat().format(ageGroupPercentage[3]) << "%)\n";
        std::cout << "60 <= Idade     : " << ageGroup[4] << " (" << poll.portugueseFormat().format(ageGroupPercentage[4]) << "%)\n\n";
    }

    void report9() {
        int male = 0;
        int female = 0;

        for (const Candidate& c : sortCandidates) {
            if (c.isElected()) {
                if (c.getGender() == 2) {
                    male++;
                } else if (c.getGender() == 4) {
                    female++;
                }
            }
        }

        double malePercentage = (static_cast<double>(male) / static_cast<double>(poll.getSeats())) * 100;
        double femalePercentage = (static_cast<double>(female) / static_cast<double>(poll.getSeats())) * 100;

        std::cout << "Eleitos, por gênero:\n";
        std::cout << "Feminino:\t" << female << " (" << poll.portugueseFormat().format(femalePercentage) << "%)\n";
        std::cout << "Masculino:\t" << male << " (" << poll.portugueseFormat().format(malePercentage) << "%)\n\n";
    }

    void report10() {
        double nominalPercentage = (static_cast<double>(poll.getNominalVotes()) / static_cast<double>(poll.getTotalVotes())) * 100;
        double listPercentage = (static_cast<double>(poll.getListVotes()) / static_cast<double>(poll.getTotalVotes())) * 100;

        std::cout << "Total de votos válidos:\t" << poll.portugueseFormat().format(poll.getTotalVotes())
                  << "\nTotal de votos nominais:\t" << poll.portugueseFormat().format(poll.getNominalVotes()) << " ("
                  << poll.portugueseFormat().format(nominalPercentage) << "%)"
                  << "\nTotal de votos de legenda:\t" << poll.portugueseFormat().format(poll.getListVotes()) << " ("
                  << poll.portugueseFormat().format(listPercentage) << "%)" << std::endl;
    }
};
