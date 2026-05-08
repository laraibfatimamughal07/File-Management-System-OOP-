#include"CommandManager.h"
#include"Folder.h"

commandManager::commandManager(Folder* root)
{
	this->root = root;
	this->current = current;
}

void commandManager::Execute(string command)
{
	//all the commands are directed and managed here
	string cmd = "";
	string arg1 = "";
	string arg2 = "";
	int i = 0;
	while (i < command.length() && command[i] != ' ')
	{
		cmd += command[i];
		i++;
	}
	i++;
	while (i < command.length() && command[i] != ' ')
	{
		arg1 += command[i];
		i++;
	}
	i++;
	while (i < command.length() && command[i] != ' ')
	{
		arg2 += command[i];
		i++;
	}
	if (cmd == "ls")
	{
		ls();
	}
	else if (cmd == "mkdir")
	{
		mkdir(arg1);
	}
	else if (cmd == "touch")
	{
		touch(arg1, arg2);
	}
	else if (cmd == "cd")
	{
		cd(arg1);
	}
	else if (cmd == "rm")
	{
		rm(arg1);
	}
	else if (cmd == "rename")
	{
		renameNode(arg1);
	}
	else
	{
		cout << "Invalid command!\n";
	}
}

void commandManager::ls()
{
	current->list();
}

void commandManager::mkdir(string n)
{
	Folder* newFolder = new Folder(n, current);
	current->addNode(newFolder);
}
void commandManager::rm(string n)
{

}

void commandManager::touch(string t, string n)
{
	/*File* newFile = new TextFile(n, current);
	current->addNode(newFile);*/
}
void commandManager::cd(string n)
{
	//to chanage the current directory
	if (n == "..")
	{
		if (current->getParent() != nullptr)
		{
			current = static_cast<Folder*>(current->getParent());
			cout << "[CURRENT DIRECTORY] " << current->getName() << endl;
		}
		return;
	}
	Node* node = current->findchild(n);
	if (node != nullptr && node->isFolder())
	{
		current = static_cast<Folder*>(node);
	}
	else
	{
		cout << "Folder not Found!\n";
	}
}
void commandManager::renameNode(string newName)
{
	
}
void commandManager::search(string n)
{
	bool found = current->searchNode(n, current->getName());
	if (!found)
	{
		cout << "<" <<n<< "> not found" << endl;
	}
}
