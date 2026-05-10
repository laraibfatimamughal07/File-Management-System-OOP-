#include"CommandManager.h"
#include"Folder.h"
#include "TxtFile.h"
#include "AudioFile.h"
#include "PrivateFile.h"
#include "ZipFile.h"

commandManager::commandManager(Folder* root)
{
	this->root = root;
	this->current = root;
}

Folder* commandManager::getCurrent()
{
	return current;
}

void commandManager::Execute(string command)
{
	//all the commands are directed and managed here
	string cmd = "";
	string arg1 = "";
	string arg2 = "";
	size_t i = 0;
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
	else if (cmd == "zip")
	{
		zipNode(arg1);
	}
	else if (cmd == "open") 
	{ 
		openNode(arg1); 
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
	if (current->findchild(n) != nullptr) {
		cout << "Error: Name already exists!" << endl;
		return;
	}

	Node* newFile = nullptr;
	if (t == "txt") {
		newFile = new TxtFile(n, current);
	}
	else if (t == "audio") {
		newFile = new AudioFile(n, current);
	}
	else if (t == "priv") {
		string pass;
		cout << "Set passkey for private file: ";
		cin >> pass;
		cin.ignore(1000, '\n');
		newFile = new PrivateFile(n, current, pass);
	}
	else {
		cout << "Unknown file type: " << t << endl;
		return;
	}

	if (newFile) current->addNode(newFile);
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

void commandManager::openNode(string name) {
	Node* target = current->findchild(name);
	if (target != nullptr) {
		target->Open(); // This triggers polymorphism (Txt vs Audio vs Folder)
	}
	else {
		cout << "Node not found!" << endl;
	}
}

void commandManager::zipNode(string name) {
	Node* target = current->findchild(name);
	if (!target) {
		cout << "Node not found!" << endl;
		return;
	}

	// Create the zip file (assuming ZipFile is built to take extension/name)
	string ext = target->isFolder() ? "/" : ".file";
	ZipFile* z = new ZipFile(name, ext, current);

	// According to many implementations, we might remove the original or just add the zip
	current->addNode(z);
	cout << "[ZIPPED] " << name << " into " << name << "-zip.zip" << endl;
}