
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

// Menambahkan data di awal
void insertFirst(int nilai) {
    Node* baru = new Node;
    baru->data = nilai;

    if (head == NULL) {
        head = baru;
        baru->next = head;
    } else {
        Node* bantu = head;

        while (bantu->next != head) {
            bantu = bantu->next;
        }

        baru->next = head;
        bantu->next = baru;
        head = baru;
    }

    cout << "Data berhasil ditambahkan!\n";
}

// Menambahkan data di akhir
void insertLast(int nilai) {
    Node* baru = new Node;
    baru->data = nilai;

    if (head == NULL) {
        head = baru;
        baru->next = head;
    } else {
        Node* bantu = head;

        while (bantu->next != head) {
            bantu = bantu->next;
        }

        bantu->next = baru;
        baru->next = head;
    }

    cout << "Data berhasil ditambahkan!\n";
}

// Menampilkan seluruh data
void display() {
    if (head == NULL) {
        cout << "Linked List kosong!\n";
        return;
    }

    Node* bantu = head;

    cout << "Data: ";

    do {
        cout << bantu->data;
        bantu = bantu->next;

        if (bantu != head) {
            cout << " -> ";
        }

    } while (bantu != head);

    cout << " -> kembali ke HEAD\n";
}

// Mencari data
void search(int nilai) {
    if (head == NULL) {
        cout << "Linked List kosong!\n";
        return;
    }

    Node* bantu = head;
    int posisi = 1;
    bool ditemukan = false;

    do {
        if (bantu->data == nilai) {
            cout << "Data ditemukan pada posisi "
                 << posisi << endl;
            ditemukan = true;
            break;
        }

        bantu = bantu->next;
        posisi++;

    } while (bantu != head);

    if (!ditemukan) {
        cout << "Data tidak ditemukan!\n";
    }
}

// Menghapus data pertama
void deleteFirst() {
    if (head == NULL) {
        cout << "Linked List kosong!\n";
        return;
    }

    Node* hapus = head;

    if (head->next == head) {
        head = NULL;
    } else {
        Node* bantu = head;

        while (bantu->next != head) {
            bantu = bantu->next;
        }

        head = head->next;
        bantu->next = head;
    }

    delete hapus;
    cout << "Data pertama berhasil dihapus!\n";
}

// Menghapus data terakhir
void deleteLast() {
    if (head == NULL) {
        cout << "Linked List kosong!\n";
        return;
    }

    Node* hapus = head;

    if (head->next == head) {
        head = NULL;
    } else {
        Node* bantu = head;

        while (bantu->next->next != head) {
            bantu = bantu->next;
        }

        hapus = bantu->next;
        bantu->next = head;
    }

    delete hapus;
    cout << "Data terakhir berhasil dihapus!\n";
}

void deleteSearch(int nilai) {
    if (head == NULL) {
        cout << "Linked List kosong!\n";
        return;
    }
    Node* bantu = head;

while (bantu->next->data !=nilai){
    bantu=bantu->next;
}

Node* hapus = bantu->next;
bantu->next = hapus->next;
delete hapus;

cout<< "Setelah node tengah dihapus : ";
bantu = head;
while (bantu !=nullptr){
    cout << bantu->data<<" ";
    bantu = bantu->next;
}
}

// Membebaskan seluruh memori
void clearList() {
    while (head != NULL) {
        deleteFirst();
    }
}

int main() {
    int pilihan, nilai;

    do {
        cout << "\n=== CIRCULAR LINKED LIST ===\n";
        cout << "1. Insert First\n";
        cout << "2. Insert Last\n";
        cout << "3. Display\n";
        cout << "4. Search\n";
        cout << "5. Delete First\n";
        cout << "6. Delete Last\n";
        cout << "7. Delete Search\n";
        cout << "8. Exit\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan angka: ";
                cin >> nilai;
                insertFirst(nilai);
                break;

            case 2:
                cout << "Masukkan angka: ";
                cin >> nilai;
                insertLast(nilai);
                break;

            case 3:
                display();
                break;

            case 4:
                cout << "Masukkan angka yang dicari: ";
                cin >> nilai;
                search(nilai);
                break;

            case 5:
                deleteFirst();
                break;

            case 6:
                deleteLast();
                break;

            case 7:
                cout << "Masukan nilai yang ingin dihapus";
                cin >> nilai;
                deleteSearch(nilai);
                break;
            case 8:
                clearList();
                cout << "Program selesai!\n";
                break;

            default:
                cout << "Pilihan tidak valid!\n";
        }

    } while (pilihan != 7);

    return 0;
}
