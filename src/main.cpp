#include <iostream>
#include <string>
using namespace std;
struct node {
    string data;
    node* prev;
    node* next;
    node(string n) {
        data = n;
        prev = nullptr;
        next = nullptr;
    }
};
class list {
public:
    node* head;
    node* tail;
    list() {
        head = nullptr;
        tail = nullptr;
    }
    ~list() {
        node* bantu = head;
        while (bantu != nullptr) {
            node* hapusnode = bantu;
            bantu = bantu->next;
            delete hapusnode;
        }
    }
    void tambah(string n) {
        node* baru = new node(n);
        if (head == nullptr) {
            head = baru;
            tail = baru;
            return;
        }
        tail->next = baru;
        baru->prev = tail;
        tail = baru;
    }
    void cetakmaju() {
        node* bantu = head;
        while (bantu != nullptr) {
            cout << bantu->data;
            if (bantu->next != nullptr) {
                cout << " <-> ";
            }
            bantu = bantu->next;
        }
        cout << "\n";
    }
    void cetakmundur() {
        node* bantu = tail;
        while (bantu != nullptr) {
            cout << bantu->data;
            if (bantu->prev != nullptr) {
                cout << " <-> ";
            }
            bantu = bantu->prev;
        }
        cout << "\n";
    }
    void sisip(string target, string n) {
        node* bantu = head;
        while (bantu != nullptr && bantu->data != target) {
            bantu = bantu->next;
        }
        if (bantu == nullptr) {
            return;
        }
        node* baru = new node(n);
        baru->next = bantu->next;
        baru->prev = bantu;
        if (bantu->next != nullptr) {
            bantu->next->prev = baru;
        } else {
            tail = baru;
        }
        bantu->next = baru;
    }
    void hapus(string n) {
        node* bantu = head;
        while (bantu != nullptr && bantu->data != n) {
            bantu = bantu->next;
        }
        if (bantu == nullptr) {
            return;
        }
        if (bantu == head) {
            head = bantu->next;
            if (head != nullptr) {
                head->prev = nullptr;
            } else {
                tail = nullptr;
            }
        } else if (bantu == tail) {
            tail = bantu->prev;
            if (tail != nullptr) {
                tail->next = nullptr;
            } else {
                head = nullptr;
            }
        } else {
            bantu->prev->next = bantu->next;
            bantu->next->prev = bantu->prev;
        }
        delete bantu;
    }
};
void tugas() {
    list l;
    l.tambah("Song A");
    l.tambah("Song B");
    l.tambah("Song C");
    l.tambah("Song D");
    l.tambah("Song E");
    cout << "awal:\n";
    l.cetakmaju();
    cout << "maju:\n";
    l.cetakmaju();
    cout << "mundur:\n";
    l.cetakmundur();
    cout << "sisip Song X:\n";
    l.sisip("Song B", "Song X");
    l.cetakmaju();
    l.cetakmundur();
    cout << "hapus Song C:\n";
    l.hapus("Song C");
    l.cetakmaju();
    l.cetakmundur();
}
int main() {
    int pilih = 0;
    list manual;
    while (pilih != 3) {
        cout << "menu:\n1. tugas 1-6\n2. manual\n3. keluar\npilih: ";
        if (!(cin >> pilih)) {
            return 0;
        }
        if (pilih == 1) {
            tugas();
        } else if (pilih == 2) {
            int opsi = 0;
            while (opsi != 6) {
                cout << "opsi:\n1. tambah\n2. maju\n3. mundur\n4. sisip\n5. hapus\n6. kembali\npilih: ";
                if (!(cin >> opsi)) {
                    return 0;
                }
                if (opsi == 1) {
                    string n;
                    cout << "data: ";
                    cin >> n;
                    manual.tambah(n);
                } else if (opsi == 2) {
                    cout << "maju:\n";
                    manual.cetakmaju();
                } else if (opsi == 3) {
                    cout << "mundur:\n";
                    manual.cetakmundur();
                } else if (opsi == 4) {
                    string target, n;
                    cout << "target: ";
                    cin >> target;
                    cout << "data: ";
                    cin >> n;
                    manual.sisip(target, n);
                } else if (opsi == 5) {
                    string n;
                    cout << "data: ";
                    cin >> n;
                    manual.hapus(n);
                }
            }
        }
    }
}
