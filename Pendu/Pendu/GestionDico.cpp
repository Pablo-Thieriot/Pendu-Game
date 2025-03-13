#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>	
#include"GestionDico.h"
#define _CRT_SECURE_NO_WARNINGS

int nombreAleatoire(int nombreMax)
{
	srand(time(NULL));
	return (rand() % nombreMax);
	
}

int piocherMot(char* motPiocher)
{
	FILE* dico = NULL;
	int nombreMots = 0;
	int numMotChoisi, i = 0;
	int caractereLu = 0;

	dico = fopen("dico.txt.txt", "r"); /*On ouvre le dico en lecture seul*/
	if(dico == NULL)/*l'ouverture a fail*/
	{
		printf("\nL'ouverture du fichier du dictionnaire a rate");
		return 0;
	}
	
	do
	{
		caractereLu = fgetc(dico);
		if (caractereLu == '\n')
			nombreMots++;/*22735 normalement*/
	} while (caractereLu != EOF);


	numMotChoisi = nombreAleatoire(nombreMots);/*on prend un mot random*/

	rewind(dico);
	while (numMotChoisi > 0)
	{
		caractereLu = fgetc(dico);
		if (caractereLu == '\n')
			numMotChoisi--;
	}
	/*Maintenant le curseur est au bon endroit*/
	fgets(motPiocher, 100, dico);
		motPiocher[strlen(motPiocher) - 1] = '\0';

	fclose(dico);
		
	return 1; /*Tout est OK, on return 1*/
	
}