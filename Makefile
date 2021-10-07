CC=g++
WC=x86_64-w64-mingw32-g++
HC=emcc
SCR=src/main.cpp src/duck.cpp src/obstacle.cpp
FLAGS=-L/usr/local/lib -I/usr/local/include -lSDL2 -lSDL2_image -Iinclude
WFLAGS=-L/usr/x86_64-w64-mingw32/lib -I/usr/x86_64-w64-mingw32/include -lSDL2 -lSDL2_image -static-libstdc++ -static-libgcc -Iinclude
all:
	$(CC) -o game.AppImage $(SCR) $(FLAGS)
	./game.AppImage
win:
	$(WC) -o game.exe $(SCR) $(WFLAGS)