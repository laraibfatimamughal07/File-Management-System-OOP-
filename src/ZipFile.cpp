#include "ZipFile.h"

ZipFile::ZipFile(string name, string ext, Node* parent)
    : File(name + "-zip.zip", parent) {
    this->originalExtension = ext;
}

void ZipFile::Open() {
    cout << "Zipped files cannot be opened, unzip first." << endl;
    cout << "Would you like to unzip? (y/n): ";
    char choice; 
    cin >> choice;
    cin.ignore(1000, '\n');

    if (choice == 'y') {
        cout << "[UNZIPPED] New file created: " << name + "-unzipped" + originalExtension << endl;
        // Logic to create a new File node of the original type would go in CommandManager
    }
}

void ZipFile::Remove() { 
    cout << "[DELETED] Zip file: " << name << endl;
}