# 1. Base Class (Parent)
class Relawan:
    def __init__(self, id_relawan, nama, asal_kota):
        self._id_relawan = id_relawan
        self._nama = nama
        self._asal_kota = asal_kota

    def display_info(self):
        return f"ID: {self._id_relawan} | Nama: {self._nama} | Asal: {self._asal_kota}"

# 2. Child Class 1 (Hierarchical Inheritance)
class RelawanMedis(Relawan):
    def __init__(self, id_relawan, nama, asal_kota, keahlian, no_str):
        super().__init__(id_relawan, nama, asal_kota)
        self.__keahlian = keahlian
        self.__no_str = no_str

    def display_info(self):
        return f"{super().display_info()} | Keahlian: {self.__keahlian} | No STR: {self.__no_str}"

# 3. Child Class 2 (Hierarchical Inheritance)
class RelawanLogistik(Relawan):
    def __init__(self, id_relawan, nama, asal_kota, area_fokus, kapasitas_kg):
        super().__init__(id_relawan, nama, asal_kota)
        self.__area_fokus = area_fokus
        self.__kapasitas_kg = kapasitas_kg

    def display_info(self):
        return f"{super().display_info()} | Fokus: {self.__area_fokus} | Kapasitas Distribusi: {self.__kapasitas_kg} kg"

# 4. Component Class (Untuk Komposisi)
class Programtugas:
    def __init__(self, nama_tugas, lokasi_bencana):
        self.nama_tugas = nama_tugas
        self.lokasi_bencana = lokasi_bencana

    def display_tugas(self):
        print("========================================")
        print(f"TUGAS DI POSKO : {self.nama_tugas}")
        print(f"LOKASI         : {self.lokasi_bencana}")
        print("========================================")

# 5. Composite Class (Komposisi & List of Objects)
class PoskoRelawan:
    def __init__(self, kode_posko, nama_tugas, lokasi):
        self.kode_posko = kode_posko
        self.tugas = Programtugas(nama_tugas, lokasi)  # Komposisi
        self.tim_medis = []                        # List of Objects
        self.tim_logistik = []                     # List of Objects

    def tambah_medis(self, relawan):
        self.tim_medis.append(relawan)

    def tambah_logistik(self, relawan):
        self.tim_logistik.append(relawan)

    def cetak_data(self, status):
        print(f"\n>>> STATUS DATA: {status} <<<")
        print(f"Kode Posko: {self.kode_posko}")
        self.tugas.display_tugas()

        print("\n[TIM RELAWAN MEDIS]")
        if not self.tim_medis:
            print("(Belum ada data relawan medis)")
        else:
            for m in self.tim_medis:
                print(m.display_info())

        print("\n[TIM RELAWAN LOGISTIK]")
        if not self.tim_logistik:
            print("(Belum ada data relawan logistik)")
        else:
            for l in self.tim_logistik:
                print(l.display_info())
        print("----------------------------------------")

def main():
    posko = PoskoRelawan("POSKO-KITABISA", "Tanggap Darurat Banjir", "Bandung")

    # Data Awal
    posko.tambah_medis(RelawanMedis("M01", "dr. Tirta", "Jakarta", "Dokter Umum", "STR-1092"))
    posko.tambah_logistik(RelawanLogistik("L01", "Annida", "Bandung", "Distribusi Pangan", 40))

    # 1. Tampilkan Sebelum Penambahan
    posko.cetak_data("SEBELUM PENAMBAHAN DATA")

    # 2. Tambahkan Data Baru
    print("\n[*] Melakukan penambahan data relawan baru...")
    posko.tambah_medis(RelawanMedis("M02", "Sonya", "Surabaya", "Perawat Gawat Darurat", "STR-4481"))
    posko.tambah_logistik(RelawanLogistik("L02", "Geannisa", "Yogyakarta", "Manajemen Shelter", 25))

    # 3. Tampilkan Sesudah Penambahan
    posko.cetak_data("SESUDAH PENAMBAHAN DATA")

if __name__ == "__main__":
    main()