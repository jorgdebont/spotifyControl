#include "spotify.h"

Spotify::Spotify(void)
{
    this->destination   = "org.mpris.MediaPlayer2.spotify";
    this->path          = "/org/mpris/MediaPlayer2";
    this->member        = "org.mpris.MediaPlayer2.Player";
}

string Spotify::getCommandReply(char *command)
{
    FILE* pipe = popen(command, "r");
    if (!pipe) return "ERROR";
    char buffer[128];
    std::string result = "";
    while(!feof(pipe))
    {
        if(fgets(buffer, 128, pipe) != NULL)
            result += buffer;
    }
    pclose(pipe);
    return result;
}

void Spotify::play()
{
    this->sendPlayerCommand("Play", false);
}

void Spotify::pause()
{
    this->sendPlayerCommand("Pause", false);
}

void Spotify::playPause()
{
    this->sendPlayerCommand("PlayPause", false);
}

void Spotify::sendPlayerCommand(string command, bool print_reply)
{
    string toSend = "dbus-send ";
    if(print_reply)
        toSend += "--print-reply ";
    toSend += "--dest=" + this->destination + " " + this->path + " " + this->member + ".";
    toSend += command;
    system(toSend.c_str());
}
