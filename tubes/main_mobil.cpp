#include <iostream>
#include "mobil.h"
#include "sales.h"
#include "string"

using namespace std;

void createListMobil(listMobil &L){
    L.first = nullptr;
    L.last = nullptr;
}

adrMobil createElmMobil(string merk, string warna, int stok ){
    adrMobil p = new elmMobil;
    p->info.Merk = merk;
    p->info.warna = warna;
    p->info.stock = stok;
    p->next = nullptr;
    p->prev = nullptr;
    p->firstSales = nullptr;

    return p;
}

void insertFirstMobil (listMobil &L, adrMobil p){
    if(L.first == nullptr  && L.last == nullptr){
        L.first = p;
        L.last = p;
    }else{
        p->next = L.first;
        L.first->prev = p;
        L.first = p;
    }
}

void insertLastMobil(listMobil &L, adrMobil p){
    if(L.first == nullptr  && L.last == nullptr){
        L.first = p;
        L.last = p;
    }else{
        p->prev = L.last;
        L.last->next = p;
        L.last = p;
    }
}

void insertAfterMobil(listMobil &L, adrMobil p, adrMobil prec){
    if (L.first == nullptr && L.last == nullptr){
        L.first = p;
        L.last = p;
    }else if (L.first == L.last){
        p->prev = L.last;
        L.last->next = p;
        L.last = p;
    }else {
        p->next = prec->next;
        p->prev = prec;
        prec->next->prev = p;
        prec->next = p;
    }
}

void deleteFirstMobil(listMobil &L, adrMobil &p){
    if (L.first == nullptr && L.last == nullptr){
        cout << "List Kosong" << endl;
    }else if(L.first == L.last){
        p = L.first;
        L.first = nullptr;
        L.last = nullptr;
    }else{
        p = L.first;
        L.first = p->next;
        p->next = nullptr;
    }
}

void deleteLastMobil(listMobil &L, adrMobil &p){
    if (L.first == nullptr && L.last == nullptr){
        cout << "List Kosong" << endl;
    }else if(L.first == L.last){
        p = L.first;
        L.first = nullptr;
        L.last = nullptr;
    }else{
        p = L.last;
        L.last = p->prev;
        p->prev = nullptr;
    }
}

void deleteAfterMobil(listMobil &L, adrMobil &p, adrMobil prec){
    if (L.first == nullptr && L.last == nullptr){
        cout << "List Kosong" << endl;
    }else if(L.first == L.last){
        p = L.first;
        L.first = nullptr;
        L.last = nullptr;
    }else{
        p = prec->next;
        prec->next = p->next;
        p->next->prev = prec;
        p->next = nullptr;
        p->prev = nullptr;
    }
}

adrMobil findElmMobil(listMobil L, string x){
    adrMobil p = L.first;
    while (p->next != nullptr && p->info.Merk != x ){
        p = p->next;
    }
    return p;
}

void viewMobil(listMobil L){
    adrMobil p = L.first;
    while(p != nullptr){
        cout << p ->info.Merk << endl;
        cout << p ->info.stock << endl;
        cout << p ->info.warna << endl;
        p = p ->next;
    }
}

void mobilTerjualan(listSales sales, listMobil mobil){
    adrMobil y = mobil.first;
    adrSales p;
    int total = 0;
    int sum = 0;
    while (y != nullptr){
        p = y->firstSales;
        while (p != nullptr){
            total++;
            p = p->next;
        }
        cout << "Total " << y->info.Merk << "Terjual : " << total << endl;
        sum = sum + total;
        y = y->next;
    }
    cout << "Total seluruh mobil terjual : "<< sum << endl;
}
