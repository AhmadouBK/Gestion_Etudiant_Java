#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct 
{
    int reference;
    char libelle[30];
    int coefficient;
}tmatiere;
int main();
void Gestion_Matiere(tmatiere matiere);
void ajout_matiere(tmatiere matiere);
void modif_matiere(tmatiere matiere);
void research_matiere(tmatiere matiere);
void delete_matiere(tmatiere matiere);
void affiche_matiere(tmatiere matiere);