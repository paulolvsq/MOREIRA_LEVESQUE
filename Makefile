CC = gcc-11
GLOUTON = AlgoGlouton.c
RECHERCHE = RechercheExhaustive.c
PROGDYN = AlgoProgDyn.c
COMPATIBLE = TestGloutonCompatible.c
CFLAGS = -ftree-vectorize -O3 -fopenmp

all : glouton recherche algoprogdyn compatible exec

exec :
	./glouton res_glouton/donnees_glouton.txt
	./algoprogdyn res_dyn/donnees_progdyn.txt
	./recherche res_recherche/donnees_recherche.txt
	./compatible res_compatible/donnees.txt

glouton : $(GLOUTON)
	$(CC) $(CFLAGS) -o $@ $<

recherche : $(RECHERCHE)
	$(CC) $(CFLAGS) -o $@ $<

algoprogdyn : $(PROGDYN)
	$(CC) $(CFLAGS) -o $@ $<

compatible : $(COMPATIBLE)
	$(CC) $(CFLAGS) -o $@ $<

clean :
	rm -f *~ *.o glouton recherche algoprogdyn compatible
	cd res_dyn && rm -f *~ *.o 
	cd res_recherche && rm -f *~ *.o
	cd res_glouton && rm -f *~ *.o 
	cd res_compatible && rm -f *~ *.o

.PHONY : all clean
