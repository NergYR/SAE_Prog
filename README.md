# SAE Programmation (SA05 - Traité les données) BUT1 RT1 
### pour compiler utiliser un makefile comme suit `Makefile`:
```Makefile
CC = gcc
FLAGS= -Wall 
LIBS= -lm -lSDL -lSDL_ttf
CGIDIR = /usr/lib/cgi-bin/
LOGDIR = /var/log/apache2/
WWWDIR = /var/www/
SRC_PATH = src/
DESTDIR = src/output/
HTMLDIR= $(WWWDIR)/html/


SDL_CFLAGS = $(shell sdl-config --cflags)
SDL_LDFLAGS = $(shell sdl-config --libs)


all: clean install

install: install-html install-cgi
	@sudo chmod a+rx $(LOGDIR) 
	@sudo chmod a+r $(LOGDIR)/access.log 

install-cgi:
	@cd www/codescompiles/ ; \
	sudo cp aecrire.html versiondynamique-txt versionstatique \
	     $(CGIDIR) ;\
	cd ../..
	@echo "Installation du programme :"
	sudo cp www/codescompiles/versiondynamique $(CGIDIR)
	sudo cp src/output/create $(CGIDIR)

install-html:
	@echo "Copie des fichiers aux bons emplacements" 
	@sudo tar xf www/www.tar -C /
	@echo "Copie d'un fichier de log de taille conséquente" 
	@sudo cp www/access.log.big $(LOGDIR)/access.log

clean: 
	@sudo rm -rf /var/www/*
	@sudo mkdir $(HTMLDIR)
	@sudo cp www/index.html $(HTMLDIR)
	@sudo rm -rf $(CGIDIR)/*

%.o: %.c
	$(CC) $(FLAGS) -c $^ -o $@


create: $(SRC_PATH)main.o $(SRC_PATH)fonction.o $(SRC_PATH)results.o $(SRC_PATH)versiontexte.o $(SRC_PATH)versionweb.o $(SRC_PATH)versiongraphique.o 
$(SRC_PATH)../lib/libgraphique.o
	$(CC) $(FLAGS) -o $(DESTDIR)$@ $^ $(SDL_CFLAGS) $(SDL_LDFLAGS) $(LIBS) 
	rm $(SRC_PATH)*.o
```
Ensuite utilisez la commande `make create` pour compiler sous Linux.
> [!CAUTION]
> Veuillez bien Respecter l'arborescence des dossier

