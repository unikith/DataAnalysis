#ifndef BST_H
#define BST_H

#include "TransactionNode.h"

using std::endl;

class BST // uses Transaction Nodes that are saved via Node*, ordered by mUnits
{
public:
	// constructor and destructor
	BST();
	~BST();

	// setter
	void setRoot(Node *& pNewRoot);

	// getter
	Node *& getRoot();

	// BST functions
	void insert(const string & newData, const int & newUnits);
	void inOrderTransversal();
	TransactionNode & findSmallest();
	TransactionNode & findLargest();

private:
	Node * mpRoot;

	// Helper functions
	void deleteTree(Node * pSubTree);
	void insert(const string & newData, const int & newUnits, Node *& pSubTree);
	void inOrderTransversal(Node *& pSubTree);
	TransactionNode & findSmallest(Node *& pSubTree);
	TransactionNode & findLargest(Node *& pSubTree);
};

#endif // !BST_H
