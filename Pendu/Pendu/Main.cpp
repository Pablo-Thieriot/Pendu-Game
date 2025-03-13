#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
#include "Header.h"
#include"GestionDico.h"
#define _CRT_SECURE_NO_WARNINGS

int main(int argc, const char* argv[])
{
	char lettre = 0;
	char motSecret[100] = { 0 };
	int* lettreTrouvee = NULL;
	int coupRestant = 10;
	//int nombreLettres/*= taille du mot*/ = tailleMot(motSecret); /*égale au nombre de lettre (5 pour l'ex)*/

	int i = 0;
	int tailleMot = 0;
	//lettreTrouvee = (int *)malloc(nombreLettres * sizeof(int));
	//initTableau(lettreTrouvee, nombreLettres);


	printf("Bienevenue dans le Pendu\nBonne chance !\n");

	if (!piocherMot(motSecret))
		exit(0);
	tailleMot = strlen(motSecret);


	lettreTrouvee = (int*)malloc(tailleMot * sizeof(int));/*on alloue dynamiquement le tableau lettreTrouvee maintenant qu'on à la taille*/
	if (lettreTrouvee == NULL)
		exit(0);

	for (i = 0; i < tailleMot; i++)
		lettreTrouvee[i] = 0;


	while (coupRestant > 0 && !gagne(lettreTrouvee, tailleMot))
	{
		printf("\n\nIl vous reste %d coups a jouer", coupRestant);
		printf("\nQuel est le mot secret ? ");

		for (i = 0; i < tailleMot; i++)
		{
			if (lettreTrouvee[i])
			{
				printf("%c", motSecret[i]);
			}
			else
				printf("*");
		}
		printf("\nProposez une lettre : ");
		lettre = lireCaractere();
		if (!rechercheLettre(lettre, motSecret, lettreTrouvee))
		{
			coupRestant--;
		}
	}
	if (gagne(lettreTrouvee, tailleMot))
	{
		printf("\n\nGagne ! Le mot secret etait bien : %s", motSecret);
	}
	else
		printf("\n\nNullos ! Le mot secret etait : %s", motSecret);

	free(lettreTrouvee);
	return 0;
}

int rechercheLettre(char lettre, char motSecret[], int lettreTrouvee[])
{
	int i = 0, bonneLettre = 0;

	for (i = 0; motSecret[i] != '\0'; i++)
	{
		if (lettre == motSecret[i])
		{
			bonneLettre = 1;
			lettreTrouvee[i] = 1;
		}
	}
	return bonneLettre;
}
char lireCaractere()
{
	char caractere = 0;

	caractere = getchar();

	while (getchar() != '\n');

	return caractere;
}

int tailleMot(char motSecret[])
{
	int nombreLettres = 0;
	int i = 0;
	for (i = 0; motSecret[i] !='\0'; i++)
	{
		nombreLettres++;	
	}
	return nombreLettres;
}

void initTableau(int* lettreTrouvee, int taille)
{
	for (int i = 0; i < taille; i++)
	{
		lettreTrouvee[i] = 0;
	}
}

int gagne(int lettreTrouvee[], int tailleMot)
{
	int i = 0;
	int joueurGagne = 1;

	for (i = 0; i < tailleMot; i++)
	{
		if (lettreTrouvee[i] == 0)
			joueurGagne = 0;
	}
	return joueurGagne;
}