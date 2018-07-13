// -----------------------------------------------------------
// File: Organism.cpp
// Atchima Klomkaew
// Programming Assignment 1 - MendelSimulation
// This program is entire my own work
// -----------------------------------------------------------
#include "Organism.h"
#include <iostream>
#include "GeneMaster.h"

using namespace std;

Organism::Organism()
{
	strcpy(genotype, "");
	strcpy(genusName, "");
	strcpy(speciesName, "");
	strcpy(scientificName, "");
	strcpy(commonName, "");
	geneNum = 0;
}

Organism::~Organism()
{
	DeleteGenes();
	vGene.clear();
}

void Organism::DeleteGenes()
{
	for(int i = 0; i < geneNum; i++)
	{
		delete vGene[i].gene;
	}
}

void Organism::setGenotype(char *name)
{
	strcpy(genotype, name);
}

char *Organism::getGenotype()
{
	return genotype;
}

void Organism::setGenusName(char *name)
{
	strcpy(genusName, name);
}

char *Organism::getGenusName()
{
	return genusName;
}

void Organism::setSpeciesName(char *name)
{
	strcpy(speciesName, name);
}

char *Organism::getSpeciesName()
{
	return speciesName;
}

void Organism::setScientificName(char *name)
{
	strcpy(scientificName, name);
}

char *Organism::getScientificName()
{
	return scientificName;
}

void Organism::setCommonName(char *name)
{
	strcpy(commonName, name);
}

char *Organism::getCommonName()
{
	return commonName;
}

void Organism::loadData(GeneticsSimDataParser *parser, int geneCount)
{
	char *nextGene;
	GeneStruct gStruct;

	strcpy(genusName,parser->getGenus());
	parser->getParentGenotype(genotype);
	strcpy(speciesName, parser->getSpecies());
	strcpy(scientificName, parser->getScientificName());
	strcpy(commonName, parser->getCommonName());
	geneNum = geneCount;

	Gene *gene = new Gene();

	nextGene = strtok(genotype, " ");	// first term
	gene->loadData(nextGene);
	gStruct.gene = gene;
	gStruct.counter = 0;
	vGene.push_back(gStruct);

	for(int i = 1; i < geneNum; i++)
	{
		Gene *gene = new Gene();
		nextGene = strtok(NULL, " ");
		gene->loadData(nextGene);
		gStruct.gene = gene;
		gStruct.counter = i;
		vGene.push_back(gStruct);
	}
}

char Organism::getAllele(int index)
{
	int randNum = 0;
	char ret = '\0';

	randNum = rand() % 100 + 1;
	if(randNum < 51)
	{
		// pick first allele
		ret = vGene[index].gene->getAllele1();
	}
	else
	{
		// pick second allele
		ret = vGene[index].gene->getAllele2();
	}
	return ret;
}

vector<GeneStruct> Organism::getvGeneStruct()
{
	return vGene;
}

int Organism::getGeneNum()
{
	return geneNum;
}

void Organism::setGeneNum(int num)
{
	geneNum = num;
}