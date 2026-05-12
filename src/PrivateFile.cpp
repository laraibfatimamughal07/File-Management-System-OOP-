#include "PrivateFile.h"
#include<fstream>

PrivateFile::PrivateFile(string name, Node* parent, string pass) : File(name + ".priv", parent)
{
    this->passKey = pass;
	this->currentLine = 0;
	ofstream out(getPath());
	out.close();
	cout << "[PRIVATE FILE CREATED]" << endl;
}

void PrivateFile::Open()
{
    string attempt;
    cout << "Enter passkey for " << name << ": ";
    cin >> attempt;
    cin.ignore(1000, '\n');

    if (attempt == passKey)
	{
        cout << "[ACCESS GRANTED] Opening secure editor..." << endl;
		lines.clear();
		ifstream in(getPath());
		if (!in)
		{
			cout << "[CAN NOT OPEN FILE]";
			return;
		}
		string line;
		while (getline(in, line))
		{
			lines.push_back(line);
		}
		in.close();
		int choice;
		do {
			if (lines.empty())
			{
				cout << "[EMPTY FILE]\n";
			}
			else
			{
				cout << "Line " << currentLine + 1 << "/" << lines.size() << ":";
				cout << lines.at(currentLine) << endl;
			}
			cout << "Commands: " << endl;
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
					currentLine--;
				else
					cout << "Already at First line.\n";
				break;
			case 2:
				if (!lines.empty() && currentLine < lines.size() - 1)
					currentLine++;
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
					for (int i = 0; i < lines.size(); i++)
					{
						cout << i + 1 << ". " << lines.at(i) << endl;
					}
				}
				cout << "Press Enter to return to menu...";
				cin.get();
				break;
			case 6:
			{
				ofstream out(getPath());
				for (string line : lines)
				{
					out << line << endl;
				}
				out.close();
				cout << "[PRIVATE FILE SAVED]" << endl;
				cout << "[File CLOSED]" << endl;
				cin.clear();
				break;
			}
			default:
				cout << "[INVALID CHOICE]" << endl;
			}
		} while (choice != 6);
    }
    else 
	{
        cout << "[ACCESS DENIED] Incorrect passkey!" << endl;
    }
}

void PrivateFile::Remove()
{
    string attempt;
    cout << "Enter passkey to confirm deletion of private file: ";
    cin >> attempt;
    cin.ignore(1000, '\n');

    if (attempt == passKey)
	{
        cout << "Are you sure you want to delete this private file? (y/n): ";
        char confirm;
        cin >> confirm;
		cin.ignore();

        if (confirm == 'y' || confirm == 'Y') 
		{
			string cmd = "del \"" + getPath() + "\"";
			system(cmd.c_str());

            cout << "[DELETED SECURE FILE] " << name << " destroyed." << endl;
        }
		else if (confirm == 'n' || confirm == 'N')
		{
			cout << "[Okay, FILE WILL NOT BE DELETED]" << endl;
			return;
		}
		else
		{
			cout << "Invalid Input!" << endl;
			return;
		}
    }
    else {
        cout << "Wrong passkey. Deletion aborted." << endl;
    }
}
PrivateFile::~PrivateFile()
{

}