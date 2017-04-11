#include "TransactionNode.h"
// Member Functions
// Public Functions
// constructor and destructor
TransactionNode::TransactionNode(const string & newData, const int & newUnits) : Node(newData)
{
	this->mUnits = newUnits;
}

TransactionNode::~TransactionNode()
{
	
}

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
void TransactionNode::printData()
{
	cout << this->mData  << " : " << this->getUnits();
}