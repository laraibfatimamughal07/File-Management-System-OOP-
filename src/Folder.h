#pragma once
#include "Node.h"
#include<vector>

class Folder: public Node {
	vector<Node*>children;
public:
	Folder(string name, Node* parent);

	void addNode(Node* node);
	void removeNode(string name);

	//opened
	//created
	//deleted

	Node* findchild(string name) const;
	bool search(string target, string path);

	void list() const;
	void Open() override;
	void Remove() override;
	bool isFolder() override;

	~Folder();
};