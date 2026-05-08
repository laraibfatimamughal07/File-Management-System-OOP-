#pragma once
#include"File.h"
class AudioFile : public File {
public:
	AudioFile(string name, Node* parent);

	void Open() override;
	void Remove() override;
};