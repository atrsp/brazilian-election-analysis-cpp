#include <iostream>
#include <string>
#include <chrono>

class Candidate {
private:
    int officeOption;
    int candidateNumber;
    std::string ballotName;
    int partyNumber;
    std::string partyAcronym;
    int federationNumber;
    std::chrono::system_clock::time_point birthDate;
    int gender;
    int turnStatus;
    std::string voteDestinationType;
    int candidacyCondition;
    int nominalVotes;
    int age;

public:
    Candidate(int office, int number, std::string ballotName, int partyNumber, std::string partyAcronym, int federationNumber, std::string birthDate, int gender, int status, std::string voteDestination, int condition, std::chrono::system_clock::time_point electionDate)
        : officeOption(office), candidateNumber(number), ballotName(ballotName), partyNumber(partyNumber), partyAcronym(partyAcronym), federationNumber(federationNumber),
        birthDate(std::chrono::system_clock::from_time_t(std::stoi(birthDate))), gender(gender), turnStatus(status), voteDestinationType(voteDestination), candidacyCondition(condition), nominalVotes(0) {
        this->age = calculateAge(this->birthDate, electionDate);
    }

    int calculateAge(std::chrono::system_clock::time_point birthDate, std::chrono::system_clock::time_point electionDate) {
        auto birthTime = std::chrono::system_clock::to_time_t(birthDate);
        auto electionTime = std::chrono::system_clock::to_time_t(electionDate);

        struct tm birthStruct, electionStruct;

        localtime_s(&birthStruct, &birthTime);
        localtime_s(&electionStruct, &electionTime);

        int birthYear = birthStruct.tm_year + 1900;
        int electionYear = electionStruct.tm_year + 1900;

        int age = electionYear - birthYear;

        int birthMonth = birthStruct.tm_mon + 1;
        int electionMonth = electionStruct.tm_mon + 1;

        int birthDay = birthStruct.tm_mday;
        int electionDay = electionStruct.tm_mday;

        if (electionMonth < birthMonth || (electionMonth == birthMonth && electionDay < birthDay)) {
            age -= 1;
        }

        return age;
    }

    void addVotes(int votes) {
        this->nominalVotes += votes;
    }

    int getOfficeOption() {
        return officeOption;
    }

    int getCandidateNumber() {
        return candidateNumber;
    }

    std::string getBallotName() {
        return ballotName;
    }

    int getPartyNumber() {
        return partyNumber;
    }

    std::string getPartyAcronym() {
        return partyAcronym;
    }

    int getFederationNumber() {
        return federationNumber;
    }

    std::chrono::system_clock::time_point getBirthDate() {
        return birthDate;
    }

    int getGender() {
        return gender;
    }

    int getTurnStatus() {
        return turnStatus;
    }

    std::string getVoteDestinationType() {
        return voteDestinationType;
    }

    int getCandidacyCondition() {
        return candidacyCondition;
    }

    int getNominalVotes() {
        return nominalVotes;
    }

    int getAge() {
        return age;
    }

    bool isElected() {
        return (turnStatus == 2 || turnStatus == 3);
    }

    std::string changeName() {
        return (federationNumber != -1) ? "*" + ballotName : ballotName;
    }

    bool operator<(const Candidate& other) const {
        if (nominalVotes != other.nominalVotes) {
            return nominalVotes < other.nominalVotes;
        }

        return age < other.age;
    }
};
