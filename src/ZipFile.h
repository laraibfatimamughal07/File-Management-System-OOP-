#pragma once
#include"File.h"
class ZipFile : public File {
	string originalExtension;
public:
	ZipFile(string name, string ext, Node* parent);

	void Open() override;
	void Remove() override;

	~ZipFile();
};