#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>



typedef struct Etudiant
{
    char nom[100];
    char prenom[100];
    int age;
    char sexe[100];
    char classe[100];
    char matricule[100];
}Etudiant;

//Fonction pour ajouter un étudiant

void ajouterEtudiant(FILE *fichier, struct Etudiant etudiant)
{
    fichier = fopen("etudiant.bin", "a");
    if(fichier != NULL)
    {
        fprintf(fichier, "%s %s %d %s %s %s\n", etudiant.nom, etudiant.prenom, etudiant.age, etudiant.sexe, etudiant.classe, etudiant.matricule);
        fclose(fichier);
    }
    else
    {
        printf("Impossible d'ouvrir le fichier\n");
    }
}

// Fonction pour modifier les informations d'un étudiant

void modifierEtudiant(FILE *fichier, int id, struct Etudiant etudiant)
{
    fichier = fopen("etudiant.bin", "r+");
    if(fichier != NULL)
    {
        fseek(fichier, id * sizeof(struct Etudiant), SEEK_SET);
        fprintf(fichier, "%s %s %d %s %s %s\n", etudiant.nom, etudiant.prenom, etudiant.age, etudiant.sexe, etudiant.classe, etudiant.matricule);
        fclose(fichier);
    }
    else
    {
        printf("Impossible d'ouvrir le fichier\n");
    }
}


// Fonction pour supprimer un étudiant

void supprimerEtudiant(FILE *fichier, int id)
{
    fichier = fopen("etudiant.bin", "r+");
    if(fichier != NULL)
    {
        fseek(fichier, id * sizeof(struct Etudiant), SEEK_SET);
        fprintf(fichier, "%s %s %d %s %s %s\n", "", "", 0, "", "", "");
        fclose(fichier);
    }
    else
    {
        printf("Impossible d'ouvrir le fichier\n");
    }
}


// Fonction pour afficher les informations  étudiants

void afficherEtudiants(FILE *fichier)
{
    fichier = fopen("etudiant.bin", "r");
    if(fichier != NULL)
    {
        struct Etudiant etudiant;
        int i = 0;
        while(fscanf(fichier, "%s %s %d %s %s %s\n", etudiant.nom, etudiant.prenom, &etudiant.age, etudiant.sexe, etudiant.classe, etudiant.matricule) != EOF)
        {
            if(strcmp(etudiant.nom, "") != 0)
            {
                printf("Etudiant %d : %s %s %d %s %s %s\n", i, etudiant.nom, etudiant.prenom, etudiant.age, etudiant.sexe, etudiant.classe, etudiant.matricule);
                i++;
            }
        }
        fclose(fichier);
    }
    else
    {
        printf("Impossible d'ouvrir le fichier\n");
    }
}

int main()
{
    FILE *fichier = NULL;
    struct Etudiant etudiant;
    strcpy(etudiant.nom, "Diallo");
    strcpy(etudiant.prenom, "Mamadou");
    etudiant.age = 20;
    strcpy(etudiant.sexe, "Masculin");
    strcpy(etudiant.classe, "L3");
    strcpy(etudiant.matricule, "20MD001");
    ajouterEtudiant(fichier, etudiant);
    afficherEtudiants(fichier);
    return 0;
}

