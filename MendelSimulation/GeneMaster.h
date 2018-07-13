// -----------------------------------------------------------
// File: GeneMaster.h
// Atchima Klomkaew
// Programming Assignment 1 - MendelSimulation
// This program is entire my own work
// -----------------------------------------------------------
#pragma once;

#include <vector>
#include "GeneticsSimDataParser.h"
#include "Organism.h"
#include <string>
#include <iostream>

using namespace std;

struct GeneStructDef
{
	char traitName[50];
	char domAllele[50];
	char domSym[2];
	char recAllele[50];
	char recSym[2];
	char homoDom[3];
	char hetero[3];
	char homoRec[3];
};

class GeneMaster
{
private:
	int geneCount;
	vector<GeneStructDef> vGeneStruct;
public:
	GeneMaster();
	~GeneMaster();
	int getGeneCount();
	void setGeneCount(int num);
	void loadData(GeneticsSimDataParser *parser);
	void getGeneInfo(char *trait, char *domDesc, char *domSymbol, char *recDesc, char *recSymbol);
	void PrintData();
	void PrintParentData(Organism *org);
	vector<GeneStructDef> GetGeneStructDef();
};