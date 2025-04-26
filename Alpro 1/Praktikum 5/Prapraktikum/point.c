#ifndef POINT_H
#define POINT_H

#include "boolean.h"  

/* Definisi type POINT */
typedef struct {
    float X;  /* absis (sumbu X) */
    float Y;  /* ordinat (sumbu Y) */
} POINT;

/* Macro selektor komponen */
#define Absis(P)   (P).X
#define Ordinat(P) (P).Y

/* Membentuk POINT P dengan komponen X dan Y */
void CreatePoint(POINT *P, float X, float Y){
    Absis(*P) = X;
    Ordinat(*P) = Y;
}
/* Membaca nilai POINT dari stdin: masukkan X Y */
void BacaPOINT(POINT *P){
    float X, Y;
    scanf("%f %f", &X, &Y);
    CreatePoint(P, X, Y);
}
/* Menulis POINT ke stdout dalam format "(X,Y)" */
void TulisPOINT(POINT P){
    printf("(%f,%f)", Absis(P), Ordinat(P));
}

/* Mengambil / mengubah komponen X dan Y */
float GetX(const POINT P){
    return Absis(P);
}
float GetY(const POINT P){
    return Ordinat(P);
}
void  SetX(POINT *P, float X){
    Absis(*P) = X;
}
void  SetY(POINT *P, float Y){
    Ordinat(*P) = Y;
}

/* Mengecek lokasi POINT pada sumbu atau kuadran */
boolean IsOrigin(POINT P){
    if(Absis(P) == 0 && Ordinat(P) == 0){
        return true;
    } else {
        return false;
    }
}     /* true jika P = (0,0) */
boolean IsOnSbX(POINT P){
    if(Ordinat(P) == 0){
        return true;
    } else {
        return false;
    }
}      /* true jika Y = 0 */
boolean IsOnSbY(POINT P){      /* true jika X = 0 */
    if(Absis(P) == 0){
        return true;
    } else {
        return false;
    }
}
int     Kuadran(POINT P){
    if(Absis(P) > 0 && Ordinat(P) > 0){
        return 1;
    } else if(Absis(P) < 0 && Ordinat(P) > 0){
        return 2;
    } else if(Absis(P) < 0 && Ordinat(P) < 0){
        return 3;
    } else if(Absis(P) > 0 && Ordinat(P) < 0){
        return 4;
    } else {
        return 0;
    }
}      /* 1..4; prekondisi: P bukan origin dan tidak di sumbu */

/* Membandingkan dua POINT */
boolean Equals(POINT P1, POINT P2){
    if(Absis(P1) == Absis(P2) && Ordinat(P1) == Ordinat(P2)){
        return true;
    } else {
        return false;
    }
}   /* true jika X dan Y identik */
boolean NonEquals(POINT P1, POINT P2){
    if(Absis(P1) != Absis(P2) || Ordinat(P1) != Ordinat(P2)){
        return true;
    } else {
        return false;
    }
    
}/* negasi Equals */

/* Menghitung jarak Euclidean antara P1 dan P2, Gunakan fungsi sqrtf dari math.h untuk menghitung akar kuadrat */
#include <math.h>
float  Distance(POINT P1, POINT P2){
    return sqrtf(powf(Absis(P1) - Absis(P2), 2) + powf(Ordinat(P1) - Ordinat(P2), 2));
}
/* Menghasilkan titik tengah P1 dan P2 */
POINT  MidPoint(POINT P1, POINT P2){
    POINT Tengah;
    Absis(Tengah) = (Absis(P1) + Absis(P2)) / 2;
    Ordinat(Tengah) = (Ordinat(P1) + Ordinat(P2)) / 2;
    return Tengah;
}

#endif  /* POINT_H */