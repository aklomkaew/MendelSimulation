// -----------------------------------------------------------
// File: Gene.h
// Atchima Klomkaew
// Programming Assignment 1 - MendelSimulation
// This program is entire my own work
// -----------------------------------------------------------
#pragma once;
#include <iostream>

using namespace std;

class Gene
{
private:
	char geneTrait[64];
	char allele1;
	char allele2;
public:
	Gene();
	~Gene();
	void setGeneTrait(char *name);
	char *getGeneTrait();
	void setAllele1(char name);
	char getAllele1();
	void setAllele2(char name);
	char getAllele2();
	void loadData(char *genotype);
	void getGenotype();
};