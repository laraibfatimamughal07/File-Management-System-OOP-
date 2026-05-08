#pragma once
#include<iostream>
#include<string>
using namespace std;
class Node {
protected:
	string name;
	Node* parent;
public:
	Node(string name, Node* parent);
		
	string getName()const ;
	Node* getParent() const;
	void setName(string n);

	virtual void Open() = 0;
	virtual void Remove() = 0;
	virtual bool isFolder() = 0;

	//created
	//opened
	//deleted

	virtual~Node();
};