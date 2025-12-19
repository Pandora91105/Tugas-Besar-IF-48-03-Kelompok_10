#include <iostream>
#include "mobil.h"
#include "string"

using namespace std;

void createListSales(listSales &L){
    L.first = nullptr;
}

adrSales createElmSales(string nama, string kode, int penjualan ){
    adrSales p = new elmSales;
    p->info.Nama = nama;
    p->info.penjualan = penjualan;
    p->info.kode = kode;
    p->next = nullptr;

    return p;
}

void insertFirstSales(adrMobil &p, adrSales q){
    if(p ->firstSales == nullptr){
        p ->firstSales = q;
    }else {
        q ->next = p ->firstSales;
        p ->firstSales = q;
    }
}


void insertLastSales(adrMobil &p, adrSales q){
    if (p->firstSales == nullptr){
        p->firstSales = q;
    }else{
        adrSales x = p->firstSales;
        while (x->next != nullptr){
            x = x->next;
        }
        x->next = q;
    }
}

void insertAfterSales(adrMobil &p, adrSales q, adrSales prec){
    if (p->firstSales == nullptr){
        p->firstSales = q;
    }else if (p->firstSales->next == nullptr){
        p->firstSales->next = q;
    }else{
        q->next = prec->next;
        prec->next = q;
    }
}

void deleteFirstSales(adrMobil &p, adrSales q){
    if (p->firstSales == nullptr){
        cout << "Sales Kosong";
    }else if (p->firstSales->next == nullptr){
        q = p->firstSales;
        p->firstSales == nullptr;
    }else{
        q = p->firstSales->next;
        p->firstSales = nullptr;
    }
}

void deleteLastSales(adrMobil &p, adrSales q){
    if (p->firstSales == nullptr){
        cout << "Sales kosong";
    }else if (p->firstSales->next == nullptr){
        q = p->firstSales;
        p->firstSales == nullptr;
    }else {
        adrSales x = p->firstSales;
        while (x->next->next != nullptr){
            x = x->next;
        }
        q = x->next;
        x->next = nullptr;
    }
}

void deleteAfterSales(adrMobil &p, adrSales q, adrSales prec){
    if (p->firstSales == nullptr){
        cout << "Sales Kosong";
    }else if (p->firstSales->next == nullptr){
        cout << "sales hanya 1 orang";
    }else{
        q = prec->next;
        prec = prec->next;
        q->next = nullptr;
    }
}

adrSales findSales(adrMobil p, string kode){
    adrSales q = p->firstSales;
    while (q->info.kode != kode && q != nullptr){
        q = q->next;
    }
    return q;
}

void viewSales(listMobil L){
    adrMobil p = L.first;

    while (p != nullptr){
        cout << p ->info.Merk << endl;
        cout << p ->info.stock << endl;
        cout << p ->info.warna << endl;
        adrSales q = p->firstSales;
        while (q != nullptr){
            cout << "==================================================";
            cout << "|| Nama sales : " << q->info.Nama << " ||" << endl;
            cout << "|| kode sales : " << q->info.kode << " ||" << endl;
            cout << "|| Performa : " << q->info.penjualan << " penjualan" << " ||"<<endl;
            q = q->next;
        }
        p = p->next;
    }
}

void performaSales(listSales sales, listMobil mobil, string kode){
    adrMobil y = mobil.first;
    adrSales p;
    int total = 0;
    int sum = 0;
    while (y != nullptr){
        p = y->firstSales;
        while (p != nullptr){
            if (p->info.kode == kode){
                total++;
            }
            p = p->next;
        }
        cout << "Total " << y->info.Merk << "Terjual : " << total << endl;
        sum = sum + total;
        y = y->next;
    }
    cout << "Total penjualan sales dengan kode " << kode << " : " << sum << endl;
}
