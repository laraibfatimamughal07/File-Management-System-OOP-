#include "Node.h"

Node::Node(string name, Node* parent)
{
	this->name = name;
	this->parent = parent;
}

Node::~Node() {
	// if we delete[] parent,deleting it here can
	//1. crash program
	//2. double delete memory
	//3. corrupt tree structure
}

string Node::getName() const
{
	return name;
}
Node* Node::getParent() const
{
	return parent;
}
void Node::setName(string n)
{
	name = n;
}