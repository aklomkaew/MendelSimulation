// -----------------------------------------------------------
// File: Gene.cpp
// Atchima Klomkaew
// Programming Assignment 1 - MendelSimulation
// This program is entire my own work
// -----------------------------------------------------------
#include "Gene.h"
#include <iostream>

using namespace std;

Gene::Gene()
{
	strcpy(geneTrait, "");
	allele1 = '\0';
	allele2 = '\0';
}

Gene::~Gene()
{
}

void Gene::setGeneTrait(char *name)
{
	strcpy(geneTrait, name);
}

char *Gene::getGeneTrait()
{
	return geneTrait;
}

void Gene::setAllele1(char name)
{
	allele1 = name;
}

char Gene::getAllele1()
{
	return allele1;
}

void Gene::setAllele2(char name)
{
	allele2 = name;
}

char Gene::getAllele2()
{
	return allele2;
}

void Gene::loadData(char *genotype)
{
	allele1 = genotype[0];
	allele2 = genotype[1];
}