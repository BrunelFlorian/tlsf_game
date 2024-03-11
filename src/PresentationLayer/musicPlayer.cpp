#include "../../include/PresentationLayer/musicPlayer.h"

MusicPlayer::MusicPlayer() {
    if (SDL_Init(SDL_INIT_AUDIO) < 0) {
        throw std::runtime_error("Erreur lors de l'initialisation de SDL: " + std::string(SDL_GetError()));
    }

    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        throw std::runtime_error("Erreur lors de l'initialisation de SDL_Mixer: " + std::string(Mix_GetError()));
    }
}

MusicPlayer::~MusicPlayer() {
    Mix_CloseAudio();
    SDL_Quit();

    if (music != nullptr) {
        Mix_FreeMusic(music);
    }
}

void MusicPlayer::loadMusic(const std::string& filePath) {
    if (music != nullptr) {
        Mix_FreeMusic(music);
    }

    music = Mix_LoadMUS(filePath.c_str());
    if (!music) {
        throw std::runtime_error("Erreur lors du chargement de la musique: " + std::string(Mix_GetError()));
    }
}

void MusicPlayer::playMusic(int loops) {
    if (!Mix_PlayingMusic()) {
        Mix_PlayMusic(music, loops);
    }
}

void MusicPlayer::pauseMusic() {
    if (Mix_PlayingMusic()) {
        Mix_PauseMusic();
    }
}

void MusicPlayer::resumeMusic() {
    if (Mix_PausedMusic()) {
        Mix_ResumeMusic();
    }
}

void MusicPlayer::stopMusic() {
    if (Mix_PlayingMusic()) {
        Mix_HaltMusic();
    }
}

void MusicPlayer::setVolume(int volume) {
    Mix_VolumeMusic(volume);
}

void MusicPlayer::fadeInMusic(Uint32 msDuration) {
    int currentVolume = 0;
    Uint32 startTime = SDL_GetTicks();

    Mix_PlayMusic(music, -1);
    Mix_VolumeMusic(0);

    SDL_bool done = SDL_FALSE;
    while (!done) {
        Mix_VolumeMusic(currentVolume);
        Uint32 elapsedTime = SDL_GetTicks() - startTime;
        if (elapsedTime >= msDuration) {
            Mix_VolumeMusic(MIX_MAX_VOLUME);
            done = SDL_TRUE;
        } else {
            currentVolume = (elapsedTime * MIX_MAX_VOLUME) / msDuration;
        }
        SDL_Delay(10);
    }
}

