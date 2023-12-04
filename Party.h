#ifndef PARTY_H
#define PARTY_H

#include <string>
#include <list>
#include <map>
#include "Candidate.h"

class Party {
private:
    int partyNumber;
    std::string partyAcronym;
    std::string partyName;
    int numberOfCandidates;
    int listVotes;
    int nominalVotes;
    int totalVotes;
    std::map<int, Candidate*> candidates;
    std::map<int, Candidate*> dismissedCandidates;

public:
    Party(int number, std::string acronym, std::string name);
    ~Party();

    void addCandidate(int candidateNumber, Candidate* c);
    void addDismissedCandidate(int candidateNumber, Candidate* c);
    bool hasDismissedCandidate(int candidateNumber);
    void addVotes(int votes);
    void addCandidateVotes(int votes, int candidateNumber);
    std::list<Candidate*> getCandidates();
    int getPartyNumber();
    std::string getPartyAcronym();
    std::string getPartyName();
    int getNumberOfCandidates();
    int getNumberOfElecteds();
    int getListVotes();
    int getNominalVotes();
    int getTotalVotes();
    void setTotalVotes();
    bool operator<(const Party& other) const;
};

#endif // PARTY_H
