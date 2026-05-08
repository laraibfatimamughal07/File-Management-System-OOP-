#include"CommandManager.h"
#include"Folder.h"

commandManager::commandManager(Folder* root)
{
	this->root = root;
	this->current = root;
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
	if (i < command.length())
	{
		i++;
	}
	while (i < command.length() && command[i] != ' ')
	{
		arg1 += command[i];
		i++;
	}
	if (i < command.length())
	{
		i++;
	}
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
	else if (cmd == "search")
	{
		search(arg1);
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
	if (current->findchild(n) != nullptr)
	{
		cout<<"Node already exists!\n";
		return;
	}
	Folder* newFolder = new Folder(n, current);
	current->addNode(newFolder);
}
void commandManager::rm(string n)
{
	current->removeNode(n);
}

void commandManager::touch(string t, string n)
{
	/*File* newFile = new TextFile(n, current);
	current->addNode(newFile);*/
}
void commandManager::cd(string n)
{
	//to change the current directory
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
		cout << "[CURRENT DIRECTORY] " << current->getName() << endl;
	}
	else
	{
		cout << "Folder not Found!\n";
	}
}
void commandManager::renameNode(string newName)
{
	if (current == root)
	{
		cout << "Root Folder can not be renamed!" << endl;
		return;
	}
	Node* parent = current->getParent();
	if (parent != nullptr)
	{
		Folder* parentFolder = static_cast<Folder*>(parent);
		Node* existing = parentFolder->findchild(newName);
		if (existing != nullptr)
		{
			cout << "Name already exixts!" << endl;
			return;
		}
	}
	current->setName(newName);
	cout << "[RENAMED] " << newName << endl;
}
void commandManager::search(string n)
{
	bool found = current->searchNode(n, current->getName());
	if (!found)
	{
		cout << "<" <<n<< "> not found" << endl;
	}
}
