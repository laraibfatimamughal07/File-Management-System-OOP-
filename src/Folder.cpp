#include "Folder.h"
#include<cstdlib> // to create mkdir on disk

Folder::Folder(string name, Node* parent) :Node(name, parent)
{
	string cmd = "mkdir \"" + getPath() + "\"";
	system(cmd.c_str()); 
	if (parent != nullptr)    
	{
		cout << "[FOLDER CREATED] " << name << endl;
	}
}

void Folder::addNode(Node* node)			//Function to add Node
{
	children.push_back(node);				//stores address and address-> object
}

Node* Folder::findchild(string name) const	//Function to Find Child of Node (abstract) class
{
	for (Node* child : children)
	{
		if (child->getName() == name)
			return child;
	}
	return nullptr;
}

void Folder::removeNode(string name)		//Function to remove Node
{
	for (int i = 0;i < children.size();i++)
	{
		if (children[i]->getName() == name)
		{
			children[i]->Remove();
			delete children[i];
			children.erase(children.begin() + i);
			break;
		}
	}
}

void Folder::list() const					//Function to list all the Contents (childs) of a Folder
{
	cout << "[CONTENTS] "<<name << endl;
	for (Node* child : children)
	{
		cout << "-" << child->getName() << endl;
	}
}

bool Folder::searchNode(string target, string path)		//Function to search a child's path and name
{
	string current = path + "/" + name;

	for (Node* child : children)
	{
		if (child->getName() == target)
		{
			cout << "[FOUND]" << endl;
			cout << "Name: " << target << endl;
			cout << "Path: " << current << "/" << target << endl;
			return true;
		}
		if (child->isFolder())
		{
			Folder* f = static_cast<Folder*>(child);
			if (f->searchNode(target, current))
				return true;
		}
	}
	return false;
}

void Folder::Open()		//Functio to Open Folder
{
	cout << "[OPENED] " << name << endl;
	list();
}

void Folder::Remove()	//Function to Remove Folder
{
	string cmd = "rmdir /s /q \"" + getPath() + "\"";
	system(cmd.c_str());
	cout << "[FOLDER DELETED] " << name << endl;
}

bool Folder::isFolder()		//Function returns yrue if the object formed is a Folder
{
	return true;
}

Folder::~Folder()	
{
	for (Node* child : children)
	{
		delete child;
	}
}