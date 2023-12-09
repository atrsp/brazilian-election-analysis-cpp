#ifndef ELECTION_H
#define ELECTION_H

#include <list>
#include <iostream>
#include <string>
#include <map>

#include "./party.hpp"
#include "./candidate.hpp"
#include "./date.hpp"

class Election {
private:
    map<int, Candidate*> candidates;
    map<int, Party*> parties;
    Date electionDate;
    string officeOption;
    int seats; // == number of electeds
    int listVotes;
    int nominalVotes;
    int totalVotes;

public:
    Election(Date electionDate, string officeOption);
    Election();
    
    list<Candidate> getCandidates() const; //list ou map, n sei
    list<Party> getParties() const;
    Candidate* getCandidate(int number) const;
    Party* getParty(int number) const;

    void addVotes(int votes, int votableNumber, string office);
    void addParty(int number, Party* p);
    bool hasParty(int number) const;
    void addCandidate(int candidateNumber, Candidate* c);
    bool hasCandidate(int number) const;
    void addCandidateToParty(Candidate* c);
    void addDismissedCandidateToParty(Candidate* c);

    Date getElectionDate() const;
    string getOfficeOption() const;
    int getSeats() const;
    void setSeats(int seats);
    int getListVotes() const;
    int getNominalVotes() const;
    int getTotalVotes() const;
    void setTotalVotes();
};

#endif