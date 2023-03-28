#include "etudiant.h"
unsigned int choix,i,j,valeur_var,boul,choix2,numero;
FILE* etudiant_fic = NULL;
FILE* vall_fic = NULL;
char var[200],num[8];
void Menu_etudiant()
  {
    printf("\nMENU DE GESTION DES ETUDIANTS\n");
    printf("1 : AJOUT\n");
    printf("2 : MODIFICATION\n");
    printf("3 : RECHERCHE\n");
    printf("4 : SUPPRESSION\n");
    printf("5 : LISTE DES ETUDIANTS\n");
    printf("6 : MENU PRINCIPAL\n\n");
    printf("Saisir : ");
  }
void ajout_Etudiant(tetudiant etudiant)
{
 
    //Saisie des informations
  printf("AJOUT ETUDIANT\n");
  printf("Nom: ");
  scanf("%s", etudiant.nom);
  printf("Prénom: ");
  scanf("%s", etudiant.prenom);
  printf("Email: ");
  scanf("%s", etudiant.email);
  printf("Date de naissance (jj/mm/aaaa): ");
  scanf("%s",etudiant.date);
  num_etud:
  printf("N° Etudiant : ");
  scanf("%d",&etudiant.numero);
  //recuperation du numero etudiant précedent
 etudiant_fic = fopen("etudiant.csv","r+");
         while(fgets(var,200,etudiant_fic) != NULL)
        {   
                for(i = 0;i<=strlen(var);i++)
                {   num[i] = '\0';
                    if(var[i] == '|')
                    {
                        break;
                    }
                    else
                    {
                    num[i] = var[i];
                    }
                }
              numero = atoi(num);
          if(etudiant.numero == numero)
          {
              printf("Ce numero Existe déja \n");
              goto num_etud;
          }
        }
        fclose(etudiant_fic);
num_classe:
printf("N° Classe Etudiant : ");
scanf("%d",&etudiant.classe);
vall_fic = fopen("classe.csv","r");
boul = 0;
while(fgets(var,200,vall_fic) != NULL)
{ 
  for(i = 0;i<=strlen(var);i++)
  {num[i] = '\0';
    if(var[i] == '|')
        {
          break;
        }
        else
        {
          num[i] = var[i];
        }
        
  }
  numero = atoi(num);
  if(etudiant.classe == numero)
  { fclose(vall_fic);
    boul = 1;
    break;
  }
}
if(boul == 0)
{
    printf("Classe Invalide\n");
    goto num_classe;
}
else
{
    etudiant_fic = fopen("etudiant.csv","a+");
    fprintf(etudiant_fic,"%8d|%30s|%20s|%30s|%20s|%2d\n",etudiant.numero,etudiant.nom,etudiant.prenom,etudiant.email,etudiant.date,etudiant.classe);
    fclose(etudiant_fic);
}
}
void Modifier_Etudiant(tetudiant etudiant)
 {

  printf("MODIFICATION INFORMATIONS\n");
  printf("N° Etudiant : ");
  scanf("%u",&numero);
  boul = 0;
etudiant_fic = fopen("etudiant.csv","r+");

while(fgets(var,200,etudiant_fic) != NULL)
{ valeur_var = strlen(var);
  for(i = 0;i<=strlen(var);i++)
  {num[i] = '\0';
    if(var[i] == '|')
    {
      break;
    }
    else
    {
      num[i] = var[i];
    }    
  } 
  etudiant.numero = atoi(num);
  if(etudiant.numero == numero)
  {
    boul = 1;
    do
  {
  printf("Que voulez-vous modifier :\n");
  printf("1 - Nom\n");
  printf("2 - Prenom\n");
  printf("3 - Email\n");
  printf("4 - Date de naissance\n");
  printf("Saisir : ");
  scanf("%u",&choix2);
  }while(choix2 > 4 || choix2 < 1);
    switch (choix2)
    {
    case 1:
    printf("Nouveau Nom : ");
    scanf("%s",etudiant.nom);
    fseek(etudiant_fic,-strlen(var),SEEK_CUR);
    fprintf(etudiant_fic,"%8d|%30s",etudiant.numero,etudiant.nom);
    fclose(etudiant_fic);
    break;
    case 2:
    printf("Nouveau Prenom : ");
    scanf("%s",etudiant.prenom);
    fseek(etudiant_fic,-76,SEEK_CUR);
    fprintf(etudiant_fic,"%20s",etudiant.prenom);
    fclose(etudiant_fic);
    break;
    case 3:
    printf("Nouvelle Adresse Email : ");
    scanf("%s",etudiant.email);
    fseek(etudiant_fic,-52,SEEK_CUR);
    fprintf(etudiant_fic,"%30s",etudiant.email);
    fclose(etudiant_fic);
    break;
    case 4:
    printf("Nouvelle Date de naissance : ");
    scanf("%s",etudiant.date);
    fseek(etudiant_fic,-21,SEEK_CUR);
    fprintf(etudiant_fic,"%20s",etudiant.date);
    fclose(etudiant_fic);
    break;
    
    }//fin switch choix2
  }
}//Fin boucle While
if(boul == 0)
{
  printf("Etudiant Inexistant\n");
   Menu_etudiant();
}
 }

 void Rechercher_Etudiant(tetudiant etudiant)
  {
     printf("REHCHERCHE D'ETUDIANT\n");
  printf("N° Etudiant rechercher : ");
  scanf("%d",&numero);
  etudiant_fic = fopen("etudiant.csv","r+");
  boul = 0;
while(fgets(var,200,etudiant_fic) != NULL)
{ valeur_var = strlen(var);
  for(i = 0;i<=strlen(var);i++)
  {num[i] = '\0';
    if(var[i] == '|')
    {
      break;
    }
    else
    {
      num[i] = var[i];
    }
  }
  etudiant.numero = atoi(num);
    if(etudiant.numero == numero)
    {
      boul = 1;
      printf("%s\n",var);
    }
}
fclose(etudiant_fic);
  if(boul == 0)
  {
    printf("Etudiant Introuvable :/ \n");
     Menu_etudiant();
  } 
  }
void Supprimer_Etudiant (tetudiant etudiant )
    {
      printf("N° Etudiant à Supprimer : ");
  scanf("%d",&numero);
  etudiant_fic = fopen("etudiant.csv","r+");
  boul = 0;
while(fgets(var,200,etudiant_fic) != NULL)
{ valeur_var = strlen(var);
  for(i = 0;i<=strlen(var);i++)
  {num[i] = '\0';
    if(var[i] == '|')
    {
      break;
    }
    else
    {
      num[i] = var[i];
    }
  }
  etudiant.numero = atoi(num);
    if(etudiant.numero == numero)
    {
      boul = 1;
      fseek(etudiant_fic,-strlen(var),SEEK_CUR);
      for(j = 0;j<=strlen(var);j++)
      {
        fputc(' ',etudiant_fic);
      }
      fputc('\n',etudiant_fic);
      break;
    }
}
fclose(etudiant_fic);
  if(boul == 0)
  {
    printf("Etudiant Introuvable :/ \n");
    Menu_etudiant();
  } 
    }
    void Listes_des_etudiant (tetudiant etudiant)
      {
        etudiant_fic = fopen("etudiant.csv","r+");
          while(fgets(var,200,etudiant_fic) != NULL)
              {
                printf("%s",var);
              }
              fclose(etudiant_fic);
      }
void Gestion_Etudiant(tetudiant etudiant)
  {
        do
        {
        menu_etudiant: Menu_etudiant();
        scanf("%d",&choix);
        }
        while(choix > 6 || choix < 1);
      switch (choix)
        {
          case 1: ajout_Etudiant(etudiant);  
          break;
          case 2: Modifier_Etudiant(etudiant);
          break;
          case 3: Rechercher_Etudiant(etudiant);
          break ;
          case 4: Supprimer_Etudiant(etudiant);
          break ;
          case 5: Listes_des_etudiant(etudiant);
          break ;
          case 6: main();
          break;
        }
}