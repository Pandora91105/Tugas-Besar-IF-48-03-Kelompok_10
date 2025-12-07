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


#endif // MOBIL_H_INCLUDED
