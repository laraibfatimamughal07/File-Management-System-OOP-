#pragma once
#include "Node.h"

class Folder: public Node {
	Node** children;
	int size;
	int count;
public:
	Folder(string name, Node* parent);

	void addNode(Node* node);
	void removeNode(string name);
	Node* findchild(string name);
	void searchRecursive(string target, string path);

	void list();
	void Open() override;
	string getType() override;
	void Remove() override;

	int getCount();

	~Folder();
};