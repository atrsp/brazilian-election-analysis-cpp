#ifndef REPORT_H
#define REPORT_H

#include <string>
#include <list>

class Election;  // Forward declaration

class Report {
private:
    Election* election;

public:
    Report(Election* election);
    ~Report();

    void generateReport();
    void generateCandidatesReport();
    void generatePartiesReport();
};

#endif // REPORT_H
