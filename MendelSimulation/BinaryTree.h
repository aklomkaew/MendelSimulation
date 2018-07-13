// -----------------------------------------------------------
// File: BinaryTree.h
// Atchima Klomkaew
// Programming Assignment 1 - MendelSimulation
// This program is entire my own work
// Although the structure of BinaryTree is from Code Vault as I used it as a guideline.
// -----------------------------------------------------------
#pragma once
#include <iostream>

using namespace std;

struct Node
{
	char key[64];
	int counter;
	Node *left;
	Node *right;
	char balanceFactor;
};

class BinaryTree
{
private:
	Node *root;
	void ClearTree(Node *T);
	Node *DupNode(Node *T);
	void PrintAll(Node *T);
public:
	BinaryTree();
	~BinaryTree();
	bool isEmpty();
	Node *SearchTree(char *key, Node *T);
	bool Insert(Node *newNode);
	bool Insert(char *key);
	Node *Delete(char *key);
	void PrintOne(Node *T);
	void PrintTree();
	void IncrementCounter(char *key);
	Node *GetRoot();
	void CustomizedPrintOne(Node *T);
	void CustomizedPrintAll(Node *T);
};
