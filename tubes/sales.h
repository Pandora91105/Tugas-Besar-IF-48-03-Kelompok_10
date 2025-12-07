#ifndef SALES_H_INCLUDED
#define SALES_H_INCLUDED
#include <iostream>
#include "string"

using namespace std;

typedef struct elmSales *adrSales;

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
#endif // SALES_H_INCLUDED
