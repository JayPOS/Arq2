#include "../includes/vetorizado.h"
#include <stdio.h>
#include <stdlib.h>
#include <papi.h>

#define SEC_AS_NANO 1000000000.0


double ident_tempoN(Matriz_N *mat)
{   
    int retval, Events = PAPI_NULL;
	long_long values[5];

	/* Initialize the PAPI library */
	retval = PAPI_library_init(PAPI_VER_CURRENT);

	if (retval != PAPI_VER_CURRENT) {
		printf("PAPI library init error!\n");
		exit(1);
	}

	if (PAPI_create_eventset(&Events) != PAPI_OK)
  	{
		printf("0-0\n");
		exit(1);
	}

	if (PAPI_add_event(Events, PAPI_L1_TCM) != PAPI_OK)
	{
		exit(1);
	}
    if (PAPI_add_event(Events, PAPI_L2_TCA) != PAPI_OK)
	{
		exit(1);
	}
    if (PAPI_add_event(Events, PAPI_L2_DCM) != PAPI_OK)
	{
		exit(1);
	}
    if (PAPI_add_event(Events, PAPI_LST_INS) != PAPI_OK)
	{
		exit(1);
	}
    /* Start counting events */
	if (PAPI_start(Events) != PAPI_OK)
	{
		int i;
		i = 0;
		printf("1\n");
		exit(1);
	}
    struct timespec ini, fim;
    clock_gettime(CLOCK_REALTIME, &ini);
    //SEU CODIGO VEM AQUI
    printf("Matriz VetN: %d\n", eh_identidadeN(mat));
    clock_gettime(CLOCK_REALTIME, &fim);
    double iniSec = (ini.tv_sec + ini.tv_nsec / SEC_AS_NANO)*1000;
    double fimSec = (fim.tv_sec + fim.tv_nsec / SEC_AS_NANO)*1000;

    /* Read the counters */
	if (PAPI_read(Events, values) != PAPI_OK)
	{
		int a;
		a = 0;
		printf("1\n");
		exit(1);
	}
    /* Stop counting events */
    if (PAPI_stop(Events, values) != PAPI_OK)
	{
		int a;
		a = 0;
		printf("1\n");
		exit(1);
	}

    FILE *file = NULL;
    file = fopen("./info/resultadosN.txt", "w");
    if (file == NULL)
    {
        printf("Arquivo invalido\n");
        exit(1);
    }
    fprintf(file, "Teste com Matriz normal metodo padrao \n\n");
    fprintf(file, "Time IdentidadeN: %.5lf\n", fimSec -iniSec);
    fprintf(file, "Level 1 cache misses: %lld\n", values[0]);
    fprintf(file, "Level 2 total cache accesses: %lld\n", values[1]);
    fprintf(file, "Level 2 data cache misses: %lld\n", values[2]);
    fprintf(file, "Load/store instructions completed: %lld\n", values[3]);

    fclose(file);

    return (fimSec - iniSec);
}

double ident_tempo(Matriz_V *mat)
{
    int retval, Events = PAPI_NULL;
	long_long values[5];

	/* Initialize the PAPI library */
	retval = PAPI_library_init(PAPI_VER_CURRENT);

	if (retval != PAPI_VER_CURRENT) {
		printf("PAPI library init error!\n");
		exit(1);
	}

	if (PAPI_create_eventset(&Events) != PAPI_OK)
  	{
		printf("0-0\n");
		exit(1);
	}

	if (PAPI_add_event(Events, PAPI_L1_TCM) != PAPI_OK)
	{
		exit(1);
	}
    if (PAPI_add_event(Events, PAPI_L2_TCA) != PAPI_OK)
	{
		exit(1);
	}
    if (PAPI_add_event(Events, PAPI_L2_DCM) != PAPI_OK)
	{
		exit(1);
	}
    if (PAPI_add_event(Events, PAPI_LST_INS) != PAPI_OK)
	{
		exit(1);
	}
    /* Start counting events */
	if (PAPI_start(Events) != PAPI_OK)
	{
		int i;
		i = 0;
		printf("1\n");
		exit(1);
	}
    struct timespec ini, fim;
    clock_gettime(CLOCK_REALTIME, &ini);
    //SEU CODIGO VEM AQUI
    printf("Matriz Vet0: %d\n", eh_identidade0(mat));
    clock_gettime(CLOCK_REALTIME, &fim);
    double iniSec = (ini.tv_sec + ini.tv_nsec / SEC_AS_NANO)*1000;
    double fimSec = (fim.tv_sec + fim.tv_nsec / SEC_AS_NANO)*1000;

    /* Read the counters */
	if (PAPI_read(Events, values) != PAPI_OK)
	{
		int a;
		a = 0;
		printf("1\n");
		exit(1);
	}
    /* Stop counting events */
    if (PAPI_stop(Events, values) != PAPI_OK)
	{
		int a;
		a = 0;
		printf("1\n");
		exit(1);
	}

    FILE *file = NULL;
    file = fopen("./info/resultados0.txt", "w");
    if (file == NULL)
    {
        printf("Arquivo invalido\n");
        exit(1);
    }
    fprintf(file, "Teste com Matriz em vet padrao\n\n");
    fprintf(file, "Time Identidade0: %.5lf\n", fimSec -iniSec);
    fprintf(file, "Level 1 cache misses: %lld\n", values[0]);
    fprintf(file, "Level 2 total cache accesses: %lld\n", values[1]);
    fprintf(file, "Level 2 data cache misses: %lld\n", values[2]);
    fprintf(file, "Load/store instructions completed: %lld\n", values[3]);

    fclose(file);

    return (fimSec - iniSec);
}
double ident_tempo01(Matriz_V *mat)
{
    int retval, Events = PAPI_NULL;
	long_long values[5];

	/* Initialize the PAPI library */
	retval = PAPI_library_init(PAPI_VER_CURRENT);

	if (retval != PAPI_VER_CURRENT) {
		printf("PAPI library init error!\n");
		exit(1);
	}

	if (PAPI_create_eventset(&Events) != PAPI_OK)
  	{
		printf("0-0\n");
		exit(1);
	}

	if (PAPI_add_event(Events, PAPI_L1_TCM) != PAPI_OK)
	{
		exit(1);
	}
    if (PAPI_add_event(Events, PAPI_L2_TCA) != PAPI_OK)
	{
		exit(1);
	}
    if (PAPI_add_event(Events, PAPI_L2_DCM) != PAPI_OK)
	{
		exit(1);
	}
    if (PAPI_add_event(Events, PAPI_LST_INS) != PAPI_OK)
	{
		exit(1);
	}
    /* Start counting events */
	if (PAPI_start(Events) != PAPI_OK)
	{
		int i;
		i = 0;
		printf("1\n");
		exit(1);
	}
    struct timespec ini, fim;
    clock_gettime(CLOCK_REALTIME, &ini);
    //SEU CODIGO VEM AQUI
    printf("Matriz Vet1: %d\n", eh_identidade1(mat));
    clock_gettime(CLOCK_REALTIME, &fim);
    double iniSec = (ini.tv_sec + ini.tv_nsec / SEC_AS_NANO)*1000;
    double fimSec = (fim.tv_sec + fim.tv_nsec / SEC_AS_NANO)*1000;

    /* Read the counters */
	if (PAPI_read(Events, values) != PAPI_OK)
	{
		int a;
		a = 0;
		printf("1\n");
		exit(1);
	}
    /* Stop counting events */
    if (PAPI_stop(Events, values) != PAPI_OK)
	{
		int a;
		a = 0;
		printf("1\n");
		exit(1);
	}

    FILE *file = NULL;
    file = fopen("./info/resultados.txt", "w");
    if (file == NULL)
    {
        printf("Arquivo invalido\n");
        exit(1);
    }
    fprintf(file, "Teste com Matriz em Vet metodo 1 (soma_modulos)\n\n");
    fprintf(file, "Time Identidade01: %.5lf\n", fimSec -iniSec);
    fprintf(file, "Level 1 cache misses: %lld\n", values[0]);
    fprintf(file, "Level 2 total cache accesses: %lld\n", values[1]);
    fprintf(file, "Level 2 data cache misses: %lld\n", values[2]);
    fprintf(file, "Load/store instructions completed: %lld\n", values[3]);

    fclose(file);

    return (fimSec - iniSec);
}
double ident_tempo02(Matriz_V *mat)
{
   

        int retval, Events = PAPI_NULL;
	long_long values[5];

	/* Initialize the PAPI library */
	retval = PAPI_library_init(PAPI_VER_CURRENT);

	if (retval != PAPI_VER_CURRENT) {
		printf("PAPI library init error!\n");
		exit(1);
	}

	if (PAPI_create_eventset(&Events) != PAPI_OK)
  	{
		printf("0-0\n");
		exit(1);
	}

	if (PAPI_add_event(Events, PAPI_L1_TCM) != PAPI_OK)
	{
		exit(1);
	}
    if (PAPI_add_event(Events, PAPI_L2_TCA) != PAPI_OK)
	{
		exit(1);
	}
    if (PAPI_add_event(Events, PAPI_L2_DCM) != PAPI_OK)
	{
		exit(1);
	}
    if (PAPI_add_event(Events, PAPI_LST_INS) != PAPI_OK)
	{
		exit(1);
	}
    /* Start counting events */
	if (PAPI_start(Events) != PAPI_OK)
	{
		int i;
		i = 0;
		printf("1\n");
		exit(1);
	}
    struct timespec ini, fim;
    clock_gettime(CLOCK_REALTIME, &ini);
    //SEU CODIGO VEM AQUI
    printf("Matriz Vet1: %d\n", eh_identidade1(mat));
    clock_gettime(CLOCK_REALTIME, &fim);
    double iniSec = (ini.tv_sec + ini.tv_nsec / SEC_AS_NANO)*1000;
    double fimSec = (fim.tv_sec + fim.tv_nsec / SEC_AS_NANO)*1000;

    /* Read the counters */
	if (PAPI_read(Events, values) != PAPI_OK)
	{
		int a;
		a = 0;
		printf("1\n");
		exit(1);
	}
    /* Stop counting events */
    if (PAPI_stop(Events, values) != PAPI_OK)
	{
		int a;
		a = 0;
		printf("1\n");
		exit(1);
	}

    FILE *file = NULL;
    file = fopen("./info/resultados2.txt", "w");
    if (file == NULL)
    {
        printf("Arquivo invalido\n");
        exit(1);
    }
    fprintf(file, "Teste com Matriz em Vet metodo 2(Checa_linhas)\n\n");
    fprintf(file, "Time Identidade01: %.5lf ms\n", fimSec -iniSec);
    fprintf(file, "Level 1 cache misses: %lld\n", values[0]);
    fprintf(file, "Level 2 total cache accesses: %lld\n", values[1]);
    fprintf(file, "Level 2 data cache misses: %lld\n", values[2]);
    fprintf(file, "Load/store instructions completed: %lld\n", values[3]);

    fclose(file);

    return (fimSec - iniSec);
}
double ident_tempo03(Matriz_V *mat)
{
    int retval, Events = PAPI_NULL;
	long_long values[5];

	/* Initialize the PAPI library */
	retval = PAPI_library_init(PAPI_VER_CURRENT);

	if (retval != PAPI_VER_CURRENT) {
		printf("PAPI library init error!\n");
		exit(1);
	}

	if (PAPI_create_eventset(&Events) != PAPI_OK)
  	{
		printf("0-0\n");
		exit(1);
	}

	if (PAPI_add_event(Events, PAPI_L1_TCM) != PAPI_OK)
	{
		exit(1);
	}
    if (PAPI_add_event(Events, PAPI_L2_TCA) != PAPI_OK)
	{
		exit(1);
	}
    if (PAPI_add_event(Events, PAPI_L2_DCM) != PAPI_OK)
	{
		exit(1);
	}
    if (PAPI_add_event(Events, PAPI_LST_INS) != PAPI_OK)
	{
		exit(1);
	}
    /* Start counting events */
	if (PAPI_start(Events) != PAPI_OK)
	{
		int i;
		i = 0;
		printf("1\n");
		exit(1);
	}
    struct timespec ini, fim;
    clock_gettime(CLOCK_REALTIME, &ini);
    //SEU CODIGO VEM AQUI
    printf("Matriz AVX: %d\n", eh_identidade3(mat));
    clock_gettime(CLOCK_REALTIME, &fim);
    double iniSec = (ini.tv_sec + ini.tv_nsec / SEC_AS_NANO)*1000;
    double fimSec = (fim.tv_sec + fim.tv_nsec / SEC_AS_NANO)*1000;

    /* Read the counters */
	if (PAPI_read(Events, values) != PAPI_OK)
	{
		int a;
		a = 0;
		printf("1\n");
		exit(1);
	}
    /* Stop counting events */
    if (PAPI_stop(Events, values) != PAPI_OK)
	{
		int a;
		a = 0;
		printf("1\n");
		exit(1);
	}

    FILE *file = NULL;
    file = fopen("./info/resultados3.txt", "w");
    if (file == NULL)
    {
        printf("Arquivo invalido\n");
        exit(1);
    }
    fprintf(file, "Teste com Matriz em Vet e AVX \n\n");
    fprintf(file, "Time Identidade3: %.5lf ms\n", fimSec - iniSec);
    fprintf(file, "Level 1 cache misses: %lld\n", values[0]);
    fprintf(file, "Level 2 total cache accesses: %lld\n", values[1]);
    fprintf(file, "Level 2 data cache misses: %lld\n", values[2]);
    fprintf(file, "Load/store instructions completed: %lld\n", values[3]);

    fclose(file);

    return (fimSec - iniSec);
}
int main()
{
    Matriz_N *opa = gera_matrizN(IDENTIDADE, 2000, 2000);
    Matriz_V *opa2 = gera_matrizV(IDENTIDADE, 2000, 2000);
    // printf("%d\n", opa2->matriz[399999999]);
    printf("TempoAVX: %lf\n", ident_tempo03(opa2));
    printf("Tempo2: %lf\n", ident_tempo02(opa2));
    printf("Tempo1: %lf\n", ident_tempo01(opa2));
    printf("Tempo0: %lf\n", ident_tempo(opa2));
    printf("TempoN: %lf\n", ident_tempoN(opa));
    liberaV(opa2);
    return 0;
}