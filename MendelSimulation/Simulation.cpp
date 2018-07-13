// -----------------------------------------------------------
// File: Simulation.cpp
// Atchima Klomkaew
// Programming Assignment 1 - MendelSimulation
// This program is entire my own work
// -----------------------------------------------------------
#include "Simulation.h"
#include "GeneticsSimDataParser.h"
#include "GeneMaster.h"
#include "Organism.h"
#include "Breed.h"
#include "BinaryTree.h"
#include "OffspringReader.h"
#include <iostream>
#include <string>

using namespace std;

Simulation::Simulation()
{
	parent1 = NULL;
	parent2 = NULL;
	numOffspring = 0;
	numGene = 0;
}

Simulation::~Simulation()
{
	delete parent1;
	delete parent2;
}

void Simulation::runSimulation()
{
	char fileName[64];
	cout << "Please enter file name: " << endl;
	scanf("%s", fileName);

	// Read data file
	GeneticsSimDataParser *parser = new GeneticsSimDataParser(fileName);
	GeneMaster *master = new GeneMaster();
	master->loadData(parser);
	numGene = master->getGeneCount();
	master->PrintData();

	// Load data into each parent 
	parent1 = new Organism();
	parent2 = new Organism();
	parent1->loadData(parser, numGene);
	parent2->loadData(parser, numGene);

	// Print parent's data
	system("pause");
	master->PrintParentData(parent1);
	master->PrintParentData(parent2);

	cout << "\nEnter number of offspring to generate: \n--> ";
	cin >> numOffspring;

	// Start breeding & generate offsprings
	Breed *breeder = new Breed();
	BinaryTree *bt = new BinaryTree();
	BinaryTree *bt2 = new BinaryTree();
	breeder->execute(bt, bt2, parent1, parent2, numOffspring, numGene);

	cout << "\n================================= Results of this Run =================================" << endl << endl;

	// Print offsprings in the right format
	OffspringReader *reader = new OffspringReader();
	reader->PrintAllGenesCount(bt, master);
	
	system("pause");
	reader->PrintAllOccurringGenotypes(bt2);
	delete reader;
	delete bt2;
	delete bt;
	delete master;
	delete parser;
	delete breeder;
	system("pause");
}

// -- don't really need these functions
Organism *Simulation::getParent1()
{
	return parent1;
}

void Simulation::setParent1(Organism *par)
{
	*parent1 = *par;
}

Organism *Simulation::getParent2()
{
	return parent2;
}

void Simulation::setParent2(Organism *par)
{
	*parent2 = *par;
}