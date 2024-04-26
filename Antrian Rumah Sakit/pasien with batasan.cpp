#include <iostream>
#include <queue>

using namespace std;

struct Pasien {
    string nama;
    int umur;
};

int main() {
    queue<Pasien> antrian;
    int pilihan;

    do {
        cout << "=== Antrian Pasien Rumah Sakit Rayhan Bersatu ===\n" << endl;
        cout << "=== Selamat Datang di RS RB Silahkan Tekan Tombol Di Bawah Ini ===\n" << endl;
        cout << "1. Membuat Antrian Pasien Pasien\n";
        cout << "2. Memanggil Antrian Pasien\n";
        cout << "3. Lihat Pasien\n";
        cout << "4. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: {
                if (antrian.size() == 5) {
                    cout << "Antrian penuh. Tidak dapat menambahkan pasien.\n\n";
                } else {
                    Pasien pasien;
                    cout << "Masukkan nama pasien: ";
                    cin >> pasien.nama;
                    cout << "Masukkan umur pasien: ";
                    cin >> pasien.umur;
                    antrian.push(pasien);
                    cout << "Pasien " << pasien.nama << " ditambahkan ke antrian.\n\n";
                }
                break;
            }
            case 2: {
                if (antrian.empty()) {
                    cout << "Tidak ada pasien dalam antrian RB.\n\n";
                } else {
                    Pasien pasien = antrian.front();
                    antrian.pop();
                    cout << "Pasien " << pasien.nama << " dipanggil.\n\n";
                }
                break;
            }
            case 3: {
                if (antrian.empty()) {
                    cout << "Tidak ada pasien dalam antrian RB.\n\n";
                } else {
                    cout << "Antrian Pasien:\n";
                    int nomor_antrian = 1;
                    queue<Pasien> totalAntrian = antrian;
                    while (!totalAntrian.empty()) {
                        Pasien pasien = totalAntrian.front();
                        cout << nomor_antrian << ". " << pasien.nama << " (" << pasien.umur << " tahun)\n";
                        totalAntrian.pop();
                        nomor_antrian++;
                    }
                    cout << endl;
                }
                break;
            }
            case 4: {
                cout << "Terima kasih telah menyelesaikan antrian.\n";
                break;
            }
            default: {
                cout << "Pilihan salah. Silakan coba lagi.\n\n";
                break;
            }
        }
    } while (pilihan != 4);

    return 0;
}

