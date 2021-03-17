#include "Runner.hpp"

using std::cin;
using std::cout;

void deleteRunners(Runner* runners, unsigned count)
{
    for (unsigned i = 0; i < count; i++) {
        delete[] runners[i].name;
    }
}

int main()
{
    unsigned n;
    cin >> n;
    cin.ignore();

    Runner* runners = new Runner[n];
    if (!runners) {
        return 1;
    }

    for (int i = 0; i < n; i++) {
        Runner* r = initRunner();
        runners[i] = *r;
        cin.ignore();
    }

    printRunnerWithLowestTempo(runners, n);

    if (n > 2) {
        cout << runners[0].beatNtimes(&runners[1]);
    }

    deleteRunners(runners, n);
    delete[] runners;

    return 0;
}
