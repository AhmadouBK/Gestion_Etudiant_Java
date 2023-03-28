#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    float note_cc;
    float note_ds;
    int id_etudiant;
    int id_matiere;
}tnote;
int main();
void Menu_note();
void menu_ajout_note(tnote note);
void modifier_note(tnote note);
void supression_note(tnote note);
void affichage_note(tnote note);
void Gestion_note(tnote note);
