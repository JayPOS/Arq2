#ifndef _VETORIZADO_H
#define _VETORIZADO_H

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
int modulo(int a);
int soma_modulos(Matriz_V *mat);
int soma_modulosAVX(Matriz_V *mat);
int checa_diagonal(Matriz_V *mat);
int checa_quadrada(Matriz_V *mat); 
int eh_identidadeN(Matriz_N *mat); // NORMAL MATRIZ
int eh_identidade0(Matriz_V *mat); // NORMAL VETOR
int eh_identidade1(Matriz_V *mat); // PRIMEIRA CAMADA DE OTIMIZACAO
int eh_identidade2(Matriz_V *mat); // SEGUNDA CAMADA DE OTIMIZACAO
int eh_identidade3(Matriz_V *mat);  // AVX
void printa_matrizV(Matriz_V *mat);
void liberaN(Matriz_N *mat);
void liberaV(Matriz_V *mat);

#endif