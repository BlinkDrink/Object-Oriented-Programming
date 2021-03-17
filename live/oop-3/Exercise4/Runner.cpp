#include "Runner.hpp"
#include <cstring>

using std::cin;
using std::cout;
using std::strlen;

Runner* initRunner()
{
    Runner* r = new Runner;

    char name[100];
    cin.getline(name, 100);

    unsigned nameLen = strlen(name);
    const unsigned recordsLen = 12;

    r->name = new char[nameLen + 1];
    if (!r->name) {
        return nullptr;
    }

    for (unsigned i = 0; i <= nameLen; i++) {
        r->name[i] = name[i];
    }

    for (unsigned i = 0; i < recordsLen; i++) {
        cin >> r->records[i];
    }

    return r;
};

void printRunner(Runner* r)
{
    cout << r->name << ' ';
}

double getAvgTime(Runner* r)
{
    double avg = 0;
    for (unsigned i = 0; i < 12; i++) {
        avg += r->records[i];
    }

    return avg / 12;
}

void printRunnerWithLowestTempo(Runner* runners, unsigned count)
{
    unsigned index = 0;
    double minTempo = 3000;
    const double KM_PER_RUN = 42;
    for (unsigned i = 0; i < count; i++) {
        double currTempo = getAvgTime(&runners[i]) / KM_PER_RUN;
        if (minTempo > currTempo) {
            minTempo = currTempo;
            index = i;
        }
    }

    printRunner(&runners[index]);
    cout << minTempo << '\n';
}
