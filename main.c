#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "functions.h"

int main(void) {

	srand((unsigned)time(NULL));

	int odabir = 1;

	char* datoteka = "trgovina.bin";

	kreiranjeDatoteke(datoteka);

	while (odabir)
	{
		odabir = izbornik(datoteka);
	}

	printf("Kraj programa");

	return 0;
}
