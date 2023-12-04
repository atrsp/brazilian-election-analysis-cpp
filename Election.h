#ifndef ELECTION_H
#define ELECTION_H

#include <string>
#include <list>
#include <map>
#include "Candidate.h"
#include "Party.h"

class Election {
private:
    std::map<int, Candidate*> candidates;
    std::map<int, Party*> parties;
    std::string officeOption;
    int seats;
    int listVotes;
    int nominalVotes;
    int totalVotes;

public:
    Election(std::string officeOption);
    ~Election();

    std::list<Candidate*> getCandidates();
    std::list<Party*> getParties();
    Candidate* getCandidate(int number);
    Party* getParty(int number);
    void addVotes(int votes, int votableNumber, std::string office);
    void addParty(int number, Party* p);
    bool hasParty(int number);
    void addCandidate(int candidateNumber, Candidate* c);
    bool hasCandidate(int number);
    void addCandidateToParty(Candidate* c);
    void addDismissedCandidateToParty(Candidate* c);
    std::string getOfficeOption();
    int getSeats();
    void setSeats(int seats);
    int getListVotes();
    int getNominalVotes();
    int getTotalVotes();
    void setTotalVotes();
};

#endif // ELECTION_H
