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
		
	string getName();
	Node* getParent();
	void setName(string n);

	virtual void Open() = 0;
	virtual void Display() = 0;

	virtual~Node();
};