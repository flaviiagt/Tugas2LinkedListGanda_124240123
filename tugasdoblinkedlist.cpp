#include <iostream>
#include <string>
using namespace std;

struct Node
{
    string judul;
    string penulis;
    Node *next;
    Node *prev;
};

struct Node *buatnode(const string &judul, const string &penulis)
{
    Node *newNode = new Node;
    newNode -> judul = judul;
    newNode -> penulis = penulis;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void sisipnodedepan(Node **head, const string &judul, const string &penulis)
{
    Node *newNode = buatnode(judul, penulis);
    newNode->next = *head;
    if (*head != NULL)
    {
        (*head)->prev = newNode;
    }
    *head = newNode;
}

void sisipnodebelakang(Node **head, const string &judul, const string &penulis)
{
    Node *newNode = buatnode(judul, penulis);
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    Node *bantu = *head;
    while (bantu->next != NULL)
    {
        bantu = bantu->next;
    }
    bantu->next = newNode;
    newNode->prev = bantu;
}

Node *searching(Node *head, string key)
{
    Node *bantu = head;
    while (bantu != NULL)
    {
        if (bantu->judul == key)
        {
            return bantu;
        }
        bantu = bantu->next;
    }
    return NULL;
}

void printdaridepan(Node* head){
    if (head == NULL){
        cout << "Daftar Buku Kosong!" << endl;
        return;
    }
    Node* bantu = head;
    while (bantu != NULL){
        cout << bantu -> judul << " oleh ";
        cout << bantu -> penulis << " | ";
        bantu = bantu -> next;
    }
    cout <<  endl;
}

int pilihmenu; 

void menu (){
 cout << "===== Manajemen Buku Perpustakaan =====" << endl;
    cout << "1. Tambah Buku di Depan" << endl;
    cout << "2. Tambah Buku di Belakang" << endl;
    cout << "3. Hapus Buku berdasarkan Judul" << endl;
    cout << "4. Tampilkan Daftar Buku" << endl;
    cout << "5. Keluar" << endl;
    cout << "========================================" << endl;
    cout << "Pilih menu: ";
    cin >> pilihmenu;
    cin.ignore();
}

int main()
{   menu();
    Node *head = NULL;
    while (pilihmenu != 5)
    {
        switch (pilihmenu)
        {
        case 1:
        {
            string judul;
            string penulis;
            cout << "Masukkan Judul Buku: ";
            getline(cin, judul);
            cout << "Masukkan Penulis: ";
            getline(cin, penulis);
            sisipnodedepan(&head, judul, penulis);
            cout << "Buku Berhasil Ditambahkan" << endl;
            break;
        }
        case 2:
        {
            string judul;
            string penulis;
            cout << "Masukkan Judul Buku: ";
            getline(cin, judul);
            cout << "Masukkan Penulis:";
            getline(cin, penulis);
            sisipnodebelakang(&head, judul, penulis);
            cout << "Buku Berhasil Ditambahkan!";
            cout << endl;
            break;
        }
        case 3:
        {
            string judul;
            cout << "Masukkan judul buku yang ingin dihapus: ";
            getline(cin, judul);
            Node *nodeToDelete = searching(head, judul);
            if (nodeToDelete != NULL)
            {
                if (nodeToDelete->prev != NULL)
                {
                    nodeToDelete->prev->next = nodeToDelete->next;
                }
                else
                {
                    head = nodeToDelete->next;
                }
                if (nodeToDelete->next != NULL)
                {
                    nodeToDelete->next->prev = nodeToDelete->prev;
                }
                delete nodeToDelete;
                cout << "Buku berhasil dihapus." << endl;
            }
            else
            {
                cout << "Buku tidak ditemukan." << endl;
            }
            cout << endl;
            break;
        }
        case 4:
        {
            cout << "Daftar Buku:" << endl;
            printdaridepan(head);
            cout << endl;
            break;
        }
        default:
            cout << "Pilihan tidak valid." << endl;
        }
        cout << "Tekan Enter untuk kembali ke menu..." << endl;
        cin.ignore();
        menu();
    }
    cout << "Terima Kasih Sudah Menggunakan Program Ini!";
    return 0;
}