#include "etudiant.h"
#include "matiere.h"
#include "classe.h"
#include "note.h"
int main()
{
  int choice;
  tetudiant et;
  tclasse class;
  tmatiere subject;
  tnote mark;
  do
    {
    printf("\t Bienvenue dans notre application \n");
    printf("Veuillez saisir l'opération à effectuer \n");
    printf("1 - Gestion des étudiants\n");
    printf("2 - Gestion des matières\n");
    printf("3 - Gestion des classes\n");
    printf("4 - Gestion des notes\n");
    printf("5 - Quitter\n");
    printf("Saisir : ");
    scanf("%u",&choice);
    }
    while((choice <= 0)||(choice >= 6));
  switch(choice)
  {
  case 1:
  Gestion_Etudiant(et);
  break;
  case 2:
  Gestion_Matiere(subject);
  break;
  case 3:
  Gestion_classe(class);
  break;
  case 4:
  Gestion_note(mark);
  break;
  case 5:
  printf("Merci d'avoir utilisé notre application, à la prochaine \n");
  }
return 0;
}