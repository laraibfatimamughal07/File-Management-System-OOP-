#include "ZipFile.h"
#include<fstream>

ZipFile::ZipFile(string name, string ext, Node* parent)
    : File(name + "-zip.zip", parent)
{
    this->originalExtension = ext;
	ofstream out(this->getPath());
    if (out.is_open())
    {
        out << "This is a zipped file:" << endl;
		out.close();
        cout << "[ZIP FILE OPENED] " << getPath() << endl;
    }
}

void ZipFile::Open() 
{
    cout << "Zipped files cannot be opened, unzip first." << endl;
    cout << "Would you like to unzip? (y/n): ";
    char choice; 
    cin >> choice;
    cin.ignore(1000, '\n');

    if (choice == 'y') 
    {
        cout << "[UNZIPPED] New file created: " << name + "-unzipped" + originalExtension << endl;
        // Logic to create a new File node of the original type would go in CommandManager
    }
}

void ZipFile::Remove()
{ 
    string cmd = "del \"" + getPath() + "\"";
    system(cmd.c_str());
    cout << "[ZIP FILE DELETED]" << endl;
}