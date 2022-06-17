CC=g++
CXX=g++
RANLIB=ranlib

LIBSRC=sockets.cpp container.cpp
LIBOBJ=$(LIBSRC:.cpp=.o)

TARGETS=$(LIBSRC:.cpp=)

INCS=-I.
CFLAGS = -Wall -std=c++11 -g $(INCS)
CXXFLAGS = -Wall -std=c++11 -g $(INCS)

TAR=tar
TARFLAGS=-cvf
TARNAME=ex5.tar
TARSRCS=$(LIBSRC) Makefile README

all: clean container

sockets:
	$(CC) $(CFLAGS) -o $@ sockets.cpp

container:
	$(CC) $(CFLAGS) -o $@ container.cpp

clean:
	$(RM) $(TARGETS) $(CONTAINERLIB) $(OBJ) $(LIBOBJ) *~ *core

depend:
	makedepend -- $(CFLAGS) -- $(SRC) $(LIBSRC)

tar:
	$(TAR) $(TARFLAGS) $(TARNAME) $(TARSRCS)
