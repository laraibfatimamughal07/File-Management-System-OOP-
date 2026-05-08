#include "Folder.h"

Folder::Folder(string name, Node* parent) :Node(name, parent)
{
	
}

void Folder::addNode(Node* node)
{
	children.push_back(node);
}

Node* Folder::findchild(string name) const
{
	for (Node* child : children)
	{
		if (child->getName() == name)
			return child;
	}
	return nullptr;
}

void Folder::removeNode(string name)
{
	for (int i = 0;i < children.size();i++)
	{
		if (children[i]->getName() == name)
		{
			delete children[i];
			children.erase(children.begin() + i);
			break;
		}
	}
}

void Folder::list() const
{
	cout << "[CONTENTS OF " << name << " ]" << endl;
	for (Node* child : children)
	{
		cout << "-" << child->getName() << endl;
	}
}

bool Folder::searchNode(string target, string path)
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

void Folder::Open()
{
	cout << "[OPENED] " << name << endl;
	list();
}

void Folder::Remove()
{
	cout << "[DELETED] Folder: " << name << endl;
}

bool Folder::isFolder()
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