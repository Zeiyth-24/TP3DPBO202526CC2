# Tugas Praktikum 3 - Desain dan Pemrograman Berorientasi Objek 2026

## Janji
Saya Zufar Ahmad Maulidy dengan NIM 2400285 mengerjakan Tugas Praktikum 3 dalam mata kuliah Desain dan Pemrograman Berorientasi Objek untuk keberkahan-Nya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.

                         ┌──────────────────┐
                         │     Relawan      │
                         ├──────────────────┤
                         │ idRelawan        │
                         │ nama             │
                         │ asalKota         │
                         ├──────────────────┤
                         │ displayInfo()    │
                         └────────┬─────────┘
                                  │
                    ┌─────────────┴─────────────┐
                    │                           │
                    ▼                           ▼
        ┌─────────────────────┐     ┌──────────────────────┐
        │   RelawanMedis      │     │  RelawanLogistik     │
        ├─────────────────────┤     ├──────────────────────┤
        │ keahlian            │     │ areaFokus            │
        │ noSTR               │     │ kapasitasBawaKg      │
        ├─────────────────────┤     ├──────────────────────┤
        │ displayInfo()       │     │ displayInfo()        │
        └─────────────────────┘     └──────────────────────┘
                    ▲                           ▲
                    │                           │
                    │                           │
                    └───────────┬───────────────┘
                                │
                                │ dikelola oleh
                                │
                         ┌──────┴───────┐
                         │ PoskoRelawan │
                         ├──────────────┤
                         │ kodePosko    │
                         │ tugas        │─────────────┐
                         │ timMedis     │             │
                         │ timLogistik  │             │
                         ├──────────────┤             │
                         │ tambahMedis()│             │
                         │ tambahLog()  |             │
                         │ cetakData()  │             │
                         └──────────────┘             │
                                                      │
                                                      ▼
                                            ┌─────────────────┐
                                            │  ProgramTugas   │
                                            ├─────────────────┤
                                            │ namaTugas       │
                                            │ lokasiBencana   │
                                            ├─────────────────┤
                                            │ displayTugas()  │
                                            └─────────────────┘


Dokumentasi Program Relawan
1. Penjelasan Atribut dan Method Setiap Kelas
Class Relawan (Base Class)

Relawan merupakan kelas dasar yang menyimpan identitas umum yang dimiliki oleh setiap relawan.

Atribut
Atribut	Tipe Data	Deskripsi
idRelawan	string	Identitas unik relawan.
nama	string	Nama lengkap relawan.
asalKota	string	Kota asal relawan.
Method
Method	Deskripsi
displayInfo()	Menampilkan atribut dasar relawan.
Class RelawanMedis (Child Class dari Relawan)

RelawanMedis merupakan kelas turunan dari Relawan yang digunakan untuk menyimpan informasi khusus relawan di bidang medis.

Atribut
Atribut	Tipe Data	Deskripsi
keahlian	string	Spesialisasi medis, seperti Dokter, Perawat, dan lain-lain.
noSTR	string	Nomor Surat Tanda Registrasi profesi.
Method
Method	Deskripsi
displayInfo()	Melakukan override terhadap method dari parent class untuk menampilkan atribut dasar serta data medis.
Class RelawanLogistik (Child Class dari Relawan)

RelawanLogistik merupakan kelas turunan dari Relawan yang digunakan untuk menyimpan informasi khusus relawan di bidang logistik.

Atribut
Atribut	Tipe Data	Deskripsi
areaFokus	string	Konsentrasi tugas logistik, seperti distribusi pangan, shelter, dan lain-lain.
kapasitasBawaKg	int	Kapasitas beban logistik yang dapat dikelola dalam satuan kilogram (kg).
Method
Method	Deskripsi
displayInfo()	Melakukan override terhadap method dari parent class untuk menampilkan atribut dasar serta kapasitas logistik.
Class TugasdiProgram (Component Class)

TugasdiProgram merupakan kelas komponen yang menyimpan informasi mengenai agenda operasi kemanusiaan yang sedang dijalankan.

Atribut
Atribut	Tipe Data	Deskripsi
namaTugas	string	Nama agenda operasi kemanusiaan.
lokasiBencana	string	Wilayah penugasan atau lokasi bencana.
Method
Method	Deskripsi
displayTugas()	Mencetak detail informasi mengenai Tugas.
Class PoskoRelawan (Composite Class)

PoskoRelawan merupakan kelas utama yang mengelola informasi posko, Tugas, serta kumpulan relawan yang bertugas di dalamnya.

Atribut
Atribut	Tipe Data	Deskripsi
kodePosko	string	Kode identifikasi posko.
Tugas	TugasdiProgram	Objek Tugas yang dimiliki oleh posko melalui hubungan komposisi.
timMedis	vector/list	Koleksi objek RelawanMedis.
timLogistik	vector/list	Koleksi objek RelawanLogistik.
Method
Method	Deskripsi
tambahMedis(RelawanMedis)	Menambahkan objek relawan medis ke dalam koleksi timMedis.
tambahLogistik(RelawanLogistik)	Menambahkan objek relawan logistik ke dalam koleksi timLogistik.
cetakData(string status)	Menampilkan data posko, informasi Tugas, serta daftar seluruh relawan yang terdaftar.
2. Penjelasan Desain Program
Hierarchical Inheritance

Program menerapkan konsep Hierarchical Inheritance, yaitu satu base class memiliki beberapa child class.

Struktur pewarisannya adalah:

                 Relawan
                /       \
               /         \
      RelawanMedis   RelawanLogistik


Kelas Relawan menjadi base class yang menyimpan identitas dasar setiap relawan.

Kemudian, kelas:

RelawanMedis

RelawanLogistik

diturunkan dari kelas Relawan.

Kedua kelas tersebut mewarisi atribut dan method dasar dari Relawan, tetapi masing-masing memiliki atribut tambahan sesuai bidang tugasnya.

RelawanMedis memiliki data khusus seperti:

keahlian

noSTR

Sedangkan RelawanLogistik memiliki data khusus seperti:

areaFokus

kapasitasBawaKg

Keduanya juga melakukan override terhadap method displayInfo() sehingga informasi yang ditampilkan dapat disesuaikan dengan jenis relawannya.

Composition

Program juga menerapkan konsep Composition antara kelas PoskoRelawan dan TugasdiProgram.

Hubungan tersebut dapat digambarkan sebagai berikut:

PoskoRelawan
     |
     | memiliki
     v
TugasdiProgram


Kelas PoskoRelawan memiliki objek TugasdiProgram sebagai bagian dari dirinya.

Objek TugasdiProgram dibuat dan dimiliki langsung oleh PoskoRelawan, sehingga objek Tugas memiliki keterikatan kuat dengan siklus hidup objek posko.

Dengan demikian, ketika objek PoskoRelawan sudah tidak ada, objek TugasdiProgram yang menjadi bagiannya juga ikut berakhir.

Array of Objects

Program menggunakan array of objects untuk menyimpan banyak data relawan.

Pada C++, koleksi tersebut menggunakan:

std::vector


Sedangkan pada Python menggunakan:

list


Koleksi tersebut digunakan untuk menampung objek relawan secara dinamis, yaitu:

PoskoRelawan
├── timMedis
│   ├── RelawanMedis
│   ├── RelawanMedis
│   └── ...
│
└── timLogistik
    ├── RelawanLogistik
    ├── RelawanLogistik
    └── ...


Dengan menggunakan vector atau list, jumlah relawan yang dapat ditambahkan ke dalam posko tidak perlu ditentukan secara statis sejak awal.

3. Penjelasan Alur Program

Secara umum, alur program berjalan melalui beberapa tahapan berikut:

1. Inisialisasi Posko

Program menginisialisasi objek PoskoRelawan.

Pada proses tersebut, objek TugasdiProgram juga dibentuk sebagai bagian dari PoskoRelawan karena menggunakan konsep Composition.

Program dimulai
      ↓
Membuat PoskoRelawan
      ↓
Membentuk TugasdiProgram

2. Menambahkan Data Relawan Awal

Program kemudian menambahkan data relawan awal ke dalam posko, yaitu:

Relawan medis

Relawan logistik

Data tersebut disimpan pada koleksi masing-masing.

PoskoRelawan
├── timMedis
│   └── Data relawan medis awal
│
└── timLogistik
    └── Data relawan logistik awal

3. Menampilkan Status Sebelum Penambahan

Program mencetak seluruh data posko ke terminal dengan status:

SEBELUM PENAMBAHAN DATA


Informasi yang ditampilkan meliputi:

Kode posko

Informasi Tugas

Daftar relawan medis

Daftar relawan logistik

4. Menambahkan Data Relawan Baru

Program kemudian melakukan penambahan data relawan baru secara statis ke dalam objek PoskoRelawan.

Relawan baru dapat berupa:

RelawanMedis

RelawanLogistik

5. Menampilkan Status Setelah Penambahan

Setelah data baru berhasil ditambahkan, program mencetak kembali seluruh data dengan status:

SESUDAH PENAMBAHAN DATA


Pada tahap ini, daftar relawan sudah berisi data awal dan data baru yang telah ditambahkan.

4. Dokumentasi Output

Program tersedia dalam dua implementasi bahasa pemrograman:

C++

Python

Output C++

Contoh output program C++:

<img width="1470" height="956" alt="Screenshot 2026-10-06 at 14 38 04" src="https://github.com/user-attachments/assets/2ab345d3-8a15-4aec-b747-a45ac09ddb84" />

Output Python

Contoh output program Python:

<img width="1470" height="956" alt="Screenshot 2026-10-06 at 14 39 23" src="https://github.com/user-attachments/assets/2239a012-0f08-4a55-96cb-62e2c7536d39" />

5. Ringkasan Konsep OOP

Program ini menerapkan beberapa konsep utama Object-Oriented Programming (OOP), yaitu:

Konsep OOP	Implementasi
Inheritance	RelawanMedis dan RelawanLogistik mewarisi Relawan.
Hierarchical Inheritance	Satu base class (Relawan) memiliki dua child class.
Method Overriding	displayInfo() pada child class meng-override method dari Relawan.
Composition	PoskoRelawan memiliki objek TugasdiProgram.
Array of Objects	vector pada C++ dan list pada Python digunakan untuk menyimpan kumpulan relawan.
Encapsulation	Data dan method dikelompokkan berdasarkan tanggung jawab masing-masing class.
