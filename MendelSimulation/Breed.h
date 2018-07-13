// -----------------------------------------------------------
// File: Breed.h
// Atchima Klomkaew
// Programming Assignment 1 - MendelSimulation
// This program is entire my own work
// -----------------------------------------------------------
#pragma once;

#include "Simulation.h"
#include "Organism.h"
#include "BinaryTree.h"
#include <iostream>

using namespace std;

class Breed
{
private:
	char allele1;
	char allele2;
	char pair[3];
public:
	Breed();
	~Breed();
	void setAllele1(char name);
	char getAllele1();
	void setAllele2(char name);
	char getAllele2();
	void setPair(char *name);
	char *getPair();
	void execute(BinaryTree *tree, BinaryTree *tree2, Organism *par1, Organism *par2, int numOffspring, int numGene);
	void getCorrectFormGene();
};