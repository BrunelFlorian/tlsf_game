#ifndef MUSICPLAYER_H
#define MUSICPLAYER_H

#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <stdexcept>

class MusicPlayer {
public:
    MusicPlayer();
    ~MusicPlayer();

    void loadMusic(const std::string& filePath);
    void playMusic(int loops = -1);
    void pauseMusic();
    void resumeMusic();
    void stopMusic();
    void setVolume(int volume);
    void fadeInMusic(Uint32 msDuration);

private:
    Mix_Music* music = nullptr;
};

#endif // MUSICPLAYER_H
