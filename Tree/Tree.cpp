#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
struct Node{
int data;
Node *kiri;
Node *kanan;
};
Node *pohon = NULL;
void tambah (Node **root, int databaru){
if ((*root)==NULL){
 Node *baru;
 baru = new Node;
 baru->data=databaru;
 baru->kiri=NULL;
 baru->kanan=NULL;
 (*root) = baru;
 (*root) -> kiri = NULL;
 (*root) -> kanan = NULL;
 printf("Data Bertambah!");
}
else if (databaru<(*root)->data)
 tambah(&(*root)->kiri,databaru);
else if (databaru>(*root)->data)
 tambah(&(*root)->kanan,databaru);
else if (databaru==(*root)->data)
 printf("Data Sudah ada!");
}
void tampil(Node *root){
if(root!=NULL){
 if(root->data!='\0'){
 printf("%d ",root->data);
 }
 tampil(root->kiri);
 tampil(root->kanan);
}
}
int height(Node *root){
if(root == NULL)
 return -1;
else{
 int u = height(root->kiri);
 int v = height(root->kanan);
 if(u > v)
 return u + 1;
 else
 return v + 1;
}
}
int main(){
char pil;
int del,cari;
while (true){
 system("cls");
 char data;
 
printf("=========================================================================\n");
 printf("|| PROGRAM MENGETAHUI KEDALAMAN MAKSIMUM DARI TREE YANG TELAH DIBANGUN ||\n");
 
printf("=========================================================================\n");
 printf("Menu Pilihan :\n");
 printf("|1| Tambah Data\n");
 printf("|2| Lihat\n");
 printf("|3| Hitung Simpul Pada Tree\n");
 printf("|4| Keluar\n");
 
printf("=========================================================================\n");
 printf("Masukkan Pilihan : ");
 scanf("%c",&pil);
 fflush(stdin);
 switch(pil){
 case '1':
 printf("\n--- Input Data --");
 printf("\nInput Data : ");
 scanf("%d", &data);
 tambah(&pohon,data);
 _getch();
 break;
 case '2':
 printf("\n--- Output Data ---\n ");
 if(pohon!=NULL)
 tampil(pohon);
 else
 printf("Masih Kosong!!!");
 _getch();
 break;
 case '3' :
 printf("Tingkat Kedalaman Tree\n");
 printf("KEDALAMAN TREE(LEVEL-> DIMULAI DARI 0)\n");
 
printf("=========================================================================\n");
 printf("\nKedalaman Tree : %d\n", height(pohon));
 _getch();
 break;
 case '4'|'4':
 exit(0);
 break;
 }
}
}
