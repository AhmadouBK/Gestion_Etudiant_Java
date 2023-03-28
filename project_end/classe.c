#include "classe.h"
FILE* classe_fic = NULL;
char chaine[150],mod[50];
int choix, i, num_classe, x, alter, j, research;

void menu_classe()
{
        //Affichage du Menu Classe
            printf("Bienvenue dans la section Classe; Veuillez entrer votre choix: \n");
            printf("1. Ajouter une classe\n");
            printf("2. Modifier les informations d'une classe\n");
            printf("3. Aficher les classes\n");
            printf("4. Supprimer une classe\n");
            printf("5. Recherche de classe\n");
            printf("6. Retourner au menu principal\n");
            printf("Saisir:");
}

void ajout_classe(tclasse classe)
{
            printf("Donner le nom de la classe: \n");
            scanf("%s",classe.nom);
            do
                {
                    printf("Entrer le niveau de la classe: \n");
                    printf("1. Licence  2. Master \n");
                    scanf("%u",&classe.level);
                }
            while((classe.level != Licence) && (classe.level != Master));
  code:
            printf("Donner le code de la classe: \n");
            scanf("%d",&classe.code);
            classe_fic = fopen("classe.csv","r+");
        while(fgets(chaine,150,classe_fic) != NULL) //Pas d'erreur de saisie
        {   
                for(i = 0 ;i <= strlen(chaine) ;i++)
                {   mod[i] = '\0';
                    if(chaine[i] == '|')
                    {
                        break;
                    }
                    else
                    {
                    mod[i] = chaine[i];
                    }
                }
              num_classe = atoi(mod);
          if(classe.code == num_classe)
          {
              printf("Ce numero existe déja \n");
              goto code;
          }
        }
        fclose(classe_fic);
        classe_fic = fopen("classe.csv","a+");
        fprintf(classe_fic,"%10d|%10s|%2u\n",classe.code,classe.nom,classe.level);
        fclose(classe_fic);

}

void modifier_classe(tclasse classe)
{
        printf("Entrer le numéro de la classe à modifier: \n");
        scanf("%d",&num_classe);
        classe_fic = fopen("classe.csv","r+");
        while(fgets(chaine,150,classe_fic) != NULL)
        {   
            for(i = 0;i<=strlen(chaine);i++)
            {   classe.nom[i] = '\0'; 
                if(chaine[i] == '|')
                {
                    break;
                }
                else
                {
                classe.nom[i] = chaine[i];
                }
            }
        classe.code = atoi(classe.nom);
        if(classe.code == num_classe)
        {
        x = 1;
        do
        {

            printf("Quel attribut souhaitez-vous modifier ? Veuillez choisir 1 ou 2");
            printf("1. Le nom de la classe");
            printf("2. Le niveau de la classe");
            scanf("%d",&alter);
        }
        while((alter !=1)&&(alter !=2));
        if(alter==1)
        {
            printf("Entrer le nouveau nom : \n");
            scanf("%s",classe.nom);
            fseek(classe_fic, -strlen(chaine), SEEK_CUR);
            fprintf(classe_fic,"%10d|%10s",classe.code,classe.nom);
        }
        else
        {
            do
            {
                printf("1 - Licence \n");
                printf("2 - Master \n");
                printf("Entrer le nouveau niveau :");
                scanf("%u",&classe.level);
            }
            while((classe.level != 1)&&(classe.level !=2));
                fseek(classe_fic,-3, SEEK_CUR);
                fprintf(classe_fic,"%2u",classe.level);
        }
        }
    }
    fclose(classe_fic);
        if(x == 0)
        {
            printf("Cette classe n'existe pas !\n");
        }
}
       

void affichage_classe(tclasse classe)
{
        classe_fic = fopen("classe.csv","r");
        while (fgets(chaine,150,classe_fic) != NULL) 
        {   
            printf("%s",chaine);
        }
        fclose(classe_fic);
}
void supression_classe(tclasse classe)
{
        printf("Entrer le code de la classe à supprimer: \n");
        scanf("%d",&num_classe);
        classe_fic = fopen("classe.csv","r+");
        x = 0;
    while(fgets(chaine,150,classe_fic) != NULL)
{ 
  for(i = 0;i<=strlen(chaine);i++)
    {
    mod[i] = '\0';
    if(chaine[i] == '|')
    {
      break;
    }
    else
    {
      mod[i] = chaine[i];
    }
    }
  classe.code = atoi(mod);
    if(classe.code == num_classe)
    {
      x = 1;
      fseek(classe_fic,-strlen(chaine),SEEK_CUR);
      for(j = 0;j<=strlen(chaine);j++)
      {
        fputc(' ',classe_fic);
      }
      fputc('\n',classe_fic);
    }
}
fclose(classe_fic);
  if(x == 0)
  {
    printf("Cette classe n'existe pas :/ \n");
  }
}
void recherche_classe(tclasse classe)
{
  printf("Entrer le numéro de la classe que vous souhaitez rechercher: \n");
  scanf("%d",&research);
  classe_fic = fopen("classe.csv","r+");
  x = 0;
while(fgets(chaine,150,classe_fic) != NULL)
{ 
  for(i = 0;i<=strlen(chaine);i++)
  {mod[i] = '\0';
    if(chaine[i] == '|')
    {
      break;
    }
    else
    {
      mod[i] = chaine[i];
    }
  }
  classe.code = atoi(mod);
    if(classe.code == research)
    {
      x = 1;
      printf("%s\n",chaine);
    }
}
fclose(classe_fic);
  if(x == 0)
  {
    printf("Cette classe n'existe pas :/ \n");
  } 
}
void Gestion_classe(tclasse classe)
{
  do
  {
    Menu_classe: menu_classe();
    scanf("%d",&choix);
  }while((choix >= 7)||(choix <= 0));
      switch (choix)
        {
          case 1: ajout_classe(classe);  
          break;
          case 2: modifier_classe(classe);
          break;
          case 3: affichage_classe(classe);
          break ;
          case 4: supression_classe(classe);
          break ;
          case 5: recherche_classe(classe);
          break ;
          case 6: main();
          break;
        }
}
