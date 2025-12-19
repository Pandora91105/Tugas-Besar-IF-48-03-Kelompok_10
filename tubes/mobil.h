#ifndef MOBIL_H_INCLUDED
#define MOBIL_H_INCLUDED
#include <iostream>
#include "string"
#include "sales.h"
using namespace std;


typedef struct elmMobil *adrMobil;

struct mobil {
    string warna;
    string Merk;
    int stock;
};

struct elmMobil {
    mobil info;
    adrMobil next, prev;
    adrSales firstSales;
};

struct listMobil {
    adrMobil first, last;
};


void createListMobil(listMobil &L);
adrMobil createElmMobil(string merk, string warna, int stok);
void insertFirstMobil(listMobil &L, adrMobil p);
void insertLastMobil(listMobil &L, adrMobil p);
void insertAfterMobil(listMobil &L, adrMobil p, adrMobil prec);
void deleteFirstMobil(listMobil &L, adrMobil &p);
void deleteLastMobil(listMobil &L, adrMobil &p);
void deleteAfterMobil(listMobil &L, adrMobil &p, adrMobil prec);
adrMobil findElmMobil(listMobil L, string x);
void viewMobil(listMobil L);
void mobilTerjualan(listSales sales, listMobil mobil);


#endif // MOBIL_H_INCLUDED

