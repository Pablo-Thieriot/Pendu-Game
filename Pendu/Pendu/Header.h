#pragma once

int tailleMot(char motSecret[]);

void initTableau(int* lettreTrouvee, int taille);

int gagne(int* lettreTrouvee, int nombreLettres);

char lireCaractere();

int rechercheLettre(char lettre, char motSecret[], int* lettreTrouvee);