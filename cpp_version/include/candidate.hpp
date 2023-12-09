#ifndef CANDIDATE_H
#define CANDIDATE_H

#include <iostream>
#include <string>
#include "./party.hpp"
#include "./date.hpp"

using std::string;

class Party;
class Date;

class Candidate{

private:
    int officeOption;
    int candidateNumber;
    string ballotName;
    int partyNumber;
    string partyAcronym;
    int federationNumber;
    Date birthDate; // ?????????
    int gender;
    int turnStatus;
    string voteDestinationType;
    int candidacyCondition;
    int nominalVotes;
    int age;

public:
    Candidate(int office, int number, string ballotName, int partyNumber, string partyAcronym, int federationNumber, string birthDate,  int gender, int status, string voteDestination, int condition, Date electionDate);

    string changeName();
    void addVotes(int votes);
    int calculateAge(Date birthDate, Date electionDate);

    int getOfficeOption()const;
    int getCandidateNumber()const;
    int getPartyNumber()const;
    int getFederationNumber() const;
    int getGender() const;
    int getTurnStatus()const;
    int getCandidacyCondition() const;
    int getAge() const;
    int getNominalVotes()const;
    bool isElected() const;

    Date getBirthDate() const;
    string getBallotName()const;
    string getVoteDestinationType() const;
    string getPartyAcronym()const;
    //int compareTo(Candidate o);        

};

#endif