#ifndef _ORIGINAL_H
#define _ORIGINAL_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <smmintrin.h>
#include <immintrin.h>

#define IDENTIDADE 1
#define ALEATORIA 0
#define VETORIZADA 1
#define NORMAL 0

typedef struct matriz_normal
{
    int l;
    int c;
    int **matriz;
} Matriz_N;
typedef struct matriz_vetorizada
{
    int l;
    int c;
    int *matriz;
} Matriz_V;

Matriz_N *gera_matrizN(int tipo, int l, int c);
Matriz_V *gera_matrizV(int tipo, int l, int c);
int eh_identidadeN(Matriz_N *mat);
int checa_diagonalV(Matriz_V *mat);
int checa_quadradaV(Matriz_V *mat);
int eh_identidadeV(Matriz_V *mat);
void printa_matrizN(Matriz_N *mat);
void printa_matrizV(Matriz_V *mat);

#endif