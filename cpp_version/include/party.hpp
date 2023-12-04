#ifndef PARTY_H
#define PARTY_H

using namespace std;

#include <iostream>
#include <list>
#include "./candidate.hpp"

class Candidate;

class Party{

private:
    int partyNumber;
    string partyAcronym;
    string partyName;
    int numberOfCandidates;
    int listVotes; //"votos de legenda"
    int nominalVotes; 
    int totalVotes; //listVotes + nominalVotes

    //private Map<Integer, Candidate> candidates;
    //private Map<Integer, Candidate> dismissedCandidates;

    //John Wick:
    //list<Candidate*> listaCandidatosPartido;

public:

    Party(int number, string acronym, string name);

    void setTotalVotes();
    void addVotes(int votes);
    void addCandidate(int candidateNumber, Candidate c);
    void addCandidateVotes(int votes, int candidateNumber);
    void addDismissedCandidate(int candidateNumber, Candidate c);

    int getListVotes()const;
    int getTotalVotes()const;
    int getPartyNumber()const;
    int getNominalVotes()const;
    int getNumberOfElecteds()const;
    int getNumberOfCandidates() const;

    bool hasDismissedCandidate(int candidateNumber)const;

    string getPartyName()const;
    string getPartyAcronym()const;
    
    list<Candidate*> getCandidates()const;
    
    // int compareTo(Party o);
};

#endif