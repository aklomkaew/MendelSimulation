// -----------------------------------------------------------
// File: Organism.h
// Atchima Klomkaew
// Programming Assignment 1 - MendelSimulation
// This program is entire my own work
// -----------------------------------------------------------
#pragma once;

#include "Simulation.h"
#include "GeneticsSimDataParser.h"
#include "Gene.h"
#include <vector>
#include <iostream>

using namespace std;

struct GeneStruct
{
	Gene *gene;
	int counter;
};

class Organism
{
private:
	char genotype[64];
	char genusName[32];
	char speciesName[32];
	char scientificName[64];
	char commonName[32];
	int geneNum;
	void DeleteGenes();
	vector<GeneStruct> vGene;

public:
	Organism();
	~Organism();
	void setGenotype(char *name);
	char *getGenotype();
	void setGenusName(char *name);
	char *getGenusName();
	void setSpeciesName(char *name);
	char *getSpeciesName();
	void setScientificName(char *name);
	char *getScientificName();
	void setCommonName(char *name);
	char *getCommonName();
	void setGeneNum(int num);
	int getGeneNum();
	void loadData(GeneticsSimDataParser *parser, int geneCount);
	char getAllele(int index);
	vector<GeneStruct> getvGeneStruct();
};
