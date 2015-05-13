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

string Spotify::getMetaData()
{
    string commandToSend;
    commandToSend  = "dbus-send --print-reply --session ";
    commandToSend += "--dest=" + this->destination + " " + this->path + " ";
    commandToSend += "org.freedesktop.DBus.Properties.Get string:";
    commandToSend += "'" + this->member + "' string:'Metadata'";
    return getCommandReply(&commandToSend[0]);
}

void Spotify::play()
{
    //this->sendPlayerCommand("Play", true);
    this->getMetaData();
}

void Spotify::pause()
{
    this->sendPlayerCommand("Pause", true);
}

void Spotify::playPause()
{
    this->sendPlayerCommand("PlayPause", true);
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
