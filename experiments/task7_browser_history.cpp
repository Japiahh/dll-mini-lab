#include <iostream>
#include <string>
using namespace std;
struct node {
    string url;
    node* prev;
    node* next;
    node(string u) {
        url = u;
        prev = nullptr;
        next = nullptr;
    }
};
class browser {
public:
    node* aktif;
    browser(string awal) {
        aktif = new node(awal);
    }
    ~browser() {
        while (aktif != nullptr && aktif->prev != nullptr) {
            aktif = aktif->prev;
        }
        while (aktif != nullptr) {
            node* hapusnode = aktif;
            aktif = aktif->next;
            delete hapusnode;
        }
    }
    void kunjungi(string u) {
        node* depan = aktif->next;
        while (depan != nullptr) {
            node* hapusnode = depan;
            depan = depan->next;
            delete hapusnode;
        }
        node* baru = new node(u);
        baru->prev = aktif;
        aktif->next = baru;
        aktif = baru;
    }
    void mundur() {
        if (aktif == nullptr || aktif->prev == nullptr) {
            return;
        }
        aktif = aktif->prev;
    }
    void maju() {
        if (aktif == nullptr || aktif->next == nullptr) {
            return;
        }
        aktif = aktif->next;
    }
    void cetak() {
        node* bantu = aktif;
        while (bantu != nullptr && bantu->prev != nullptr) {
            bantu = bantu->prev;
        }
        while (bantu != nullptr) {
            cout << bantu->url;
            if (bantu == aktif) {
                cout << "*";
            }
            if (bantu->next != nullptr) {
                cout << " <-> ";
            }
            bantu = bantu->next;
        }
        cout << "\n";
    }
};
int main() {
    browser b("google.com");
    cout << "buka: google.com\n";
    b.kunjungi("youtube.com");
    cout << "kunjungi: youtube.com\n";
    b.kunjungi("github.com");
    cout << "kunjungi: github.com\n";
    b.kunjungi("stackoverflow.com");
    cout << "kunjungi: stackoverflow.com\n";
    cout << "riwayat:\n";
    b.cetak();
    b.mundur();
    cout << "mundur:\n";
    b.cetak();
    b.mundur();
    cout << "mundur:\n";
    b.cetak();
    b.maju();
    cout << "maju:\n";
    b.cetak();
    b.kunjungi("wikipedia.org");
    cout << "kunjungi: wikipedia.org\n";
    b.cetak();
    b.mundur();
    cout << "mundur:\n";
    b.cetak();
}
