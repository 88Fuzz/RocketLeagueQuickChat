PROJECT_NAME=RocketLeagueQuickChat
LOCAL_INCLUDES=inc/
SFML_INCS=/home/kyle/workspace/SFML-master/include/
SFML_LIBS=/home/kyle/workspace/SFML-master/build/lib/
SFML_LINKS=-lsfml-graphics -lsfml-window -lsfml-system
DIRS=obj bin

CC=g++
LL=g++
EXE=bin/$(PROJECT_NAME)
SRC=$(wildcard src/*.cpp)
OBJS=$(patsubst src/%.cpp,obj/%.o,$(SRC))

#Base arguments for C compiler.
CFLAGS=-Wall -c -std=c++1y
#Library paths passed as flags.
CFLAGS+=-I$(LOCAL_INCLUDES) -I$(SFML_INCS)

LFLAGS=-L$(SFML_LIBS)

all: dirs setupFastRelease $(OBJS) $(PROJECT_NAME)
release: dirs setupRelease $(OBJS) $(PROJECT_NAME)
debug: dirs setupDebug $(OBJS) $(PROJECT_NAME)

dirs:
	@echo Making directories...
	@mkdir -p $(DIRS)

setupFastRelease:
	@echo Adding quick compile flags...
	$(eval CFLAGS_RELEASE = $(CFLAGS) -O0)

setupRelease:
	@echo Adding optimization flags...
	$(eval CFLAGS_RELEASE = $(CFLAGS) -O3)

setupDebug:
	@echo Adding debug flags...
	$(eval CFLAGS_RELEASE = $(CFLAGS) -g)

obj/%.o: src/%.cpp
	@echo
	@echo Compiling release $<
	$(CC) $(CFLAGS_RELEASE) $(<) -o $(@)

${PROJECT_NAME}: $(OBJS)
	@echo
	@echo Linking $<
	$(LL) $(LFLAGS) $(OBJS) $(SFML_LINKS) -o $(EXE)

clean:
	@echo Cleaning up...
	rm bin/* obj/*
	rmdir bin obj
