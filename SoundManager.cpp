//SoundManager.cpp
#include "SoundManager.h"

SoundManager SoundManager::SoundControl;

SoundManager::SoundManager(){}

int SoundManager::loadWAV(char* file){
	Mix_Chunk* TempSound = NULL;
 
  if((TempSound = Mix_LoadWAV(file)) == NULL) {
      return -1;
  }
 
  SoundList.push_back(TempSound);
 
  return (SoundList.size() - 1);
}

void SoundManager::setup(int x, int y, int z){
    ballBounceWall = x;
    ballPlayerHit = y;
    ballPlayerThrow = z;
}

void SoundManager::playAudio(){
	Mix_Resume(-1);
}

void SoundManager::pauseAudio(){
	Mix_Pause(-1);
}

void SoundManager::playClip(int clipID, int loop){
	if(clipID < 0 || clipID >= SoundList.size()) return;
    if(SoundList[clipID] == NULL) return;
 
  Mix_PlayChannel(-1, SoundList[clipID], loop);
}

void SoundManager::cleanup() {
	for(int i = 0;i < SoundList.size();i++) {
        Mix_FreeChunk(SoundList[i]);
    }
 
    SoundList.clear();
}