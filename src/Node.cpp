#include "Node.h"

Node::Node(string name, Node* parent)
{
	this->name = name;
	this->parent = parent;
}

Node::~Node() {
	//if we delete[] parent,deleting it here can cause
	//crash program
	//double delete memory
	//corrupt tree structure
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
string Node::getPath() const
{
	if (parent == nullptr) 
	{
		return name; 
	}
	return parent->getPath() + "\\" + name;		//Path Direction
}
void Node::renameDisk(string newName)
{
	string oldPath = getPath();
	string parentPath = "";
	if (parent != nullptr)
	{
		parentPath = parent->getPath() + "/";
	}
	string newPath = parentPath + newName;
	string cmd = "[RENAMED] \"" + oldPath + "\" \"" + newName + "\"";
	system(cmd.c_str());
	name = newName;
}