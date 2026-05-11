#pragma once
#include"File.h"
class TxtFile : public File {
public:
	TxtFile(string name, Node* parent);

	void Open() override;
	void Remove() override;
	~TxtFile();
};