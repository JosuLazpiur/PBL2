#include "funtzioak_floyd.h"
#include "motorra_funtzioak_floyd.h"
#include "main.h"

int main_floyd() //FLOYD-WARSHALL PROGRAMA NAGUSIA
{
  int A = 0, B = 0;

  int ibilbidea[N_MAX];
  int ibilbidea_giroekin[N_MAX];
  int F[N_MAX][N_MAX];
  int S[N_MAX][N_MAX];

  int Nodoak[N_MAX][N_MAX];
  int x, y;
  int tamaina_n;

  NODOA Nodoen_m[N_MAX][N_MAX];
  NODOA nodoen_lista[N_MAX * N_MAX];

  int tamaina_mapa_x;
  int tamaina_mapa_y;

  int mapa[N_MAX][N_MAX];

  char fitx_izena[MAX_STR];

  // FUNTZIOAK

  galdetu_irakurri_beharrekoa_1(fitx_izena);

  irakurri_mapa_1(fitx_izena, mapa, &tamaina_mapa_x, &tamaina_mapa_y, nodoen_lista); // ondo irakurtzen du

  nodoak_funtzioak_1(mapa, F, Nodoak, &tamaina_n, &x, &y, Nodoen_m, tamaina_mapa_x, tamaina_mapa_y, nodoen_lista);

  matrizea_prestatu_1(S, tamaina_n);

  //prestatu_nodoak(Nodoen_m, Nodoak, tamaina_mapa_x, tamaina_mapa_y);

  Floyd_Warshall_1(F, S, tamaina_n);

  menua_floyd_1(mapa, nodoen_lista, tamaina_mapa_x, tamaina_mapa_y, tamaina_n, F, S, ibilbidea, &A, &B, Nodoen_m, Nodoak, ibilbidea_giroekin, x, y);

  return 0;
}

