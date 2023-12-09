#include "../include/election.hpp"

Election::Election(Date electionDate, string officeOption)
{
}

Election::Election()
{
}

list<Candidate> Election::getCandidates() const
{
    return list<Candidate>();
}

list<Party> Election::getParties() const
{
    return list<Party>();
}

Candidate *Election::getCandidate(int number) const
{
    return nullptr;
}

Party *Election::getParty(int number) const
{
    return nullptr;
}

void Election::addVotes(int votes, int votableNumber, string office)
{
}

void Election::addParty(int number, Party *p)
{
}

bool Election::hasParty(int number) const
{
    return false;
}

void Election::addCandidate(int candidateNumber, Candidate *c)
{
}

bool Election::hasCandidate(int number) const
{
    return false;
}

void Election::addCandidateToParty(Candidate *c)
{
}

void Election::addDismissedCandidateToParty(Candidate *c)
{
}

Date Election::getElectionDate() const
{
    return Date();
}

string Election::getOfficeOption() const
{
    return string();
}

int Election::getSeats() const
{
    return 0;
}

void Election::setSeats(int seats)
{
}

int Election::getListVotes() const
{
    return 0;
}

int Election::getNominalVotes() const
{
    return 0;
}

int Election::getTotalVotes() const
{
    return 0;
}

void Election::setTotalVotes()
{
}
