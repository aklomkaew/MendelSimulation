// -----------------------------------------------------------
// File: OffspringReader.h
// Atchima Klomkaew
// Programming Assignment 1 - MendelSimulation
// This program is entire my own work
// -----------------------------------------------------------
#pragma once;

#include "BinaryTree.h"
#include "GeneMaster.h"
#include <iostream>

using namespace std;

class OffspringReader
{
private:
public:
	OffspringReader();
	~OffspringReader();
	void PrintAllGenesCount(BinaryTree *tree, GeneMaster *master);
	void PrintAllOccurringGenotypes(BinaryTree *tree);
};