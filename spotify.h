#ifndef SPOTIFY_H
#define SPOTIFY_H
using namespace std;
#include <string>

class spotify
{
public:
    void pause(void);
    void play(void);
    void playPause(void);
    void nextSong(void);
    void previousSong(void);
    void stop(void);
private:
    string getMetaData(void);

};

#endif // SPOTIFY_H
