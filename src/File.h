#pragma once
#include "Node.h"
#include<vector>
class File:public Node {
protected:
	vector<string>lines;
	int currentLine;
public:
	File(string name, Node* parent);

	virtual void Open() = 0;
	virtual void Remove() = 0;
	bool isFolder() override;

	virtual ~File();
};