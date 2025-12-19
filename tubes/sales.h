#ifndef SALES_H_INCLUDED
#define SALES_H_INCLUDED
#include <iostream>
#include "string"

using namespace std;

typedef struct elmSales *adrSales;
typedef struct elmMobil *adrMobil;
struct listMobil;

struct sales {
    string Nama;
    int penjualan;
    string kode;
};

struct elmSales {
    sales info;
    adrSales next;
};
 struct listSales{
    adrSales first;
 };

void createListSales(listSales &L);
adrSales createElmSales( string nama, string kode, int penjualan);
void insertFirstSales(adrMobil &p, adrSales q);
void insertLastSales(adrMobil &p, adrSales q);
void insertAfterSales(adrMobil &p, adrSales q, adrSales prec);
void deleteFirstSales(adrMobil &p, adrSales q);
void deleteLastSales(adrMobil &p, adrSales q);
void deleteAfterSales(adrMobil &p, adrSales q, adrSales prec);
adrSales findSales(adrMobil p, string kode);
void viewSales(listMobil L);
void performaSales(listSales sales, listMobil mobil, string kode);
#endif // SALES_H_INCLUDED
