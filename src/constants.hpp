#ifndef _PHYSIC_SIMULATION_CONSTANTS
	#define _PHYSIC_SIMULATION_CONSTANTS
	// This file defines all constants in the program

	static const double TARGET_TIME = 314.15926;
	const int TOTAL_STEPS = 10000;
	const int TOTAL_EPOCHS = 20;

	const double TIME_STEP = TARGET_TIME / TOTAL_STEPS;
	const int ARRAY_SIZE = TOTAL_STEPS + 1;
	const int EPOCH_SIZE = TOTAL_STEPS / TOTAL_EPOCHS;

#endif
