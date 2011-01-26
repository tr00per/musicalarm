#ifndef SOUND_H
#define SOUND_H

#include <QtCore>

class Sound {
public:
    Sound(const QString & filename);
    ~Sound();

    void play();
    void stop();
};

#endif // SOUND_H
