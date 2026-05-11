#pragma once
#include "Node.h"
#include<vector>

class Folder: public Node {
	vector<Node*>children;

public:
	Folder(string name, Node* parent);

	void addNode(Node* node);
	void removeNode(string name);

	Node* findchild(string name) const;
	bool searchNode(string target, string path);

	void list() const;
	void Open() override;
	void Remove() override;
	bool isFolder() override;

	//opened
	//created
	//deleted

	~Folder();
};