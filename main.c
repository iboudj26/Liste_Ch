#include<stdio.h>
#include<stdlib.h>
typedef struct Liste {
int val ;
struct Liste *suiv;
}Liste ;

//Fct Creer la list
Liste* Creer_Liste(int n , Liste *L){
Liste *T , *P;
int i ;
//Creation de la tete
T=(Liste*)malloc(sizeof(Liste));      printf("Donnez votre valeur : ");     scanf("%d",&T->val);
T->suiv=NULL;
L=T;
//Creation de les autres elements
for(i=2;i<=n;i++){
    P=(Liste*)malloc(sizeof(Liste));   printf("\n Donnez la valeur de l'elemen %d : ",i);        scanf("%d",&P->val);
    P->suiv=NULL;    L->suiv=P;    L=P;
}L=T;
   return L;
}
//fonction insertion d'une nouvelle tete
Liste* Inserer_tete(Liste *L){
Liste *P ;
P=(Liste*)malloc(sizeof(Liste));  printf("\ndooez la valeur de la noiuvelle tete : ");  scanf("%d",&P->val);
P->suiv=L;
L=P;
return L ;   }
//inserer à la fin
Liste* Inserer_Fin(Liste *Q){
Liste *Der_elet , *elet;
Der_elet=(Liste*)malloc(sizeof(Liste));
elet=(Liste*)malloc(sizeof(Liste));   printf("Donnez la nouvelle fin : ");     scanf("%d",&Der_elet->val);
Der_elet->suiv=NULL;  elet=Q;
while(elet->suiv != NULL){
    elet=elet->suiv;   }    elet->suiv=Der_elet;
return Q ;
}
//Procedure pour afficher les elements d'une liste
void affiche_list(Liste *L){
Liste *T;
T=L;
printf("\n les elements de la liste sont : ");
while (T != NULL){
    printf("%d\t",T->val);
    T=T->suiv;    }  }
main(){
    Liste *T,*liste;
    int nbr , pos ;
     printf("Donnez le nbr des elements de la liste : ");      scanf("%d",&nbr);
    //Appel de la fonction Creer_Liste
    liste = Creer_Liste(nbr , T);
    //appel de la fonction affiche_list
    affiche_list(liste);
    //inserer une nouvelle tete
    liste = Inserer_tete(liste);
    //inserer à l'afin de la liste
    liste= Inserer_Fin(liste);*/
      //appel de la fonction affiche_list
    affiche_list(liste);
}
