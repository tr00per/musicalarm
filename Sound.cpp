#include "Sound.h"

#include <iostream>

Sound::Sound(const QString & filename):
    playing(false) {
    mobj = new Phonon::MediaObject();
    mobj->setCurrentSource(Phonon::MediaSource(filename));
    mout = new Phonon::AudioOutput(Phonon::NotificationCategory);
    mpath = Phonon::createPath(mobj, mout);

    connect(mobj, SIGNAL(stateChanged(Phonon::State,Phonon::State)), this, SLOT(looping(Phonon::State,Phonon::State)));
}

Sound::~Sound() {
    mobj->stop();
    mpath.disconnect();
    delete mout;
    delete mobj;
}

void Sound::play() {
    playing = true;
    mobj->play();
}

void Sound::stop() {
    playing = false;
    mobj->stop();
}

void Sound::looping(Phonon::State newstate, Phonon::State oldstate) {
    if (playing && newstate == Phonon::StoppedState && oldstate == Phonon::PlayingState) {
        mobj->seek(0);
        mobj->play();
    }
}
