#ifndef CSVREADER_H
#define CSVREADER_H

#include <string>
#include <list>
#include <vector>

class Election;  // Forward declaration

class CSVReader {
private:
    Election* election;

public:
    CSVReader(Election* election);
    ~CSVReader();

    void readCandidatesCSV(const std::string& filename);
    void readVotesCSV(const std::string& filename);
};

#endif // CSVREADER_H
