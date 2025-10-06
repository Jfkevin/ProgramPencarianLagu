# 🎵 Program Pencarian Lagu (C Language)

Program ini dibuat menggunakan **bahasa pemrograman C** dengan tujuan untuk **mencari dan mengurutkan data lagu** dari sebuah file teks bernama `database_musik.txt`.

Program ini merupakan implementasi konsep **Sorting dan Searching Algorithms** (Bubble Sort, Insertion Sort, Selection Sort, dan Binary Search), serta penerapan **menu interaktif berbasis CLI (Command Line Interface)**.

<img width="495" height="458" alt="Screenshot 2025-10-05 215844" src="https://github.com/user-attachments/assets/ce45a716-bd0d-4bac-a80d-244cf3b3240c" />

<img width="447" height="319" alt="Screenshot 2025-10-05 215932" src="https://github.com/user-attachments/assets/ec1e3de8-723c-4ac4-9a4e-a930f6d56329" />

---

## 🧠 Deskripsi Program

Program ini akan membaca data lagu dari file eksternal `database_musik.txt`.  
Setelah file dibaca, pengguna akan disuguhkan menu utama yang berisi tiga pilihan:

1. **Sort**  
   Mengurutkan data lagu berdasarkan:
   - **Judul Lagu**  
   - **Tahun Rilis**  

   Pengguna dapat memilih salah satu algoritma pengurutan berikut:
   - 🔹 Bubble Sort  
   - 🔹 Insertion Sort  
   - 🔹 Selection Sort  

   Setelah proses pengurutan selesai, hasil sort akan ditampilkan dan disimpan sebagai tampilan default di menu utama berikutnya.

2. **Search**  
   Terdapat dua jenis pencarian:
   - 🔍 **Search berdasarkan Judul Lagu**  
     Program akan melakukan **sorting berdasarkan judul lagu** terlebih dahulu, kemudian menggunakan **Binary Search** untuk mencari data.
     - Jika lagu ditemukan, akan ditampilkan seluruh informasinya.
     - Jika tidak ditemukan, akan ditampilkan pesan *"Lagu tidak ditemukan dalam database."*
   
   - 🔍 **Search berdasarkan Tahun Rilis**  
     Program akan mencari semua lagu yang rilis pada tahun tertentu menggunakan **Linear Search atau metode lain yang sesuai**.  
     Hasil pencarian ditampilkan dalam bentuk daftar lagu.

3. **Exit**  
   Keluar dari program.

---

## 📄 Struktur File Database

File `database_musik.txt` berisi daftar lagu dengan format berikut:

---

## 📚 Mata Kuliah

Algoritma dan Struktur Data - IF 232

Program Studi Informatika

Fakultas Teknik dan Informatika

🏫 Universitas Multimedia Nusantara (UMN)

