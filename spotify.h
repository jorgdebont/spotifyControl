#ifndef SPOTIFY_H
#define SPOTIFY_H
using namespace std;
#include <string>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

class Spotify
{
public:
    Spotify();
    void pause(void);
    void play(void);
    void playPause(void);
    void nextSong(void);
    void previousSong(void);
    void stop(void);
private:
    string destination, path, member;
    string getMetaData(void);
    string getCommandReply(char* command);
    void sendPlayerCommand(string command, bool print_reply);

};

#endif // SPOTIFY_H
