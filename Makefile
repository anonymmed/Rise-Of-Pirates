
INCLUDES :=-Iinclude/

SDL_FLAGS := -lSDL -lSDL_mixer -lSDL_image -lSDL_ttf

C_FALGS := -g

game:main.o menu.o personnage.o background.o collision.o
	gcc -o game bin/main.o bin/menu.o bin/personnage.o bin/background.o bin/collision.o $(SDL_FLAGS)
personnage.o:src/personnage.c
	gcc $(INCLUDES) -c -o bin/personnage.o src/personnage.c $(C_FALGS)
background.o:src/background.c
	gcc $(INCLUDES) -c -o bin/background.o src/background.c $(C_FALGS)
collision.o:src/collision.c
	gcc $(INCLUDES) -c -o bin/collision.o src/collision.c $(C_FALGS)
main.o:src/main.c
	gcc $(INCLUDES) -c -o bin/main.o src/main.c $(C_FALGS)
menu.o:src/menu.c
	gcc $(INCLUDES) -c -o bin/menu.o src/menu.c $(C_FALGS)
clean:
	rm -rf bin/collision.o bin/background.o bin/personnage.o bin/menu.o bin/main.o game
