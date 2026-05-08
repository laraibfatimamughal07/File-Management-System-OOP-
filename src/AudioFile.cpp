//..........
#include"AudioFile.h"
AudioFile::AudioFile(string name, Node* parent) :File(name + ".mp3", parent)
{
	cout << "[RECORDING STARTED]" << endl;
	//
	cout << "[RECORDING ENDED]" << endl;
}
void AudioFile::Open()
{
	cout << "[PLAYING AUDIO FILE] " << name << endl;

}
void AudioFile::Remove()
{
	cout << "[REMOVED AUDIO FILE] " << name << endl;
}
AudioFile::~AudioFile()
{

}