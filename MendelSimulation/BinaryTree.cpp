// -----------------------------------------------------------
// File: BinaryTree.cpp
// Atchima Klomkaew
// Programming Assignment 1 - MendelSimulation
// This program is entire my own work
// Although some of the functions are either from or somewhat from Code Vault
// -----------------------------------------------------------
#include "BinaryTree.h"
#include <iostream>

using namespace std;

BinaryTree::BinaryTree()
{
	root = NULL;
}

BinaryTree::~BinaryTree()
{
	ClearTree(root);
}

Node *BinaryTree::SearchTree(char *key, Node *T)
{
	if(T != NULL)
	{
		if(strcmp(key, T->key) == 0)
			return T;
		else if(strcmp(key, T->key) < 0)
			return SearchTree(key, T->left);
		else
			return SearchTree(key, T->right);
	}
	return NULL;
}

bool BinaryTree::Insert(Node *newNode)
{
	Node *temp = root;
	Node *back = NULL;

	Node *t = SearchTree(newNode->key, root);
	if(t != NULL)
	{
		t->counter++;
		return true;
	}

	while(temp != NULL)
	{
		back = temp;
		if(strcmp(newNode->key, temp->key) < 0)
			temp = temp->left;
		else
			temp = temp->right;
	}
	if(back == NULL)
		root = newNode;
	else if(strcmp(newNode->key, back->key) < 0)
		back->left = newNode;
	else
		back->right = newNode;

	return true;
}

bool BinaryTree::Insert(char *key)
{
	Node *newNode = new Node();
	
	strcpy(newNode->key, key);
	newNode->counter = 1;
	newNode->left = newNode->right = NULL;

	return Insert(newNode);
}

// -- don't really need this
Node *BinaryTree::Delete(char *key)
{
	Node *temp = root;
	Node *back = NULL;
	Node *delNode = NULL;
	Node *delParent = NULL;

	// Step 1: Find node to delete
	while((temp != NULL) && (temp->key != key))
	{
		back = temp;
		if(key > temp->key)
		{
			temp = temp->right;
		}
		else
		{
			temp = temp->left;
		}
	}

	if(temp == NULL)
	{
		return NULL;
	}
	else
	{
		delNode = temp;
		delParent = back;
	}

	// Step 2: No children or one child on left
	if(delNode->right == NULL)
	{
		if(delParent == NULL)	// deleting the root
		{
			root = delNode->left;
			return delNode;
		}
		else
		{
			if(delParent->left == delNode)
			{
				delParent->left = delNode->left;
			}
			else
			{
				delParent->right = delNode->left;
			}
			return delNode;
		}
	}

	// Step 3: One child on the right
	else if(delNode->left == NULL)
	{
		if(delParent == NULL)
		{
			// delNode is root
			root = delNode->right;
			return delNode;
		}
		else
		{
			if(delParent->left == delNode)
			{
				delParent->left = delNode->right;
			}
			else
			{
				delParent->right = delNode->right;
			}
			return delNode;
		}
	}

	// Step 4: Two children
	else
	{
		Node *dup = this->DupNode(delNode);
		// find right most node in left sub tree or left most node in right sub tree
		temp = delNode->left;
		back = delNode;
		while(temp->right != NULL)
		{
			back = temp;
			temp = temp->right;
		}

		// copy data into node to be "deleted"
		strcpy(temp->key, delNode->key);
		temp->counter = delNode->counter;

		// copy pointer
		if(back == delNode)
		{
			back->left = temp->left;
		}
		else
		{
			back->right = temp->left;
		}

		// free(temp)
		delete temp;
		return dup;
	}
}

// -- don't really need this
void BinaryTree::PrintOne(Node *T)
{
	cout << T->key << "\t\t" << T->counter << endl;
}

void BinaryTree::PrintTree()
{
	PrintAll(root);
}

void BinaryTree::ClearTree(Node *T)
{
	if(T == NULL)
		return;
	if(T->left != NULL)
		ClearTree(T->left);
	if(T->right != NULL)
		ClearTree(T->right);
	delete T;
}

Node *BinaryTree::DupNode(Node *T)
{
	Node *dup = new Node();
	*dup = *T;
	dup->left = dup->right = NULL;

	return dup;
}

void BinaryTree::PrintAll(Node *T)
{
	if(T != NULL)
	{
		// in-order
		PrintAll(T->left);
		PrintOne(T);
		PrintAll(T->right);
	}
}

Node *BinaryTree::GetRoot()
{
	return root;
}

void BinaryTree::CustomizedPrintOne(Node *T)
{
	cout << "\tGenotype = " << T->key 
		 << "\tOffspring count = " << T->counter << endl;
}

void BinaryTree::CustomizedPrintAll(Node *T)
{
	if(T != NULL)
	{
		// in-order
		CustomizedPrintAll(T->left);
		CustomizedPrintOne(T);
		CustomizedPrintAll(T->right);
	}
}