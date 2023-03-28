#include "note.h"
FILE* note_fic = NULL;
FILE* classe_fichier = NULL;
FILE* mat_fic = NULL;
FILE* etud_fic = NULL;
int choice1, choice2, choice3, choice4, student_research, x, mat_research, reference_class, class_check, y, i, j;
char chaine[150],numero[10], class_ref[2], mat_ref[2];
void Menu_note()
{
    //Affichage du Menu Note
    printf("1 - Ajout de Note\n");
    printf("2 - Modification de Note\n");
    printf("3 - Suppression de Note\n");
    printf("4 - Affichage de Note\n");
    printf("5 - Revenir au menu precedent\n");
    printf("Saisir : ");
}

void menu_ajout_note(tnote note)
{
    do
    {
        printf("\t Ajout de Note \n");
        printf("1 - Ajout de note d'un Etudiant\n");
        printf("2 - Ajout des notes d'un Etudiant dans toutes les matieres\n");
        printf("3 - Ajout des notes d'une classe dans une matiere\n");
        printf("4 - Revenir au menu precedent\n");
        printf("Saisir : ");
        scanf("%d",&choice1);
    }while((choice1<=0)||(choice1>=5));
        switch (choice1)
        {
            case 1:
                begin_etudiant:
            printf("Entrer l'identifiant de l'étudiant : ");
            scanf("%d",&student_research);
            note_fic = fopen("etudiant.csv","r");
            x = 0;
            while(fgets(chaine,150,note_fic) != NULL)
            {   
                for(i=0;i<=strlen(chaine);i++)
                {   numero[i] = '\0';
                    if(chaine[i] == '|')
                    {
                        break;
                    }
                    else
                    {
                        numero[i] = chaine[i];/*recuperation du code de l'etudiant*/
                    }
                }
                note.id_etudiant = atoi(numero);
                if(note.id_etudiant == student_research)
                {
                    x = 1;
                }
                 
            }
            if(x == 0)
            {
                    printf("Cet étudiant n'existe pas !\n");
                    goto begin_etudiant;
            }
            begin_matiere:
            note_fic = fopen("matiere.csv","r");
            x = 0;
            printf("Liste des matieres\n");
            while(fgets(chaine,150,note_fic) != NULL)
            {   
                printf("%s",chaine);
            }
            fclose(note_fic);
            printf("N° Reference Matiere : \n");
            scanf("%d",&mat_research);
            note_fic = fopen("matiere.csv","r");
            x = 0;
            while(fgets(chaine,150,note_fic) != NULL)
            {   
                for(i=0;i<=strlen(chaine);i++)
                {   numero[i] = '\0';
                    if(chaine[i] == '|')
                    {
                        break;
                    }
                    else
                    {
                        numero[i] = chaine[i];/*recuperation du code de la matiere*/
                    }
                }
                note.id_matiere = atoi(numero);
                if(note.id_matiere == mat_research)
                {
                    x = 1;
                }
                 
            }
            if(x == 0)
            {
                    printf("Matiere introuvable !\n");
                    goto begin_matiere;
            }
            fclose(note_fic);
            /*Insertion des informations vers le fichier note.csv*/
            /*printf("%d",etudiant_recherche);
            printf("\n%d\n",matiere_recherche);*/
            do
            {
                printf("Entrer la note obtenue au controle continue (CC) \n");
                printf("Saisir : ");
                scanf("%f",&note.note_cc);
            }
            while((note.note_cc < 0)||(note.note_cc > 20));
            do
            {
                printf("Entrer la note obtenue au devoir (DS) \n");
                printf("Saisir : ");
                scanf("%f",&note.note_ds);
            }
            while((note.note_ds < 0)||(note.note_ds > 20));
            
            note_fic = fopen("note.csv","a+");
            fprintf(note_fic,"%8d|%2d|%2.2f|%2.2f\n",student_research,mat_research,note.note_cc,note.note_ds);
            fclose(note_fic);
            break;

            case 2:
            debut_etudiant:
            printf("N° Id Etudiant : ");
            scanf("%d",&student_research);
            note_fic = fopen("etudiant.csv","r");
            x = 0;
            while(fgets(chaine,150,note_fic) != NULL)
            {   
                for(i=0;i<=strlen(chaine);i++)
                {   numero[i] = '\0';
                    if(chaine[i] == '|')
                    {
                        break;
                    }
                    else
                    {
                        numero[i] = chaine[i];/*recuperation du code de l'etudiant*/
                    }
                }
                note.id_etudiant = atoi(numero);
                if(note.id_etudiant == student_research)
                {   
                    x = 1;
                    class_ref[0] = chaine[strlen(chaine) - 3];/// <=> strlen(chaine) - 3 = 113
                    class_ref[1] = chaine[strlen(chaine) - 2];/// <=> strlen(chaine) - 2 = 114
                    reference_class = atoi(class_ref);//On recupere le numero de la classe dans etudiant.csv
                    fclose(note_fic);
                    classe_fichier = fopen("a_lieu.csv","r+");
                    while(fgets(chaine,15,classe_fichier) != NULL)
                    {
                        for(i=0;i<=strlen(chaine);i++)
                            {   numero[i] = '\0';
                                if(chaine[i] == '|')
                                {
                                    break;
                                }
                                else
                                {
                                    numero[i] = chaine[i];/*recuperation du code de l'etudiant*/
                                }
                            }
                            class_check = atoi(numero);
                            if(reference_class == class_check )/*Verification apparition classe de l'etudiant dans a_lieu.csv*/
                            {   x = 1;
                                printf("%s",chaine);
                                mat_ref[0] = chaine[strlen(chaine) - 3];
                                mat_ref[1] = chaine[strlen(chaine) - 2];
                                note.id_matiere = atoi(mat_ref);
                                printf("Note CC Etudiant N°%d Matiere N°%d : ",note.id_etudiant,note.id_matiere);
                                scanf("%f",&note.note_cc);
                                printf("Note DS Etudiant N°%d Matiere N°%d : ",note.id_etudiant,note.id_matiere);
                                scanf("%f",&note.note_ds);
                                note_fic = fopen("note1.csv","a+");
                                fprintf(note_fic,"%8d|%2d|%2.2f|%2.2f\n",note.id_matiere,note.id_matiere,note.note_cc,note.note_ds);
                                fclose(note_fic);
                            }
                    }
                    fclose(classe_fichier);
                    if(x = 0)
                    {
                        printf("La classe associée à l'eleve ne contient aucune matiere\n");
                        goto debut_etudiant;
                    }
                    break;
                }
                 
            }
            if(x == 0)
            {
                    printf("Etudiant introuvable !\n");
                    goto debut_etudiant;
            }
            break;
            case 3:
                 printf("Ajout\n");
                    printf("Entrer la reference de la matiere \n");
                    scanf("%d",&mat_research);
                    mat_fic = fopen("matiere.csv","r+");
                    x = 0;
                    while(fgets(chaine,150,mat_fic) != NULL)
                    {
                    int i=0;
                        while(chaine[i]!=',')
                        {
                            numero[i] =chaine[i];
                            i++;
                        }
                    note.id_matiere = atoi(numero);
                    if(note.id_matiere == mat_research)
                        {
                        x = 1;
                        }
                    }
                    fclose(mat_fic);
                    etud_fic = fopen("etudiant.csv","r+");
                    while(fgets(chaine,150,etud_fic) != NULL){
                    int i=0;
                        while(chaine[i]!=',')
                        {
                            numero[i] =chaine[i];
                            i++;
                        }
                    if(x==1)
                    {
                           note.id_etudiant = atoi(numero);
                            printf("Etudiant: %s\n",chaine); 
                            printf("Ajout des notes \n");
                            printf("Ajjouter la note de DS\n");
                            scanf("%f",&note.note_ds);
                            printf("Ajjouter la note de CC\n");
                            scanf("%f",&note.note_cc);
                            note_fic = fopen("note2.csv","a");
                            fprintf(note_fic,"%d,%d,%f,%f\n", note.id_etudiant,note.id_matiere,note.note_ds,note.note_cc);
                            fclose(note_fic); 
                    }
                        else
                        {
                            printf("Etudiant introuvable\n ");
                        }
                        
                    }
                    fclose(etud_fic);
                break;
            case 4:
                break;
        }//fin du switch
    
}//fin de la fontion menu_ajout_note

void modifier_note(tnote note)
{
    begin_modif:
    printf("N° Id Etudiant : ");
            scanf("%d",&student_research);
            note_fic = fopen("note.csv","r+");
            x = 0;
            y = 0;
            printf("N° Reference Matiere : ");
            scanf("%d",&mat_research);
            while(fgets(chaine,150,note_fic) != NULL)
            {   
                for(i=0;i<=strlen(chaine);i++)
                {   numero[i] = '\0';
                    if(chaine[i] == '|')
                    {
                        break;
                    }
                    else
                    {
                        numero[i] = chaine[i];/*recuperation du code de l'etudiant*/
                    }
                }
                note.id_etudiant = atoi(numero);
                if(note.id_etudiant == student_research)
                {  
                    x = 1;
                    mat_ref[0] = chaine[9];
                    mat_ref[1] = chaine[10];
                    note.id_matiere = atoi(mat_ref);
                    if(mat_research == note.id_etudiant)
                    {   
                        y = 1;
                        do
                        {
                        printf("Que voulez vous modifier : \n");
                        printf("1 - Note CC\n");
                        printf("2 - Note DS\n");
                        printf("Saisir : ");
                        scanf("%d",&choice2);
                        }
                        while((choice2 < 1)||(choice2 > 2));
                        switch (choice2)
                        {
                        case 1:
                            printf("Nouveau Note CC : ");
                            scanf("%f",&note.note_cc);
                            fseek(note_fic,-12,SEEK_CUR);
                            fprintf(note_fic,"%2.2f",note.note_cc);
                            printf("Opération reussie \n");
                            break;
                        case 2:
                            printf("Nouveau Note DS : ");
                            scanf("%f",&note.note_ds);
                            fseek(note_fic,-6,SEEK_CUR);
                            fprintf(note_fic,"%2.2f",note.note_ds);
                            printf("Opération reussie \n");
                            break;
                        }
                    }
                }
                 
            }fclose(note_fic);
            if(x == 0)
            {
                    printf("Etudiant introuvable !\n");
                    goto begin_modif;
            }
            if(y == 0)
            {
                printf("Matiere Introuvable \n");
                goto begin_modif;
            }
}//fin de la fontion modifier_note

void supression_note(tnote note)
{
        begin_suppression:
            printf("N° Id Etudiant : ");
            scanf("%d",&student_research);
            note_fic = fopen("note.csv","r+");
            x = 0;
            y = 0;
            printf("N° Reference Matiere : ");
            scanf("%d",&mat_research);
            while(fgets(chaine,150,note_fic) != NULL)
            {   
                for(i=0;i<=strlen(chaine);i++)
                {   numero[i] = '\0';
                    if(chaine[i] == '|')
                    {
                        break;
                    }
                    else
                    {
                        numero[i] = chaine[i];/*recuperation du code de l'etudiant*/
                    }
                }
                note.id_etudiant = atoi(numero);
                if(note.id_etudiant == student_research)
                {  
                    x = 1;
                    mat_ref[0] = chaine[9];
                    mat_ref[1] = chaine[10];
                    note.id_matiere = atoi(mat_ref);
                    if(mat_research == note.id_matiere)
                    {   
                        y = 1;
                        fseek(note_fic,-strlen(chaine),SEEK_CUR);
                        for(j =0 ;j<=strlen(chaine);j++)
                        {
                        fputc(' ',note_fic);
                        if( j == strlen(chaine))
                        {
                        fseek(note_fic,-strlen(chaine),SEEK_CUR);
                        break;
                        }
                        }
                    }
                }
                 
            }fclose(note_fic);
            if(x == 0)
            {
                    printf("Etudiant introuvable !\n");
                    goto begin_suppression;
            }
            if(y == 0)
            {
                printf("Matiere Introuvable \n");
                goto begin_suppression;
            }

}//fin de la fontion supression_note

void affichage_note(tnote note)
{
    do
        {
        printf("\n Affichage de Note\n\n");
        printf("1 - Affichage de note d'un Etudiant\n");
        printf("2 - Affichage des notes d'un Etudiant dans toutes les matieres\n");
        printf("3 - Affichage des notes d'une classe dans une matiere\n");
        printf("4 - Revenir au menu precedent\n");
        printf("Saisir : ");
        scanf("%u",&choice3);
        }
    while((choice3 < 1)|| (choice3 > 4));
        switch (choice3)
        {
    case 1:
            afficher:
            x=1;
            printf("N° Id Etudiant : ");
            scanf("%d",&student_research);
            note_fic = fopen("note.csv","r");
            while(fgets(chaine,150,note_fic) != NULL)
            {   
                for(i=0;i<=strlen(chaine);i++)
                {   numero[i] = '\0';
                    if(chaine[i] == '|')
                    {
                        break;
                    }
                    else
                    {
                        numero[i] = chaine[i];/*recuperation du code de l'etudiant*/
                    }
                }
                note.id_etudiant = atoi(numero);
                if(note.id_etudiant == student_research)
                {
                    x = 1;
                }
                 
            }
            if(x == 0)
            {
                    printf("Etudiant introuvable !\n");
                    goto afficher;
            }
            recherche:
            printf("N° Reference Matiere : ");
            scanf("%d",&mat_research);
            note_fic = fopen("note.csv","r");
            while(fgets(chaine,150,note_fic) != NULL)
            {   
                numero[0] = chaine[10];
                numero[1] = chaine[11];
                numero[2] = '\0';
                note.id_matiere = atoi(numero);
                if(note.id_matiere == mat_research)
                {
                    x = 1;
                    printf("%s",chaine);
                }
                 
            }
            if(x == 0)
            {
                    printf("Matiere introuvable !\n");
                    goto afficher;
            }
            fclose(note_fic);
            break;
            case 2:
            note_fic = fopen("note1.csv","r");
            if (note_fic == NULL)
            {
                printf("Ouverture impossible \n");
            }
            else
            {
                while(fgets(chaine,150,note_fic) != NULL)
                {
                    printf("%s",chaine);
                }
            }
            fclose(note_fic);
            break;
            case 3:
            note_fic = fopen("note2.csv","r");
            if (note_fic == NULL)
            {
                printf("Ouverture impossible \n");
            }
            else
            {
                while(fgets(chaine,150,note_fic) != NULL)
                {
                    printf("%s",chaine);
                }
            }
            fclose(note_fic);
            break;
            case 4:
            menu_ajout_note(note);
            break;
        }//fin du switch
}//fin de la fonction affichage_note
void Gestion_note(tnote note)
{
    do
  {
    Menu_Note: Menu_note();
    scanf("%d",&choice4);
  }while((choice4 >= 6)||(choice4 <= 0));
      switch (choice4)
        {
          case 1: menu_ajout_note(note);  
          break;
          case 2: modifier_note(note);
          break;
          case 3: supression_note(note);
          break ;
          case 4: affichage_note(note);
          break ;
          case 5: main();
          break ;
        }
}
