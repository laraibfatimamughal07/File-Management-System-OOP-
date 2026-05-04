#include<iostream>
#include"Folder.h"

using namespace std;

int main()
{
	cout << "Program testing!\n";
	Folder* root = new Folder("root", nullptr);
	Folder* f1 = new Folder("docs", root);
	Folder* f2 = new Folder("images", root);
	root->addNode(f1);
	root->addNode(f2);
	cout << "Contents: ";
	root->list();

	delete root;

	return 0;
}