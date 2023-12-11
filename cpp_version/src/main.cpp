#include "../include/election.hpp"
#include "../include/party.hpp"
#include "../include/candidate.hpp"
#include "../include/csvReader.hpp"
#include "../include/report.hpp"

int main(int argc, char const *argv[]) {

    /*
    string officeOption = argv[1];
    string candidatesFilePath = argv[2];
    string pollFilePath = argv[3];
    string dateString = argv[4];

    cout << "officeOption: " << officeOption << endl;
    cout << "candidatesFilePath: " << candidatesFilePath << endl;
    cout << "pollFilePath: " << pollFilePath << endl;
    cout << "dateString: " << dateString << endl;

    Date electionDate;
    //DateTimeFormatter dateFormat = DateTimeFormatter.ofPattern("dd/MM/yyyy", Locale.forLanguageTag("pt-BR"));

    Election poll = Election(electionDate, officeOption);

    CsvReader reader = CsvReader(candidatesFilePath, pollFilePath);
    reader.candidatesReader(poll);
    reader.votesReader(poll);

    Report report = Report(poll);
    report.report1(); 
    report.report2(); 
    report.report3(); 
    report.report4(); 
    report.report5(); 
    report.report6(); 
    report.report7();
    report.report8(); 
    report.report9(); 
    report.report10();

    */
    Date date;
    Candidate c(1, 11123, "SANDRO HELENO GOMES DE SOUZA", 11, "PT", 1, "25/05/04", 1, 2, "sla", 1, date);
    Party p (11, "PT", "Partido dos Trabalhadores");

    p.addCandidate(c.getCandidateNumber(), &c);
    map<int, Candidate*> copy = p->getCandidates()->find(11);

    return 0;
}