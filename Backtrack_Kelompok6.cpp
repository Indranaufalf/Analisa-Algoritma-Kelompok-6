#include <iostream>
#include <string>
using namespace std;

const int MAX = 20;
string namaBarang[MAX];
int harga[MAX];
int n, budget;
int solusiCount = 0, callCount = 0;
bool dipilih[MAX];

void printSolusi() {
    solusiCount++;
    cout << "\n  Solusi " << solusiCount << ": ";
    int total = 0;
    for (int i = 0; i < n; i++) {
        if (dipilih[i]) {
            cout << namaBarang[i] << " (Rp" << harga[i] << ") ";
            total += harga[i];
        }
    }
    cout << "=> Total: Rp" << total;
}

void subsetSum(int index, int total) {
    callCount++;

    if (total == budget) { printSolusi(); return; }
    if (index == n)       return;
    if (total > budget)   return;

    dipilih[index] = true;
    subsetSum(index + 1, total + harga[index]);

    dipilih[index] = false;
    subsetSum(index + 1, total);
}

int main() {
    n = 7;
    namaBarang[0] = "Sabun";        harga[0] = 10000;
    namaBarang[1] = "Shampo";       harga[1] = 15000;
    namaBarang[2] = "Pasta Gigi";   harga[2] = 12000;
    namaBarang[3] = "Sikat Gigi";   harga[3] = 8000;
    namaBarang[4] = "Deterjen";     harga[4] = 20000;
    namaBarang[5] = "Sabun Cuci";   harga[5] = 18000;
    namaBarang[6] = "Tisu";         harga[6] = 7000;
    budget = 35000;

    cout << "========================================" << endl;
    cout << "          PENGELOLAAN ANGGARAN    " << endl;
    cout << "========================================" << endl;
    cout << "\n[DATA BARANG]" << endl;
    cout << "-------------------------------------" << endl;
    for (int i = 0; i < n; i++)
        cout << "  " << i+1 << ". " << namaBarang[i]
             << "\t: Rp" << harga[i] << endl;
    cout << "-------------------------------------" << endl;
    cout << "Budget: Rp" << budget << endl;
    cout << "\n[MENCARI KOMBINASI...]" << endl;

    subsetSum(0, 0);

    cout << "\n\n========================================" << endl;
    cout << "Total solusi ditemukan  : " << solusiCount << endl;
    cout << "Total pemanggilan rekursi: " << callCount  << endl;
    cout << "========================================" << endl;

    return 0;
}