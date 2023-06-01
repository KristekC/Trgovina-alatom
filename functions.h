#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include "dataType.h"

//6
//9
//10

int	 menu(const char* const);
void kreiranjeDatoteke(const char* const);
void dodavanjeAlata(const char* const);
void* ucitajAlate(const char* const);
void ispisiSve(const ALAT*);
void ispisiSortirano(const ALAT*);
void uredivanjeAlata(ALAT* const, const char* const);
void brisanjeAlata(ALAT* const, const char* const);
void* pretraziAlate(ALAT* const);

#endif


