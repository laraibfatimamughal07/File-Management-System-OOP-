#include "AudioFile.h"
#include <cstdlib>                                              // Needed for system()

AudioFile::AudioFile(string name, Node* parent) : File(name + ".mp3", parent) 
{
    if (this->name.find(".mp3") == string::npos)
    {
        this->name += ".mp3";
    }
    cout << "[RECORDING STARTED - 5 SECONDS]" << endl;

    string mic = "Internal Microphone (Conexant ISST Audio)";
    string cmd = "ffmpeg -y -f dshow -i audio=\"" + mic + "\" -t 5 \"" + getPath() + "\"";

    system(cmd.c_str());
    cout << "[RECORDING ENDED]" << endl;
}

void AudioFile::Open()
{
    cout << "[PLAYING AUDIO FILE] " << name << endl;
    string cmd = "start " + getPath();                       // 'start' works on Windows to play file in default player
    system(cmd.c_str());
}

void AudioFile::Remove() 
{
    string cmd = "del \"" + getPath()+"\"";                   // Physically delete the mp3 from disk
    system(cmd.c_str());
    cout << "[DELETED AUDIO FILE] " << name << endl;
}

AudioFile::~AudioFile()
{

}