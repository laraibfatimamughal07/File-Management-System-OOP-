#pragma once
#include"File.h"
class PrivateFile :public File {
	string passKey;
public:
	PrivateFile(string name, Node* parent, string pass);

	void Open() override;
	void Remove() override;
};