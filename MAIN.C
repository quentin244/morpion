#include <stdio.h>
#include <stdlib.h>
#define DimTabl 13

char tableau[DimTabl][DimTabl];
int Joueur = 'O';
int N = 3;
int Z = 1;
int pointRond = 0;
int pointCroix = 0;
int ligne = 0;
int col = 0;

void initialiser()
{

    int saisieCorrecte = 0;
    do
    {
        printf("\nNombre de pion a aligner avant de gagner un point: ");
        scanf("%d", &N);

        if ((N > 0) && (N < DimTabl))
        {
            printf("\nNombre de point a avoir pour gagner la partie: ");
            scanf("%d", &Z);
            if ((Z > 0) && (Z < DimTabl))
            {
                saisieCorrecte = 1;
            }
            else
            {
                printf("\nNombre incorrect. Veuillez recommencer:");
            }
        }
        else
        {
            printf("\nNombre incorrect. Veuillez recommencer:");
        }
    }
    while (!saisieCorrecte);

    int i;
    int j;
    for(i=0; i<DimTabl; i++)
    {
        for(j=0; j<DimTabl; j++)
        {
            tableau[i][j] = ' ' ;
        }
    }
}

int affichertab()
{
    int i, j;
    for (i=0; i<DimTabl; i++)
    {
        for (j=0; j<DimTabl; j++)
        {
            switch (tableau[i][j])
            {
            case ' ':
                printf("_ ");
                break;
            case 'O':
                printf("O ");
                break;
            case 'X':
                printf("X ");
                break;
            }
        }
        printf("\n");
    }
    return 0;
}

void metUnPionSurTab()
{
    int saisieCorrecte = 0;
    printf("\nNumeros de ligne et de colonne: ");

    do
    {
        scanf("%d %d", &ligne, &col);
        printf("\n""\n");

        if ((ligne > 0) && (ligne <= DimTabl) && (col > 0) && (col <= DimTabl))
        {
            ligne--;
            col--;
            if (tableau[ligne][col] != ' ')
                printf("\nCette case a deja ete remplie. Veuillez recommencer: ");
            else
            {
                saisieCorrecte = 1;
                tableau[ligne][col] = Joueur;
            }
        }
        else
        {
            printf("\nIndice de ligne ou de colonne incorrect. Veuillez recommencer:");
        }
    }
    while (!saisieCorrecte);
}

int testePointGagner()
{
    int joueurGagnant;
    int PointFini = 0;

    int i = ligne;
    int j = col;

    while(tableau[i][j] == tableau[i-1][j])
    {
        i--;
    }

    int pionAligner = 0;

    while (i<DimTabl)
    {
        if (tableau[i][j] == ' ')
        {
            pionAligner = 0;
        }
        else if(tableau[i][j] == tableau[i+1][j])
        {
            pionAligner++;
        }
        else
        {
            pionAligner = 0;
        }

        if(pionAligner >= N -1)
        {
            joueurGagnant = tableau[ligne][col];
            PointFini = 1;
        }
        i++;
    }

    i = ligne;
    j = col;

    while(tableau[i][j] == tableau[i][j - 1])
    {
        j--;
    }
    pionAligner = 0;

    while (j<DimTabl)
    {
        if (tableau[i][j] == ' ')
        {
            pionAligner = 0;
        }
        else if(tableau[i][j] == tableau[i][j+1])
        {
            pionAligner++;
        }
        else
        {
            pionAligner = 0;
        }

        if(pionAligner >= N -1)
        {
            joueurGagnant = tableau[ligne][col];
            PointFini = 1;
        }
        j++;
    }


    i = ligne;
    j = col;
    while(tableau[i][j] == tableau[i-1][j-1])
    {
        i--;
        j--;
    }
    pionAligner = 0;

    while (i<DimTabl)
    {
        if (tableau[i][j] == ' ')
        {
            pionAligner = 0;
        }
        else if(tableau[i][j] == tableau[i+1][j+1])
        {
            pionAligner++;
        }
        else
        {
            pionAligner = 0;
        }

        if(pionAligner >= N -1)
        {
            joueurGagnant = tableau[ligne][col];
            PointFini = 1;
        }
        i++;
        j++;
    }


    i = ligne;
    j = col;
    while(tableau[i][j] == tableau[i+1][j-1])
    {
        i++;
        j--;
    }
    pionAligner = 0;

    while (i>0)
    {

        if (tableau[i][j] == ' ')
        {
            pionAligner = 0;
        }
        else if(tableau[i][j] == tableau[i-1][j+1])
        {
            pionAligner++;
        }
        else
        {
            pionAligner = 0;
        }

        if(pionAligner >= N -1)
        {
            joueurGagnant = tableau[ligne][col];
            PointFini = 1;
        }
        i--;
        j++;
    }


    if (PointFini)
    {
        printf("\nFelicitations au joueur ayant les ");
        if (joueurGagnant == 'O')
        {
            printf("ronds ");
            pointRond = pointRond +1;
            printf("\nNombre de points : %d ", pointRond);

            if ((pointRond % 2) == 1)
            {
                printf("\nChangement de pion");
                Joueur = 'O';
            }
            else
            {
                Joueur = 'X';
            }
        }

        else
        {
            printf("croix ");
            pointCroix = pointCroix +1;
            printf("\nNombre de points : %d ", pointCroix);

            if ((pointCroix % 2) == 1)
            {
                printf("\nChangement de pion");
                Joueur = 'X';
            }
            else
            {
                Joueur = 'O';
            }
        }
        PointFini = 0;
    }

    else {
        if (Joueur == 'O'){
            Joueur = 'X';
        }
        else if(Joueur == 'X') {
            Joueur = 'O';
        }
    }

    PointFini = 0;
    return 0;
}

int testeFinJeu()
{
    if((pointCroix == Z)|| (pointRond == Z))
    {
        return 1;
    }

    int i,j;
    for (i=0; i<DimTabl; i++)
    {
        for (j=0; j<DimTabl; j++)
        {
            if (tableau[i][j] == ' ')
            {
                return 0;
            }
        }
    }
    return 1;
}

int main()
{
    initialiser();
    affichertab();
    do
    {
        metUnPionSurTab();
        affichertab();
        testePointGagner();
    }
    while(!testeFinJeu());
    printf("\nFin de la partie");
    printf("\nNombre de points Rond : %d", pointRond);
    printf("\nNombre de points Croix : %d", pointCroix);
    return 0;
}
