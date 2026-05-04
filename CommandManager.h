#pragma once
#include "Folder.h"
class commandManager {
	Folder* current;
public:
	commandManager(Folder* root);

	void run();
	void Execute(string i);
};