#ifndef CANDIDATE_H
#define CANDIDATE_H

#include <string>
#include <list>
#include "Party.h"

class Election;  // Forward declaration

class Candidate {
private:
    int officeOption;
    int candidateNumber;
    std::string ballotName;
    int partyNumber;
    std::string partyAcronym;
    int federationNumber;
    int gender;
    int turnStatus;
    std::string voteDestinationType;
    int candidacyCondition;
    int nominalVotes;
    int age;

public:
    Candidate(int office, int number, std::string ballotName, int partyNumber, std::string partyAcronym, int federationNumber,
              std::string birthDate, int gender, int status, std::string voteDestination, int condition, Election* election);
    ~Candidate();

    int calculateAge(Election* election);
    void addVotes(int votes);
    int getOfficeOption();
    int getCandidateNumber();
    std::string getBallotName();
    int getPartyNumber();
    std::string getPartyAcronym();
    int getFederationNumber();
    int getGender();
    int getTurnStatus();
    std::string getVoteDestinationType();
    int getCandidacyCondition();
    int getNominalVotes();
    int getAge();
    bool isElected();
    std::string changeName();
    int compareTo(Candidate* other);
};

#endif // CANDIDATE_H
