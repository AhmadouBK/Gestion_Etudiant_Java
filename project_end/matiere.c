#include "matiere.h"
FILE* matiere_fic = NULL;
FILE* clas_fic = NULL;
FILE* lieu = NULL;
	char var2[200],num2[8];
	unsigned int choix,numero_matiere,boul = 0,boulA = 0,numero_classe,choix2,choix3,numero, i, j;

void ajout_matiere(tmatiere matiere)
{
    num_matiere:
    printf("N° Matiere : ");
        scanf("%d",&matiere.reference);
        /*Recuperation de l'id*/
        matiere_fic = fopen("matiere.csv","r+");
         while(fgets(var2,200,matiere_fic) != NULL)
        {   
                for(i = 0;i<=strlen(var2);i++)
                {   num2[i] = '\0';
                    if(var2[i] == '|')
                    {
                        break;
                    }
                    else
                    {
                    num2[i] = var2[i];
                    }
                }
              numero_matiere = atoi(num2);
          if(matiere.reference == numero_matiere)
          {
              printf("Cette matiere Existe déja \n");
              goto num_matiere;
          }
        }
        printf("Libellé Matiere : ");
        scanf("%s",matiere.libelle);
        printf("Coefficient Matiere : ");
        scanf("%d",&matiere.coefficient);
        fclose(matiere_fic);
        matiere_fic = fopen("matiere.csv","a+");
        fprintf(matiere_fic,"%8d|%30s|%2d\n",matiere.reference,matiere.libelle,matiere.coefficient);
        fclose(matiere_fic);	
}
void modif_matiere(tmatiere matiere)
{
printf("MODIFICATION INFORMATIONS\n");
matiere_rech:
printf("N° Matiere : ");
scanf("%u",&numero_matiere);
boul = 0;
matiere_fic = fopen("matiere.csv","r+");
while(fgets(var2,200,matiere_fic) != NULL)
{ 
  for(i = 0;i<=strlen(var2);i++)
  {num2[i] = '\0';
    if(var2[i] == '|')
    {
      break;
    }
    else
    {
      num2[i] = var2[i];
    }    
  } 
  matiere.reference = atoi(num2);
  if(matiere.reference == numero_matiere)
  {
    boul = 1;
        do
    {
    printf("Que voulez-vous modifier :\n");
    printf("1 - Libellé\n");
    printf("2 - Coefficient\n");
    printf("Saisir : ");
    scanf("%u",&choix2);
    }while(choix2 > 2 || choix2 < 1);
            switch (choix2)
            {
            case 1:
                printf("Nouveau Libellé : ");
                scanf("%s",matiere.libelle);
                fseek(matiere_fic,-34,SEEK_CUR);
                fprintf(matiere_fic,"%30s",matiere.libelle);
                break;
            case 2:
                printf("Nouveau Coefficient : ");
                scanf("%d",&matiere.coefficient);
                fseek(matiere_fic,-3,SEEK_CUR);
                fprintf(matiere_fic,"%2d\n",matiere.coefficient);
                break;
            }//fin Switch choix2
  }
}
if(boul == 0)
{
    printf("N° Matiere Invalide\n");
    goto matiere_rech;
}
fclose(matiere_fic);
      
}
void research_matiere(tmatiere matiere)
{
menu_matiere:
	   printf("REHCHERCHE DE MATIERE\n");
  printf("N° matiere : ");
  scanf("%d",&numero_matiere);
  matiere_fic = fopen("matiere.csv","r+");
  boul = 0;
while(fgets(var2,200,matiere_fic) != NULL)
{
  for(i = 0;i<=strlen(var2);i++)
  {num2[i] = '\0';
    if(var2[i] == '|')
    {
      break;
    }
    else
    {
      num2[i] = var2[i];
    }
  }
  matiere.reference = atoi(num2);
    if(matiere.reference == numero_matiere)
    {
      boul = 1;
      printf("%s\n",var2);
    }
}
fclose(matiere_fic);
  if(boul == 0)
  {
    printf("Matiere Introuvable :/");
    goto menu_matiere;
  } 
    
}
void delete_matiere(tmatiere matiere)
{
menu_matiere:
	printf("N° Matiere à Supprimer : ");
  scanf("%d",&numero_matiere);
  matiere_fic = fopen("matiere.csv","r+");
  boul = 0;
while(fgets(var2,200,matiere_fic) != NULL)
{ 
  for(i = 0;i<=strlen(var2);i++)
  {num2[i] = '\0';
    if(var2[i] == '|')
    {
      break;
    }
    else
    {
      num2[i] = var2[i];
    }
  }
  matiere.reference = atoi(num2);
    if(matiere.reference == numero_matiere)
    {
      boul = 1;
      fseek(matiere_fic,-strlen(var2),SEEK_CUR);
      for(j = 0;j<=strlen(var2);j++)
      {
        fputc(' ',matiere_fic);
      }
      fputc('\n',matiere_fic);
      break;
    }
}
fclose(matiere_fic);
  if(boul == 0)
  {
    printf("Matiere Introuvable :/ ");
    goto menu_matiere;
  }
}
void affiche_matiere(tmatiere matiere)
{
	matiere_fic = fopen("matiere.csv","r+");
  while(fgets(var2,200,matiere_fic) != NULL)
{
  printf("%s",var2);
}
fclose(matiere_fic);
}

void Gestion_Matiere(tmatiere matiere)
{

	printf("Bienvenu dans Matière\n");
	printf("Choisissez une option\n");
	printf("1. Ajouter une matière\n");
	printf("2. Modifier une matière\n");
	printf("3. Rechercher une matière\n");
	printf("4. Supprimer une matière\n");
	printf("5. Afficher les matieres\n");
	printf("6. Quitter le sous-menu\n");
	scanf("%d",&choix);

	switch (choix)
		{
      case 1: ajout_matiere(matiere);
				break;
			case 2: modif_matiere(matiere); 
				break;
			case 3: research_matiere(matiere);
				 break;
			case 4: delete_matiere(matiere);
				 break;
			case 5: affiche_matiere(matiere);
				 break;
			case 6: main();
				break; 
		}
}
