#include "CommandManager.h"
#include "Folder.h"
#include "TxtFile.h"
#include "AudioFile.h"
#include "PrivateFile.h"
#include "ZipFile.h"
#include<string>

commandManager::commandManager(Folder* root)
{
	this->root = root;
	this->current = root;
}

Folder* commandManager::getCurrent()				//Return current Folder
{
	return current;
}

void commandManager::Execute(string command)		//All the commands are directed and managed here
{
	//biggest command in this program is 
	//touch <type> <name>

	string cmd = "";	//touch
	string cmd1 = "";	//type
	string cmd2 = "";	//name

	int i = 0;
	while (i < command.length() && command[i] != ' ')
	{
		cmd += command[i];							//Take first part of commmand
		i++;
	}
	if (i < command.length())
	{
		i++;										//skip space
	}
	while (i < command.length() && command[i] != ' ')
	{
		cmd1 += command[i];							//Take second part of Command
		i++;
	}
	if (i < command.length())
	{
		i++;										//skip next space
	}
	while (i < command.length() && command[i] != ' ')
	{
		cmd2 += command[i];							//Take third part of command
		i++;
	}

	if (cmd == "ls")
	{
		ls();										 //ls
	}
	else if (cmd == "mkdir")
	{
		mkdir(cmd1);								//mkdir <name>
	}
	else if (cmd == "touch")
	{
		touch(cmd1, cmd2);							//touch <type> <name>
	}
	else if (cmd == "cd")
	{
		cd(cmd1);									//cd <name>
	}
	else if (cmd == "rm")
	{
		rm(cmd1);									//rm <name>
	}
	else if (cmd == "search")
	{
		search(cmd1);								//search <name>
	}
	else if (cmd == "rename")
	{
		renameNode(cmd1);							//removeNode <name>
	}
	else if (cmd == "zip")
	{
		zipNode(cmd1);								//zip <name.type>
	}
	else if (cmd == "open") 
	{ 
		openNode(cmd1);								//openNode <name>
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
		cout<<"[NODE ALREADY EXISTS!]\n";		//Avoid making same name directory
		return;
	}
	Folder* newFolder = new Folder(n, current);
	current->addNode(newFolder);				//made a new directory
}

void commandManager::rm(string n)
{
	current->removeNode(n);						//removed directory
}

void commandManager::touch(string t, string n)
{
	if (current->findchild(n) != nullptr)
	{
		cout << "[NODE ALREADY EXISTS!]" << endl;
		return;
	}

	Node* newFile = nullptr;
	if (t == "txt")
	{
		newFile = new TxtFile(n, current);
	}
	else if (t == "audio")
	{
		newFile = new AudioFile(n, current);
	}
	else if (t == "priv")
	{
		string pass;
		cout << "[SET PASSKEY]: ";
		cin >> pass;

		cin.ignore(1000, '\n');

		newFile = new PrivateFile(n, current, pass);
	}
	else
	{
		cout << "[UNKNOWN FILE TYPE] " << t << endl;
		return;
	}
	if (newFile)
	{
		current->addNode(newFile);			//New File created
	}
}

void commandManager::cd(string n)			//to change the current directory
{
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
		cout << "[CURRENT FOLDER]: Can not be Renamed!" << endl;
		return;
	}
	Node* parent = current->getParent();

	if (parent != nullptr)
	{
		Folder* parentFolder = static_cast<Folder*>(parent);
		if (parentFolder->findchild(newName))
		{
			cout << "[NAME ALREADY EXISTS]" << endl;
			return;
		}
	}
	current->renameDisk(newName);
	cout << "[RENAMED] " << newName << endl;
}

void commandManager::search(string n)
{
	bool found = current->searchNode(n, current->getName());
	if (!found)
	{
		cout <<n<< " not found" << endl;
	}
}

void commandManager::openNode(string name) 
{
	Node* target = current->findchild(name);
	if (target != nullptr) 
	{
		target->Open();								// This triggers polymorphism (Txt vs Audio vs Folder)
	}
	else {
		cout << "[NODE NOT FOUND]" << endl;
	}
}

void commandManager::zipNode(string name) 
{
	Node* target = current->findchild(name);
	if (!target)
	{
		cout << "[NODE NOT FOUND]" << endl;
		return;
	}

	string ext="";
	if (target->isFolder())
	{
		ext = "/";
	}
	else
	{
		ext = ".file";
	}
	ZipFile* z = new ZipFile(name, ext, current);
	current->addNode(z);

	cout << "[ZIPPED] " << name << " created in " << current->getName() << "-zip.zip" << endl;
}