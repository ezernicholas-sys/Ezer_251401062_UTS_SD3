
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int nilai[5][4];
    double rata[5];
    string komponen[4] = {
        "Tugas", "Kuis", "UTS", "Praktikum"
    };

    double total;
    double tertinggi, terendah;
    int jumlahLulus = 0;

    // Input nilai mahasiswa
    cout << "=== INPUT NILAI MAHASISWA ===" << endl;

    for (int i = 0; i < 5; i++) {
        cout << "\nMahasiswa ke-" << i + 1 << endl;

        for (int j = 0; j < 4; j++) {
            cout << "Nilai " << komponen[j] << ": ";
            cin >> nilai[i][j];
        }
    }

    // Menghitung rata-rata setiap mahasiswa
    for (int i = 0; i < 5; i++) {
        total = 0;

        for (int j = 0; j < 4; j++) {
            total += nilai[i][j];
        }

        rata[i] = total / 4.0;
    }

    // Menentukan rata-rata tertinggi dan terendah
    tertinggi = rata[0];
    terendah = rata[0];

    for (int i = 1; i < 5; i++) {
        if (rata[i] > tertinggi) {
            tertinggi = rata[i];
        }

        if (rata[i] < terendah) {
            terendah = rata[i];
        }
    }

    // Menghitung jumlah mahasiswa dengan rata-rata >= 75
    for (int i = 0; i < 5; i++) {
        if (rata[i] >= 75) {
            jumlahLulus++;
        }
    }

    // Menampilkan hasil
    cout << "\n\n=== HASIL PENILAIAN ===" << endl;

    cout << fixed << setprecision(2);

    for (int i = 0; i < 5; i++) {
        cout << "Mahasiswa ke-" << i + 1
             << " - Rata-rata: " << rata[i] << endl;
    }

    cout << "\nRata-rata tertinggi: " << tertinggi << endl;
    cout << "Diperoleh oleh mahasiswa: ";

    for (int i = 0; i < 5; i++) {
        if (rata[i] == tertinggi) {
            cout << i + 1 << " ";
        }
    }

    cout << "\nRata-rata terendah: " << terendah << endl;
    cout << "Diperoleh oleh mahasiswa: ";

    for (int i = 0; i < 5; i++) {
        if (rata[i] == terendah) {
            cout << i + 1 << " ";
        }
    }

    cout << "\nJumlah mahasiswa dengan rata-rata >= 75: "
         << jumlahLulus << endl;

    return 0;
}
