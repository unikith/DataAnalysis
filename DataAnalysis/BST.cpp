#include "BST.h"
// Member Functions
// Public Functions
// constructor and destructor
BST::BST()
{
	this->mpRoot = nullptr;
}

BST::~BST()
{
	this->deleteTree(this->getRoot());
}

// setter
void BST::setRoot(Node *& pNewRoot)
{
	this->mpRoot = pNewRoot;
}

// getter
Node *& BST::getRoot()
{
	return this->mpRoot;
}

// BST functions

void BST::insert(const string & newData, const int & newUnits)
{
	this->insert(newData, newUnits, this->getRoot());
}

void BST::inOrderTransversal()
{
	this->inOrderTransversal(this->getRoot());
}

TransactionNode & BST::findSmallest()
{
	return this->findSmallest(this->getRoot());
}

TransactionNode & BST::findLargest()
{
	return this->findLargest(this->getRoot());
}

// Private Functions
// Helper functions
void BST::deleteTree(Node * pSubTree)
{
	if (pSubTree != nullptr)
	{
		this->deleteTree(pSubTree->getLeft());
		this->deleteTree(pSubTree->getRight());
		delete pSubTree;
	}
}

void BST::insert(const string & newData, const int & newUnits, Node *& pSubTree)
{
	TransactionNode * pTree = dynamic_cast<TransactionNode *>(pSubTree);
	if (pSubTree == nullptr)
	{
		TransactionNode * pMem = new TransactionNode(newData, newUnits);
		pSubTree = pMem;
	}// pSubTree == nullptr
	else if (pTree != nullptr)
	{
		if (pTree->getUnits() > newUnits)
		{
			this->insert(newData, newUnits, pSubTree->getLeft());
		}
		else if (pTree->getUnits() < newUnits)
		{
			this->insert(newData, newUnits, pSubTree->getRight());
		}
		else
		{
			cout << "Duplicate Value" << endl;
		}
	} // pTree != nullptr
	else
	{
		cout << "Unable to insert values" << endl;
	}
	
}

void BST::inOrderTransversal(Node *& pSubTree)
{
	if (pSubTree != nullptr)
	{
		inOrderTransversal(pSubTree->getLeft());
		TransactionNode * pTree = dynamic_cast<TransactionNode *>(pSubTree);
		pTree->printData();
		cout << endl;
		inOrderTransversal(pSubTree->getRight());
	}
}

TransactionNode & BST::findSmallest(Node *& pSubTree)
{
	if (pSubTree->getLeft() == nullptr)
	{
		return  *(dynamic_cast<TransactionNode *>(pSubTree));
	}
	else
	{
		return findSmallest(pSubTree->getLeft());
	}
}

TransactionNode & BST::findLargest(Node *& pSubTree)
{
	if (pSubTree->getRight() == nullptr)
	{
		return  *(dynamic_cast<TransactionNode *>(pSubTree));
	}
	else
	{
		return findLargest(pSubTree->getRight());
	}
}