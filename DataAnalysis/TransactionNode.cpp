#include "TransactionNode.h"
// Member Functions
// Public Functions
// constructor and destructor
TransactionNode::TransactionNode(const string & newData, const int & newUnits) : Node(newData)
{
	this->mUnits = newUnits;
}

TransactionNode::~TransactionNode(){/*Empty*/}

// setter
void TransactionNode::setUnits(const int & newUnits)
{
	this->mUnits = newUnits;
}

// getter
int TransactionNode::getUnits() const
{
	return this->mUnits;
}

// Node Functions
void TransactionNode::printData() // prints out data to console note: does not add new line
{
	cout << this->mData  << " : " << this->getUnits();
}