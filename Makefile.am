ACLOCAL_AMFLAGS= -I m4
noinst_HEADERS=DodgeBall.h SoundManager.h GUIManager.h Simulator.h NetworkManager.h Player.h Ball.h

bin_PROGRAMS= DodgeBall
DodgeBall_CPPFLAGS= -I$(top_srcdir)
DodgeBall_SOURCES=DodgeBall.cpp SoundManager.cpp GUIManager.cpp Simulator.cpp NetworkManager.cpp Player.cpp Ball.cpp
DodgeBall_CXXFLAGS = $(OGRE_CFLAGS) $(OIS_CFLAGS) $(bullet_CFLAGS) $(SDL_CFLAGS) $(SDL_mixer_CFLAGS) $(SDL_net_CFLAGS)
DodgeBall_LDADD = $(OGRE_LIBS) $(OIS_LIBS) $(bullet_LIBS) $(SDL_LIBS) $(SDL_mixer_LIBS)  $(SDL_net_LIBS)

EXTRA_DIST= buildit makeit
AUTOMAKE_OPTIONS= foreign