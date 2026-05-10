#pragma once
#include "Folder.h"
class commandManager {
	Folder* current;
	Folder* root;
public:
	commandManager(Folder* root);
	void Execute(string command);
	Folder* getCurrent();

	void ls();
	void mkdir(string name);
	void touch(string type, string name);
	void cd(string name);
	void search(string name);
	void rm(string name);
	void renameNode(string newName);
	void openNode(string name);
	void zipNode(string name);
};