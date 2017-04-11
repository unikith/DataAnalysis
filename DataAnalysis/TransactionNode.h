#ifndef TRANSACTIONNODE_H
#define TRANSACTIONNODE_H

#include "Node.h"

#include <iostream>

using std::cout;

class TransactionNode : public Node // a concrete class derived from Node to 
								//insert into the BST and track units
{
public:
	// constructor and destructor
	TransactionNode(const string & newData = "", const int & newUnits = 0);
	~TransactionNode();

	// setter
	void setUnits(const int & newUnits);

	// getter
	int getUnits() const;

	// Node Functions
	void printData();
private:
	int mUnits;
};

#endif // !TRANSACTIONNODE_H
