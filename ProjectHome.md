It's purpose is to play selected music file when given time arrives.
Also I'm getting familiar with some more Qt4/Phonon mechanisms.

Features:
  * allows set any valid date in the future
  * force user to type random string of chars to stop playing
  * plays selected file
  * shows timer for hours:mins:secs of sleep left
  * save last selected files
  * configure history size

Future:
  * play random song from selected dir
  * narrow file search to supported types

Code in English, all the rest in Polish (for my convenience).

Compiling/running:
qmake && make && bin/alarm