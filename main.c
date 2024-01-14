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
Liste* Tri_insrt(Liste *debut){
 Liste *tp , *p;
 int PR;;
 if(debut!=NULL){
    for(tp=debut;tp->suiv !=NULL;tp=tp->suiv)
        for(p=tp->suiv;p!=NULL;p=p->suiv){
            if (p->val<tp->val){
           PR=p->val;
           p->val=tp->val ;
           tp->val=PR ;
            }
        }
 }
    return debut ;
}
//fonction insertion d'une nouvelle tete
Liste* Inserer_tete(Liste *L){
Liste *P ;
P=(Liste*)malloc(sizeof(Liste));  printf("\ndooez la valeur de la noiuvelle tete : ");  scanf("%d",&P->val);
P->suiv=L;
L=P;
return L ;   }
//inserer au milieu de la list selon la pos
Liste* Inserer_Mil(Liste *T , int Pos){
    Liste *Mil, *Elet;
    int i ;
    Mil = (Liste*)malloc(sizeof(Liste));
    Elet = (Liste*)malloc(sizeof(Liste));    printf("Donnez la valeur de l'element milieu :");   scanf("%d",&Mil->val);
    Elet = T ;
    //boucle de la position
    for(i=1;i<Pos;i++){
        Elet = Elet->suiv;     }
    Mil->suiv = Elet->suiv;
    Elet->suiv = Mil ;
    return T ;
}
//inserer à la fin
Liste* Inserer_Fin(Liste *Q){
Liste *Der_elet , *elet;
Der_elet=(Liste*)malloc(sizeof(Liste));
elet=(Liste*)malloc(sizeof(Liste));   printf("Donnez la nouvelle fin : ");     scanf("%d",&Der_elet->val);
Der_elet->suiv=NULL;  elet=Q;
while(elet->suiv != NULL){
    elet=elet->suiv;   }    elet->suiv=Der_elet;
return Q ;    }
//Suprimer la tete
Liste* Sup_Tete(Liste *T){
  if(T==NULL)  exit(0);
   Liste *sup=T;     T=T->suiv;   free(sup);
   return T ;    }
    //supres une element au milieu
   Liste* Sup_Mil(Liste *T , int posi){
   Liste *ele_sup , *ele_pred;
   int i ;           ele_sup = T ;
   for(i=1;i<posi;i++){
    ele_pred=ele_sup;
    ele_sup=ele_sup->suiv;
   }
   ele_pred->suiv=ele_sup->suiv;
   free(ele_sup);
   return T ;    }
   //Suprimer la fin de la liste
Liste* Sup_Fin(Liste *Q){
    Liste *Ele;
    Ele=Q;
    Liste *elet_pre;
    while(Ele->suiv != NULL){
        elet_pre = Ele;
            Ele=Ele->suiv;   }
    elet_pre->suiv = NULL;
    printf("La valeur de la Fin suprime est  : %d ",Ele->val);
    free(Ele);
    return Q ;  }
    //Fonction de rechercher une elements
    int Recher_Elet(Liste *T , int Val){
    Liste *elet =T ;
    if(elet == NULL) return 0 ;
    if(elet->val==Val){
        return 1 ;
    }else {  return Recher_Elet(elet->suiv,Val);  }
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
   printf("Bienvenue sur Mon Programme !");
    char Ch[50] ;
    Liste *T,*liste;
    int nbr , pos ;
     printf("\n Donnez le nbr des elements de la liste : ");      scanf("%d",&nbr);
    //Appel de la fonction Creer_Liste
    liste = Creer_Liste(nbr , T);
    //appel de la fonction affiche_list
    affiche_list(liste);
    printf("\n*****Liste non triee*****");
    liste=Tri_insrt(liste);
     affiche_list(liste);
     printf("\n****Liste triee****\n");
     int true ;
     true=1;
     while(true == 1){
        printf("\n Veuillez choisir une Modification :(ins_deb , insert_mil , insert_fin , Sup_deb , Sup_mil , Sup fin , Rech ,Quitter): \n");
        scanf("%s",&Ch);
        if(strcmp(Ch ,"Quitter")==0 ){
            printf("Au revoir !");    true=0;
        }
       if(strcmp(Ch,"ins_deb")==0) { //inserer une nouvelle tete
           liste = Inserer_tete(liste);
           affiche_list(liste);   }
      if(strcmp(Ch,"insert_mil")==0){ //Inserer au milieu de la liste
    do{   printf("\n Donnez la position pour inserer une nouvelle elet : ");    scanf("%d",&pos);
    }while(pos<=0 || pos>nbr);
    liste=Inserer_Mil(liste ,pos);    affiche_list(liste);          }
        if(strcmp(Ch,"insert_fin")==0){  //inserer à l'afin de la liste
           liste= Inserer_Fin(liste);    affiche_list(liste);               }
       if (strcmp(Ch,"Sup_deb")==0){        //Apell de la fct sup le debut
    liste = Sup_Tete(liste);   affiche_list(liste);       }
       if (strcmp(Ch,"Sup_mil")==0){    //Sup milieu
    do{        printf("\n Donnez la position pour suprimer elet : ");      scanf("%d",&pos);   }while(pos<=0 || pos>nbr);
    liste = Sup_Mil(liste,pos);                   affiche_list(liste);    }
     if (strcmp(Ch,"Sup_fin")==0){   //Appel de la fct sup la fin
    liste = Sup_Fin(liste);   affiche_list(liste);           }
       if (strcmp(Ch,"Rech")==0){//Appel de la fct recherche ele
             int v ;                        printf("\n Donnez la valeur recherche :");    scanf("%d",&v);
             affiche_list(liste);
    if(Recher_Elet(liste,v)==1){   printf("la valeur %d existe dans la liste chainee .",v);
    }else{   printf("la valeur %d n'existe pas  dans la liste chainee .",v);
    }         }
        }
}
