#include <iostream>
#include <iomanip>
#include "constants.hpp"
#include "Tools.hpp"

using namespace std;

// Declare the functions

void ComputeInEpochs(Euler * const euler, double * const & verlet, double * const & mine);
void PrintResults(Euler * const euler, double * const & verlet, double * const & mine);

// Main function
int main() {

    Euler euler;
    double verlet[ARRAY_SIZE], mine[ARRAY_SIZE];

    // Initialization
    euler.displacement[0] = verlet[0] = mine[0] = 1.0;

    ComputeInEpochs(&euler, verlet, mine);
    PrintResults(&euler, verlet, mine);

    return 0;
}

// Define the tool functions

// Compute the three methods in epochs
void ComputeInEpochs(Euler * const euler, double * const & verlet, double * const & mine) {

    // Compute the three methods in epochs
    for (int epoch = 0; epoch < TOTAL_EPOCHS; epoch++) {
        cout << "Epoch: " << epoch << endl;

        const int START = epoch * EPOCH_SIZE + 1,
                    END = (epoch + 1) * EPOCH_SIZE;

        cout << "Computing Euler... ";
        ComputeEuler(euler, START, END);
        cout << "Done!" << endl;

        cout << "Computing Verlet... ";
        ComputeVerlet(verlet, START, END);
        cout << "Done!" << endl;

        cout << "Computing Mine... ";
        ComputeMine(mine, START, END);
        cout << "Done!" << endl;
    }
}

// Print the results
void PrintResults(Euler *const euler, double *const &verlet, double *const &mine) {
    const int ARRAY_END = ARRAY_SIZE - 1;

    // Print the results
    cout << "\nHere are the results:" << endl;
    cout << "Euler:" << setprecision(10) << euler->displacement[ARRAY_END] << endl;
    cout << "Verlet:" << setprecision(10) << verlet[ARRAY_END] << endl;
    cout << "Mine:" << setprecision(10) << mine[ARRAY_END] << endl;
}