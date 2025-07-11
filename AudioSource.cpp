#include "AudioSource.h"
void AudioSource::Play(std::string path)
{
	std::wstring wpath = std::wstring(path.begin(), path.end());
	PlaySound(wpath.c_str(), NULL, SND_ASYNC);
}