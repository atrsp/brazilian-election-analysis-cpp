#include <iostream>
#include <string>
#include <map>
#include <list>

class Candidate;  // Forward declaration

class Party {
private:
    int partyNumber;
    std::string partyAcronym;
    std::string partyName;
    int numberOfCandidates;
    int listVotes; //"votos de legenda"
    int nominalVotes;
    int totalVotes; //listVotes + nominalVotes

    std::map<int, Candidate*> candidates;
    std::map<int, Candidate*> dismissedCandidates;

public:
    Party(int number, std::string acronym, std::string name)
        : partyNumber(number), partyAcronym(acronym), partyName(name), numberOfCandidates(0), listVotes(0), nominalVotes(0), totalVotes(0) {}

    void addCandidate(int candidateNumber, Candidate* c) {
        if (candidates.find(candidateNumber) == candidates.end()) {
            candidates[candidateNumber] = c;
            numberOfCandidates += 1;
        }
    }

    void addDismissedCandidate(int candidateNumber, Candidate* c) {
        if (dismissedCandidates.find(candidateNumber) == dismissedCandidates.end()) {
            dismissedCandidates[candidateNumber] = c;
        }
    }

    bool hasDismissedCandidate(int candidateNumber) {
        return dismissedCandidates.find(candidateNumber) != dismissedCandidates.end();
    }

    void addVotes(int votes) {
        listVotes += votes;
    }

    void addCandidateVotes(int votes, int candidateNumber) {
        Candidate* c = candidates[candidateNumber];
        c->addVotes(votes);
        nominalVotes += votes;
    }

    std::list<Candidate*> getCandidates() {
        std::list<Candidate*> candidateList;
        for (auto const& entry : candidates) {
            candidateList.push_back(entry.second);
        }
        return candidateList;
    }

    int getPartyNumber() {
        return partyNumber;
    }

    std::string getPartyAcronym() {
        return partyAcronym;
    }

    std::string getPartyName() {
        return partyName;
    }

    int getNumberOfCandidates() {
        return numberOfCandidates;
    }

    int getNumberOfElecteds() {
        int sum = 0;

        for (auto const& entry : candidates) {
            if (entry.second->isElected()) {
                sum++;
            }
        }

        return sum;
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
        totalVotes = listVotes + nominalVotes;
    }

    bool operator<(const Party& other) const {
        if (totalVotes != other.totalVotes) {
            return totalVotes < other.totalVotes;
        }

        return partyNumber < other.partyNumber;
    }
};
