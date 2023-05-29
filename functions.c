#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dataType.h"
#include "functions.h"

static int brojAlata = 0;

void kreiranjeDatoteke(const char* const ime) {

	FILE* fp = fopen(ime, "rb");


	if (fp == NULL) {
		fp = fopen(ime, "wb");

		fwrite(&brojAlata, sizeof(int), 1, fp);

		fclose(fp);
	}
	else {
		fclose(fp);
	}

}

void dodajAlat(const char* const ime) {

	FILE* fp = fopen(ime, "rb+");

	if (fp == NULL) {
		perror("Dodavanje alata u datoteku");
		exit(EXIT_FAILURE);
	}


	fread(&brojAlata, sizeof(int), 1, fp);
	printf("Broj alata: %d\n\n", brojAlata);

	ALAT temp = { 0 };
	temp.id = brojAlata + 1;

	getchar();
	printf("Unesite naziv alata: ");
	scanf("%24[^\n]", temp.naziv);

	getchar();
	printf("Unesite kategoriju alata: ");
	scanf("%24[^\n]", &temp.kategorija);

	getchar();
	printf("Unesite kolicinu: ");
	scanf("%d", &temp.kolicina);

	getchar();
	printf("Unesite cijenu: ");
	scanf("%d", &temp.cijena);

	
	fseek(fp, sizeof(ALAT) * brojAlata, SEEK_CUR);
	fwrite(&temp, sizeof(ALAT), 1, fp);
	printf("Novi alat dodan.\n\n");


	rewind(fp);
	brojAlata++;


	fwrite(&brojAlata, sizeof(int), 1, fp);

	fclose(fp);
}

void* ucitajAlate(const char* const ime) {

	FILE* fp = fopen(ime, "rb");

	if (fp == NULL) {
		perror("Ucitavanje alata iz datoteke");
		return NULL;
		exit(EXIT_FAILURE);
	}

	fread(&brojAlata, sizeof(int), 1, fp);
	printf("Broj alata: %d\n", brojAlata);

	ALAT* poljeAlata = (ALAT*)calloc(brojAlata, sizeof(ALAT));

	if (poljeAlata == NULL) {
		perror("Zauzimanje memorije za alate");
		return NULL;
		exit(EXIT_FAILURE);
	}

	fread(poljeAlata, sizeof(ALAT), brojAlata, fp);

	printf("Svi alati uspjesno ucitani.\n\n");

	return poljeAlata;
}

void ispisiSve(const ALAT* polje) {

	if (brojAlata == 0) {
		printf("Polje alata je prazno\n");
		return;
	}

	int i;

	for (i = 0; i < brojAlata; i++) {
		printf("ID: %d\nNaziv alata: %s\nKategorija: %s\nKolicina: %d\nCijena %d kn\n\n",
			(polje + i)->id,
			(polje + i)->naziv,
			(polje + i)->kategorija,
			(polje + i)->kolicina,
			(polje + i)->cijena);
	}
}

void* pretraziAlate(ALAT* const polje) {

	if (brojAlataa == 0) {
		printf("Polje alata je prazno\n");
		return;
	}

	int i;

	int trazeniId;


	printf("Unesite ID alata koji trazite: \n");
	scanf("%d", &trazeniId);

	
	for (i = 0; i < brojAlata; i++) {

		if (trazeniId == (polje + i)->id) {
			printf("Alat pronaden\n");

			return (polje + i);
		}
	}
	return NULL;
}

void zamjena(ALAT* const veci, ALAT* const manji) {
	ALAT temp = { 0 };
	temp = *manji;
	*manji = *veci;
	*veci = temp;
}

void* sortirajPoKolicini(const ALAT* polje) {

	int min = -1;

	for (int i = 0; i < brojAlata - 1; i++) {

		min = i;
		for (int j = i + 1; j < brojAlata; j++) {

			if ((polje + j)->kolicina < (polje + min)->kolicina) {
				min = j;
			}
		}

		zamjena((polje + i), (polje + min));
	}

	return polje;
}

void* sortirajPoCijeni(const ALAT* polje) {

	int min = -1;

	for (int i = 0; i < brojAlata - 1; i++) {

		min = i;
		for (int j = i + 1; j < brojAlata; j++) {

			if ((polje + j)->cijena < (polje + min)->cijena) {
				min = j;
			}
		}

		zamjena((polje + i), (polje + min));
	}

	return polje;
}

void ispisiSortirano(const ALAT* polje, int po) {

	if (brojAlata == 0) {
		printf("Polje alata je prazno\n");
		return;
	}

	int i;

	if (po == 1)
	{
		polje = sortirajPoKolicini(polje);
	}
	else if (po == 2)
	{
		polje = sortirajPoCijeni(polje);
	}
	else
	{
		return;
	}


	for (i = 0; i < brojAlata; i++) {
		printf("\nID: %d\nNaziv alata: %s\nKategorija: %s\nKolicina: %d\nCijena %d kn\n\n",
			(polje + i)->id,
			(polje + i)->naziv,
			(polje + i)->kategorija,
			(polje + i)->kolicina,
			(polje + i)->cijena);
	}
}
