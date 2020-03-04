# KELAS 02 - KELOMPOK 6

## Petunjuk Penggunaan Program
Dalam direktori root lakukan kompilasi program dengan makefile:

* Untuk melakukan kompilasi dijkstra versi serial:

`make serial`

`bin/serial [number of vertices]`

* Untuk melakukan kompilasi dijkstra versi paralel (OpenMP):

`make paralel_omp nt=[jumlah thread] nv=[jumlah nodes]`

## Pembagian Tugas
* 13517122 - M. ALgah Fattah I. : Paralel DIjksta OpenMP, Laporan, Eksplorasi
* 13517128 - Yudy Valentino : Debug Paralel Dijkstra OpenMP, Laporan, Eksplorasi

## Laporan Pengerjaan
### Deskripsi Solusi Paralel

Solusi paralel yang kami buat adalah paralelisasi dalam menjalankan algoritma dijkstra secara keseluruhan. Sebagaimana yang diketahui, algoritma dijkstra dapat mencari jarak terdekat dari suatu node ke semua node lain. Oleh karena pada persoalan yang diberikan kita diminta untuk mencari jarak dari semua node ke semua node lain, paralelisasi yang kami lakukan adalah setiap thread menjalankan dijkstra dari titik asal (source) yang berbeda-beda, lalu kemudian menuliskan hasil jarak antara titik-titik lain dengan source tersebut pada baris yang bersangkutan di matriks yang merepresentasikan hasil akhir.

Misalkan ada 3 anak proses dan ada 3 node pada graf yang di-proses, maka diparalelisasi sehingga anak proses pertama memproses node A, anak proses kedua memproses node B, dan anak proses ketiga memproses node C. Misalkan pula sebuah matriks akhir `result` yang menyimpan matriks akhir, maka anak proses pertama akan menuliskan ke baris pertama `result` yang merepresentasikan jarak dari node A ke node-node lain, dst.


### Analisis Solusi
Dalam konteks memparalelisasi algoritma dijkstra, menurut kami jika dapat dilakukan pengisian matriks menggunakan `memcpy()` di-dalam suatu proses anak maka solusi akan jauh lebih teroptimasi.


### Hasil Uji
Berikut Merupakan hasil uji yang kami lakukan untuk node 100, 500, 1000, dan 3000 baik untuk Serial Dijkstra dan Paralel Dijkstra (dalam seconds):

* **Serial Dijkstra**

| N             | Percobaan 1   | Percobaan 2 | Percobaan 3 | Rata-rata           |
| ------------- |:-------------:| -----:| ------------- |:-------------:|
| 100      | 11.085 | 11.06 | 11.177 | 11.1073333333 |
| 500      | 1209.287 | 1195.14 | 1189.376 | 1197.93433333 |
| 1000     | 9638.09 | 9648.635 | 9691.299 | 9659.34133333 |
| 3000     | 289041.44 | 290054.272 | 289371.232 | 289488.981333 |


* **Paralel Dijkstra OpenMP**

| N             | Percobaan 1   | Percobaan 2 | Percobaan 3 | Rata-rata           |
| ------------- |:-------------:| -----:| ------------- |:-------------:|
| 100      | 0.279115 | 0.28755525 | 0.296497 | 0.28772241666 |
| 500      | 141.22473825 | 160.160105 | 155.14105175 | 152.175298333 |
| 1000     | 2646.930331 | 2650.61712975 | 2651.74764425 | 2649.765035 |
| 3000     | 232189.652940250002 | 238495.246832749981 | 241372.985165749997 | 237352.628313 |

**Thread yang digunakan untuk Paralel Dijkstra OpenMP = 4**


### Analisis Uji
Dari seluruh percobaan yang dilakukan, didapatkan bahwa program paralel selalu lebih cepat daripada program serial. 
Hal ini tentu karena paralelisasi lebih mengutilisasi resource yang ada dengan thread yang lebih dari 1 menjadikan proses lebih cepat.