#include "constants.hpp"
#ifndef _PHYSIC_SIMULATION_TOOLS
	#define _PHYSIC_SIMULATION_TOOLS

	// define the Structure

	// this Euler structure is defined for the use of Euler method
	struct Euler {
	    double displacement[ARRAY_SIZE] = {0};
	    double velocity[ARRAY_SIZE] = {0};
	};

	// Declare the functions

	void ComputeEuler(Euler * const eulerArrays, int start, int end);
	void ComputeVerlet(double * const & arrays, int start, int end);
	void ComputeMine(double * const & arrays, int start, int end);
#endif