#include <iostream>
#include <vector>

using namespace std;

// 1. Base Class (Parent)
class Relawan {
protected:
    string idRelawan;
    string nama;
    string asalKota;

public:
    Relawan(string id, string nama, string asalKota) {
        this->idRelawan = id;
        this->nama = nama;
        this->asalKota = asalKota;
    }

    virtual void displayInfo() const {
        cout << "ID: " << idRelawan << " | Nama: " << nama << " | Asal: " << asalKota;
    }

    virtual ~Relawan() {}
};

// 2. Child Class 1 (Hierarchical Inheritance)
class RelawanMedis : public Relawan {
private:
    string keahlian;
    string noSTR;

public:
    RelawanMedis(string id, string nama, string asalKota, string keahlian, string noSTR)
        : Relawan(id, nama, asalKota) {
        this->keahlian = keahlian;
        this->noSTR = noSTR;
    }

    void displayInfo() const override {
        Relawan::displayInfo();
        cout << " | Keahlian: " << keahlian << " | No STR: " << noSTR << endl;
    }
};

// 3. Child Class 2 (Hierarchical Inheritance)
class RelawanLogistik : public Relawan {
private:
    string areaFokus;
    int kapasitasBawaKg;

public:
    RelawanLogistik(string id, string nama, string asalKota, string areaFokus, int kapasitas)
        : Relawan(id, nama, asalKota) {
        this->areaFokus = areaFokus;
        this->kapasitasBawaKg = kapasitas;
    }

    void displayInfo() const override {
        Relawan::displayInfo();
        cout << " | Fokus: " << areaFokus << " | Kapasitas Distribusi: " << kapasitasBawaKg << " kg" << endl;
    }
};

// 4. Component Class (Untuk Komposisi)
class ProgramMisi {
private:
    string namaTugas;
    string lokasiBencana;

public:
    ProgramMisi(string misi, string lokasi) {
        this->namaTugas = misi;
        this->lokasiBencana = lokasi;
    }

    void displayMisi() const {
        cout << "========================================" << endl;
        cout << "TUGAS DI POSKO : "           << namaTugas << endl;
        cout << "LOKASI         : "       << lokasiBencana << endl;
        cout << "========================================" << endl;
    }
};

// 5. Composite Class (Menerapkan Komposisi & Array of Object)
class PoskoRelawan {
private:
    string kodePosko;
    ProgramMisi misi;                         // Komposisi: Misi adalah tugas bagian tetap dari Posko
    vector<RelawanMedis> relawanMedis;        // Array of Objects
    vector<RelawanLogistik> relawanLogistik;  // Array of Objects

public:
    PoskoRelawan(string kode, string namaTugas, string lokasi)
        : misi(namaTugas, lokasi) {
        this->kodePosko = kode;
    }

    void tambahMedis(const RelawanMedis& r) {
        relawanMedis.push_back(r);
    }

    void tambahLogistik(const RelawanLogistik& r) {
        relawanLogistik.push_back(r);
    }

    void cetakData(const string& status) const {
        cout << "\n>>> STATUS DATA: " << status << " <<<\n";
        cout << "Kode Posko: " << kodePosko << endl;
        misi.displayMisi();

        cout << "\n[TIM RELAWAN MEDIS]" << endl;
        if (relawanMedis.empty()) {
            cout << "(Belum ada data relawan medis)" << endl;
        } else {
            for (const auto& m : relawanMedis) {
                m.displayInfo();
            }
        }

        cout << "\n[TIM RELAWAN LOGISTIK]" << endl;
        if (relawanLogistik.empty()) {
            cout << "(Belum ada data relawan logistik)" << endl;
        } else {
            for (const auto& l : relawanLogistik) {
                l.displayInfo();
            }
        }
        cout << "----------------------------------------\n";
    }
};

int main() {
    // Inisialisasi Posko
    PoskoRelawan posko("POSKO-KITABISA", "Tanggap Darurat Banjir", "Bandung");

    // Menambahkan data awal
    posko.tambahMedis(RelawanMedis("M01", "dr. Tirta", "Jakarta", "Dokter Umum", "STR-1092"));
    posko.tambahLogistik(RelawanLogistik("L01", "Nuroni Fanjaufi", "Bandung", "Distribusi Pangan", 40));

    // 1. Tampilkan data SEBELUM penambahan
    posko.cetakData("SEBELUM PENAMBAHAN DATA");

    // 2. Tambah data baru (statis)
    cout << "\n[*] Melakukan penambahan data relawan baru...\n";
    posko.tambahMedis(RelawanMedis("M02", "Alvitra", "Surabaya", "Perawat Gawat Darurat", "STR-4481"));
    posko.tambahLogistik(RelawanLogistik("L02", "Chlaudiah", "Yogyakarta", "Manajemen Shelter", 25));

    // 3. Tampilkan data SESUDAH penambahan
    posko.cetakData("SESUDAH PENAMBAHAN DATA");

    return 0;
}