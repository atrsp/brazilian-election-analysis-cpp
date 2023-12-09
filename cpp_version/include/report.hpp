#ifndef REPORT_H
#define REPORT_H

#include "./election.hpp"

class Report {
private:
    Election poll;
    list<Candidate> sortCandidates;
    list<Party> sortParties;
    int seats;

public:
    Report(const Election& poll);
    void report1();
    void report2();
    void report3();
    void report4();
    void report5();
    void report6();
    void report7();
    void report8();
    void report9();
    void report10();

    locale portugueseFormat(); //pt_BR.utf8
    void doubleFormat(locale nf);
};

#endif