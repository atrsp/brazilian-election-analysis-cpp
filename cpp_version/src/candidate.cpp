#include "../include/candidate.hpp"
#include "../include/date.hpp"

Candidate::Candidate(int office, int number, string ballotName, int partyNumber, string partyAcronym, int federationNumber, string birthDate,  int gender, int status, string voteDestination, int condition, Date electionDate)
{
        this->officeOption = office;
        this->candidateNumber = number;
        this->ballotName = ballotName;
        this->partyNumber = partyNumber;
        this->partyAcronym = partyAcronym;
        this->federationNumber = federationNumber;
        this->gender = gender;
        this->turnStatus = status;
        this->voteDestinationType = voteDestination;
        this->candidacyCondition = condition;
        this->nominalVotes = 0;

        /*
        
        DateTimeFormatter dateFormat = DateTimeFormatter.ofPattern("dd/MM/yyyy", Locale.forLanguageTag("pt-BR"));

        try {
            if (birthDate != null && !birthDate.isEmpty()) {
                this.birthDate = LocalDate.parse(birthDate, dateFormat);
                this.age = calculateAge(this.birthDate, electionDate);
            } else {
                System.out.println("Birth date is empty or null. Candidate: " + this.ballotName + " (" + this.candidateNumber + ")");
            }
        } catch (DateTimeParseException e) {
            System.out.println("Date parse exception error: " + e.getMessage());
        }

        */

}

    string Candidate::changeName()
    {
        if (this->federationNumber != -1) {
            return "*" + this->ballotName;
        }
        else return this->ballotName;
    }

    void Candidate::addVotes(int votes)
    {
        this->nominalVotes += votes;
    }

    int Candidate::calculateAge(Date birthDate, Date electionDate)
    {
        return 0;
    }

    int Candidate::getOfficeOption()const
    {
        return officeOption;
    }
    
    int Candidate::getCandidateNumber()const
    {
        return candidateNumber;
    }

    int Candidate::getPartyNumber()const
    {
        return partyNumber;
    }

    int Candidate::getFederationNumber() const
    {
        return federationNumber;
    }

    int Candidate::getGender() const
    {
        return gender;
    }

    int Candidate::getTurnStatus()const
    {
        return turnStatus;
    }

    int Candidate::getCandidacyCondition() const
    {
        return candidacyCondition;
    }

    int Candidate::getAge() const
    {
        return age;
    }

    int Candidate::getNominalVotes() const
    {
        return nominalVotes;
    }

    bool Candidate::isElected() const
    {
        if (turnStatus == 2 || turnStatus == 3) {
            return true;
        }
        else return false;
    }


    Date Candidate::getBirthDate() const
    {
        return birthDate;
    }

    string Candidate::getBallotName()const
    {
        return ballotName;
    }

    string Candidate::getVoteDestinationType() const
    {
        return voteDestinationType;
    }

    string Candidate::getPartyAcronym()const
    {
        return partyAcronym;
    }

    /*

    int Candidate::compareTo(Candidate o)
    {
        int voteResult = Integer.compare(o.nominalVotes, this->nominalVotes);

        if (voteResult != 0) return voteResult;

        int ageResult = Integer.compare(o.age, this->age);
        return ageResult;
    }      

    */ 

