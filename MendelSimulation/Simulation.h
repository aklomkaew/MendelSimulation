#ifndef SIMULATION_H
#define SIMULATION_H
#pragma once;
#include <iostream>
#include <string.h>

// -----------------------------------------------------------
// File: Simulation.h
// Atchima Klomkaew
// Programming Assignment 1 - MendelSimulation
// This program is entire my own work
// -----------------------------------------------------------
#pragma once;

#include <iostream>
using namespace std;

class Organism;

class Simulation
{
private:
	Organism *parent1;
	Organism *parent2;
	int numOffspring;
	int numGene;
public:
	Simulation();
	~Simulation();
	void runSimulation();
	Organism *getParent1();
	void setParent1(Organism *par);
	Organism *getParent2();
	void setParent2(Organism *par);
};

#endif