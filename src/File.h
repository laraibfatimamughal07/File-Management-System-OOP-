#pragma once
#include "Node.h"
#include<vector>

class File:public Node {
protected:
	vector<string>lines;
	int currentLine;					//To keep a count and check of current line
public:
	File(string name, Node* parent);

	virtual void Open() = 0;
	virtual void Remove() = 0;
	bool isFolder() override;			//Returns False as it is a File now

	virtual ~File();
};