#include <iostream>
using namespace std;
struct Node
{
int bilPokok;
int pangkat;
Node *before;
Node *next;
};
Node *head, *tail;
void init()
{
head = NULL;
tail = NULL;
}
int isEmpty()
{
if (tail == NULL)
return 1;
else
return 0;
}
void Hapus(int bilP)
{
Node *hapus = head;
Node *cur;
if (hapus->bilPokok == bilP)
{
head = hapus->next;
hapus->before = NULL;
}
else
{
while (hapus->bilPokok != bilP)
{
cur = hapus;
hapus = hapus->next;
}
cur->next = hapus->next;
cur->before = hapus->before;
}
}
void sisipAwal(int BilP, int Pangkat)
{
Node *baru = new Node;
Node *cari = head;
if (cari->pangkat < Pangkat)
{
baru->next = head;
baru->before = NULL;
head = baru;
}
baru->bilPokok = BilP;
baru->pangkat = Pangkat;
cout << "Data masuk...\n";
}
void sisipTA(int BilP, int Pangkat)
{
Node *baru, *stl;
Node *cari = head;
baru = new Node;
stl = new Node;
baru->bilPokok = BilP;
baru->pangkat = Pangkat;
while (cari->pangkat > Pangkat)
{
stl = cari;
cari = cari->next;
if (cari == NULL)
{
break;
}
}
baru->next = cari;
stl->next = baru;
baru->before = stl;
cout << "Data masuk...\n";
}
void cekSisip(int BilP, int Pangkat)

Node *baru;
baru = new Node;
if (tail == NULL)
{
baru->bilPokok = BilP;
baru->pangkat = Pangkat;
baru->next = NULL;
if (isEmpty() == 1)
{
head = tail = baru;
tail->next = NULL;
tail->before = baru;
}
else
{
Node *temp = head;
while (temp->next != NULL)
temp = temp->next;
temp->next = baru;
baru->before = temp;
}
cout << "Data masuk...\n";
}
else
{
while (bantu != NULL)
{
if (bantu->pangkat > Pangkat)
{
sisipTA(BilP, Pangkat);
break;
}
else
{
sisipAwal(BilP, Pangkat);
break;
}
}
}
}
void tampil()
{
cout << "\nData yang ada di list saat ini :\n";
Node *bantu = head;
if (isEmpty() == 0)
{
while (bantu != NULL)
{
if (bantu->bilPokok != 1)
cout << bantu->bilPokok;
if (bantu->pangkat != 0)
cout << "x^" << bantu->pangkat;
if (bantu->next != NULL)
cout << " + ";
bantu = bantu->next;
}
cout << endl;
}
else
cout << "Data Kosong...\n"
<< endl;
}
int main()
{
init();
system("cls");
int pil, BilP, Pangkat;
while (true)
{
cout <<
"\n==============================================================" << endl;
cout << "MEMPRESENTASIKAN BILANGAN POLINOMIAL DENGAN DOUBLELINKED LIST" << endl;
cout <<
"==============================================================" << endl;
cout << "= 1. Menyisipkan bilangan polinomial =" << endl;
cout << "= 2. Menghapus bilangan polinomial =" << endl;
cout << "= 3. Tampil =" << endl;
cout << "= 4. Exit =" << endl;
cout << "============================================================= =" << endl;
cout << "Masukkan pilihan : ";
cin >> pil;
switch (pil)
{
case 1:
system("cls");
{
tampil();
cout << "\nInsert bilangan polinomial" << endl;
cout << "Bilangan pokok : ";
cin >> BilP;
cout << "Pangkat : ";
cin >> Pangkat;
cekSisip(BilP, Pangkat);
tampil();
break;
}
case 2:
system("cls");
{
tampil();
cout << "Bilangan polinomial yang akan di hapus : " <<endl;
cout << "Bilangan pokok : ";
cin >> BilP;
Hapus(BilP);
tampil();
break;
}
case 3:
system("cls");
{
tampil();
break;
}
case 4:
{
cout << "Terima kasih...\n";
exit(0);
break;
}
default:
system("cls");
{
cout << "Pilihan anda tidak tersedia..." << endl;
break;
}
}
}
}
