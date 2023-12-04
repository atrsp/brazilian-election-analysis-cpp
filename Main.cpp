#include <iostream>
#include <regex>
#include <string>
#include <locale>
#include <chrono>
#include "Election.h"
#include "Report.h"
#include "CSVReader.h"

int main(int argc, char* argv[]) {
    
    // Verifique se o número correto de argumentos foi fornecido
    if (argc != 5) {
        std::cout << "To run properly, use: ./deputies --<office_option> <candidates_file_path> <poll_file_path> <election_date>" << std::endl;
        return 0;
    }
    
    // Extrair argumentos
    std::string officeOption = argv[1];
    std::string candidatesFilePath = argv[2];
    std::string pollFilePath = argv[3];
    std::string dateString = argv[4];

    // Validar o formato da data
    std::regex datePattern("\\d{2}/\\d{2}/\\d{4}");
    if (!std::regex_match(dateString, datePattern)) {
        std::cout << "Invalid Date Format. Use dd/MM/yyyy" << std::endl;
        return 0;
    }
    
    std::chrono::system_clock::time_point electionDate;
    std::istringstream dateStream(dateString);
    dateStream >> std::get_time(&electionDate, "%d/%m/%Y");

    // Criar uma nova instância de Election
    Election poll(electionDate, officeOption);

    // Ler dados de candidatos e votos de arquivos CSV
    CSVReader reader(candidatesFilePath, pollFilePath);
    reader.candidatesReader(poll);
    reader.votesReader(poll);

    // Gerar relatórios
    Report report(poll);
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
