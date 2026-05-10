#include "AudioFile.h"
#include <cstdlib> // Needed for system()

AudioFile::AudioFile(string name, Node* parent) : File(name + ".mp3", parent) {
    cout << "[RECORDING STARTED - 5 SECONDS]" << endl;

    string mic = "Microphone Array (Intel® Smart Sound Technology for Digital Microphones)";
    string cmd = "ffmpeg -y -f dshow -i audio=\"" + mic + "\" -t 5 \"" + name + ".mp3\"";

    system(cmd.c_str());
    cout << "[RECORDING ENDED]" << endl;
}

void AudioFile::Open() {
    cout << "[PLAYING AUDIO FILE] " << name << endl;
    string cmd = "start " + name; // 'start' works on Windows to play file in default player
    system(cmd.c_str());
}

void AudioFile::Remove() {
    string cmd = "del " + name; // Physically delete the mp3 from disk
    system(cmd.c_str());
    cout << "[REMOVED AUDIO FILE] " << name << endl;
}

AudioFile::~AudioFile()
{

}