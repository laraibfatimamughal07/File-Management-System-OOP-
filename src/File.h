#pragma once
#include "Node.h"

class File : public Node{
public:
	File(string name, Node* parent);
	string getType() override;

	virtual~File();
};

class TextFile : public File {
	string* lines;
	int lineCount;
public:
	TextFile(string name, Node* parent);
	~TextFile();
	void Open() override;
};

class AudioFile : public File {
public:
	AudioFile(string name, Node* parent);
	void Open() override;
};

class PrivateFile : public File {
	string key;
public:
	PrivateFile(string name, Node* parent, string k);
	void Open() override;
	string getKey();
};

class ZipFile : public File {
	string ext;
public:
	ZipFile(string name, Node* parent, string e);
	void Open() override;
};