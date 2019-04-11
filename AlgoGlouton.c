#include <stdio.h>
#include <time.h>

int AlgoGlouton(int s, int V[], int k){
  int liste_bocaux[k]; //une liste de bocaux de taille k
  int j;
  int cpt = 0;
  for(j = 0; j < k; j++){
    liste_bocaux[j] = 0; //on met toutes les cases du tableau à 0 pour les incrémenter plus tard
  }
  int i = k - 1; //le -1 est important pour ne pas sortir du tableau
  while(s > 0){
    if(V[i] <= s){
      s -= V[i]; //on décrémente le s s'il est possible de remplir le bocal
      liste_bocaux[i]++; //on incrémente le compteur de bocaux correspondant
      cpt++; //on incrémente le compteur de bocaux
    }
    else{
      i--; //sinon on passe simplement au bocal suivant
    }
  }
  printf("(%d, [", cpt);
  int index;
  for(index = 0; index < k; index ++){ //affichage du tableau de bocaux
    if(index == k - 1) printf("%d", liste_bocaux[index]);
    else printf("%d, ", liste_bocaux[index]);
  }
  printf("])");
  return cpt; //le compteur correspond au nombre minimal de bocaux requis par l'algorithme glouton
}

int main(int argc, char **argv){

  FILE *fichier; 
  fichier = fopen(argv[1], "r"); //on ouvre le fichier
  float temps;
  clock_t t1, t2; //variables de temps
  int s, k; //vont stocker la quantité de confiture et la taille du tableau
  int a; 
  if(!fichier){ //traitement du cas d'erreur
    fprintf(stderr, "Fichier vide.\n");
  }

  else{
    //on recupere s et k 
    fscanf(fichier, "%d %d", &s, &k);
    int V[k]; //on declare un tableau de taille k pour stocker le système de capacité
    //on recupere le tableau sur le reste du fichier
    for(a = 0; a < k; a++){
	fscanf(fichier, "%d", &V[a]);
    }	
    t1 = clock();		
    int nbMinBocaux = AlgoGlouton(s, V, k); //on récupère la valeur retournée par l'algorithme glouton
    printf("\n");
    printf("Quantite = %d\nNombre de bocaux minimum : %d.\n", s, nbMinBocaux); //on l'affiche
    t2 = clock();
    temps = (float) (t2-t1)/CLOCKS_PER_SEC; //on calcule le temps d'exécution
    printf("Temps d'execution : %f secondes.\n", temps); //on affiche le temps
  }

  fclose(fichier);

  return 0;
}
