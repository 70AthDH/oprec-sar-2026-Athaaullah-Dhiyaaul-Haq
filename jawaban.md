# jawaban oprec sar Athaaullah Dhiyaaul Haq

## q1-servo

1. yang berbahaya untuk servo fisik adalah 200 dan -10. degre 200 = 2611 ms sedangkan -10 = 395
2. di fix dengan menambahkan if.

```C
int deg_to_us(int deg) {
    if (deg < 0) deg = 0;
    if (deg > 180) deg = 180;
    return 500 + 1900 * deg / 180;
    }
```

3. untuk capit yang 72 memerlukan 1260 dan yang 90 perlu 1450. rumusnya 500 + (1900 * degree) / 180 = puls.

## q2-korban || dummy ?

* yang salah adalah confident, berapa lama setelah di temukan, dan gabunga dari keduanya masih termasuk menjadi true.
* di fix dengan menambahakan.

```C
bool mau_ambil(det_t d) {
    return (d.cls == 1) && (d.age_ms <= 1000) && (d.conf >= 0.5f);
}
```

* robot tetap berada di tempat yang sama karena tidak tau korbanya di mana.

## q3-lengan 2 joint

* yang diketahui.

```none
L1 = 120 mm
L2 = 60 mm
q1 = 0.524 rad
q2 = 1.047 rad
q1 + q2 = 1.571
cos 30 = 0.866
sin 30 = 0.5
cos 90 = 0
sin 90 = 1

jadi

x = 120 * 0.866 + 60 * 0 +-= 103,9 mm

z = 120 * 0.5 + 60 * 1 = 120 mm
```

* maksimum = 120 + 60 = 180, minimum = 120 - 60 = 60

* maka.

```none
(-40 + 140)^2 = sqrt(1600 + 19600) = sqrt(21200) +-= 145,6

(-100 + 80)^2 = sqrt(10000 + 6400) = sqrt(16400) +-= 128

kedua titik ini berada di titik jangkauan capit.
```

## q4-kecepatan VS langkah "J

* rumus:

```none
stride diminta = (speed_mms * tran_ms)/1000

tran = 320
potongan kalu lewat 35 mm

s1 = 50 * 320 / 1000 = 16 mm dibawah 35 mm
s2 = 100 * 320 / 1000 = 32mm masih dibawah 35 mm
s3 = 150 * 320 / 1000 = 48 mm kepotong jadi 35 mm
s4 = 200 * 320 / 1000 = 64 mm kepotong jadi 35 mm

pemotonga mulai di speed = 35 * 1000 / 320 +-= 109 mm
```

* di uji pada kecepatan 60, 80, 100, dan 108 mms dengan tran = 320. yang diukur setiap percobaan adalah waktu tempu 1m, drift arah penyimpang ke arah kiri atau kanan, dan jumlah selip yang mengamati seberapa frkuensi slipnya.

* yang diketahui.

```none
bias bawaan = +4.5 /s
otoritas belok = 13.7 rad/s

koreksi min = -4.5/13.7 = +-= 0.33 rad/s 

sebenernya cukup tapi terlalu dikit sisanya kalau ada error tambahan dari ganguan luar .

sebaiknya menambahkan batas korksi dan gunnakan feed forward.

```

## q5-melihat dan buat keputusan :O

* jadi korban persis ada di depan hidung berarti 0.0 tapi robot melihat korban +6.0 berarti trim harus dikalibrasi ulang dengan rumus.

```none
6.0 + trim = 0 maka trim adalah -6.0
```

* kenapa tolak dummy? karena buang buang waktu dan salah target. kenapa tolak umur dibawah 1000 karena informasi data sudah basi dan korban sudah pindah. confident rendah ditolak kenapa? karena benda tidak di kenali dan bisa mengira dummy adalah korban. kenapa tolak jarak misterious? karena tanpa informasi jelas robot tidak bisa mengetahui kepastian posisi seperti mengetahui target yag sudah jelas informasi tempatnya untuk menghindari kesalahan manuver.

* strateginya adalah dekati pelan pelan sambil meminta konfirmasi ulang mengumpulan beberapa frame  deteksi berikutnya untuk memastikan korban beneran ada.

    resikonya adalah malah mengambil dummy dan melewati korban.

    penyebab pertama adalah perubaha cahaya, cara mengatasinya dengan menambahkan lampu LED, mengunakan white balance camera, dan mengunci exposure.

    sudut pandang 45 derajat. jangan memutuskan dengan satu frame saja tapi gunakan banyak dari rata rata.



