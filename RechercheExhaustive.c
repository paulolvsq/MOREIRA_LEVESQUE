#include <stdio.h>
#include <time.h>
#define INF 99999

int cpt = 0;
int cpt2 = 0;

int rechercheExhaustive(int k, int V[], int s){
	cpt++;
	if(cpt == 2147483647){
		cpt = 0; cpt2++;
	}
	if(cpt%100000000 == 0) printf("%d %d\n", cpt/100000000, cpt2);
	int i = 0;
	int NbCont = 0;
	int x = 0;
    
	if(s < 0){
		return INF;
	}
	else{
		if(s == 0){
			return 0;
		}
		else{
			NbCont = s;
			for(i = 0; i<k; i++){
				x = rechercheExhaustive(k, V, s-V[i]);
				if(x+1 < NbCont){
					NbCont = x+1;
				}
			}
			return NbCont;
		}
	}
}

//algorithme fourni dans l'énoncé

int main(int argc, char **argv){
  
	FILE *fichier;
	fichier = fopen(argv[1], "r"); //on ouvre le fichier
	float temps; 
	clock_t t1, t2; //variables de temps
	int s, k; //vont stocker la quantité de confiture et la taille du tableau
	int a;

	if(!fichier){ ////traitement du cas d'erreur
		fprintf(stderr, "Fichier vide.\n");
	}

	else{
		fscanf(fichier, "%d %d", &s, &k);
		int V[k]; //on declare un tableau de taille k pour le système de capacite
		for(a = 0; a < k; a++){
			fscanf(fichier, "%d", &V[a]);
		}
		t1 = clock();
		int nbMinBocaux = rechercheExhaustive(k, V, s); ////on récupère la valeur retournée par l'algorithme recherche
		printf("Nombre de bocaux minimum : %d.\n", nbMinBocaux); //on affiche ce résultat
		t2 = clock();
		temps = (float) (t2-t1)/CLOCKS_PER_SEC; //on calcule le temps d'exécution
		printf("Temps d'execution : %f secondes.\n", temps); //on l'affiche

	}
	fclose(fichier);
  
	return 0;
}


	
  
  
