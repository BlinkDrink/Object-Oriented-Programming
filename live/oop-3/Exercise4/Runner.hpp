#pragma once
#include <iostream>

struct Runner {
    char* name;
    unsigned records[12];

    unsigned beatNtimes(Runner* runner)
    {
        unsigned counter = 0;

        for (unsigned i = 0; i < 12; i++) {
            if (runner->records[i] < records[i]) {
                counter++;
            }
        }

        return counter;
    }
};

Runner* initRunner();

void printRunner(Runner* r);

void printRunnerWithLowestTempo(Runner* runners, unsigned count);

double getAvgTime(Runner* runner);
