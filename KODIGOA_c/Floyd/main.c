#include "funtzioak.h"
#include "motorra_funtzioak.h"

//FLOYD-WARSHALL PROGRAMA NAGUSIA
int main()
{
    //BARIABLE GUZTIAK DEFINITU
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

    //MAPA DEFINITU
    int tamaina_mapa_x;
    int tamaina_mapa_y;

    int mapa[N_MAX][N_MAX];
    
    char fitx_izena[MAX_STR];//MAPEN MATRIZEA IRAKURTZEKO

    // FUNTZIOAK

    if (gpioInitialise() < 0) 
    {
        printf("Error al inicializar PiGPIO.\n"); //ERROREA NOTIFIKATU HASIERAPENEAN
        return 1;
    }

    galdetu_irakurri_beharrekoa(fitx_izena); //MAPA ZABALTZEKO

    irakurri_mapa(fitx_izena, mapa, &tamaina_mapa_x, &tamaina_mapa_y, nodoen_lista); //EMANDAKO MATRIZEA IRAKURTZEKO

    nodoak_funtzioak(mapa, F, Nodoak, &tamaina_n, &x, &y, Nodoen_m, tamaina_mapa_x, tamaina_mapa_y, nodoen_lista);

    S_prestatu(S, tamaina_n);

    //prestatu_nodoak(Nodoen_m, Nodoak, tamaina_mapa_x, tamaina_mapa_y);

    Floyd(F, S, tamaina_n);

    menua(mapa, nodoen_lista, tamaina_mapa_x, tamaina_mapa_y, tamaina_n, F, S, ibilbidea, &A, &B, Nodoen_m, Nodoak, ibilbidea_giroekin, x, y);

    return 0;
}
