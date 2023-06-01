#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"
#include "dataType.h"


//8
int main() {
	int odabir = 0;
	char ime[100];

	printf("__________________________________________________________________\n");
	printf("Izaberite sto zelite napraviti unosom broja opcije:\n\n");
	printf("1   Prikazi sve alate\n");
	printf("2   Prikazi cijenu zeljenog alata\n");
	printf("3   Prikazi alate sortirane po cijeni od najnize do najvise\n");
	printf("4   Promjeni kolicinu nekog alata u skladistu\n");
	printf("5   Brisanje nekog alata iz evidencije\n");
	printf("6   Dodavanje nekog alata u evidenciju\n");
	printf("__________________________________________________________________\n");
	 //4
	scanf("%d", &odabir);

	ALAT* poljeAlata = NULL;

	switch (odabir) {
	case 1:
		if (poljeAlata != NULL) {
			free(poljeAlata);
			poljeAlata = NULL;
		}

		poljeAlata = ucitajAlat(ime);

		ispisiSve(poljeAlata);
		break;

	case 2:
		if (poljeAlata != NULL) {
			free(poljeAlata);
			poljeAlata = NULL;
		}

		poljeAlata = ucitajAlate(ime);

		ALAT* pronadenAlat = pretraziAlate(poljeAlata);

		if (pronadenAlat != NULL) {
			printf("\n");
			printf("ID: %d\n", pronadenAlat->id);
			printf("Naziv: %s\n", pronadenAlat->naziv);
			printf("Kolicina: %d\n", pronadenAlat->kolicina);
			printf("Cijena: %d kn\n", pronadenAlat->cijena);
		}
		else {
			printf("Ne postoji alat s tim ID-em.\n");
		}

		break;
//13
	case 3:
		if (poljeAlata != NULL) {
			free(poljeAlata);
			poljeAlata = NULL;
		}

		poljeAlata = ucitajAlate(ime);

		ispisiSortirano(poljeAlata, 2);
		break;

	case 5:
		if (poljeAlata != NULL) {
			free(poljeAlata);
			poljeAlata = NULL;
		}

		poljeAlata = ucitajAlat(ime);

		dodavanjeAlata(poljeAlata, ime);
		break;

	case 6:
		if (poljeAlata != NULL) {
			free(poljeAlata);
			poljeAlata = NULL;
		}

		poljeAlata = ucitajAlate(ime);

		brisanjeAlata(poljeAlata, ime);
		break;

	default:
		free(poljeAlata);
		poljeAlata = NULL;
		odabir = 0;
	}

	return odabir;
}
