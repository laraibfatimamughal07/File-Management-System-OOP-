#include "Node.h"

Node::Node(string name, Node* parent)
{
	this->name = name;
	this->parent = parent;
}

Node::~Node() {

}

string Node::getName()
{
	return name;
}
Node* Node::getParent()
{
	return parent;
}
void Node::setName(string n)
{
	name = n;
}