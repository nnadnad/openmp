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
| 100      | xx | xx | xx      | xx |
| 500      | xx | xx | xx      | xx |
| 1000     | xx | xx | xx      | xx |
| 3000     | xx | xx | xx      | xx |


* **Paralel Dijkstra OpenMP**

| N             | Percobaan 1   | Percobaan 2 | Percobaan 3 | Rata-rata           |
| ------------- |:-------------:| -----:| ------------- |:-------------:|
| 100      | xx | xx | xx      | xx |
| 500      | xx | xx | xx      | xx |
| 1000     | xx | xx | xx      | xx |
| 3000     | xx | xx | xx      | xx |


### Analisis Uji
`BELOMAN`