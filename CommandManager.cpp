#include"CommandManager.h"
#include<string>
commandManager::commandManager(Folder* root)
{
	current = root;
}
void commandManager::run()
{
	string in;
	int l = 0;
	while (in[l] != '\0')
		l++;
	for (int i = 0;i < l;i++)
	{
		cout << "\n>";
		getline(cin, in);
		if (in == "exist")
			break;
		Execute(in);
	}
}
void commandManager::Execute(string cmd)
{
	int position = cmd.find(' ');
	string command="";
	string arg="";
	int i = 0;
	while (i < cmd.length() && cmd[i] != ' ')
	{
		command += cmd[i];
		i++;
	}
	i++;
	while (i < cmd.length())
	{
		arg += cmd[i];
		i++;
	}
	if (command == "is")
	{
		current->list(); //CHECK THIS 
	}
	else if (command == "mkdir")
	{
		if (arg == "")
		{
			cout << "Enter Folder Name\n";
			return;
		}
		if (current->find(arg) != nullptr)
		{
			cout << "Name already exists\n";
		}
		Folder* newFolder = new Folder(arg, current);
		current->addNode(newFolder);
	}
	else if (command == "cd")
	{
		if (arg == "..")
		{
			if (current->getParent() != nullptr)
			{
				current = (Folder*)current->getParent();
			}
			return;
		}
		Node* found = current->find(arg);
		if (found == nullptr)
		{
			cout << "Not found\n";
			return;
		}
		Folder* f = (Folder*)found;
		current = f;
	}
	else
	{
		cout << "Invalid Command\n";
	}
}