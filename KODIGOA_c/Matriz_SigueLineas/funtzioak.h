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

typedef enum { BEHERA, GORA, ESKUINERA, EZKERRERA }NORABIDEAK;
typedef enum { ATZERA, AURRERA, ESKUINERA_GIRATU, EZKERRERA_GIRATU, AMAITU }NORABIDEAK_KOTXEAREN_PERSPEKTIBA;


// KALKULUAK EGITEN DIREN FUNTZIOAK

void S_prestatu(int S[N_MAX][N_MAX], int tamaina_n);

void Floyd_kalkulua(int F[N_MAX][N_MAX], int S[N_MAX][N_MAX], int n, int tamaina_n); // PISU BAT KALKULATU
void Floyd(int F[N_MAX][N_MAX], int S[N_MAX][N_MAX], int tamaina_n); // PISUA KALKULATU

// F ETA S BISTARATZEKO FUNTZIOAK

void printf_F(int F[N_MAX][N_MAX], int tamaina_n); // BISTARATU MATRIZEAK
void printf_S(int S[N_MAX][N_MAX], int tamaina_n);


// IBILBIDEAREKIN ZERIKUSIA DITUZTEN FUNTZIOAK

void eskatu_ibilbidea(int* A, int* B, int tamaina_n);
void ibilbidea_kalk(int S[N_MAX][N_MAX], int A, int B, int ibilbidea[N_MAX], int tamaina_n);
void printf_ibilbidea(int ibilbidea[N_MAX]);

void prestatu_nodoak(NODOA Nodoen_m[N_MAX][N_MAX], int Nodoak[N_MAX][N_MAX], int x, int y);


void bilatu_matrizean(int Nodoak[N_MAX][N_MAX], int orain, int* n, int* m, NODOA nodoen_lista[N_MAX * N_MAX]);
void bilatu_nora(NODOA Nodoen_m[N_MAX][N_MAX], int helmuga, int n, int m, int* norabidea);
void printf_kotxearen_pausuak(NODOA Nodoen_m[N_MAX][N_MAX], int Nodoak[N_MAX][N_MAX], int ibilbidea[N_MAX], int ibilbidea_giroekin[N_MAX], NODOA nodoen_lista[N_MAX * N_MAX]);


// ROBOTA MUGITZEKO FUNTZIOAK

void robota_funtzioak(int mapa[N_MAX][N_MAX], int* A, int* B, NODOA nodoen_lista[N_MAX * N_MAX], int tamaina_mapa_x, int tamaina_mapa_y, int tamaina_n, int ibilbidea[N_MAX], int S[N_MAX][N_MAX], NODOA Nodoen_m[N_MAX][N_MAX], int Nodoak[N_MAX][N_MAX], int ibilbidea_giroekin[N_MAX], int x, int y);

void main_mugitu(int ibilbidea_giroekin[N_MAX], int ibilbidea[N_MAX]);

void norabidea_galdetu(int* kotxea_norabidea);

void aurrera_while(float t);
void atzera_while(float t);
void eskuinera_tanke_while(float t);
void ezkerrera_tanke_while(float t);


// MAPETIK NODOAK IRAKURTZEKO ETA KALKULUAK EGITEKO FUNTZIOAK

void irakurri_mapa(char fitx_izena[N_MAX], int mapa[N_MAX][N_MAX], int* tamaina_mapa_x, int* tamaina_mapa_y, NODOA nodoen_lista[N_MAX * N_MAX]);
void nodoak_funtzioak(int mapa[N_MAX][N_MAX], int F[N_MAX][N_MAX], int Nodoak[N_MAX][N_MAX], int* tamaina_n, int* x, int* y, NODOA Nodoen_m[N_MAX][N_MAX], int tamaina_mapa_x, int tamaina_mapa_y, NODOA nodoen_lista[N_MAX]);
void nodoen_matrizea_sortu(NODOA nodoen_lista[N_MAX* N_MAX], NODOA Nodoen_m[N_MAX][N_MAX], int nodo_kop, int* tamaina_n, int Nodoak[N_MAX][N_MAX], int tamaina_mapa_x, int tamaina_mapa_y);
void nodoen_bizilagunak_aurkitu(NODOA nodoen_lista[N_MAX]);
void F_kalkulatu_nodoekin(NODOA nodoen_lista[N_MAX], int tamaina_n, int F[N_MAX][N_MAX]);
void nodoak_aurkitu(int mapa[N_MAX][N_MAX], NODOA nodoen_lista[N_MAX], int tamaina_mapa_x, int tamaina_mapa_y, int* nodo_kop);
void galdetu_irakurri_beharrekoa(char fitx_izena[MAX_STR]);


// MENUAREN FUNTZIOAK

void menua(int mapa[N_MAX][N_MAX], NODOA nodoen_lista[N_MAX], int tamaina_mapa_x, int tamaina_mapa_y, int tamaina_n, int F[N_MAX][N_MAX], int S[N_MAX][N_MAX], int ibilbidea[N_MAX], int* A, int* B, NODOA Nodoen_m[N_MAX][N_MAX], int Nodoak[N_MAX][N_MAX], int ibilbidea_giroekin[N_MAX], int x, int y);

void bistaratu_mapa(int mapa[N_MAX][N_MAX], NODOA Nodoen_lista[N_MAX], int tamaina_mapa_x, int tamaina_mapa_y, int tamaina_n, int Nodoak[N_MAX][N_MAX]);
