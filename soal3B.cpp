#include <iostream>
#include <string>
using namespace std;

struct Node {
    string nama;
    int data;
    Node* next;
};

Node* front = nullptr;
Node* rear = nullptr;

//Tambahkan Pelanggan
 void masukanPelanggan(string nama) {
    Node* node1 = new Node();
    node1->nama = nama;
    node1->next = nullptr;
    front = node1;
    rear = node1;
 }

 void layaniPelanggan(string nama) {
    Node* hapus = front;
    cout << "dequeue : " << front->data << endl;
    front = front->next;
    delete hapus;
 }

 

 //tampilkan depan belakang
 void tampilkanDepan() {
     cout << "Pelanggan depan : " << front->nama << endl;
 }
 void tampilkanBelakang() {
     cout << "Pelanggan belakang : " << rear->nama << endl;
 }



int main() {
    int pilihan, nilai;
    cout << "\n=== Antrean Pelanggan ===\n";
    cout << "1. Masukan Pelanggan\n";
    cout << "2. Layani Pelanggan\n";
    cout << "4. Tampilkan pelanggan depan\n";
    cout << "5. Tampilkan pelanggan belakang\n";
    cin >> pilihan;
    


}