# Combat
CC = gcc --std=c99
CFLAGS = -Wall -g #-pedantic -ansi -g
BINDIR = ./bin
SRCDIR = ./src
OBJS = $(BINDIR)/init.o $(BINDIR)/affichage.o $(BINDIR)/combat.o $(BINDIR)/plateau.o $(BINDIR)/strategie.o $(BINDIR)/deroulement.o $(BINDIR)/main.o
.PHONY : clean

objs : $(OBJS)

$(BINDIR)/init.o : $(SRCDIR)/init.c $(SRCDIR)/init.h
	$(CC) $(CFLAGS) -c  $(SRCDIR)/init.c -o $@

$(BINDIR)/affichage.o : $(SRCDIR)/affichage.c $(SRCDIR)/affichage.h $(SRCDIR)/init.h
	$(CC) $(CFLAGS) -c $(SRCDIR)/affichage.c -o $@

$(BINDIR)/combat.o : $(SRCDIR)/combat.c $(SRCDIR)/combat.h $(SRCDIR)/affichage.h
		$(CC) $(CFLAGS) -c $(SRCDIR)/combat.c -o $@

$(BINDIR)/plateau.o : $(SRCDIR)/plateau.c $(SRCDIR)/plateau.h $(SRCDIR)/combat.h
		$(CC) $(CFLAGS) -c  $(SRCDIR)/plateau.c -o $@

$(BINDIR)/strategie.o : $(SRCDIR)/strategie.c $(SRCDIR)/strategie.h $(SRCDIR)/plateau.h
		$(CC) $(CFLAGS) -c  $(SRCDIR)/strategie.c -o $@

$(BINDIR)/deroulement.o : $(SRCDIR)/deroulement.c $(SRCDIR)/deroulement.h
		$(CC) $(CFLAGS) -c $(SRCDIR)/deroulement.c -o $@

$(BINDIR)/main.o : $(SRCDIR)/main.c $(SRCDIR)/init.h $(SRCDIR)/affichage.h $(SRCDIR)/combat.h $(SRCDIR)/plateau.h $(SRCDIR)/strategie.h $(SRCDIR)/deroulement.h
		$(CC) $(CFLAGS) -c $(SRCDIR)/main.c -o $@

jeu : $(OBJS)
		$(CC) -o $@ $^ -lm



clean :
	@rm -f $(BINDIR)/*.o  #2> /dev/null || true
	@echo "cleaning done"
