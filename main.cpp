#include <iostream>
#include <string>
#include "src/File.h"
#include "src/Node.h"
#include "src/Folder.h"
#include "src/CommandManager.h"

using namespace std;

int main()
{	
	system("mkdir root >nul 2>nul");						// Create a physical root directory on disk
	Folder* root = new Folder("root", nullptr);
	
	commandManager cm(root);
	string command;
	while (true)
	{
		cout << "["<< cm.getCurrent()->getName() << "]>";

		getline(cin, command);
		if (command == "exit")
			break;

		cm.Execute(command);
	}
	
	return 0;
}