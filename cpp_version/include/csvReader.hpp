#ifndef CSVREADER_H
#define CSVREADER_H

#include <fstream>
#include <iostream>
#include <string>
#include "./election.hpp"

class CsvReader {
private:
    string candidatesFilePath;
    string pollFilePath;

public:
    CsvReader(string candidatesFilePath, string pollFilePath);
    
    string getCandidatesFilePath();
    string getPollFilePath();
    void candidatesReader(Election poll);
    void votesReader(Election poll);
    int stringToInt(string str) const;

};

#endif