#include <iostream>
#include <string>
#include "src/File.h"
#include "src/Node.h"
#include "src/Folder.h"
#include "src/CommandManager.h"


using namespace std;


int main()
{	// create root folder
	system("mkdir root"); // Create a physical root directory on disk
	Folder* root = new Folder("root", nullptr);
	// command manager
	commandManager cm(root);
	string command;
	cout << "Simple File System Started...\n";
	while (true)
	{
		cout << "\n["
			<< cm.getCurrent()->getName()
			<< "]> ";
		cout << "\n> ";
		getline(cin, command);

		if (command == "exit")
			break;

		cm.Execute(command);
	}
	
	return 0;
}