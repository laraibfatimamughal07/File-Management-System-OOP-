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
	Node* find(string name);

	void list();
	void Open() override;
	void Display() override;

	~Folder();
};