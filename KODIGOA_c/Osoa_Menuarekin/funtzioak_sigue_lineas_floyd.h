#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STR 128
#define N_MAX 12
#define INF 1000

typedef struct Nodoa //ERPINA
{
  int i;
  int j;
  int goian;
  int eskuinean;
  int behean;
  int ezkerretan;
}NODOA;

typedef enum { BEHERA_1, GORA_1, ESKUINERA_1, EZKERRERA_1 }NORABIDEAK;
typedef enum { ATZERA_1, AURRERA_1, ESKUINERA_GIRATU_1, EZKERRERA_GIRATU_1, AMAITU_1 }NORABIDEAK_KOTXEAREN_PERSPEKTIBA;


// KALKULUAK EGITEN DIREN FUNTZIOAK

void matrizea_prestatu_2(int S[N_MAX][N_MAX], int tamaina_n);

void Floyd_kalkulua_1(int F[N_MAX][N_MAX], int S[N_MAX][N_MAX], int n, int tamaina_n); // PISU BAT KALKULATU
void Floyd_Warshall_2(int F[N_MAX][N_MAX], int S[N_MAX][N_MAX], int tamaina_n); // PISUA KALKULATU

// F ETA S BISTARATZEKO FUNTZIOAK

void printf_matrizearen_pisua_2(int F[N_MAX][N_MAX], int tamaina_n); // BISTARATU MATRIZEAK
void printf_matrizearen_ibilbidea_2(int S[N_MAX][N_MAX], int tamaina_n);


// IBILBIDEAREKIN ZERIKUSIA DITUZTEN FUNTZIOAK

void eskatu_ibilbidea_2(int* A, int* B, int tamaina_n);
void ibilbidea_motzena_kalkulatu_2(int S[N_MAX][N_MAX], int A, int B, int ibilbidea[N_MAX], int tamaina_n);
void printf_ibilbidea_2(int ibilbidea[N_MAX]);

void prestatu_nodoak_2(NODOA Nodoen_m[N_MAX][N_MAX], int Nodoak[N_MAX][N_MAX], int x, int y);


void bilatu_matrizean_2(int Nodoak[N_MAX][N_MAX], int orain, int* n, int* m, NODOA nodoen_lista[N_MAX * N_MAX]);
void bilatu_helmuga_2(NODOA Nodoen_m[N_MAX][N_MAX], int helmuga, int n, int m, int* norabidea);
void printf_kotxearen_pausuak_2(NODOA Nodoen_m[N_MAX][N_MAX], int Nodoak[N_MAX][N_MAX], int ibilbidea[N_MAX], int ibilbidea_giroekin[N_MAX], NODOA nodoen_lista[N_MAX * N_MAX]);


// ROBOTA MUGITZEKO FUNTZIOAK

void robota_funtzioak_2(int mapa[N_MAX][N_MAX], int* A, int* B, NODOA nodoen_lista[N_MAX * N_MAX], int tamaina_mapa_x, int tamaina_mapa_y, int tamaina_n, int ibilbidea[N_MAX], int S[N_MAX][N_MAX], NODOA Nodoen_m[N_MAX][N_MAX], int Nodoak[N_MAX][N_MAX], int ibilbidea_giroekin[N_MAX], int x, int y);

void main_mugitu_2(int ibilbidea_giroekin[N_MAX], int ibilbidea[N_MAX]);

void norabidea_galdetu_2(int* kotxea_norabidea);

void aurrera_buklea_2(float t);
void atzera_buklea_2(float t);
void eskuinera_tanke_buklea_2(float t);
void ezkerrera_tanke_buklea_2(float t);


// MAPETIK NODOAK IRAKURTZEKO ETA KALKULUAK EGITEKO FUNTZIOAK

void irakurri_mapa_2(char fitx_izena[N_MAX], int mapa[N_MAX][N_MAX], int* tamaina_mapa_x, int* tamaina_mapa_y, NODOA nodoen_lista[N_MAX * N_MAX]);
void nodoak_funtzioak_2(int mapa[N_MAX][N_MAX], int F[N_MAX][N_MAX], int Nodoak[N_MAX][N_MAX], int* tamaina_n, int* x, int* y, NODOA Nodoen_m[N_MAX][N_MAX], int tamaina_mapa_x, int tamaina_mapa_y, NODOA nodoen_lista[N_MAX]);
void nodoen_matrizea_sortu_2(NODOA nodoen_lista[N_MAX * N_MAX], NODOA Nodoen_m[N_MAX][N_MAX], int nodo_kop, int* tamaina_n, int Nodoak[N_MAX][N_MAX], int tamaina_mapa_x, int tamaina_mapa_y);
void nodoen_bizilagunak_aurkitu_2(NODOA nodoen_lista[N_MAX]);
void F_kalkulatu_nodoekin_2(NODOA nodoen_lista[N_MAX], int tamaina_n, int F[N_MAX][N_MAX]);
void nodoak_aurkitu_2(int mapa[N_MAX][N_MAX], NODOA nodoen_lista[N_MAX], int tamaina_mapa_x, int tamaina_mapa_y, int* nodo_kop);
void galdetu_irakurri_beharrekoa_2(char fitx_izena[MAX_STR]);


// MENUAREN FUNTZIOAK

void menua_floyd_2(int mapa[N_MAX][N_MAX], NODOA nodoen_lista[N_MAX], int tamaina_mapa_x, int tamaina_mapa_y, int tamaina_n, int F[N_MAX][N_MAX], int S[N_MAX][N_MAX], int ibilbidea[N_MAX], int* A, int* B, NODOA Nodoen_m[N_MAX][N_MAX], int Nodoak[N_MAX][N_MAX], int ibilbidea_giroekin[N_MAX], int x, int y);

void bistaratu_mapa_2(int mapa[N_MAX][N_MAX], NODOA Nodoen_lista[N_MAX], int tamaina_mapa_x, int tamaina_mapa_y, int tamaina_n, int Nodoak[N_MAX][N_MAX]);

