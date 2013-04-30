# Makefile.in generated by automake 1.11.3 from Makefile.am.
# Makefile.  Generated from Makefile.in by configure.

# Copyright (C) 1994, 1995, 1996, 1997, 1998, 1999, 2000, 2001, 2002,
# 2003, 2004, 2005, 2006, 2007, 2008, 2009, 2010, 2011 Free Software
# Foundation, Inc.
# This Makefile.in is free software; the Free Software Foundation
# gives unlimited permission to copy and/or distribute it,
# with or without modifications, as long as this notice is preserved.

# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY, to the extent permitted by law; without
# even the implied warranty of MERCHANTABILITY or FITNESS FOR A
# PARTICULAR PURPOSE.





pkgdatadir = $(datadir)/SampleApp
pkgincludedir = $(includedir)/SampleApp
pkglibdir = $(libdir)/SampleApp
pkglibexecdir = $(libexecdir)/SampleApp
am__cd = CDPATH="$${ZSH_VERSION+.}$(PATH_SEPARATOR)" && cd
install_sh_DATA = $(install_sh) -c -m 644
install_sh_PROGRAM = $(install_sh) -c
install_sh_SCRIPT = $(install_sh) -c
INSTALL_HEADER = $(INSTALL_DATA)
transform = $(program_transform_name)
NORMAL_INSTALL = :
PRE_INSTALL = :
POST_INSTALL = :
NORMAL_UNINSTALL = :
PRE_UNINSTALL = :
POST_UNINSTALL = :
build_triplet = x86_64-unknown-linux-gnu
host_triplet = x86_64-unknown-linux-gnu
bin_PROGRAMS = DodgeBall$(EXEEXT)
subdir = .
DIST_COMMON = README $(am__configure_deps) $(noinst_HEADERS) \
	$(srcdir)/Makefile.am $(srcdir)/Makefile.in \
	$(srcdir)/config.h.in $(top_srcdir)/configure config.guess \
	config.sub depcomp install-sh ltmain.sh missing
ACLOCAL_M4 = $(top_srcdir)/aclocal.m4
am__aclocal_m4_deps = $(top_srcdir)/configure.ac
am__configure_deps = $(am__aclocal_m4_deps) $(CONFIGURE_DEPENDENCIES) \
	$(ACLOCAL_M4)
am__CONFIG_DISTCLEAN_FILES = config.status config.cache config.log \
 configure.lineno config.status.lineno
mkinstalldirs = $(install_sh) -d
CONFIG_HEADER = config.h
CONFIG_CLEAN_FILES =
CONFIG_CLEAN_VPATH_FILES =
am__installdirs = "$(DESTDIR)$(bindir)"
PROGRAMS = $(bin_PROGRAMS)
am_DodgeBall_OBJECTS = DodgeBall-DodgeBall.$(OBJEXT) \
	DodgeBall-SoundManager.$(OBJEXT) \
	DodgeBall-GUIManager.$(OBJEXT) DodgeBall-Simulator.$(OBJEXT) \
	DodgeBall-NetworkManager.$(OBJEXT) DodgeBall-Player.$(OBJEXT) \
	DodgeBall-Ball.$(OBJEXT) DodgeBall-PlayerManager.$(OBJEXT)
DodgeBall_OBJECTS = $(am_DodgeBall_OBJECTS)
am__DEPENDENCIES_1 =
DodgeBall_DEPENDENCIES = $(am__DEPENDENCIES_1) $(am__DEPENDENCIES_1) \
	$(am__DEPENDENCIES_1) $(am__DEPENDENCIES_1) \
	$(am__DEPENDENCIES_1)
DodgeBall_LINK = $(LIBTOOL) --tag=CXX $(AM_LIBTOOLFLAGS) \
	$(LIBTOOLFLAGS) --mode=link $(CXXLD) $(DodgeBall_CXXFLAGS) \
	$(CXXFLAGS) $(AM_LDFLAGS) $(LDFLAGS) -o $@
DEFAULT_INCLUDES = -I.
depcomp = $(SHELL) $(top_srcdir)/depcomp
am__depfiles_maybe = depfiles
am__mv = mv -f
CXXCOMPILE = $(CXX) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) \
	$(AM_CPPFLAGS) $(CPPFLAGS) $(AM_CXXFLAGS) $(CXXFLAGS)
LTCXXCOMPILE = $(LIBTOOL) --tag=CXX $(AM_LIBTOOLFLAGS) $(LIBTOOLFLAGS) \
	--mode=compile $(CXX) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) \
	$(AM_CPPFLAGS) $(CPPFLAGS) $(AM_CXXFLAGS) $(CXXFLAGS)
CXXLD = $(CXX)
CXXLINK = $(LIBTOOL) --tag=CXX $(AM_LIBTOOLFLAGS) $(LIBTOOLFLAGS) \
	--mode=link $(CXXLD) $(AM_CXXFLAGS) $(CXXFLAGS) $(AM_LDFLAGS) \
	$(LDFLAGS) -o $@
SOURCES = $(DodgeBall_SOURCES)
DIST_SOURCES = $(DodgeBall_SOURCES)
HEADERS = $(noinst_HEADERS)
ETAGS = etags
CTAGS = ctags
DISTFILES = $(DIST_COMMON) $(DIST_SOURCES) $(TEXINFOS) $(EXTRA_DIST)
distdir = $(PACKAGE)-$(VERSION)
top_distdir = $(distdir)
am__remove_distdir = \
  if test -d "$(distdir)"; then \
    find "$(distdir)" -type d ! -perm -200 -exec chmod u+w {} ';' \
      && rm -rf "$(distdir)" \
      || { sleep 5 && rm -rf "$(distdir)"; }; \
  else :; fi
DIST_ARCHIVES = $(distdir).tar.gz
GZIP_ENV = --best
distuninstallcheck_listfiles = find . -type f -print
am__distuninstallcheck_listfiles = $(distuninstallcheck_listfiles) \
  | sed 's|^\./|$(prefix)/|' | grep -v '$(infodir)/dir$$'
distcleancheck_listfiles = find . -type f -print
ACLOCAL = ${SHELL} "/u/binary4/Game Tech/dodgeball/DodgeBall/missing" --run aclocal-1.11
AMTAR = $${TAR-tar}
AR = ar
AUTOCONF = ${SHELL} "/u/binary4/Game Tech/dodgeball/DodgeBall/missing" --run autoconf
AUTOHEADER = ${SHELL} "/u/binary4/Game Tech/dodgeball/DodgeBall/missing" --run autoheader
AUTOMAKE = ${SHELL} "/u/binary4/Game Tech/dodgeball/DodgeBall/missing" --run automake-1.11
AWK = gawk
BULLET_CFLAGS = 
BULLET_LIBS = 
CC = gcc
CCDEPMODE = depmode=gcc3
CFLAGS = -g -O2
CPP = gcc -E
CPPFLAGS = 
CXX = g++
CXXCPP = g++ -E
CXXDEPMODE = depmode=gcc3
CXXFLAGS = -g -O2
CYGPATH_W = echo
DEFS = -DHAVE_CONFIG_H
DEPDIR = .deps
DLLTOOL = false
DSYMUTIL = 
DUMPBIN = 
ECHO_C = 
ECHO_N = -n
ECHO_T = 
EGREP = /bin/grep -E
EXEEXT = 
FGREP = /bin/grep -F
GREP = /bin/grep
INSTALL = /usr/bin/install -c
INSTALL_DATA = ${INSTALL} -m 644
INSTALL_PROGRAM = ${INSTALL}
INSTALL_SCRIPT = ${INSTALL}
INSTALL_STRIP_PROGRAM = $(install_sh) -c -s
LD = /usr/bin/ld -m elf_x86_64
LDFLAGS = 
LIBOBJS = 
LIBS = 
LIBTOOL = $(SHELL) $(top_builddir)/libtool
LIPO = 
LN_S = ln -s
LTLIBOBJS = 
MAKEINFO = ${SHELL} "/u/binary4/Game Tech/dodgeball/DodgeBall/missing" --run makeinfo
MANIFEST_TOOL = :
MKDIR_P = /bin/mkdir -p
NM = /usr/bin/nm -B
NMEDIT = 
OBJDUMP = objdump
OBJEXT = o
OGRE_CFLAGS = -pthread -I/usr/include/OGRE  
OGRE_LIBS = -lOgreMain -lpthread  
OIS_CFLAGS = -I/usr/include/OIS  
OIS_LIBS = -lOIS  
OTOOL = 
OTOOL64 = 
PACKAGE = SampleApp
PACKAGE_BUGREPORT = 
PACKAGE_NAME = 
PACKAGE_STRING = 
PACKAGE_TARNAME = 
PACKAGE_URL = 
PACKAGE_VERSION = 
PATH_SEPARATOR = :
PKG_CONFIG = /usr/bin/pkg-config
PKG_CONFIG_LIBDIR = 
PKG_CONFIG_PATH = 
RANLIB = ranlib
SDL_mixer_CFLAGS = -D_GNU_SOURCE=1 -D_REENTRANT -I/usr/include/SDL  
SDL_mixer_LIBS = -lSDL_mixer -lSDL  
SDL_net_CFLAGS = -D_GNU_SOURCE=1 -D_REENTRANT -I/usr/include/SDL  
SDL_net_LIBS = -lSDL_net -lSDL  
SED = /bin/sed
SET_MAKE = 
SHELL = /bin/bash
STRIP = strip
VERSION = 0.1
abs_builddir = /u/binary4/Game Tech/dodgeball/DodgeBall
abs_srcdir = /u/binary4/Game Tech/dodgeball/DodgeBall
abs_top_builddir = /u/binary4/Game Tech/dodgeball/DodgeBall
abs_top_srcdir = /u/binary4/Game Tech/dodgeball/DodgeBall
ac_ct_AR = ar
ac_ct_CC = gcc
ac_ct_CXX = g++
ac_ct_DUMPBIN = 
am__include = include
am__leading_dot = .
am__quote = 
am__tar = $${TAR-tar} chof - "$$tardir"
am__untar = $${TAR-tar} xf -
bindir = ${exec_prefix}/bin
build = x86_64-unknown-linux-gnu
build_alias = 
build_cpu = x86_64
build_os = linux-gnu
build_vendor = unknown
builddir = .
bullet_CFLAGS = -I/usr/local/include/bullet  
bullet_LIBS = -L/usr/local/lib -lBulletSoftBody -lBulletDynamics -lBulletCollision -lLinearMath  
datadir = ${datarootdir}
datarootdir = ${prefix}/share
docdir = ${datarootdir}/doc/${PACKAGE}
dvidir = ${docdir}
exec_prefix = ${prefix}
host = x86_64-unknown-linux-gnu
host_alias = 
host_cpu = x86_64
host_os = linux-gnu
host_vendor = unknown
htmldir = ${docdir}
includedir = ${prefix}/include
infodir = ${datarootdir}/info
install_sh = ${SHELL} '/u/binary4/Game Tech/dodgeball/DodgeBall/install-sh'
libdir = ${exec_prefix}/lib
libexecdir = ${exec_prefix}/libexec
localedir = ${datarootdir}/locale
localstatedir = ${prefix}/var
mandir = ${datarootdir}/man
mkdir_p = /bin/mkdir -p
oldincludedir = /usr/include
pdfdir = ${docdir}
prefix = /usr/local
program_transform_name = s,x,x,
psdir = ${docdir}
sbindir = ${exec_prefix}/sbin
sharedstatedir = ${prefix}/com
srcdir = .
sysconfdir = ${prefix}/etc
target_alias = 
top_build_prefix = 
top_builddir = .
top_srcdir = .
ACLOCAL_AMFLAGS = -I m4
noinst_HEADERS = DodgeBall.h SoundManager.h GUIManager.h Simulator.h NetworkManager.h Player.h Ball.h PlayerManager.h
DodgeBall_CPPFLAGS = -I$(top_srcdir)
DodgeBall_SOURCES = DodgeBall.cpp SoundManager.cpp GUIManager.cpp Simulator.cpp NetworkManager.cpp Player.cpp Ball.cpp PlayerManager.cpp
DodgeBall_CXXFLAGS = $(OGRE_CFLAGS) $(OIS_CFLAGS) $(bullet_CFLAGS) $(SDL_CFLAGS) $(SDL_mixer_CFLAGS) $(SDL_net_CFLAGS)
DodgeBall_LDADD = $(OGRE_LIBS) $(OIS_LIBS) $(bullet_LIBS) $(SDL_LIBS) $(SDL_mixer_LIBS)  $(SDL_net_LIBS)
EXTRA_DIST = buildit makeit
AUTOMAKE_OPTIONS = foreign
all: config.h
	$(MAKE) $(AM_MAKEFLAGS) all-am

.SUFFIXES:
.SUFFIXES: .cpp .lo .o .obj
am--refresh: Makefile
	@:
$(srcdir)/Makefile.in:  $(srcdir)/Makefile.am  $(am__configure_deps)
	@for dep in $?; do \
	  case '$(am__configure_deps)' in \
	    *$$dep*) \
	      echo ' cd $(srcdir) && $(AUTOMAKE) --foreign'; \
	      $(am__cd) $(srcdir) && $(AUTOMAKE) --foreign \
		&& exit 0; \
	      exit 1;; \
	  esac; \
	done; \
	echo ' cd $(top_srcdir) && $(AUTOMAKE) --foreign Makefile'; \
	$(am__cd) $(top_srcdir) && \
	  $(AUTOMAKE) --foreign Makefile
.PRECIOUS: Makefile
Makefile: $(srcdir)/Makefile.in $(top_builddir)/config.status
	@case '$?' in \
	  *config.status*) \
	    echo ' $(SHELL) ./config.status'; \
	    $(SHELL) ./config.status;; \
	  *) \
	    echo ' cd $(top_builddir) && $(SHELL) ./config.status $@ $(am__depfiles_maybe)'; \
	    cd $(top_builddir) && $(SHELL) ./config.status $@ $(am__depfiles_maybe);; \
	esac;

$(top_builddir)/config.status: $(top_srcdir)/configure $(CONFIG_STATUS_DEPENDENCIES)
	$(SHELL) ./config.status --recheck

$(top_srcdir)/configure:  $(am__configure_deps)
	$(am__cd) $(srcdir) && $(AUTOCONF)
$(ACLOCAL_M4):  $(am__aclocal_m4_deps)
	$(am__cd) $(srcdir) && $(ACLOCAL) $(ACLOCAL_AMFLAGS)
$(am__aclocal_m4_deps):

config.h: stamp-h1
	@if test ! -f $@; then rm -f stamp-h1; else :; fi
	@if test ! -f $@; then $(MAKE) $(AM_MAKEFLAGS) stamp-h1; else :; fi

stamp-h1: $(srcdir)/config.h.in $(top_builddir)/config.status
	@rm -f stamp-h1
	cd $(top_builddir) && $(SHELL) ./config.status config.h
$(srcdir)/config.h.in:  $(am__configure_deps) 
	($(am__cd) $(top_srcdir) && $(AUTOHEADER))
	rm -f stamp-h1
	touch $@

distclean-hdr:
	-rm -f config.h stamp-h1
install-binPROGRAMS: $(bin_PROGRAMS)
	@$(NORMAL_INSTALL)
	test -z "$(bindir)" || $(MKDIR_P) "$(DESTDIR)$(bindir)"
	@list='$(bin_PROGRAMS)'; test -n "$(bindir)" || list=; \
	for p in $$list; do echo "$$p $$p"; done | \
	sed 's/$(EXEEXT)$$//' | \
	while read p p1; do if test -f $$p || test -f $$p1; \
	  then echo "$$p"; echo "$$p"; else :; fi; \
	done | \
	sed -e 'p;s,.*/,,;n;h' -e 's|.*|.|' \
	    -e 'p;x;s,.*/,,;s/$(EXEEXT)$$//;$(transform);s/$$/$(EXEEXT)/' | \
	sed 'N;N;N;s,\n, ,g' | \
	$(AWK) 'BEGIN { files["."] = ""; dirs["."] = 1 } \
	  { d=$$3; if (dirs[d] != 1) { print "d", d; dirs[d] = 1 } \
	    if ($$2 == $$4) files[d] = files[d] " " $$1; \
	    else { print "f", $$3 "/" $$4, $$1; } } \
	  END { for (d in files) print "f", d, files[d] }' | \
	while read type dir files; do \
	    if test "$$dir" = .; then dir=; else dir=/$$dir; fi; \
	    test -z "$$files" || { \
	    echo " $(INSTALL_PROGRAM_ENV) $(LIBTOOL) $(AM_LIBTOOLFLAGS) $(LIBTOOLFLAGS) --mode=install $(INSTALL_PROGRAM) $$files '$(DESTDIR)$(bindir)$$dir'"; \
	    $(INSTALL_PROGRAM_ENV) $(LIBTOOL) $(AM_LIBTOOLFLAGS) $(LIBTOOLFLAGS) --mode=install $(INSTALL_PROGRAM) $$files "$(DESTDIR)$(bindir)$$dir" || exit $$?; \
	    } \
	; done

uninstall-binPROGRAMS:
	@$(NORMAL_UNINSTALL)
	@list='$(bin_PROGRAMS)'; test -n "$(bindir)" || list=; \
	files=`for p in $$list; do echo "$$p"; done | \
	  sed -e 'h;s,^.*/,,;s/$(EXEEXT)$$//;$(transform)' \
	      -e 's/$$/$(EXEEXT)/' `; \
	test -n "$$list" || exit 0; \
	echo " ( cd '$(DESTDIR)$(bindir)' && rm -f" $$files ")"; \
	cd "$(DESTDIR)$(bindir)" && rm -f $$files

clean-binPROGRAMS:
	@list='$(bin_PROGRAMS)'; test -n "$$list" || exit 0; \
	echo " rm -f" $$list; \
	rm -f $$list || exit $$?; \
	test -n "$(EXEEXT)" || exit 0; \
	list=`for p in $$list; do echo "$$p"; done | sed 's/$(EXEEXT)$$//'`; \
	echo " rm -f" $$list; \
	rm -f $$list
DodgeBall$(EXEEXT): $(DodgeBall_OBJECTS) $(DodgeBall_DEPENDENCIES) $(EXTRA_DodgeBall_DEPENDENCIES) 
	@rm -f DodgeBall$(EXEEXT)
	$(DodgeBall_LINK) $(DodgeBall_OBJECTS) $(DodgeBall_LDADD) $(LIBS)

mostlyclean-compile:
	-rm -f *.$(OBJEXT)

distclean-compile:
	-rm -f *.tab.c

include ./$(DEPDIR)/DodgeBall-Ball.Po
include ./$(DEPDIR)/DodgeBall-DodgeBall.Po
include ./$(DEPDIR)/DodgeBall-GUIManager.Po
include ./$(DEPDIR)/DodgeBall-NetworkManager.Po
include ./$(DEPDIR)/DodgeBall-Player.Po
include ./$(DEPDIR)/DodgeBall-PlayerManager.Po
include ./$(DEPDIR)/DodgeBall-Simulator.Po
include ./$(DEPDIR)/DodgeBall-SoundManager.Po

.cpp.o:
	$(CXXCOMPILE) -MT $@ -MD -MP -MF $(DEPDIR)/$*.Tpo -c -o $@ $<
	$(am__mv) $(DEPDIR)/$*.Tpo $(DEPDIR)/$*.Po
#	source='$<' object='$@' libtool=no \
#	DEPDIR=$(DEPDIR) $(CXXDEPMODE) $(depcomp) \
#	$(CXXCOMPILE) -c -o $@ $<

.cpp.obj:
	$(CXXCOMPILE) -MT $@ -MD -MP -MF $(DEPDIR)/$*.Tpo -c -o $@ `$(CYGPATH_W) '$<'`
	$(am__mv) $(DEPDIR)/$*.Tpo $(DEPDIR)/$*.Po
#	source='$<' object='$@' libtool=no \
#	DEPDIR=$(DEPDIR) $(CXXDEPMODE) $(depcomp) \
#	$(CXXCOMPILE) -c -o $@ `$(CYGPATH_W) '$<'`

.cpp.lo:
	$(LTCXXCOMPILE) -MT $@ -MD -MP -MF $(DEPDIR)/$*.Tpo -c -o $@ $<
	$(am__mv) $(DEPDIR)/$*.Tpo $(DEPDIR)/$*.Plo
#	source='$<' object='$@' libtool=yes \
#	DEPDIR=$(DEPDIR) $(CXXDEPMODE) $(depcomp) \
#	$(LTCXXCOMPILE) -c -o $@ $<

DodgeBall-DodgeBall.o: DodgeBall.cpp
	$(CXX) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(DodgeBall_CPPFLAGS) $(CPPFLAGS) $(DodgeBall_CXXFLAGS) $(CXXFLAGS) -MT DodgeBall-DodgeBall.o -MD -MP -MF $(DEPDIR)/DodgeBall-DodgeBall.Tpo -c -o DodgeBall-DodgeBall.o `test -f 'DodgeBall.cpp' || echo '$(srcdir)/'`DodgeBall.cpp
	$(am__mv) $(DEPDIR)/DodgeBall-DodgeBall.Tpo $(DEPDIR)/DodgeBall-DodgeBall.Po
#	source='DodgeBall.cpp' object='DodgeBall-DodgeBall.o' libtool=no \
#	DEPDIR=$(DEPDIR) $(CXXDEPMODE) $(depcomp) \
#	$(CXX) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(DodgeBall_CPPFLAGS) $(CPPFLAGS) $(DodgeBall_CXXFLAGS) $(CXXFLAGS) -c -o DodgeBall-DodgeBall.o `test -f 'DodgeBall.cpp' || echo '$(srcdir)/'`DodgeBall.cpp

DodgeBall-DodgeBall.obj: DodgeBall.cpp
	$(CXX) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(DodgeBall_CPPFLAGS) $(CPPFLAGS) $(DodgeBall_CXXFLAGS) $(CXXFLAGS) -MT DodgeBall-DodgeBall.obj -MD -MP -MF $(DEPDIR)/DodgeBall-DodgeBall.Tpo -c -o DodgeBall-DodgeBall.obj `if test -f 'DodgeBall.cpp'; then $(CYGPATH_W) 'DodgeBall.cpp'; else $(CYGPATH_W) '$(srcdir)/DodgeBall.cpp'; fi`
	$(am__mv) $(DEPDIR)/DodgeBall-DodgeBall.Tpo $(DEPDIR)/DodgeBall-DodgeBall.Po
#	source='DodgeBall.cpp' object='DodgeBall-DodgeBall.obj' libtool=no \
#	DEPDIR=$(DEPDIR) $(CXXDEPMODE) $(depcomp) \
#	$(CXX) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(DodgeBall_CPPFLAGS) $(CPPFLAGS) $(DodgeBall_CXXFLAGS) $(CXXFLAGS) -c -o DodgeBall-DodgeBall.obj `if test -f 'DodgeBall.cpp'; then $(CYGPATH_W) 'DodgeBall.cpp'; else $(CYGPATH_W) '$(srcdir)/DodgeBall.cpp'; fi`

DodgeBall-SoundManager.o: SoundManager.cpp
	$(CXX) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(DodgeBall_CPPFLAGS) $(CPPFLAGS) $(DodgeBall_CXXFLAGS) $(CXXFLAGS) -MT DodgeBall-SoundManager.o -MD -MP -MF $(DEPDIR)/DodgeBall-SoundManager.Tpo -c -o DodgeBall-SoundManager.o `test -f 'SoundManager.cpp' || echo '$(srcdir)/'`SoundManager.cpp
	$(am__mv) $(DEPDIR)/DodgeBall-SoundManager.Tpo $(DEPDIR)/DodgeBall-SoundManager.Po
#	source='SoundManager.cpp' object='DodgeBall-SoundManager.o' libtool=no \
#	DEPDIR=$(DEPDIR) $(CXXDEPMODE) $(depcomp) \
#	$(CXX) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(DodgeBall_CPPFLAGS) $(CPPFLAGS) $(DodgeBall_CXXFLAGS) $(CXXFLAGS) -c -o DodgeBall-SoundManager.o `test -f 'SoundManager.cpp' || echo '$(srcdir)/'`SoundManager.cpp

DodgeBall-SoundManager.obj: SoundManager.cpp
	$(CXX) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(DodgeBall_CPPFLAGS) $(CPPFLAGS) $(DodgeBall_CXXFLAGS) $(CXXFLAGS) -MT DodgeBall-SoundManager.obj -MD -MP -MF $(DEPDIR)/DodgeBall-SoundManager.Tpo -c -o DodgeBall-SoundManager.obj `if test -f 'SoundManager.cpp'; then $(CYGPATH_W) 'SoundManager.cpp'; else $(CYGPATH_W) '$(srcdir)/SoundManager.cpp'; fi`
	$(am__mv) $(DEPDIR)/DodgeBall-SoundManager.Tpo $(DEPDIR)/DodgeBall-SoundManager.Po
#	source='SoundManager.cpp' object='DodgeBall-SoundManager.obj' libtool=no \
#	DEPDIR=$(DEPDIR) $(CXXDEPMODE) $(depcomp) \
#	$(CXX) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(DodgeBall_CPPFLAGS) $(CPPFLAGS) $(DodgeBall_CXXFLAGS) $(CXXFLAGS) -c -o DodgeBall-SoundManager.obj `if test -f 'SoundManager.cpp'; then $(CYGPATH_W) 'SoundManager.cpp'; else $(CYGPATH_W) '$(srcdir)/SoundManager.cpp'; fi`

DodgeBall-GUIManager.o: GUIManager.cpp
	$(CXX) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(DodgeBall_CPPFLAGS) $(CPPFLAGS) $(DodgeBall_CXXFLAGS) $(CXXFLAGS) -MT DodgeBall-GUIManager.o -MD -MP -MF $(DEPDIR)/DodgeBall-GUIManager.Tpo -c -o DodgeBall-GUIManager.o `test -f 'GUIManager.cpp' || echo '$(srcdir)/'`GUIManager.cpp
	$(am__mv) $(DEPDIR)/DodgeBall-GUIManager.Tpo $(DEPDIR)/DodgeBall-GUIManager.Po
#	source='GUIManager.cpp' object='DodgeBall-GUIManager.o' libtool=no \
#	DEPDIR=$(DEPDIR) $(CXXDEPMODE) $(depcomp) \
#	$(CXX) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(DodgeBall_CPPFLAGS) $(CPPFLAGS) $(DodgeBall_CXXFLAGS) $(CXXFLAGS) -c -o DodgeBall-GUIManager.o `test -f 'GUIManager.cpp' || echo '$(srcdir)/'`GUIManager.cpp

DodgeBall-GUIManager.obj: GUIManager.cpp
	$(CXX) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(DodgeBall_CPPFLAGS) $(CPPFLAGS) $(DodgeBall_CXXFLAGS) $(CXXFLAGS) -MT DodgeBall-GUIManager.obj -MD -MP -MF $(DEPDIR)/DodgeBall-GUIManager.Tpo -c -o DodgeBall-GUIManager.obj `if test -f 'GUIManager.cpp'; then $(CYGPATH_W) 'GUIManager.cpp'; else $(CYGPATH_W) '$(srcdir)/GUIManager.cpp'; fi`
	$(am__mv) $(DEPDIR)/DodgeBall-GUIManager.Tpo $(DEPDIR)/DodgeBall-GUIManager.Po
#	source='GUIManager.cpp' object='DodgeBall-GUIManager.obj' libtool=no \
#	DEPDIR=$(DEPDIR) $(CXXDEPMODE) $(depcomp) \
#	$(CXX) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(DodgeBall_CPPFLAGS) $(CPPFLAGS) $(DodgeBall_CXXFLAGS) $(CXXFLAGS) -c -o DodgeBall-GUIManager.obj `if test -f 'GUIManager.cpp'; then $(CYGPATH_W) 'GUIManager.cpp'; else $(CYGPATH_W) '$(srcdir)/GUIManager.cpp'; fi`

DodgeBall-Simulator.o: Simulator.cpp
	$(CXX) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(DodgeBall_CPPFLAGS) $(CPPFLAGS) $(DodgeBall_CXXFLAGS) $(CXXFLAGS) -MT DodgeBall-Simulator.o -MD -MP -MF $(DEPDIR)/DodgeBall-Simulator.Tpo -c -o DodgeBall-Simulator.o `test -f 'Simulator.cpp' || echo '$(srcdir)/'`Simulator.cpp
	$(am__mv) $(DEPDIR)/DodgeBall-Simulator.Tpo $(DEPDIR)/DodgeBall-Simulator.Po
#	source='Simulator.cpp' object='DodgeBall-Simulator.o' libtool=no \
#	DEPDIR=$(DEPDIR) $(CXXDEPMODE) $(depcomp) \
#	$(CXX) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(DodgeBall_CPPFLAGS) $(CPPFLAGS) $(DodgeBall_CXXFLAGS) $(CXXFLAGS) -c -o DodgeBall-Simulator.o `test -f 'Simulator.cpp' || echo '$(srcdir)/'`Simulator.cpp

DodgeBall-Simulator.obj: Simulator.cpp
	$(CXX) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(DodgeBall_CPPFLAGS) $(CPPFLAGS) $(DodgeBall_CXXFLAGS) $(CXXFLAGS) -MT DodgeBall-Simulator.obj -MD -MP -MF $(DEPDIR)/DodgeBall-Simulator.Tpo -c -o DodgeBall-Simulator.obj `if test -f 'Simulator.cpp'; then $(CYGPATH_W) 'Simulator.cpp'; else $(CYGPATH_W) '$(srcdir)/Simulator.cpp'; fi`
	$(am__mv) $(DEPDIR)/DodgeBall-Simulator.Tpo $(DEPDIR)/DodgeBall-Simulator.Po
#	source='Simulator.cpp' object='DodgeBall-Simulator.obj' libtool=no \
#	DEPDIR=$(DEPDIR) $(CXXDEPMODE) $(depcomp) \
#	$(CXX) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(DodgeBall_CPPFLAGS) $(CPPFLAGS) $(DodgeBall_CXXFLAGS) $(CXXFLAGS) -c -o DodgeBall-Simulator.obj `if test -f 'Simulator.cpp'; then $(CYGPATH_W) 'Simulator.cpp'; else $(CYGPATH_W) '$(srcdir)/Simulator.cpp'; fi`

DodgeBall-NetworkManager.o: NetworkManager.cpp
	$(CXX) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(DodgeBall_CPPFLAGS) $(CPPFLAGS) $(DodgeBall_CXXFLAGS) $(CXXFLAGS) -MT DodgeBall-NetworkManager.o -MD -MP -MF $(DEPDIR)/DodgeBall-NetworkManager.Tpo -c -o DodgeBall-NetworkManager.o `test -f 'NetworkManager.cpp' || echo '$(srcdir)/'`NetworkManager.cpp
	$(am__mv) $(DEPDIR)/DodgeBall-NetworkManager.Tpo $(DEPDIR)/DodgeBall-NetworkManager.Po
#	source='NetworkManager.cpp' object='DodgeBall-NetworkManager.o' libtool=no \
#	DEPDIR=$(DEPDIR) $(CXXDEPMODE) $(depcomp) \
#	$(CXX) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(DodgeBall_CPPFLAGS) $(CPPFLAGS) $(DodgeBall_CXXFLAGS) $(CXXFLAGS) -c -o DodgeBall-NetworkManager.o `test -f 'NetworkManager.cpp' || echo '$(srcdir)/'`NetworkManager.cpp

DodgeBall-NetworkManager.obj: NetworkManager.cpp
	$(CXX) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(DodgeBall_CPPFLAGS) $(CPPFLAGS) $(DodgeBall_CXXFLAGS) $(CXXFLAGS) -MT DodgeBall-NetworkManager.obj -MD -MP -MF $(DEPDIR)/DodgeBall-NetworkManager.Tpo -c -o DodgeBall-NetworkManager.obj `if test -f 'NetworkManager.cpp'; then $(CYGPATH_W) 'NetworkManager.cpp'; else $(CYGPATH_W) '$(srcdir)/NetworkManager.cpp'; fi`
	$(am__mv) $(DEPDIR)/DodgeBall-NetworkManager.Tpo $(DEPDIR)/DodgeBall-NetworkManager.Po
#	source='NetworkManager.cpp' object='DodgeBall-NetworkManager.obj' libtool=no \
#	DEPDIR=$(DEPDIR) $(CXXDEPMODE) $(depcomp) \
#	$(CXX) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(DodgeBall_CPPFLAGS) $(CPPFLAGS) $(DodgeBall_CXXFLAGS) $(CXXFLAGS) -c -o DodgeBall-NetworkManager.obj `if test -f 'NetworkManager.cpp'; then $(CYGPATH_W) 'NetworkManager.cpp'; else $(CYGPATH_W) '$(srcdir)/NetworkManager.cpp'; fi`

DodgeBall-Player.o: Player.cpp
	$(CXX) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(DodgeBall_CPPFLAGS) $(CPPFLAGS) $(DodgeBall_CXXFLAGS) $(CXXFLAGS) -MT DodgeBall-Player.o -MD -MP -MF $(DEPDIR)/DodgeBall-Player.Tpo -c -o DodgeBall-Player.o `test -f 'Player.cpp' || echo '$(srcdir)/'`Player.cpp
	$(am__mv) $(DEPDIR)/DodgeBall-Player.Tpo $(DEPDIR)/DodgeBall-Player.Po
#	source='Player.cpp' object='DodgeBall-Player.o' libtool=no \
#	DEPDIR=$(DEPDIR) $(CXXDEPMODE) $(depcomp) \
#	$(CXX) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(DodgeBall_CPPFLAGS) $(CPPFLAGS) $(DodgeBall_CXXFLAGS) $(CXXFLAGS) -c -o DodgeBall-Player.o `test -f 'Player.cpp' || echo '$(srcdir)/'`Player.cpp

DodgeBall-Player.obj: Player.cpp
	$(CXX) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(DodgeBall_CPPFLAGS) $(CPPFLAGS) $(DodgeBall_CXXFLAGS) $(CXXFLAGS) -MT DodgeBall-Player.obj -MD -MP -MF $(DEPDIR)/DodgeBall-Player.Tpo -c -o DodgeBall-Player.obj `if test -f 'Player.cpp'; then $(CYGPATH_W) 'Player.cpp'; else $(CYGPATH_W) '$(srcdir)/Player.cpp'; fi`
	$(am__mv) $(DEPDIR)/DodgeBall-Player.Tpo $(DEPDIR)/DodgeBall-Player.Po
#	source='Player.cpp' object='DodgeBall-Player.obj' libtool=no \
#	DEPDIR=$(DEPDIR) $(CXXDEPMODE) $(depcomp) \
#	$(CXX) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(DodgeBall_CPPFLAGS) $(CPPFLAGS) $(DodgeBall_CXXFLAGS) $(CXXFLAGS) -c -o DodgeBall-Player.obj `if test -f 'Player.cpp'; then $(CYGPATH_W) 'Player.cpp'; else $(CYGPATH_W) '$(srcdir)/Player.cpp'; fi`

DodgeBall-Ball.o: Ball.cpp
	$(CXX) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(DodgeBall_CPPFLAGS) $(CPPFLAGS) $(DodgeBall_CXXFLAGS) $(CXXFLAGS) -MT DodgeBall-Ball.o -MD -MP -MF $(DEPDIR)/DodgeBall-Ball.Tpo -c -o DodgeBall-Ball.o `test -f 'Ball.cpp' || echo '$(srcdir)/'`Ball.cpp
	$(am__mv) $(DEPDIR)/DodgeBall-Ball.Tpo $(DEPDIR)/DodgeBall-Ball.Po
#	source='Ball.cpp' object='DodgeBall-Ball.o' libtool=no \
#	DEPDIR=$(DEPDIR) $(CXXDEPMODE) $(depcomp) \
#	$(CXX) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(DodgeBall_CPPFLAGS) $(CPPFLAGS) $(DodgeBall_CXXFLAGS) $(CXXFLAGS) -c -o DodgeBall-Ball.o `test -f 'Ball.cpp' || echo '$(srcdir)/'`Ball.cpp

DodgeBall-Ball.obj: Ball.cpp
	$(CXX) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(DodgeBall_CPPFLAGS) $(CPPFLAGS) $(DodgeBall_CXXFLAGS) $(CXXFLAGS) -MT DodgeBall-Ball.obj -MD -MP -MF $(DEPDIR)/DodgeBall-Ball.Tpo -c -o DodgeBall-Ball.obj `if test -f 'Ball.cpp'; then $(CYGPATH_W) 'Ball.cpp'; else $(CYGPATH_W) '$(srcdir)/Ball.cpp'; fi`
	$(am__mv) $(DEPDIR)/DodgeBall-Ball.Tpo $(DEPDIR)/DodgeBall-Ball.Po
#	source='Ball.cpp' object='DodgeBall-Ball.obj' libtool=no \
#	DEPDIR=$(DEPDIR) $(CXXDEPMODE) $(depcomp) \
#	$(CXX) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(DodgeBall_CPPFLAGS) $(CPPFLAGS) $(DodgeBall_CXXFLAGS) $(CXXFLAGS) -c -o DodgeBall-Ball.obj `if test -f 'Ball.cpp'; then $(CYGPATH_W) 'Ball.cpp'; else $(CYGPATH_W) '$(srcdir)/Ball.cpp'; fi`

DodgeBall-PlayerManager.o: PlayerManager.cpp
	$(CXX) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(DodgeBall_CPPFLAGS) $(CPPFLAGS) $(DodgeBall_CXXFLAGS) $(CXXFLAGS) -MT DodgeBall-PlayerManager.o -MD -MP -MF $(DEPDIR)/DodgeBall-PlayerManager.Tpo -c -o DodgeBall-PlayerManager.o `test -f 'PlayerManager.cpp' || echo '$(srcdir)/'`PlayerManager.cpp
	$(am__mv) $(DEPDIR)/DodgeBall-PlayerManager.Tpo $(DEPDIR)/DodgeBall-PlayerManager.Po
#	source='PlayerManager.cpp' object='DodgeBall-PlayerManager.o' libtool=no \
#	DEPDIR=$(DEPDIR) $(CXXDEPMODE) $(depcomp) \
#	$(CXX) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(DodgeBall_CPPFLAGS) $(CPPFLAGS) $(DodgeBall_CXXFLAGS) $(CXXFLAGS) -c -o DodgeBall-PlayerManager.o `test -f 'PlayerManager.cpp' || echo '$(srcdir)/'`PlayerManager.cpp

DodgeBall-PlayerManager.obj: PlayerManager.cpp
	$(CXX) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(DodgeBall_CPPFLAGS) $(CPPFLAGS) $(DodgeBall_CXXFLAGS) $(CXXFLAGS) -MT DodgeBall-PlayerManager.obj -MD -MP -MF $(DEPDIR)/DodgeBall-PlayerManager.Tpo -c -o DodgeBall-PlayerManager.obj `if test -f 'PlayerManager.cpp'; then $(CYGPATH_W) 'PlayerManager.cpp'; else $(CYGPATH_W) '$(srcdir)/PlayerManager.cpp'; fi`
	$(am__mv) $(DEPDIR)/DodgeBall-PlayerManager.Tpo $(DEPDIR)/DodgeBall-PlayerManager.Po
#	source='PlayerManager.cpp' object='DodgeBall-PlayerManager.obj' libtool=no \
#	DEPDIR=$(DEPDIR) $(CXXDEPMODE) $(depcomp) \
#	$(CXX) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(DodgeBall_CPPFLAGS) $(CPPFLAGS) $(DodgeBall_CXXFLAGS) $(CXXFLAGS) -c -o DodgeBall-PlayerManager.obj `if test -f 'PlayerManager.cpp'; then $(CYGPATH_W) 'PlayerManager.cpp'; else $(CYGPATH_W) '$(srcdir)/PlayerManager.cpp'; fi`

mostlyclean-libtool:
	-rm -f *.lo

clean-libtool:
	-rm -rf .libs _libs

distclean-libtool:
	-rm -f libtool config.lt

ID: $(HEADERS) $(SOURCES) $(LISP) $(TAGS_FILES)
	list='$(SOURCES) $(HEADERS) $(LISP) $(TAGS_FILES)'; \
	unique=`for i in $$list; do \
	    if test -f "$$i"; then echo $$i; else echo $(srcdir)/$$i; fi; \
	  done | \
	  $(AWK) '{ files[$$0] = 1; nonempty = 1; } \
	      END { if (nonempty) { for (i in files) print i; }; }'`; \
	mkid -fID $$unique
tags: TAGS

TAGS:  $(HEADERS) $(SOURCES) config.h.in $(TAGS_DEPENDENCIES) \
		$(TAGS_FILES) $(LISP)
	set x; \
	here=`pwd`; \
	list='$(SOURCES) $(HEADERS) config.h.in $(LISP) $(TAGS_FILES)'; \
	unique=`for i in $$list; do \
	    if test -f "$$i"; then echo $$i; else echo $(srcdir)/$$i; fi; \
	  done | \
	  $(AWK) '{ files[$$0] = 1; nonempty = 1; } \
	      END { if (nonempty) { for (i in files) print i; }; }'`; \
	shift; \
	if test -z "$(ETAGS_ARGS)$$*$$unique"; then :; else \
	  test -n "$$unique" || unique=$$empty_fix; \
	  if test $$# -gt 0; then \
	    $(ETAGS) $(ETAGSFLAGS) $(AM_ETAGSFLAGS) $(ETAGS_ARGS) \
	      "$$@" $$unique; \
	  else \
	    $(ETAGS) $(ETAGSFLAGS) $(AM_ETAGSFLAGS) $(ETAGS_ARGS) \
	      $$unique; \
	  fi; \
	fi
ctags: CTAGS
CTAGS:  $(HEADERS) $(SOURCES) config.h.in $(TAGS_DEPENDENCIES) \
		$(TAGS_FILES) $(LISP)
	list='$(SOURCES) $(HEADERS) config.h.in $(LISP) $(TAGS_FILES)'; \
	unique=`for i in $$list; do \
	    if test -f "$$i"; then echo $$i; else echo $(srcdir)/$$i; fi; \
	  done | \
	  $(AWK) '{ files[$$0] = 1; nonempty = 1; } \
	      END { if (nonempty) { for (i in files) print i; }; }'`; \
	test -z "$(CTAGS_ARGS)$$unique" \
	  || $(CTAGS) $(CTAGSFLAGS) $(AM_CTAGSFLAGS) $(CTAGS_ARGS) \
	     $$unique

GTAGS:
	here=`$(am__cd) $(top_builddir) && pwd` \
	  && $(am__cd) $(top_srcdir) \
	  && gtags -i $(GTAGS_ARGS) "$$here"

distclean-tags:
	-rm -f TAGS ID GTAGS GRTAGS GSYMS GPATH tags

distdir: $(DISTFILES)
	$(am__remove_distdir)
	test -d "$(distdir)" || mkdir "$(distdir)"
	@srcdirstrip=`echo "$(srcdir)" | sed 's/[].[^$$\\*]/\\\\&/g'`; \
	topsrcdirstrip=`echo "$(top_srcdir)" | sed 's/[].[^$$\\*]/\\\\&/g'`; \
	list='$(DISTFILES)'; \
	  dist_files=`for file in $$list; do echo $$file; done | \
	  sed -e "s|^$$srcdirstrip/||;t" \
	      -e "s|^$$topsrcdirstrip/|$(top_builddir)/|;t"`; \
	case $$dist_files in \
	  */*) $(MKDIR_P) `echo "$$dist_files" | \
			   sed '/\//!d;s|^|$(distdir)/|;s,/[^/]*$$,,' | \
			   sort -u` ;; \
	esac; \
	for file in $$dist_files; do \
	  if test -f $$file || test -d $$file; then d=.; else d=$(srcdir); fi; \
	  if test -d $$d/$$file; then \
	    dir=`echo "/$$file" | sed -e 's,/[^/]*$$,,'`; \
	    if test -d "$(distdir)/$$file"; then \
	      find "$(distdir)/$$file" -type d ! -perm -700 -exec chmod u+rwx {} \;; \
	    fi; \
	    if test -d $(srcdir)/$$file && test $$d != $(srcdir); then \
	      cp -fpR $(srcdir)/$$file "$(distdir)$$dir" || exit 1; \
	      find "$(distdir)/$$file" -type d ! -perm -700 -exec chmod u+rwx {} \;; \
	    fi; \
	    cp -fpR $$d/$$file "$(distdir)$$dir" || exit 1; \
	  else \
	    test -f "$(distdir)/$$file" \
	    || cp -p $$d/$$file "$(distdir)/$$file" \
	    || exit 1; \
	  fi; \
	done
	-test -n "$(am__skip_mode_fix)" \
	|| find "$(distdir)" -type d ! -perm -755 \
		-exec chmod u+rwx,go+rx {} \; -o \
	  ! -type d ! -perm -444 -links 1 -exec chmod a+r {} \; -o \
	  ! -type d ! -perm -400 -exec chmod a+r {} \; -o \
	  ! -type d ! -perm -444 -exec $(install_sh) -c -m a+r {} {} \; \
	|| chmod -R a+r "$(distdir)"
dist-gzip: distdir
	tardir=$(distdir) && $(am__tar) | GZIP=$(GZIP_ENV) gzip -c >$(distdir).tar.gz
	$(am__remove_distdir)

dist-bzip2: distdir
	tardir=$(distdir) && $(am__tar) | BZIP2=$${BZIP2--9} bzip2 -c >$(distdir).tar.bz2
	$(am__remove_distdir)

dist-lzip: distdir
	tardir=$(distdir) && $(am__tar) | lzip -c $${LZIP_OPT--9} >$(distdir).tar.lz
	$(am__remove_distdir)

dist-lzma: distdir
	tardir=$(distdir) && $(am__tar) | lzma -9 -c >$(distdir).tar.lzma
	$(am__remove_distdir)

dist-xz: distdir
	tardir=$(distdir) && $(am__tar) | XZ_OPT=$${XZ_OPT--e} xz -c >$(distdir).tar.xz
	$(am__remove_distdir)

dist-tarZ: distdir
	tardir=$(distdir) && $(am__tar) | compress -c >$(distdir).tar.Z
	$(am__remove_distdir)

dist-shar: distdir
	shar $(distdir) | GZIP=$(GZIP_ENV) gzip -c >$(distdir).shar.gz
	$(am__remove_distdir)

dist-zip: distdir
	-rm -f $(distdir).zip
	zip -rq $(distdir).zip $(distdir)
	$(am__remove_distdir)

dist dist-all: distdir
	tardir=$(distdir) && $(am__tar) | GZIP=$(GZIP_ENV) gzip -c >$(distdir).tar.gz
	$(am__remove_distdir)

# This target untars the dist file and tries a VPATH configuration.  Then
# it guarantees that the distribution is self-contained by making another
# tarfile.
distcheck: dist
	case '$(DIST_ARCHIVES)' in \
	*.tar.gz*) \
	  GZIP=$(GZIP_ENV) gzip -dc $(distdir).tar.gz | $(am__untar) ;;\
	*.tar.bz2*) \
	  bzip2 -dc $(distdir).tar.bz2 | $(am__untar) ;;\
	*.tar.lzma*) \
	  lzma -dc $(distdir).tar.lzma | $(am__untar) ;;\
	*.tar.lz*) \
	  lzip -dc $(distdir).tar.lz | $(am__untar) ;;\
	*.tar.xz*) \
	  xz -dc $(distdir).tar.xz | $(am__untar) ;;\
	*.tar.Z*) \
	  uncompress -c $(distdir).tar.Z | $(am__untar) ;;\
	*.shar.gz*) \
	  GZIP=$(GZIP_ENV) gzip -dc $(distdir).shar.gz | unshar ;;\
	*.zip*) \
	  unzip $(distdir).zip ;;\
	esac
	chmod -R a-w $(distdir); chmod a+w $(distdir)
	mkdir $(distdir)/_build
	mkdir $(distdir)/_inst
	chmod a-w $(distdir)
	test -d $(distdir)/_build || exit 0; \
	dc_install_base=`$(am__cd) $(distdir)/_inst && pwd | sed -e 's,^[^:\\/]:[\\/],/,'` \
	  && dc_destdir="$${TMPDIR-/tmp}/am-dc-$$$$/" \
	  && am__cwd=`pwd` \
	  && $(am__cd) $(distdir)/_build \
	  && ../configure --srcdir=.. --prefix="$$dc_install_base" \
	    $(AM_DISTCHECK_CONFIGURE_FLAGS) \
	    $(DISTCHECK_CONFIGURE_FLAGS) \
	  && $(MAKE) $(AM_MAKEFLAGS) \
	  && $(MAKE) $(AM_MAKEFLAGS) dvi \
	  && $(MAKE) $(AM_MAKEFLAGS) check \
	  && $(MAKE) $(AM_MAKEFLAGS) install \
	  && $(MAKE) $(AM_MAKEFLAGS) installcheck \
	  && $(MAKE) $(AM_MAKEFLAGS) uninstall \
	  && $(MAKE) $(AM_MAKEFLAGS) distuninstallcheck_dir="$$dc_install_base" \
	        distuninstallcheck \
	  && chmod -R a-w "$$dc_install_base" \
	  && ({ \
	       (cd ../.. && umask 077 && mkdir "$$dc_destdir") \
	       && $(MAKE) $(AM_MAKEFLAGS) DESTDIR="$$dc_destdir" install \
	       && $(MAKE) $(AM_MAKEFLAGS) DESTDIR="$$dc_destdir" uninstall \
	       && $(MAKE) $(AM_MAKEFLAGS) DESTDIR="$$dc_destdir" \
	            distuninstallcheck_dir="$$dc_destdir" distuninstallcheck; \
	      } || { rm -rf "$$dc_destdir"; exit 1; }) \
	  && rm -rf "$$dc_destdir" \
	  && $(MAKE) $(AM_MAKEFLAGS) dist \
	  && rm -rf $(DIST_ARCHIVES) \
	  && $(MAKE) $(AM_MAKEFLAGS) distcleancheck \
	  && cd "$$am__cwd" \
	  || exit 1
	$(am__remove_distdir)
	@(echo "$(distdir) archives ready for distribution: "; \
	  list='$(DIST_ARCHIVES)'; for i in $$list; do echo $$i; done) | \
	  sed -e 1h -e 1s/./=/g -e 1p -e 1x -e '$$p' -e '$$x'
distuninstallcheck:
	@test -n '$(distuninstallcheck_dir)' || { \
	  echo 'ERROR: trying to run $@ with an empty' \
	       '$$(distuninstallcheck_dir)' >&2; \
	  exit 1; \
	}; \
	$(am__cd) '$(distuninstallcheck_dir)' || { \
	  echo 'ERROR: cannot chdir into $(distuninstallcheck_dir)' >&2; \
	  exit 1; \
	}; \
	test `$(am__distuninstallcheck_listfiles) | wc -l` -eq 0 \
	   || { echo "ERROR: files left after uninstall:" ; \
	        if test -n "$(DESTDIR)"; then \
	          echo "  (check DESTDIR support)"; \
	        fi ; \
	        $(distuninstallcheck_listfiles) ; \
	        exit 1; } >&2
distcleancheck: distclean
	@if test '$(srcdir)' = . ; then \
	  echo "ERROR: distcleancheck can only run from a VPATH build" ; \
	  exit 1 ; \
	fi
	@test `$(distcleancheck_listfiles) | wc -l` -eq 0 \
	  || { echo "ERROR: files left in build directory after distclean:" ; \
	       $(distcleancheck_listfiles) ; \
	       exit 1; } >&2
check-am: all-am
check: check-am
all-am: Makefile $(PROGRAMS) $(HEADERS) config.h
installdirs:
	for dir in "$(DESTDIR)$(bindir)"; do \
	  test -z "$$dir" || $(MKDIR_P) "$$dir"; \
	done
install: install-am
install-exec: install-exec-am
install-data: install-data-am
uninstall: uninstall-am

install-am: all-am
	@$(MAKE) $(AM_MAKEFLAGS) install-exec-am install-data-am

installcheck: installcheck-am
install-strip:
	if test -z '$(STRIP)'; then \
	  $(MAKE) $(AM_MAKEFLAGS) INSTALL_PROGRAM="$(INSTALL_STRIP_PROGRAM)" \
	    install_sh_PROGRAM="$(INSTALL_STRIP_PROGRAM)" INSTALL_STRIP_FLAG=-s \
	      install; \
	else \
	  $(MAKE) $(AM_MAKEFLAGS) INSTALL_PROGRAM="$(INSTALL_STRIP_PROGRAM)" \
	    install_sh_PROGRAM="$(INSTALL_STRIP_PROGRAM)" INSTALL_STRIP_FLAG=-s \
	    "INSTALL_PROGRAM_ENV=STRIPPROG='$(STRIP)'" install; \
	fi
mostlyclean-generic:

clean-generic:

distclean-generic:
	-test -z "$(CONFIG_CLEAN_FILES)" || rm -f $(CONFIG_CLEAN_FILES)
	-test . = "$(srcdir)" || test -z "$(CONFIG_CLEAN_VPATH_FILES)" || rm -f $(CONFIG_CLEAN_VPATH_FILES)

maintainer-clean-generic:
	@echo "This command is intended for maintainers to use"
	@echo "it deletes files that may require special tools to rebuild."
clean: clean-am

clean-am: clean-binPROGRAMS clean-generic clean-libtool mostlyclean-am

distclean: distclean-am
	-rm -f $(am__CONFIG_DISTCLEAN_FILES)
	-rm -rf ./$(DEPDIR)
	-rm -f Makefile
distclean-am: clean-am distclean-compile distclean-generic \
	distclean-hdr distclean-libtool distclean-tags

dvi: dvi-am

dvi-am:

html: html-am

html-am:

info: info-am

info-am:

install-data-am:

install-dvi: install-dvi-am

install-dvi-am:

install-exec-am: install-binPROGRAMS

install-html: install-html-am

install-html-am:

install-info: install-info-am

install-info-am:

install-man:

install-pdf: install-pdf-am

install-pdf-am:

install-ps: install-ps-am

install-ps-am:

installcheck-am:

maintainer-clean: maintainer-clean-am
	-rm -f $(am__CONFIG_DISTCLEAN_FILES)
	-rm -rf $(top_srcdir)/autom4te.cache
	-rm -rf ./$(DEPDIR)
	-rm -f Makefile
maintainer-clean-am: distclean-am maintainer-clean-generic

mostlyclean: mostlyclean-am

mostlyclean-am: mostlyclean-compile mostlyclean-generic \
	mostlyclean-libtool

pdf: pdf-am

pdf-am:

ps: ps-am

ps-am:

uninstall-am: uninstall-binPROGRAMS

.MAKE: all install-am install-strip

.PHONY: CTAGS GTAGS all all-am am--refresh check check-am clean \
	clean-binPROGRAMS clean-generic clean-libtool ctags dist \
	dist-all dist-bzip2 dist-gzip dist-lzip dist-lzma dist-shar \
	dist-tarZ dist-xz dist-zip distcheck distclean \
	distclean-compile distclean-generic distclean-hdr \
	distclean-libtool distclean-tags distcleancheck distdir \
	distuninstallcheck dvi dvi-am html html-am info info-am \
	install install-am install-binPROGRAMS install-data \
	install-data-am install-dvi install-dvi-am install-exec \
	install-exec-am install-html install-html-am install-info \
	install-info-am install-man install-pdf install-pdf-am \
	install-ps install-ps-am install-strip installcheck \
	installcheck-am installdirs maintainer-clean \
	maintainer-clean-generic mostlyclean mostlyclean-compile \
	mostlyclean-generic mostlyclean-libtool pdf pdf-am ps ps-am \
	tags uninstall uninstall-am uninstall-binPROGRAMS


# Tell versions [3.59,3.63) of GNU make to not export all variables.
# Otherwise a system limit (for SysV at least) may be exceeded.
.NOEXPORT: