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

Solusi paralel yang kami buat adalah paralelisasi dalam menjalankan algoritma dijkstra. Sebagaimana yang diketahui, algoritma dijkstra dapat mencari jarak terdekat dari suatu node ke semua node lain. Oleh karena pada persoalan yang diberikan kita diminta untuk mencari jarak dari semua node ke semua node lain, paralelisasi yang kami lakukan adalah setiap thread menjalankan dijkstra dari titik asal (source) yang berbeda-beda, lalu kemudian dikumpulkan pada satu thread master untuk dilakukan pencatatan akhir jarak setiap node yang dihitung pada masing-masing thread.


### Analisis Solusi
`BELOMAN`


### Hasil Uji
Berikut Merupakan hasil uji yang kami lakukan untuk node 100, 500, 1000, dan 3000 baik untuk Serial Dijkstra dan Paralel Dijkstra (dalam seconds):

* **Serial Dijkstra**

| N             | Percobaan 1   | Percobaan 2 | Percobaan 3 | Rata-rata           |
| ------------- |:-------------:| -----:| ------------- |:-------------:|
| 100      | 0.011085 | 0.01106 | 0.011177 | 0.01110733333 |
| 500      | 1.209287 | 1.19514 | 1.189376 | 1.19793433333 |
| 1000     | 9.63809 | 9.648635 | 9.691299 | 9.65934133333 |
| 3000     | 289.04144 | 290.054272 | 289.371232 | 289.488981333 |


* **Paralel Dijkstra OpenMP**

| N             | Percobaan 1   | Percobaan 2 | Percobaan 3 | Rata-rata           |
| ------------- |:-------------:| -----:| ------------- |:-------------:|
| 100      | 0.279115 | 0.28755525 | 0.296497 | 0.28772241666 |
| 500      | 141.22473825 | 160.160105 | 155.14105175 | 152.175298333 |
| 1000     | 2646.930331 | 2650.61712975 | 2651.74764425 | 2649.765035 |
| 3000     | 232189.652940250002 | 238495.246832749981 | 241372.985165749997 | 237352.628313 |


### Analisis Uji
`BELOMAN`