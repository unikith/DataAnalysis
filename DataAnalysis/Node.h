#ifndef NODE_H
#define NODE_H

#include <string>

using std::string;

class Node // Node is an abstract class that can be used to define types of nodes for BSTs
{
public:
	// constructor and destructor
	Node(const string & newData = "");
	virtual ~Node();

	// setters
	void setData(const string & newData);
	void setLeft(Node *& newLeft);
	void setRight(Node *& newRight);

	// getters
	string getData() const;
	Node *& getLeft();
	Node *& getRight();

	// Node functions
	virtual void printData() = 0;
protected:
	string mData;
	Node * mpLeft;
	Node * mpRight;
};

#endif // !NODE_H
