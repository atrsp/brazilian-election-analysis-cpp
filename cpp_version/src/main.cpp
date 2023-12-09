#include "../include/election.hpp"
#include "../include/csvReader.hpp"
#include "../include/report.hpp"

int main(int argc, char const *argv[]) {
    string officeOption = argv[0];
    string candidatesFilePath = argv[1];
    string pollFilePath = argv[2];
    string dateString = argv[3];

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

    return 0;
}