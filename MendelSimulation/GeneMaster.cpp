// -----------------------------------------------------------
// File: GeneMaster.cpp
// Atchima Klomkaew
// Programming Assignment 1 - MendelSimulation
// This program is entire my own work
// -----------------------------------------------------------
#include "GeneMaster.h"
#include <iostream>
#include <string.h>

using namespace std;

GeneMaster::GeneMaster()
{
	geneCount = 0;
}

GeneMaster::~GeneMaster()
{
	vGeneStruct.clear();
}

int GeneMaster::getGeneCount()
{
	return geneCount;
}

void GeneMaster::setGeneCount(int num)
{
	geneCount = num;
}

void GeneMaster::loadData(GeneticsSimDataParser *parser)
{
	geneCount = parser->getGeneCount();
	for(int i = 0; i < geneCount; i++)
	{
		GeneStructDef geneStruct;
		if(parser->getGeneData(geneStruct.traitName,
							   geneStruct.domAllele,
							   geneStruct.domSym,
							   geneStruct.recAllele,
							   geneStruct.recSym))
		{
			// add null terminator
			geneStruct.domSym[1] = '\0';
			geneStruct.recSym[1] = '\0';

			geneStruct.homoDom[0] = geneStruct.domSym[0];
			geneStruct.homoDom[1] = geneStruct.domSym[0];
			geneStruct.homoDom[2] = '\0';

			geneStruct.hetero[0] = geneStruct.domSym[0];
			geneStruct.hetero[1] = geneStruct.recSym[0];
			geneStruct.hetero[2] = '\0';

			geneStruct.homoRec[0] = geneStruct.recSym[0];
			geneStruct.homoRec[1] = geneStruct.recSym[0];
			geneStruct.homoRec[2] = '\0';

			vGeneStruct.push_back(geneStruct);
		}
	}
}

// -- don't really need this
void GeneMaster::getGeneInfo(char *trait, char *domDesc, char *domSymbol, char *recDesc, char *recSymbol)
{
	vector<GeneStructDef>::iterator itr;
	GeneStructDef gStruct;
	for(itr = vGeneStruct.begin(); itr != vGeneStruct.end(); itr++)
	{
		gStruct = *itr;
		strcpy(trait, gStruct.traitName);
		strcpy(domDesc, gStruct.domAllele);
		strcpy(domSymbol, gStruct.domSym);
		strcpy(recDesc, gStruct.recAllele);
		strcpy(recSymbol, gStruct.recSym);
	}
}

void GeneMaster::PrintData()
{
	cout << "\nMaster Genes:" << endl;
	for(int i = 0; i < geneCount; i++)
	{
		cout << "\tTrait Name: " << vGeneStruct[i].traitName << endl;
		cout << "\t\tDominant Name: " << vGeneStruct[i].domAllele 
											<< "(" << vGeneStruct[i].domSym[0] << ")" << endl;
		cout << "\t\tRecessive Name: " << vGeneStruct[i].recAllele
											 << "(" << vGeneStruct[i].recSym[0] << ")" << endl << endl;
	}
}

void GeneMaster::PrintParentData(Organism *org)
{
	int static num = 1;

	cout << "\tSim parent " << num << endl;
	cout << "\t\tOrganism genus-species: " << org->getScientificName() << endl;
	cout << "\t\tCommon name: " << org->getCommonName() << endl;
	cout << "\t\tGenes: " << endl;
	for(int i = 0; i < org->getGeneNum(); i++)
	{
		cout << "\t\t\tGene type = " << vGeneStruct[i].traitName << endl;
		cout << "\t\t\t\tGenotype = " << org->getvGeneStruct()[i].gene->getAllele1()
									  << org->getvGeneStruct()[i].gene->getAllele2() << endl;
	}

	num++;
}

vector<GeneStructDef> GeneMaster::GetGeneStructDef()
{
	return vGeneStruct;
}
