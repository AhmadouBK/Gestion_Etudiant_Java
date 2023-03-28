
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tetudiant 
{
  int numero;
  char nom[30];
  char prenom[20];
  char email[30];
  char date[20];
  int classe;
} tetudiant;
int main();
void Menu_etudiant();
void ajout_Etudiant(tetudiant etudiant);
void Modifier_Etudiant(tetudiant etudiant);
void Rechercher_Etudiant(tetudiant etudiant);
void Supprimer_Etudiant (tetudiant etudiant );
void Listes_des_etudiant (tetudiant etudiant);
void Gestion_Etudiant(tetudiant etudiant);