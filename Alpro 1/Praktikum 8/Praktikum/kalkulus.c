#include "kalkulus.h"
#include "Boolean.h"
#include "matrix.h"

Matrix dilate(Matrix v, int scale){
    Matrix kurt;
    copyMatrix(v,&kurt);
    for(int i = 0; i < v.rowEff; i++){
        for(int j = 0; j < v.colEff; j++){
            kurt.mem[i][j] *= scale;
        }
    }
    return kurt;
}
/* Setiap titik (x, y) menjadi (x*scale, y*scale) */

Matrix translate(Matrix v, int dx, int dy){
    Matrix kurt;
    copyMatrix(v,&kurt);
    for(int i = 0; i < v.rowEff; i++){
        kurt.mem[i][0] += dx;
        kurt.mem[i][1] += dy;

    }
    return kurt;
}
/* Setiap titik (x, y) menjadi (x+dx, y+dy) */

Matrix reflect(Matrix v, char axis){
    Matrix kurt;
    copyMatrix(v,&kurt);
    for(int i = 0; i < v.rowEff; i++){
        if(axis == 'x'){
            kurt.mem[i][1] *= -1;
        } else{
            kurt.mem[i][0] *= -1;
        }
    }
    return kurt;

}
/* 'x' → y = -y, 'y' → x = -x */

Matrix rotate(Matrix v, int degree){
    Matrix kurt;
    copyMatrix(v,&kurt);
    for(int i = 0; i < v.rowEff; i++){
        if(degree == 0){
            kurt.mem[i][0] = kurt.mem[i][0] * 1 + kurt.mem[i][1] * 0;
            kurt.mem[i][1] = -kurt.mem[i][0] * 0 + kurt.mem[i][1] * 1;
        } else if(degree == 90){
            kurt.mem[i][0] = kurt.mem[i][0] * 0 + kurt.mem[i][1] * 1;
            kurt.mem[i][1] = -kurt.mem[i][0] * 1 + kurt.mem[i][1] * 0;
        } else if(degree == 180){
            kurt.mem[i][0] = kurt.mem[i][0] * -1 + kurt.mem[i][1] * 0;
            kurt.mem[i][1] = -kurt.mem[i][0] * 0 + kurt.mem[i][1] * -1;
        } else if(degree == 270){
            kurt.mem[i][0] = kurt.mem[i][0] * 0 + kurt.mem[i][1] * -1;
            kurt.mem[i][1] = -kurt.mem[i][0] * -1 + kurt.mem[i][1] * 0;
        }

    }
    return kurt;
}
/* Memutar setiap titik (x, y) sebesar degree derajat searah jarum jam dari (0,0) */
/* Gunakan rumus rotasi:
   x' = x * cosθ + y * sinθ
   y' = -x * sinθ + y * cosθ
   degree hanya 0, 90, 180, 270 (bisa pakai konstanta tanpa trigonometri float) */
/* cos0 = 1, sin0 = 0*/
/* cos90 = 0, sin90 = 1*/
/* cos180 = -1, sin180 = 0*/
/* cos270 = 0, sin270 = -1*/
/* DEGREE SUDAH PASTI 4 JENIS, HARDCODE SAJA, TIDAK PERLU PAKE <math.h> */



/*
    0 sama
    90 x' =    y' =
    180
    270



*/
