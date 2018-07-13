// -----------------------------------------------------------
// File: Main.cpp
// Atchima Klomkaew
// Programming Assignment 1 - MendelSimulation
// This program is entire my own work
// -----------------------------------------------------------
#include "Simulation.h"
#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
	Simulation *sim = new Simulation();
	sim->runSimulation();

	delete sim;
	return 0;
}