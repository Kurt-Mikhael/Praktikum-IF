/* File: time.h */
/* Definisi ADT TIME */

#ifndef TIME_H
#define TIME_H

#include "boolean.h"
#include <stdio.h>
/* *** Definisi TYPE TIME <HH:MM:SS> *** */
typedef struct { 
	int HH; /* integer [0..23] */
	int MM; /* integer [0..59] */
	int SS; /* integer [0..59] */
} TIME;

/* *** Notasi Akses: selektor TIME *** */
#define Hour(T) (T).HH
#define Minute(T) (T).MM
#define Second(T) (T).SS

/* ***************************************************************** */
/* DEFINISI PRIMITIF                                                 */
/* ***************************************************************** */
/* KELOMPOK VALIDASI TERHADAP TYPE                                   */
/* ***************************************************************** */
boolean IsTIMEValid (int H, int M, int S){
    if(H < 0 || H > 23){
        return false;
    } else if (M < 0 || M > 59){
        return false;
    } else if (S < 0 || S > 59){
        return false;
    } else {
        return true;
    }
}
/* Mengirim true jika H,M,S dapat membentuk T yang valid */
/* dipakai untuk mentest SEBELUM membentuk sebuah Jam */

/* *** Konstruktor: Membentuk sebuah TIME dari komponen-komponennya *** */
void CreateTime (TIME * T, int HH, int MM, int SS){
    Hour(*T)= HH;
    Minute(*T)= MM;
    Second(*T)= SS;
}
/* Membentuk sebuah TIME dari komponen-komponennya yang valid */
/* Prekondisi : HH, MM, SS valid untuk membentuk TIME */

/* ***************************************************************** */
/* KELOMPOK BACA/TULIS                                               */
/* ***************************************************************** */
void BacaTIME (TIME * T){
/* I.S. : T tidak terdefinisi */
/* F.S. : T terdefinisi dan merupakan jam yang valid */
/* Proses : mengulangi membaca komponen HH, MM, SS sehingga membentuk T */
/* yang valid. Tidak mungkin menghasilkan T yang tidak valid. */
/* Pembacaan dilakukan dengan mengetikkan komponen HH, MM, SS
   dalam satu baris, masing-masing dipisahkan 1 spasi, diakhiri enter. */
/* Jika TIME tidak valid maka diberikan pesan: "Jam tidak valid", dan pembacaan
   diulangi hingga didapatkan jam yang valid. */
/* Contoh: 
   60 3 4
   Jam tidak valid
   1 3 4
   --> akan terbentuk TIME <1,3,4> */
   int H, M, S;
    boolean valid = false;
    while (!valid)
    {
        scanf("%d %d %d", &H, &M, &S);
        if (IsTIMEValid(H, M, S))
        {
            CreateTime(T, H, M, S);
            valid = true;
        }
        else
        {
            printf("Jam tidak valid\n");
        }
    }
    
}  
void TulisTIME (TIME T){
/* I.S. : T sembarang */
/* F.S. : Nilai T ditulis dg format HH:MM:SS */
/* Proses : menulis nilai setiap komponen T ke layar dalam format HH:MM:SS
   tanpa karakter apa pun di depan atau belakangnya, termasuk spasi, enter, dll.*/

    printf("%d:%d:%d", Hour(T), Minute(T), Second(T));
} 

/* ***************************************************************** */
/* KELOMPOK KONVERSI TERHADAP TYPE                                   */
/* ***************************************************************** */


long TIMEToDetik (TIME T){
/* Diberikan sebuah TIME, mengkonversi menjadi jumlah detik dari pukul 0:0:0 */
/* Rumus : detik = 3600*HH + 60*MM + SS */
/* Nilai maksimum = 3600*23+59*60+59 */     
    long detik = 0;
    detik = (3600 * Hour(T)) + (60 * Minute(T)) + Second(T);
    return detik;
}

TIME DetikToTIME (long N){
/* Mengirim  konversi detik ke TIME */
/* Catatan: Jika N >= 86400, maka harus dikonversi dulu menjadi jumlah detik yang 
   mewakili jumlah detik yang mungkin dalam 1 hari, yaitu dengan rumus: 
   N1 = N mod 86400, baru N1 dikonversi menjadi TIME */
   if (N >= 86400)
   {
       N = N % 86400;
   }
    TIME T;
    int HH, MM, SS;
    HH = N / 3600;
    N = N % 3600;
    MM = N / 60;
    N = N % 60;
    SS = N;
    CreateTime(&T, HH, MM, SS);
    return T;

}
/* ***************************************************************** */
/* KELOMPOK OPERASI TERHADAP TYPE                                    */
/* ***************************************************************** */
/* *** Kelompok Operator Relational *** */
boolean TEQ (TIME T1, TIME T2){
    if(Hour(T1) == Hour(T2) && Minute(T1) == Minute(T2) && Second(T1) == Second(T2)){
        return true;
    } else {
        return false;
    }
}
/* Mengirimkan true jika T1=T2, false jika tidak */
boolean TNEQ (TIME T1, TIME T2){
    if(Hour(T1) == Hour(T2) && Minute(T1) == Minute(T2) && Second(T1) == Second(T2)){
        return false;
    } else {
        return true;
    }
}
/* Mengirimkan true jika T1 tidak sama dengan T2 */
boolean TLT (TIME T1, TIME T2){
    long time1 = TIMEToDetik(T1);
    long time2 = TIMEToDetik(T2);
    if(time1 < time2){
        return true;
    } else {
        return false;
    }
}
/* Mengirimkan true jika T1<T2, false jika tidak */
boolean TGT (TIME T1, TIME T2){
    long time1 = TIMEToDetik(T1);
    long time2 = TIMEToDetik(T2);
    if(time1 > time2){
        return true;
    } else {
        return false;
    }
}
/* Mengirimkan true jika T1>T2, false jika tidak */
/* *** Operator aritmatika TIME *** */
TIME NextDetik (TIME T){
    long detik = TIMEToDetik(T);
    detik += 1;
    if (detik >= 86400)
    {
        detik = detik % 86400;
    }
    T = DetikToTIME(detik);
    return T;
}
/* Mengirim 1 detik setelah T dalam bentuk TIME */
TIME NextNDetik (TIME T, int N){
    {
        long detik = TIMEToDetik(T);
        detik += N;
        if (detik >= 86400)
        {
            detik = detik % 86400;
        }
        T = DetikToTIME(detik);
        return T;
    }
}
/* Mengirim N detik setelah T dalam bentuk TIME */
TIME PrevDetik (TIME T){
    long detik = TIMEToDetik(T);
    detik -= 1;
    if (detik < 0)
    {
        detik = 86400 + detik;
    }
    T = DetikToTIME(detik);
    return T;
}
/* Mengirim 1 detik sebelum T dalam bentuk TIME */
TIME PrevNDetik (TIME T, int N){
    long detik = TIMEToDetik(T);
    detik -= N;
    if (detik < 0)
    {
        detik = 86400 + detik;
    }
    T = DetikToTIME(detik);
    return T;
}
/* Mengirim N detik sebelum T dalam bentuk TIME */
/* *** Kelompok Operator Aritmetika *** */
long Durasi (TIME TAw, TIME TAkh){
    long detikAw, detikAkh;
    detikAw = TIMEToDetik(TAw);
    detikAkh = TIMEToDetik(TAkh);
    if (detikAkh < detikAw)
    {
        detikAkh = 86400 + detikAkh;
    }
    return (detikAkh - detikAw);
}
/* Mengirim TAkh-TAw dlm Detik, dengan kalkulasi */
/* Jika TAw > TAkh, maka TAkh adalah 1 hari setelah TAw */

#endif