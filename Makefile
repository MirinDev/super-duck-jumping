CC=g++
W32C=i686-w64-mingw32-g++
W64C=x86_64-w64-mingw32-g++
SCR=src/*cpp
FLAGS=-lSDL2 -lSDL2_image -Iinclude
W64FLAGS=icon.res -L/i686-w64-mingw32/lib -I/usr/i686-w64-mingw32/include -lSDL2 -lSDL2_image -static-libstdc++ -static-libgcc -Iinclude
W32FLAGS=icon.res -lSDL2 -lSDL2_image -static-libstdc++ -static-libgcc -Iinclude

all:
	@echo use /make win/ for windows, or /make lin/ for linux
win32:
	$(W32C) -o game.exe $(SCR) $(W32FLAGS)
	mv game.exe dist/win
win64:
	$(W64C) -o game.exe $(SCR) $(W64FLAGS)
	mv game.exe dist/win
lin:
	$(CC) -o game $(SCR) $(FLAGS)
