#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum niveau{ Licence = 1, Master = 2 }niveau;
typedef struct tclasse
{
    int code;
    char nom[30];
    niveau level;
}tclasse;
int main();
void Menu_classe();
void ajout_classe(tclasse classe);
void modifier_classe(tclasse classe);
void affichage_classe(tclasse classe);
void supression_classe(tclasse classe);
void recherche_classe(tclasse classe);
void Gestion_classe(tclasse classe);