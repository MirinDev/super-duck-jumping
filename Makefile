CC=g++
WC=x86_64-w64-mingw32-g++
SCR=src/*cpp
FLAGS=-L/usr/local/lib -I/usr/local/include -lSDL2 -lSDL2_image -Iinclude
WFLAGS=-L/usr/x86_64-w64-mingw32/lib -I/usr/x86_64-w64-mingw32/include -lSDL2 -lSDL2_image -static-libstdc++ -static-libgcc -Iinclude

all:
	@echo use /make win/ for windows, or /make lin/ for linux
win:
	$(WC) -o game.exe $(SCR) $(WFLAGS)
	mv game.exe dist/win
lin:
	$(CC) -o game $(SCR) $(FLAGS)
	mv game app/AppRun
	./appimagetool-x86_64.AppImage app
	mv duck-x86_64.AppImage dist/lin/game.AppImage
test:
	$(CC) -o game $(SCR) $(FLAGS)
	./game