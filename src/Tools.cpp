#include <iostream>
#include "Tools.hpp"
#include "constants.hpp"

using namespace std;

const double & DELTA_T = TIME_STEP;

// This module defines the tool functions

// This function takes in the struct Euler, computes the index from start to end(both included)
void ComputeEuler(Euler * const euler, int start, int end) {
    // Error exception
    if (start > end) throw string("ComputeEuler: Index error");
    if (((start < 0) || (start > ARRAY_SIZE)) || ((end < 0) ||(end > ARRAY_SIZE)))
                    throw string("ComputeEuler: Index out of range");

    // Compute function
    for (int i = start; i < end + 1; i++) {
        euler->velocity[i] = euler->velocity[i-1] + -1 * euler->displacement[i-1] * DELTA_T;
        euler->displacement[i] = euler->displacement[i-1] + euler->velocity[i-1] * DELTA_T;
    }
}

// This function takes in a double array, computes the index from start to end(both included)
void ComputeVerlet(double * const & arrays, int start, int end) {
    // Error exception
    if (start > end) throw string("ComputeVerlet: Index error");
    if (((start < 0) || (start > ARRAY_SIZE)) || ((end < 0) ||(end > ARRAY_SIZE)))
        throw string("ComputeVerlet: Index out of range");

    // Compute function
    if (start == 1) {
        arrays[1] = arrays[0] + 0.5 * -1 * DELTA_T * DELTA_T;
        ComputeVerlet(arrays, start + 1, end);
        return;
    }
    for (int i = start; i < end + 1; i++) {
        arrays[i] = 2 * arrays[i-1] - arrays[i-2] + -1 * arrays[i-1] * DELTA_T * DELTA_T;
    }
}

// This function takes in a displacement array, computes the index from start to end(both included)
void ComputeMine(double * const & arrays, int start, int end) {
    // Error exception
    if (start > end) throw string("ComputeEuler: Index error");
    if (((start < 0) || (start > ARRAY_SIZE)) || ((end < 0) ||(end > ARRAY_SIZE)))
        throw string("ComputeEuler: Index out of range");

    // Compute function
    if (start == 1) {
        arrays[1] = arrays[0] + 0.5 * -1 * DELTA_T * DELTA_T + 1.0 / 24.0 * arrays[0] * DELTA_T * DELTA_T * DELTA_T * DELTA_T;
        ComputeMine(arrays, start + 1, end);
        return;
    }
    for (int i = start; i < end + 1; i++) {
        arrays[i] = 2.0 * arrays[i-1] - arrays[i-2] + -1 * arrays[i-1] * DELTA_T * DELTA_T + 1.0 / 12.0 * arrays[i-1] * DELTA_T * DELTA_T * DELTA_T * DELTA_T;
    }

}