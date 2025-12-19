#include <iostream>
#include "MOBIL.h"
#include "SALES.h"

using namespace std;

int main() {
    listMobil Lmobil;
    listSales Lsales;
    adrMobil pMobil, pMobilTarget, pMobilPrev;
    adrSales pSales, pSalesTarget, pSalesPrev;

    createListMobil(Lmobil);

    int pilih;
    string merk, warna, namaSales, kodeSales, merkTarget, kodeTarget;
    int stok, penjualan;

    do {
        cout << "\n===============================================\n";
        cout << "           SISTEM MANAJEMEN DEALER MOBIL       \n";
        cout << "===============================================\n";
        cout << "1.  Kelola Data Mobil                       ||\n";
        cout << "2.  Kelola Data Sales                       ||\n";
        cout << "3.  Tampilkan Semua Data Mobil & Sales      ||\n";
        cout << "4.  Cari Data                               ||\n";
        cout << "5.  Komputasi & Laporan                     ||\n";
        cout << "0.  Keluar                                  ||\n";
        cout << "===============================================\n";
        cout << "Pilih menu: ";
        cin >> pilih;

        switch (pilih) {
        case 1:
            do {
                cout << "\n========= KELOLA DATA MOBIL ===========\n";
                cout << "|| 1.  Tambah Mobil (Insert First)  ||\n";
                cout << "|| 2.  Tambah Mobil (Insert After)  ||\n";
                cout << "|| 3.  Tambah Mobil (Insert Last)   ||\n";
                cout << "|| 4.  Hapus Mobil (Delete First)   ||\n";
                cout << "|| 5.  Hapus Mobil (Delete After)   ||\n";
                cout << "|| 6.  Hapus Mobil (Delete Last)    ||\n";
                cout << "|| 7.  Hapus Mobil berdasarkan Merk ||\n";
                cout << "|| 8.  Kembali ke Menu Utama        ||\n";
                cout << "=========================================\n";
                cout << "Pilih: ";
                cin >> pilih;

                switch (pilih) {
                case 1:
                    cout << "\n-- TAMBAH MOBIL (INSERT FIRST) --\n";
                    cout << "Merk Mobil  : ";
                    cin >> merk;
                    cout << "Warna       : ";
                    cin >> warna;
                    cout << "Stok        : ";
                    cin >> stok;

                    pMobil = createElmMobil(merk, warna, stok);
                    insertFirstMobil(Lmobil, pMobil);
                    cout << "Mobil berhasil ditambahkan di awal list!\n";
                    break;

                case 2:
                    cout << "\n-- TAMBAH MOBIL (INSERT AFTER) --\n";
                    cout << "Masukkan merk mobil sebagai patokan : ";
                    cin >> merkTarget;
                    pMobilTarget = findElmMobil(Lmobil, merkTarget);

                    if (pMobilTarget != nullptr) {
                        cout << "\nData mobil baru:\n";
                        cout << "Merk Mobil  : ";
                        cin >> merk;
                        cout << "Warna       : ";
                        cin >> warna;
                        cout << "Stok        : ";
                        cin >> stok;
                        pMobil = createElmMobil(merk, warna, stok);
                        if (pMobilTarget->next == nullptr){
                            insertLastMobil(Lmobil, pMobil);
                        }else{
                            insertAfterMobil(Lmobil, pMobil, pMobilTarget);
                        }
                        cout << "Mobil berhasil ditambahkan setelah " << merkTarget << "!\n";
                    } else {
                        cout << "Mobil referensi tidak ditemukan!\n";
                    }
                    break;

                case 3:
                    cout << "\n-- TAMBAH MOBIL (INSERT LAST) --\n";
                    cout << "Merk Mobil  : ";
                    cin >> merk;
                    cout << "Warna       : ";
                    cin >> warna;
                    cout << "Stok        : ";
                    cin >> stok;

                    pMobil = createElmMobil(merk, warna, stok);
                    insertLastMobil(Lmobil, pMobil);
                    cout << "Mobil berhasil ditambahkan di akhir list!\n";
                    break;

                case 4:
                    if (Lmobil.first != nullptr) {
                        deleteFirstMobil(Lmobil, pMobil);
                        cout << "Mobil pertama berhasil dihapus!\n";
                        cout << "  (Merk: " << pMobil->info.Merk << ")\n";
                    } else {
                        cout << "List mobil kosong!\n";
                    }
                    break;

                case 5:
                    cout << "\n-- HAPUS MOBIL (DELETE AFTER) --\n";
                    cout << "Masukkan merk mobil sebagai referensi: ";
                    cin >> merkTarget;
                    pMobilTarget = findElmMobil(Lmobil, merkTarget);

                    if (pMobilTarget != nullptr && pMobilTarget->next != nullptr) {
                        deleteAfterMobil(Lmobil, pMobilTarget, pMobilTarget->next);
                        cout << "Mobil setelah " << merkTarget << " berhasil dihapus!\n";
                    } else if (pMobilTarget == nullptr) {
                        cout << "Mobil referensi tidak ditemukan!\n";
                    } else {
                        cout << "Tidak ada mobil setelah " << merkTarget << "!\n";
                    }
                    break;

                case 6:
                    if (Lmobil.first != nullptr) {
                        deleteLastMobil(Lmobil, pMobil);
                        cout << "Mobil terakhir berhasil dihapus!\n";
                        cout << "  (Merk: " << pMobil->info.Merk << ")\n";
                    } else {
                        cout << "List mobil kosong!\n";
                    }
                    break;

                case 7:
                    cout << "\n-- HAPUS MOBIL BERDASARKAN MERK --\n";
                    cout << "Masukkan merk mobil yang akan dihapus: ";
                    cin >> merk;

                    pMobil = findElmMobil(Lmobil, merk);
                    if (pMobil != nullptr) {

                        pMobilPrev = Lmobil.first;
                        while (pMobilPrev != nullptr && pMobilPrev->next != pMobil) {
                            pMobilPrev = pMobilPrev->next;
                        }

                        if (pMobil == Lmobil.first) {
                            deleteFirstMobil(Lmobil, pMobil);
                        } else if (pMobil == Lmobil.last) {
                            deleteLastMobil(Lmobil, pMobil);
                        } else {
                            deleteAfterMobil(Lmobil, pMobilPrev, pMobil);
                        }
                        cout << "Mobil " << merk << " berhasil dihapus!\n";
                    } else {
                        cout << "Mobil tidak ditemukan!\n";
                    }
                    break;

                case 8:
                    cout << "Kembali ke menu utama...\n";
                    break;

                default:
                    cout << "Pilihan tidak valid!\n";
                }

            } while (pilih != 8);
            break;

        case 2:
            do {
                cout << "\n========== KELOLA DATA SALES ================\n";
                cout << "|| 1.  Tambah Sales ke Mobil (Insert First) ||\n";
                cout << "|| 2.  Tambah Sales ke Mobil (Insert After) ||\n";
                cout << "|| 3.  Tambah Sales ke Mobil (Insert Last)  ||\n";
                cout << "|| 4.  Hapus Sales (Delete First)           ||\n";
                cout << "|| 5.  Hapus Sales (Delete After)           ||\n";
                cout << "|| 6.  Hapus Sales (Delete Last)            ||\n";
                cout << "|| 7.  Hapus Sales berdasarkan Kode         ||\n";
                cout << "|| 8.  Kembali ke Menu Utama                ||\n";
                cout << "================================================";
                cout << "Pilih: ";
                cin >> pilih;

                switch (pilih) {
                case 1:
                    cout << "\n-- TAMBAH SALES (INSERT FIRST) --\n";
                    cout << "Masukkan merk mobil: ";
                    cin >> merk;
                    pMobil = findElmMobil(Lmobil, merk);

                    if (pMobil != nullptr) {
                        cout << "\nData sales baru:\n";
                        cout << "Nama Sales   : ";
                        cin >> namaSales;
                        cout << "Kode Sales   : ";
                        cin >> kodeSales;
                        cout << "Jumlah Jual  : ";
                        cin >> penjualan;

                        pSales = createElmSales(namaSales, kodeSales, penjualan);
                        insertFirstSales(pMobil, pSales);
                        cout << "Sales berhasil ditambahkan di awal list!\n";
                    } else {
                        cout << "Mobil tidak ditemukan!\n";
                    }
                    break;

                case 2:
                    cout << "\n-- TAMBAH SALES (INSERT AFTER) --\n";
                    cout << "Masukkan merk mobil: ";
                    cin >> merk;
                    pMobil = findElmMobil(Lmobil, merk);

                    if (pMobil != nullptr) {
                        cout << "Masukkan kode sales sebagai referensi: ";
                        cin >> kodeTarget;
                        pSalesTarget = findSales(pMobil, kodeTarget);

                        if (pSalesTarget != nullptr) {
                            cout << "\nData sales baru:\n";
                            cout << "Nama Sales   : ";
                            cin >> namaSales;
                            cout << "Kode Sales   : ";
                            cin >> kodeSales;
                            cout << "Jumlah Jual  : ";
                            cin >> penjualan;

                            pSales = createElmSales(namaSales, kodeSales, penjualan);
                            insertAfterSales(pMobil, pSalesTarget, pSales);
                            cout << "Sales berhasil ditambahkan setelah " << kodeTarget << "!\n";
                        } else {
                            cout << "Sales referensi tidak ditemukan!\n";
                        }
                    } else {
                        cout << "Mobil tidak ditemukan!\n";
                    }
                    break;

                case 3:
                    cout << "\n-- TAMBAH SALES (INSERT LAST) --\n";
                    cout << "Masukkan merk mobil: ";
                    cin >> merk;
                    pMobil = findElmMobil(Lmobil, merk);

                    if (pMobil != nullptr) {
                        cout << "\nData sales baru:\n";
                        cout << "Nama Sales   : ";
                        cin >> namaSales;
                        cout << "Kode Sales   : ";
                        cin >> kodeSales;
                        cout << "Jumlah Jual  : ";
                        cin >> penjualan;

                        pSales = createElmSales(namaSales, kodeSales, penjualan);
                        insertLastSales(pMobil, pSales);
                        cout << "Sales berhasil ditambahkan di akhir list!\n";
                    } else {
                        cout << "Mobil tidak ditemukan!\n";
                    }
                    break;

                case 4:
                    cout << "\n-- HAPUS SALES (DELETE FIRST) --\n";
                    cout << "Masukkan merk mobil: ";
                    cin >> merk;
                    pMobil = findElmMobil(Lmobil, merk);

                    if (pMobil != nullptr) {
                        if (pMobil->firstSales != nullptr) {
                            deleteFirstSales(pMobil, pSales);
                            cout << "Sales pertama berhasil dihapus dari mobil " << merk << "!\n";
                            cout << "  (Nama: " << pSales->info.Nama << ", Kode: " << pSales->info.kode << ")\n";
                        } else {
                            cout << "Tidak ada sales pada mobil ini!\n";
                        }
                    } else {
                        cout << "Mobil tidak ditemukan!\n";
                    }
                    break;

                case 5:
                    cout << "\n-- HAPUS SALES (DELETE AFTER) --\n";
                    cout << "Masukkan merk mobil: ";
                    cin >> merk;
                    pMobil = findElmMobil(Lmobil, merk);

                    if (pMobil != nullptr) {
                        cout << "Masukkan kode sales sebagai referensi: ";
                        cin >> kodeTarget;
                        pSalesTarget = findSales(pMobil, kodeTarget);

                        if (pSalesTarget != nullptr && pSalesTarget->next != nullptr) {
                            deleteAfterSales(pMobil, pSalesTarget, pSalesTarget->next);
                            cout << "Sales setelah " << kodeTarget << " berhasil dihapus!\n";
                        } else if (pSalesTarget == nullptr) {
                            cout << "Sales referensi tidak ditemukan!\n";
                        } else {
                            cout << "Tidak ada sales setelah " << kodeTarget << "!\n";
                        }
                    } else {
                        cout << "Mobil tidak ditemukan!\n";
                    }
                    break;

                case 6:
                    cout << "\n-- HAPUS SALES (DELETE LAST) --\n";
                    cout << "Masukkan merk mobil: ";
                    cin >> merk;
                    pMobil = findElmMobil(Lmobil, merk);

                    if (pMobil != nullptr) {
                        if (pMobil->firstSales != nullptr) {
                            deleteLastSales(pMobil, pSales);
                            cout << "Sales terakhir berhasil dihapus dari mobil " << merk << "!\n";
                            cout << "  (Nama: " << pSales->info.Nama << ", Kode: " << pSales->info.kode << ")\n";
                        } else {
                            cout << "Tidak ada sales pada mobil ini!\n";
                        }
                    } else {
                        cout << "Mobil tidak ditemukan!\n";
                    }
                    break;

                case 7:
                    cout << "\n-- HAPUS SALES BERDASARKAN KODE --\n";
                    cout << "Masukkan merk mobil: ";
                    cin >> merk;
                    pMobil = findElmMobil(Lmobil, merk);

                    if (pMobil != nullptr) {
                        cout << "Masukkan kode sales yang akan dihapus: ";
                        cin >> kodeSales;

                        pSalesTarget = findSales(pMobil, kodeSales);
                        if (pSalesTarget != nullptr) {

                            pSalesPrev = pMobil->firstSales;
                            while (pSalesPrev != nullptr && pSalesPrev->next != pSalesTarget) {
                                pSalesPrev = pSalesPrev->next;
                            }

                            if (pSalesTarget == pMobil->firstSales) {
                                deleteFirstSales(pMobil, pSalesTarget);
                            } else {
                                deleteAfterSales(pMobil, pSalesPrev, pSalesTarget);
                            }
                            cout << "Sales " << kodeSales << " berhasil dihapus!\n";
                        } else {
                            cout << "Sales tidak ditemukan!\n";
                        }
                    } else {
                        cout << "Mobil tidak ditemukan!\n";
                    }
                    break;

                case 8:
                    cout << "Kembali ke menu utama...\n";
                    break;

                default:
                    cout << "Pilihan tidak valid!\n";
                }

            } while (pilih != 8);
            break;

        case 3:
            cout << "\n=== TAMPILKAN SEMUA DATA ===\n";
            if (Lmobil.first != nullptr) {
                viewSales(Lmobil);
            } else {
                cout << "Tidak ada data mobil yang tersedia!\n";
            }
            break;

        case 4:
            do {
                cout << "\n=========== CARI DATA ===============\n";
                cout << " || 1.  Cari Mobil berdasarkan Merk ||\n";
                cout << " || 2.  Cari Sales berdasarkan Kode ||\n";
                cout << " || 3.  Kembali ke Menu Utama       ||\n";
                cout << "=======================================";
                cout << "Pilih: ";
                cin >> pilih;

                switch (pilih) {
                case 1:
                    cout << "\n-- CARI MOBIL --\n";
                    cout << "Masukkan merk mobil: ";
                    cin >> merk;
                    pMobil = findElmMobil(Lmobil, merk);

                    if (pMobil != nullptr) {
                        cout << "\nMobil ditemukan!\n";
                        cout << "Merk          : " << pMobil->info.Merk << endl;
                        cout << "Warna         : " << pMobil->info.warna << endl;
                        cout << "Stok          : " << pMobil->info.stock << endl;


                        if (pMobil->firstSales != nullptr) {
                            cout << "Daftar Sales:\n";
                            pSales = pMobil->firstSales;
                            while (pSales != nullptr) {
                                cout << "  - " << pSales->info.Nama << " ("
                                     << pSales->info.kode << "): "
                                     << pSales->info.penjualan << " unit terjual\n";
                                pSales = pSales->next;
                            }
                        }
                    } else {
                        cout << "Mobil tidak ditemukan!\n";
                    }
                    break;

                case 2:
                {
                    cout << "\n-- CARI SALES --\n";
                    cout << "Masukkan kode sales: ";
                    cin >> kodeSales;


                    pMobil = Lmobil.first;
                    bool found = false;

                    while (pMobil != nullptr && !found) {
                        pSales = findSales(pMobil, kodeSales);
                        if (pSales != nullptr) {
                            cout << "\nSales ditemukan!\n";
                            cout << "Nama          : " << pSales->info.Nama << endl;
                            cout << "Kode          : " << pSales->info.kode << endl;
                            cout << "Penjualan     : " << pSales->info.penjualan << " unit" << endl;
                            cout << "Mobil         : " << pMobil->info.Merk << endl;
                            cout << "Warna Mobil   : " << pMobil->info.warna << endl;
                            found = true;
                        }
                        pMobil = pMobil->next;
                    }

                    if (!found) {
                        cout << "Sales tidak ditemukan!\n";
                    }
                }
                break;

                case 3:
                    cout << "Kembali ke menu utama...\n";
                    break;

                default:
                    cout << "Pilihan tidak valid!\n";
                }

            } while (pilih != 3);
            break;

        case 5:
            do {
                cout << "\n=== KOMPUTASI & LAPORAN ===\n";
                cout << "1.  Total Mobil Terjual (Semua Sales)\n";
                cout << "2.  Performa Sales Tertentu\n";
                cout << "3.  Kembali ke Menu Utama\n";
                cout << "Pilih: ";
                cin >> pilih;

                switch (pilih) {
                case 1:
                    cout << "\n-- TOTAL MOBIL TERJUAL --\n";
                    mobilTerjualan(Lsales, Lmobil);
                    break;

                case 2:
                    cout << "\n-- PERFORMANCE SALES --\n";
                    cout << "Masukkan kode sales: ";
                    cin >> kodeSales;
                    performaSales(Lsales, Lmobil, kodeSales);
                    break;

                case 3:
                    cout << "Kembali ke menu utama...\n";
                    break;

                default:
                    cout << "Pilihan tidak valid!\n";
                }

            } while (pilih != 3);
            break;

        case 0:
            cout << "\nTerima kasih telah menggunakan program!\n";
            break;

        default:
            cout << "\nMenu tidak valid! Silakan pilih 0-6.\n";
        }

    } while (pilih != 0);

    return 0;
}
