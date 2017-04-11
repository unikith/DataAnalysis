#include "Node.h"
// Member Functions
// Public
// constructor and destructor
Node::Node(const string & newData) // used for derived classes
{
	this->mData = newData;
	this->mpLeft = nullptr;
	this->mpRight = nullptr;
}

Node::~Node() {/*Empty*/}

// setters
void Node::setData(const string & newData)
{
	this->mData = newData;
}

void Node::setLeft(Node *& newLeft)
{
	this->mpLeft = newLeft;
}

void Node::setRight(Node *& newRight)
{
	this->mpRight = newRight;
}

// getters
string Node::getData() const
{
	return this->mData;
}

Node *& Node::getLeft()
{
	return this->mpLeft;
}

Node *& Node::getRight()
{
	return this->mpRight;
}