// -----------------------------------------------------------
// File: OffspringReader.cpp
// Atchima Klomkaew
// Programming Assignment 1 - MendelSimulation
// This program is entire my own work
// -----------------------------------------------------------
#include "OffspringReader.h"
#include <iostream>

using namespace std;

OffspringReader::OffspringReader()
{
}

OffspringReader::~OffspringReader()
{
}

void OffspringReader::PrintAllGenesCount(BinaryTree *tree, GeneMaster *master)
{
	vector<GeneStructDef> vec = master->GetGeneStructDef();
	Node *temp = NULL;
	int homoDomCount = 0;
	int heteroCount = 0;
	int homoRecCount = 0; 

	for(int i = 0; i < master->getGeneCount(); i++)
	{
		// calculate homozygous dominant count
		temp = tree->SearchTree(vec[i].homoDom, tree->GetRoot());
		if(temp != NULL)
			homoDomCount = temp->counter;

		// calculate heterozygous dominant count
		temp = tree->SearchTree(vec[i].hetero, tree->GetRoot());
		if(temp != NULL)
			heteroCount = temp->counter;

		// calculate homozygous recessive count
		temp = tree->SearchTree(vec[i].homoRec, tree->GetRoot());
		if(temp != NULL)
			homoRecCount = temp->counter;

		cout << "Gene: " << vec[i].traitName << endl;
		cout << "\t\t" << homoDomCount << " homozygous dominant (" 
			 << vec[i].domAllele << " " << vec[i].homoDom << ")\n"
			 << "\t\t" << heteroCount << " heterozygous dominant ("
			 << vec[i].domAllele << " " << vec[i].hetero << ")\n"
			 << "\t\t" << homoRecCount << " homozygous recessive ("
			 << vec[i].recAllele << " " << vec[i].homoRec << ")\n\n";
	}
}

void OffspringReader::PrintAllOccurringGenotypes(BinaryTree *tree)
{
	cout << "\nAll occurring genotypes with the count of each.\n" << endl;
	tree->CustomizedPrintAll(tree->GetRoot());
}