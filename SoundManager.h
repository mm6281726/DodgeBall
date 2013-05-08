//SoundManager.h

#ifndef _SOUNDMANAGER_H_
    #define _SOUNDMANAGER_H_

#include "SDL/SDL.h"
#include "SDL/SDL_audio.h"
#include "SDL/SDL_mixer.h"
#include <vector>

class SoundManager{
	private:
		std::vector<Mix_Chunk*> SoundList;
	public:
		SoundManager();
		void setup(int x, int y, int z);
		int loadWAV(char* file);
		void playAudio();
		void pauseAudio();
		void playClip(int clipID, int loop);
		void mixAudio(void *unused, Uint8 *stream, Uint32 len);
		void cleanup();
		
		// Sounds
    	int ballBounceWall;
    	int ballPlayerHit;
    	int ballPlayerThrow;
		static SoundManager SoundControl;
};

#endif