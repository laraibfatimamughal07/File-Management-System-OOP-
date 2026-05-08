#pragma once
#include "Node.h"
class File:public Node {
protected:
	string content;
public:
	File(string name, Node* parent);

	virtual void Open() = 0;
	virtual void Remove() = 0;

	virtual ~File();
};