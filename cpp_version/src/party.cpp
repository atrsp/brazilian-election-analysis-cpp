#include "../include/party.hpp"


Party::Party(int number, string acronym, string name)
{
    //this->candidates = new HashMap<Integer, Candidate>();
    //this->dismissedCandidates = new HashMap<Integer, Candidate>();
    this->partyNumber = number;
    this->partyAcronym = acronym;
    this->partyName = name;
    this->numberOfCandidates = 0;
    this->listVotes = 0;
    this->nominalVotes = 0;
    this->totalVotes = 0;
}

void Party::setTotalVotes()
{
    this->totalVotes = this->listVotes + this->nominalVotes;
}

void Party::addVotes(int votes)
{
    this->listVotes += votes;
}

void Party::addCandidate(int candidateNumber, Candidate c)
{
    /*
    if (candidates->containsKey(candidateNumber) == false) {
        candidates->put(candidateNumber, c);
        numberOfCandidates+=1;
    }
    */
}

void Party::addCandidateVotes(int votes, int candidateNumber)
{
    /*
    Candidate c = candidates->get(candidateNumber);
    c->addVotes(votes);
    this->nominalVotes += votes;
    */
}

void Party::addDismissedCandidate(int candidateNumber, Candidate c)
{
    /* 
    if (dismissedCandidates->containsKey(candidateNumber) == false) {
        dismissedCandidates->put(candidateNumber, c);
    }
    */
}


int Party::getListVotes() const
{
    return listVotes;
}

int Party::getTotalVotes()const
{
    return totalVotes;
}

int Party::getPartyNumber()const
{
    return partyNumber;
}

int Party::getNominalVotes()const
{
    return nominalVotes;
}

int Party::getNumberOfElecteds()const
{
    
    int sum = 0;
    /*
    for (Candidate c : candidates->values()) {
        if (c->isElected()) sum++;
    }
    */
    return sum;
    
}

int Party::getNumberOfCandidates() const
{
    return numberOfCandidates;
}


bool Party::hasDismissedCandidate(int candidateNumber)const
{
    //return dismissedCandidates->containsKey(candidateNumber);
    return false;
}


string Party::getPartyName()const
{
    return partyName;
}

string Party::getPartyAcronym()const
{
    return partyAcronym;
}

/*
list<Candidate*> Party::getCandidates()const
{
    return new list<Candidate>(this->candidates.values()); // Linked List makes it easier to sort by vote afterwards
}
*/

    
// int Party::compareTo(Party o){}
