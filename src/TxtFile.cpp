#include"TxtFile.h"
#include<fstream>

TxtFile::TxtFile(string name, Node* parent):File(name+".txt", parent)
{
	currentLine = 0;

	ofstream out(getPath());				//File Handling
	out.close();
	cout << "[CREATED] " << getPath() << endl;
}
void TxtFile::Open()
{
	lines.clear();

	ifstream in(getPath());
	if (!in)
	{
		cout << "[UNABLE TO OPEN FILE]" << endl;
		return;
	}
	string line;

	while (getline(in, line))
	{
		lines.push_back(line);
	}
	in.close();								//Data of File Copied

	cout << "[OPENED] " << name << endl;
	int choice;
	do {
		if (lines.empty())
		{
			cout << "[EMPTY FILE]\n";
		}
		else
		{
			cout << "[LINE] " << currentLine + 1 << "/" << lines.size() << ":";
			cout << lines.at(currentLine) << endl;
		}
		cout << "Commands: \n";
		cout << "1. Move Up\n";
		cout << "2. Move Down\n";
		cout << "3. Add New Line\n";
		cout << "4. Edit Current Line\n";
		cout << "5. View All Content\n";
		cout << "6. Close File\n";
		cout << "Enter Your Choice: ";
		cin >> choice;
		while (!cin) 
		{
			cout << "Please enter an integer!!!" << endl;
			cout << "Please enter a valid  choice (1-6): ";
			cin.clear();
			cin.ignore(numeric_limits<int>::max(), '\n');
			cin >> choice;
		}
		cin.ignore();

		string newLine;
		switch (choice)
		{
		case 1:
			if (currentLine > 0)
				currentLine--;				//1 line up
			else
				cout << "Already at First line.\n";
			break;
		case 2:
			if (!lines.empty() && currentLine < lines.size() - 1)
				currentLine++;				//1 line down
			else
				cout << "Already at last line.\n";
			break;
		case 3:
			cout << "[ENTER NEW LINE] ";
			getline(cin, newLine);
			lines.push_back(newLine);
			currentLine = lines.size() - 1;
			break;
		case 4:
			if (lines.empty())
			{
				cout << "File is Empty.\n";
			}
			else
			{
				cout << "[CURRENT TEXT] " << lines.at(currentLine) << endl;
				cout << "Enter new Text: ";
				getline(cin, newLine);
				lines[currentLine] = newLine;
			}
			break;
		case 5:
			cout << "[FILE CONTENT] ";
			if (lines.empty())
			{
				cout << "[EMPTY FILE]";
			}
			else
			{
				for (int i = 0;i < lines.size();i++)
				{
					cout << i + 1 << ": " << lines.at(i) << endl;
				}
			}
			break;
		case 6:
		{
			ofstream out(getPath());
			for (string line : lines)
			{
				out << line << endl;
			}
			out.close();
			cout << "[FILE SAVED] [FILE CLOSED]" << endl;
			break;
		}
		default:
			cout << "[INVALID CHOICE]" << endl;
		}
	} while (choice != 6);
}
void TxtFile::Remove()
{
	string cmd = "del \"" + getPath() + "\"";
	system(cmd.c_str());
	cout << "[TXT FILE DELETED] " << name << endl;
}
TxtFile::~TxtFile()
{

}