CC = gcc
GLOUTON = AlgoGlouton.c
RECHERCHE = RechercheExhaustive.c
PROGDYN = AlgoProgDyn.c
COMPATIBLE = TestGloutonCompatible.c

all : glouton recherche algoprogdyn compatible

glouton : $(GLOUTON)
	$(CC) -o $@ $<

recherche : $(RECHERCHE)
	$(CC) -o $@ $<

algoprogdyn : $(PROGDYN)
	$(CC) -o $@ $<

compatible : $(COMPATIBLE)
	$(CC) -o $@ $<

clean :
	rm -f *~ *.o glouton recherche algoprogdyn compatible
	cd res_dyn && rm -f *~ *.o 
	cd res_recherche && rm -f *~ *.o
	cd res_glouton && rm -f *~ *.o 
	cd res_compatible && rm -f *~ *.o

.PHONY : all clean
