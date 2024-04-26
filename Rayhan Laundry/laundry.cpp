
#include <iostream>
#include <queue>

using namespace std;

struct Cuci {
    string baju;
    string ukuran;
};

int main() {
    queue<Cuci> antrian;
    int pilih;

    do {
        cout << "= Rayhan's Laundry =\n" << endl;
        cout << "1. Masukkan Baju\n";
        cout << "2. Cuci Baju\n";
        cout << "3. Tampilkan Baju\n";
        cout << "4. Keluar\n";
        cout << "Pilih: ";
        cin >> pilih;

        switch (pilih) {
            case 1: {
                if (antrian.size() == 5) {
                    cout << "Baju Penuh. Tidak bisa di cuci di ember ini.\n\n";
                } else {
                    Cuci cuci;
                    cout << "Masukkan jenis baju: ";
                    cin >> cuci.baju;
                    cout << "Ukuran baju: ";
                    cin >> cuci.ukuran;
                    antrian.push(cuci);
                    cout << "Baju " << cuci.baju << " ditambahkan ke ember.\n\n";
                }
                break;
            }
            case 2: {
                if (antrian.empty()) {
                    cout << "Tidak ada baju di dalam ember.\n\n";
                } else {
                    Cuci cuci = antrian.front();
                    antrian.pop();
                    cout << "Baju " << cuci.baju << " dicuci.\n\n";
                }	
                break;
            }
            case 3: {
                if (antrian.empty()) {
                    cout << "Tidak ada baju di dalam ember.\n\n";
                } else {
                    cout << "Jenis Baju:\n";
                    int urutan_baju = 1;
                    queue<Cuci> totalBaju = antrian;
                    while (!totalBaju.empty()) {
                        Cuci cuci = totalBaju.front();
                        cout << urutan_baju << ". " << cuci.baju << " (" << cuci.ukuran << ")\n";
                        totalBaju.pop();
                        urutan_baju++;
                    }
                    cout << endl;
                }
                break;
            }
            case 4: {
                cout << "Terima kasih telah mencuci disini.\n";
                break;
            }
            default: {
                cout << "Pilihan salah. Coba lagi.\n\n";
                break;
            }
        }
    } while (pilih != 4);

    return 0;
}

