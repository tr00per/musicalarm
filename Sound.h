#ifndef SOUND_H
#define SOUND_H

#include <QtCore>
#include <phonon>

class Sound: public QObject {
    Q_OBJECT
public:
    Sound(const QString & filename);
    virtual ~Sound();

    void stop();

protected:
    bool playing;
    Phonon::Path mpath;
    Phonon::MediaObject * mobj;
    Phonon::AudioOutput * mout;

public slots:
    void play();

protected slots:
    void looping(Phonon::State newstate, Phonon::State oldstate);
};

#endif // SOUND_H
