/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2024/2025
 *   Modul               : 03 - Structures and Dynamics Arrayd
 *   Hari dan Tanggal    : Rabu, 29 April 2026
 *   Nama (NIM)          : Kenny Pramanik Najla Wibowo (133224088)
 *   Nama File           : modul3.c
 *   Deskripsi           : Membuat program untuk mengurutkan artefak pada suatu sistem arsip berdasarkan prioritas pengelompokan, dimana
 *                          - Kategori alfabetis naik
 *                          - jika sama, tahun naik
 *                          - jika sama, nilai turun
 *                          - jika sama, nama alfabetis naik 
 */

#include <stdio.h> 
#include <string.h> 

typedef struct {
    char nama[50];
    char kategori[50];
    int tahun;
    int nilai;
} artefak;

void sort_artefak(artefak arr[], int n){
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n-i-1; j++){
            if(
                (strcmp(arr[j].kategori, arr[j+1].kategori)> 0) || 
                (strcmp(arr[j].kategori, arr[j+1].kategori) == 0 && arr[j].tahun < arr[j+1].tahun) || 
                (strcmp(arr[j].kategori, arr[j+1].kategori) == 0 && arr[j].tahun == arr[j+1].tahun && arr[j].nilai > arr[j+1].nilai) || 
                (strcmp(arr[j].kategori, arr[j+1].kategori) == 0 && arr[j].tahun == arr[j+1].tahun && arr[j].nilai == arr[j+1].nilai && strcmp(arr[j].nama, arr[j+1].nama) > 0)
            ){
                artefak temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
            
        }
    }

    for(int i = 0; i < n; i++){
        printf("%s %s %d %d", arr[i].nama, arr[i].kategori, arr[i].tahun, arr[i].nilai);
    }
}

int main(){
    int n;
    scanf("%d", &n);

    artefak arr[n];
    
    //melakukan perulangan untuk input elemen - elemen dari array
    for(int i = 0; i < n; i++){
        scanf("%s %s %d %d", &arr[i].nama, &arr[i].kategori, &arr[i].tahun, &arr[i].nilai);
    }

    //melakukan sorting 
    sort_artefak(arr, n);

}
