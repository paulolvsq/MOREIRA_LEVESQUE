#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define INTERVALLE 10
#define INF -10

void echanger(int tableau[], int a, int b){
  
  int temp = tableau[a];
  tableau[a] = tableau[b];
  tableau[b] = temp;
  
}

int partition(int tableau[], int deb, int fin){
  
  int compt = deb;
  int pivot = tableau[deb];
  int i;

  for(i = deb + 1; i <= fin; i++){
    if(tableau[i] < pivot){
      compt++;
      echanger(tableau, compt, i);
    }
  }
  
  echanger(tableau, compt, deb);
  return compt;
  
}

void tri_rapide_bis(int tableau[], int debut, int fin){
  
  if(debut < fin){
    int pivot = partition(tableau, debut, fin);
    tri_rapide_bis(tableau, debut, pivot-1);
    tri_rapide_bis(tableau, pivot + 1, fin);
  }
  
}

void tri_rapide(int tableau[], int longueur){
  
  tri_rapide_bis(tableau, 0, longueur - 1);
  
}
//fonctions qui servent à implémenter un tri rapide pour le tableau

int AlgoGlouton(int s, int V[], int k){
  int liste_bocaux[k]; //une liste de bocaux de taille k
  int j, a;
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
  return cpt; //le compteur correspond au nombre minimal de bocaux requis par l'algorithme glouton
}

							
int TestGloutonCompatible(int k, int V[]){
  int s, j, r1, r2;
  if(k >= 3){ //on vérifie pour k >= 3 car pour <= 2 on sait que tout système est glouton compatible
    for(s = V[2] + 2; s <= V[k - 2] + V[k - 1] -1 ; s++){ //ne pas oublier de modifier les indices pour ne pas sortir du tableau
      for(j = 1; j <= k ; j++){
        if(V[j-1] < s){
          r1 = AlgoGlouton(s, V, k);
          r2 = 1 + AlgoGlouton(s - V[j -1], V, k); 
          if(r1 > r2){
            return 0; 
          }
        }
      }
    }
  }
  return 1;
}

int main(int argc, char **argv){ 

  srand(time(NULL)); //réinitialiser la graine pour l'aléatoire

  float temps; //va servir à stocker le temps d'exécution
  int i = 0, taille = 1, j, a;//variables de compteur, de taille k, de boucles
  clock_t t1, t2; //variables de temps
  int cpt = 0; //compteur de systèmes glouton compatibles
  int nbTours = 1000; //nombre de tests de systèmes aléatoires
  int tailleK = 100; //taille de k

  t1 = clock(); //on prend le temps de départ

  while(taille < tailleK){//on teste pour un k allant jusqu'à 100
    taille++; //on incrémente la taille en premier pour avoir accès à la bonne case du tableau
    while(i < nbTours){ //on lance nbTours tests
      int V[taille]; //on déclare un tableau qui va stocker le système de capacité 
      V[0] = 1;  //on n'oublie pas de mettre la première case du tableau à 1
      for(j = 1; j < taille; j++){
        V[j] = rand()%INTERVALLE + 2; //on génère des entiers aléatoires entre 2 et INTERVALLE  
      }
      tri_rapide(V, taille); //on trie le tableau
      a = TestGloutonCompatible(taille, V); //on vérifie s'il est glouton compatible
      if(a){
        cpt++; //dans ce cas on incrémente un compteur
      }
      i++; //ne pas oublier d'incrémenter le i
    }
    printf("%d\t",taille);
    printf("%f\n",(cpt*1.0)/(nbTours*1.0));
    cpt = 0; //on remet le cpt à 0
    i = 0; //on remet le i à 0
  }

  t2 = clock(); //on stocke le temps de fin
  temps = (float) (t2-t1)/CLOCKS_PER_SEC; //on met le temps en secondes
  printf("Temps d'execution : %f secondes.\n", temps);

  return 0;
}
