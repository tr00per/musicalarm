#ifndef SOUND_H
#define SOUND_H

#include <QtCore>
#include <phonon>

class Sound: QObject {
    Q_OBJECT
public:
    Sound(const QString & filename);
    virtual ~Sound();

    void play();
    void stop();

protected:
    bool playing;
    Phonon::Path mpath;
    Phonon::MediaObject * mobj;
    Phonon::AudioOutput * mout;

protected slots:
    void looping(Phonon::State newstate, Phonon::State oldstate);
};

#endif // SOUND_H
