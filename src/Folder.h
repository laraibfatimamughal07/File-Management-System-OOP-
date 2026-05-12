#pragma once
#include "Node.h"
#include<vector>

class Folder: public Node {
	vector<Node*>children;

public:
	Folder(string name, Node* parent);

	void addNode(Node* node);						//To add a node
	void removeNode(string name);					//to remove a node

	Node* findchild(string name) const;				//to find a chile(for path's purpose)
	bool searchNode(string target, string path);	//to search a node(file/ folder in memory)

	void list() const;								//To list all the contents of a Folder
	void Open() override;							//overrided from Node
	void Remove() override;
	bool isFolder() override;

	//opened
	//created
	//deleted

	~Folder();
};