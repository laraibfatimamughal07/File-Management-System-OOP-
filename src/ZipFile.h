#pragma once
#include"File.h"
class ZipFile : public File {
public:
	ZipFile(string name, Node* parent);

	void Open() override;
	void Remove() override;
};