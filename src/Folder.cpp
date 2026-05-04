#include "Folder.h"

Folder::Folder(string name, Node* parent) :Node(name, parent), count(0)
{
	size = 5;
	count = 0;
	children = new Node * [size];
	for (int i = 0;i < size;i++)
	{
		children[i] = nullptr;
	}
}

void Folder::addNode(Node* node)
{
	if (count == size)
	{
		size *= 2;
		Node** temp = new Node * [size];
		for (int i = 0;i < size;i++)
		{
			temp[i] = nullptr;
			temp[i] = children[i];
		}
		delete[] children;
		children = temp;
	}
	children[count++] = node;
}

Node* Folder::findchild(string name)
{
	for (int i = 0;i < count;i++)
	{
		if (children[i]->getName() == name)
			return children[i];
	}
	return nullptr;
}

void Folder::removeNode(string name)
{
	for (int i = 0;i < count;i++)
	{
		if (children[i]->getName() == name)
		{
			delete children[i];
			for (int j = i;j < count-1;j++)
			{
				children[j] = children[j + 1];
			}
			count--;
		}
	}
	cout << "Node not Found!\n";
}

void Folder::list()
{
	for (int i = 0;i < count;i++)
	{
		if (children[i] != nullptr)
		{
			cout << children[i]->getType() << "\t" << children[i]->getName() << endl;
		}
	}
}

void Folder::searchRecursive(string target, string path)
{
	string current = path + "/" + name;
	for (int i = 0;i < count;i++)
	{
		if (children[i]->getName() == target)
		{
			cout << "Path: " << current << "/" << target << endl;
		}
		if (children[i]->getType() == "Folder")
		{
			static_cast<Folder*>(children[i])->searchRecursive(target, current);
		}
	}
}

void Folder::Open()
{
	cout << "Folder " << name<<" opened."<<endl;
}

void Folder::Remove()
{
	cout << "Folder " << name << " removed." << endl;
}

string Folder::getType()
{
	return "Folder";
}

Folder::~Folder()
{
	for (int i = 0;i < count;i++)
	{
		delete children[i];
	}
	delete[] children;
}