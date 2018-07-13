// -----------------------------------------------------------
// File: Breed.cpp
// Atchima Klomkaew
// Programming Assignment 1 - MendelSimulation
// This program is entire my own work
// -----------------------------------------------------------
#include "Breed.h"
#include "BinaryTree.h"
#include <iostream>

using namespace std;

Breed::Breed()
{
	allele1 = '\0';
	allele2 = '\0';
	strcpy(pair, "");
}

Breed::~Breed()
{
}

void Breed::setAllele1(char name)
{
	allele1 = name;
}

char Breed::getAllele1()
{
	return allele1;
}

void Breed::setAllele2(char name)
{
	allele1 = name;
}

char Breed::getAllele2()
{
	return allele2;
}

void Breed::setPair(char *name)
{
	strcpy(pair, name);
}

char *Breed::getPair()
{
	return pair;
}

void Breed::execute(BinaryTree *tree, BinaryTree *tree2, Organism *par1, Organism *par2, int numOffspring, int numGene)
{
	char genesGenotype[64];
	// execute for offsprings
	for(int offspring = 0; offspring < numOffspring; offspring++)
	{
		strcpy(genesGenotype, "");
		// execute for genes (4)
		for(int index = 0; index < numGene; index++)
		{
			allele1 = par1->getAllele(index);
			allele2 = par2->getAllele(index);
			
			// ensures upper case comes first
			getCorrectFormGene();		
			strcat(genesGenotype, pair);
			strcat(genesGenotype, " ");

			// insert in tree, which will check for duplicates and increment counter
			tree->Insert(pair);			
		}
		tree2->Insert(genesGenotype);
	}
}

void Breed::getCorrectFormGene()
{
	if(allele1 < allele2)
	{
		pair[0] = allele1;
		pair[1] = allele2;
		pair[2] = '\0';
	}
	else
	{
		pair[0] = allele2;
		pair[1] = allele1;
		pair[2] = '\0';
	}
}