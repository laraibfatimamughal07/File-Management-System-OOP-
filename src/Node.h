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
		
	string getName() const;
	Node* getParent() const;
	void setName(string n);

	virtual void renameDisk(string newName);		//To rename File/Folder on Disk
	virtual string getPath() const;					//To get the path of Node
	virtual void Open() = 0;						//To open a Node
	virtual void Remove() = 0;						//To remove
	virtual bool isFolder() = 0;					//to see if the child Node is Folder or File

	//opened
	//created
	//deleted

	virtual~Node();
};