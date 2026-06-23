#include "funtzioak_sigue_lineas_floyd.h"
#include "motorra_funtzioak_sigue_lineas_floyd.h"
#include "sigue_lineas_floyd.h"
#include "main.h"


void matrizea_prestatu_2(int S[N_MAX][N_MAX], int tamaina_n)
{
  int n = 1;
  int i = 0, j = 0;
  for (i = 0; i < tamaina_n; i++)
  {
    for (j = 0; j < tamaina_n; j++)
    {
      S[i][j] = n;
      n++;
    }
    n = 1;
  }
}

void Floyd_Warshall_2(int F[N_MAX][N_MAX], int S[N_MAX][N_MAX], int tamaina_n)
{
  int i, j, k;

  for (k = 0; k < tamaina_n; k++)
  {
    for (i = 0; i < tamaina_n; i++)
    {
      for (j = 0; j < tamaina_n; j++)
      {
        if (F[i][j] > F[i][k] + F[k][j])
        {
          F[i][j] = F[i][k] + F[k][j];
          S[i][j] = k + 1;
        }
      }
    }
  }
}

void printf_matrizearen_pisua_2(int F[N_MAX][N_MAX], int tamaina_n)
{
  int i = 0, j = 0;
  printf("PISU MATRIZEA (F):\n\n");
  for (i = 0; i < tamaina_n; i++)
  {
    for (j = 0; j < tamaina_n; j++)
    {
      printf("%d ", F[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

void printf_matrizearen_ibilbidea_2(int S[N_MAX][N_MAX], int tamaina_n)
{
  int i = 0, j = 0;
  printf("IBILBIDE MATRIZEA (S):\n\n");
  for (i = 0; i < tamaina_n; i++)
  {
    for (j = 0; j < tamaina_n; j++)
    {
      printf("%d ", S[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

void eskatu_ibilbidea_2(int* A, int* B, int tamaina_n)
{
  char str[MAX_STR];
  int egoera = 0;
  char a = 0, b = 0;
  while (egoera == 0)
  {
    printf("\n  Ibilbidea nondik nora izango da? (A, B)\n\t> ");
    fgets(str, MAX_STR, stdin);
    egoera = sscanf(str, "%c, %c", &a, &b);
    if (egoera == 1) egoera = sscanf(str, "%c %c", &a, &b);
    a -= 'A' - 1;
    b -= 'A' - 1;
    *A = a;
    *B = b;
    if (*A > tamaina_n || *B > tamaina_n || *A < 1 || *B < 1)
    {
      printf("[ERROREA] Emandako puntua matrizetik kanpo dago.\n");
      egoera = 0;
    }
  }
}

void ibilbidea_motzena_kalkulatu_2(int S[N_MAX][N_MAX], int A, int B, int ibilbidea[], int tamaina_n)
{
  int i = 0;
  int amaitu = 0;

  A -= 1; // 1 fila matrizearen 0 fila izateko
  B -= 1;
  int aux = S[A][B];

  if (aux != B + 1)
  {
    ibilbidea_motzena_kalkulatu_2(S, A + 1, aux, ibilbidea, tamaina_n);
    ibilbidea_motzena_kalkulatu_2(S, aux, B + 1, ibilbidea, tamaina_n);
  }
  else
  {
    while (amaitu == 0 && i < tamaina_n) // azken posizioan sartu datu berria 
    {
      if (ibilbidea[i] < 0)
      {
        ibilbidea[i] = aux;
        amaitu = 1;
      }
      i++;
    }
    amaitu = 0;
    i = 0;
  }
}

void printf_ibilbidea_2(int ibilbidea[N_MAX])
{
  int amaitu = 0;
  int i = 0;
  printf("  IBILBIDEA: ");
  while (amaitu == 0)
  {
    if (ibilbidea[i] > 0)
    {
      printf("%c ", ibilbidea[i] + 'A' - 1);
    }
    else amaitu = 1;
    i++;
  }
}

void prestatu_nodoak_2(NODOA Nodoen_m[N_MAX][N_MAX], int Nodoak[N_MAX][N_MAX], int x, int y)
{
  int i, j;
  for (i = 0; i < y; i++)
  {
    for (j = 0; j < x; j++)
    {
      if (Nodoak[i - 1][j] >= 0 && Nodoak[i - 1][j] < INF && i - 1 >= 0) Nodoen_m[i][j].goian = Nodoak[i - 1][j]; //baldin eta goikoa matrizean badago
      if (Nodoak[i + 1][j] >= 0 && Nodoak[i + 1][j] < INF && i + 1 <= y) Nodoen_m[i][j].behean = Nodoak[i + 1][j];
      if (Nodoak[i][j - 1] >= 0 && Nodoak[i][j - 1] < INF && j - 1 >= 0) Nodoen_m[i][j].ezkerretan = Nodoak[i][j - 1];
      if (Nodoak[i][j + 1] >= 0 && Nodoak[i][j + 1] < INF && j + 1 <= x) Nodoen_m[i][j].eskuinean = Nodoak[i][j + 1];
    }
  }
}

void robota_funtzioak_2(int mapa[N_MAX][N_MAX], int* A, int* B, NODOA nodoen_lista[N_MAX * N_MAX], int tamaina_mapa_x, int tamaina_mapa_y, int tamaina_n, int ibilbidea[N_MAX], int S[N_MAX][N_MAX], NODOA Nodoen_m[N_MAX][N_MAX], int Nodoak[N_MAX][N_MAX], int ibilbidea_giroekin[N_MAX], int x, int y)
{
  char str[MAX_STR];
  int aukera;
  int egoera = 0;

  int i = 0;

  bistaratu_mapa_2(mapa, nodoen_lista, tamaina_mapa_x, tamaina_mapa_y, tamaina_n, Nodoak);


  //Ibilbidea eta ibilbidea_giroekin borratu / baloreak -1 bihurtu
  for (i = 0; i < N_MAX; i++) ibilbidea[i] = -1;
  for (i = 0; i < N_MAX; i++) ibilbidea_giroekin[i] = -1;

  eskatu_ibilbidea_2(A, B, tamaina_n);

  ibilbidea[0] = *A;
  ibilbidea_motzena_kalkulatu_2(S, *A, *B, ibilbidea, tamaina_n);

  printf_ibilbidea_2(ibilbidea);

  printf_kotxearen_pausuak_2(Nodoen_m, Nodoak, ibilbidea, ibilbidea_giroekin, nodoen_lista);

  while (egoera == 0)
  {
    printf("\nKotxea martxan jartzea nahi duzu? (1/0)\n\t> ");
    fgets(str, MAX_STR, stdin);
    egoera = sscanf(str, "%d", &aukera);

    if (aukera == 1)
    {
      egoera = 1;
      main_mugitu_2(ibilbidea_giroekin, ibilbidea);
    }
  }
}

void bilatu_matrizean_2(int Nodoak[N_MAX][N_MAX], int orain, int* n, int* m, NODOA nodoen_lista[N_MAX * N_MAX])
{
  int amaitu = 0;
  int i = 0, j = 0;
  while (amaitu == 0)
  {
    if (Nodoak[i][j] == orain)
    {
      *n = i;
      *m = j;
      amaitu = 1;
    }
    if (j > N_MAX)
    {
      i++;
      j = 0;
    }
    else
    {
      j++;
    }
    if (i >= N_MAX)
    {
      amaitu = 1;
    }
  }
}

void bilatu_helmuga_2(NODOA Nodoen_m[N_MAX][N_MAX], int helmuga, int n, int m, int* norabidea)
{
  helmuga -= 1;
  if (Nodoen_m[n][m].behean == helmuga) *norabidea = BEHERA_1;
  if (Nodoen_m[n][m].goian == helmuga) *norabidea = GORA_1;
  if (Nodoen_m[n][m].eskuinean == helmuga) *norabidea = ESKUINERA_1;
  if (Nodoen_m[n][m].ezkerretan == helmuga) *norabidea = EZKERRERA_1;
}

void printf_kotxearen_pausuak_2(NODOA Nodoen_m[N_MAX][N_MAX], int Nodoak[N_MAX][N_MAX], int ibilbidea[N_MAX], int ibilbidea_giroekin[N_MAX], NODOA nodoen_lista[N_MAX * N_MAX])
{
  int i = 0;
  int j = 0;

  int n = 0;
  int m = 0;

  int norabidea;
  int kotxea_norabidea = GORA_1;
  int atzera = 0;

  norabidea_galdetu_2(&kotxea_norabidea);

  printf("\n\n  KOTXEAREN PAUSUAK:\n\n");

  while (ibilbidea[i + 1] >= 0 && ibilbidea[i + 1] < INF) // Pisu matrizearekin konparatu
  {
    bilatu_matrizean_2(Nodoak, ibilbidea[i], &n, &m, nodoen_lista); //Aurkitu posizioa matrizean
    bilatu_helmuga_2(Nodoen_m, ibilbidea[i + 1], n, m, &norabidea); // ikusi ibilbidearen hurrengoa noraka duen
    if (norabidea == BEHERA_1)
    {
      switch (kotxea_norabidea)
      {
      case GORA_1: //giratu bi aldiz
        printf("\tEz giratu\n");
        atzera = 1;
        break;
      case BEHERA_1:
        printf("\tEz giratu\n");
        break;
      case ESKUINERA_1:
        printf("\tEskuinera giratu\n");
        ibilbidea_giroekin[j] = ESKUINERA_GIRATU_1;
        j++;
        break;
      case EZKERRERA_1:
        printf("\tEzkerrera giratu\n");
        ibilbidea_giroekin[j] = EZKERRERA_GIRATU_1;
        j++;
        break;
      default:
        break;
      }
      if (atzera != 1) kotxea_norabidea = BEHERA_1;
    }
    if (norabidea == GORA_1)
    {
      switch (kotxea_norabidea)
      {
      case GORA_1: //giratu bi aldiz
        printf("\tEz giratu\n");
        break;
      case BEHERA_1:
        printf("\tEz giratu\n");
        atzera = 1;
        break;
      case ESKUINERA_1:
        printf("\tEzkerrera giratu\n");
        ibilbidea_giroekin[j] = EZKERRERA_GIRATU_1;
        j++;
        break;
      case EZKERRERA_1:
        printf("\tEskuinera giratu\n");
        ibilbidea_giroekin[j] = ESKUINERA_GIRATU_1;
        j++;
        break;
      default:
        break;
      }
      if (atzera == 0) kotxea_norabidea = GORA_1;
    }
    if (norabidea == ESKUINERA_1)
    {
      switch (kotxea_norabidea)
      {
      case GORA_1: //giratu bi aldiz
        printf("\tEskuinera giratu\n");
        ibilbidea_giroekin[j] = ESKUINERA_GIRATU_1;
        j++;
        break;
      case BEHERA_1:
        printf("\tEzkerrera giratu\n");
        ibilbidea_giroekin[j] = EZKERRERA_GIRATU_1;
        j++;
        break;
      case ESKUINERA_1:
        printf("\tEz giratu\n");
        break;
      case EZKERRERA_1:
        printf("\tEz giratu\n");
        atzera = 1;
        break;
      default:
        break;
      }
      if (atzera == 0) kotxea_norabidea = ESKUINERA_1;
    }
    if (norabidea == EZKERRERA_1)
    {
      switch (kotxea_norabidea)
      {
      case GORA_1: //giratu bi aldiz
        printf("\tEzkerrera giratu\n");
        ibilbidea_giroekin[j] = EZKERRERA_GIRATU_1;
        j++;
        break;
      case BEHERA_1:
        printf("\tEskuinera giratu\n");
        ibilbidea_giroekin[j] = ESKUINERA_GIRATU_1;
        j++;
        break;
      case ESKUINERA_1:
        printf("\tEz giratu\n");
        atzera = 1;
        break;
      case EZKERRERA_1:
        printf("\tEz giratu\n");
        break;
      default:
        break;
      }
      if (atzera == 0) kotxea_norabidea = EZKERRERA_1;
    }
    if (atzera == 0 && ibilbidea[i] != ibilbidea[i + 1])
    {
      printf("\t Aurrera\n");//mugitu
      ibilbidea_giroekin[j] = AURRERA_1;
      j++;
    }
    else if (ibilbidea[i] != ibilbidea[i + 1])
    {
      printf("\t Atzera\n");
      ibilbidea_giroekin[j] = ATZERA_1;
      j++;
    }
    atzera = 0;
    i++;
  }
  ibilbidea_giroekin[j] = AMAITU_1;
}

void norabidea_galdetu_2(int* kotxea_norabidea)
{
  char str[MAX_STR];
  int egoera = 0;

  while (egoera != 1)
  {
    printf("\n\n  Nora begira hasiko da robota? \n\t0.- Behera\n\t1.- Gora \n\t2.- Eskuinera \n\t3.- Ezkerrera\n  > ");
    fgets(str, MAX_STR, stdin);
    egoera = sscanf(str, "%d", kotxea_norabidea);
  }
}

void main_mugitu_2(int ibilbidea_giroekin[N_MAX], int ibilbidea[N_MAX])
{
  int i = 0;
  float t_aurrera = 1;
  float t_giro = 0.85;

  hasieratu_2();

  gpioInitialise();

  if (ibilbidea[i] == ibilbidea[i + 1])
  {
    printf("\nHelmugan dago!");
    hasieratu_2();
    gpioInitialise();
    eskuinera_tanke_buklea_2(0.1);
    ezkerrera_tanke_buklea_2(0.1);
    amaitu_2();
  }
  else
  {
    while (ibilbidea_giroekin[i] != AMAITU_1)
    {
      switch (ibilbidea_giroekin[i])
      {
      case ATZERA_1: //atzera
        atzera_buklea_2(t_aurrera);
        break;
      case AURRERA_1: //aurrera
        aurrera_buklea_2(t_aurrera);
        break;
      case ESKUINERA_1: //eskuinera
        eskuinera_tanke_buklea_2(t_giro);
        break;
      case EZKERRERA_1: //ezkerrera
        ezkerrera_tanke_buklea_2(t_giro);
        break;
      default:
        break;
      }
      i++;
    }
  }

  amaitu_2();
  printf("\n\tPROGRAMA AMAITU DA");
}

void aurrera_buklea_2(float t)
{
  sigueLineas();

  Pasatu_Nodoa();
}
void atzera_buklea_2(float t)
{
  clock_t start = clock();
  float pasatako_denbora = 0.0;

  while (pasatako_denbora <= t)
  {
    clock_t current = clock();
    pasatako_denbora = (float)(current - start) / CLOCKS_PER_SEC;
    printf("\natzera %f", pasatako_denbora);
    atzera_2();
  }
}
void eskuinera_tanke_buklea_2(float t)
{
  int sensor_der;

  do
  {
    sensor_der = gpioRead(SENSOR_DER_PIN);

    eskuin_tanke_2();

  } while (sensor_der == 0);

  do
  {
    sensor_der = gpioRead(SENSOR_DER_PIN);

    eskuin_tanke_2();

  } while (sensor_der == 1);
}

void ezkerrera_tanke_buklea_2(float t)
{
  int sensor_izq;

  do
  {
    sensor_izq = gpioRead(SENSOR_IZQ_PIN);

    ezker_tanke_2();

  } while (sensor_izq == 0);

  do
  {
    sensor_izq = gpioRead(SENSOR_DER_PIN);

    ezker_tanke_2();

  } while (sensor_izq == 1);

}

void irakurri_mapa_2(char fitx_izena[N_MAX], int mapa[N_MAX][N_MAX], int* tamaina_mapa_x, int* tamaina_mapa_y, NODOA nodoen_lista[N_MAX * N_MAX])
{

  FILE* fitx = fopen(fitx_izena, "r");
  if (fitx == NULL)
  {
    printf("[ERROREA] Ezin izan da fitxategia ireki.\n");
    return;
  }

  int fila = 0;
  int hilara = 0;
  char n;
  int i = 0;
  int batura = 0;

  while (fscanf(fitx, "%c", &n) == 1)
  {
    if (n == '\n')
    {
      while (fila == 0 && i < hilara && batura <= 1) //Lehenengo ilara 0 0 0 0 0 bada, kendu
      {
        batura += mapa[0][i];
        i++;
      }
      if (batura == 0 && fila == 0)
      {
        fila--;
        i = 0;
      }
      if (fila == 0) *tamaina_mapa_x = hilara;
      fila++;
      hilara = 0;
    }
    else if (n == 32);	 // hutsuneak saltatu
    else
    {
      mapa[fila][hilara] = n - '0';
      hilara++;
    }
  }
  fila++;

  fclose(fitx);

  *tamaina_mapa_y = fila;
}

void nodoak_funtzioak_2(int mapa[N_MAX][N_MAX], int F[N_MAX][N_MAX], int Nodoak[N_MAX][N_MAX], int* tamaina_n, int* x, int* y, NODOA Nodoen_m[N_MAX][N_MAX], int tamaina_mapa_x, int tamaina_mapa_y, NODOA nodoen_lista[N_MAX]) //tamaina_n gaizki dago, nodoen_kop/2 da, beraz aurreko funtziotik ezin da lortu
{
  int nodo_kop = 0;

  nodoak_aurkitu_2(mapa, nodoen_lista, tamaina_mapa_x, tamaina_mapa_y, &nodo_kop);

  nodoen_bizilagunak_aurkitu_2(nodoen_lista);

  nodoen_matrizea_sortu_2(nodoen_lista, Nodoen_m, nodo_kop, tamaina_n, Nodoak, tamaina_mapa_x, tamaina_mapa_y);

  F_kalkulatu_nodoekin_2(nodoen_lista, *tamaina_n, F);
}

void nodoak_aurkitu_2(int mapa[N_MAX][N_MAX], NODOA nodoen_lista[N_MAX], int tamaina_mapa_x, int tamaina_mapa_y, int* nodo_kop)
{
  int amaitu = 0;
  int i = 0, j = 0;
  int irteera_kop = 0;
  int nodoa = 0; //true or false
  int kop = 0;

  while (amaitu == 0)
  {
    irteera_kop = 0;
    if (mapa[i][j] == 1) //aztertu ea nodoa den
    {
      if (mapa[i - 1][j] == 1) // ez dakigu zein nodotara lotuta dauden, ibilbideekin nahastu daiteke, gero kalkulatuko da
      {
        nodoen_lista[kop].goian = i;
        irteera_kop++;
      }
      else nodoen_lista[kop].goian = -1;
      if (mapa[i][j + 1] == 1)
      {
        nodoen_lista[kop].eskuinean = j + 2;
        irteera_kop++;
      }
      else nodoen_lista[kop].eskuinean = -1;
      if (mapa[i + 1][j] == 1)
      {
        nodoen_lista[kop].behean = i + 1;
        irteera_kop++;
      }
      else nodoen_lista[kop].behean = -1;
      if (mapa[i][j - 1] == 1)
      {
        nodoen_lista[kop].ezkerretan = j;
        irteera_kop++;
      }
      else nodoen_lista[kop].ezkerretan = -1;
      if (irteera_kop == 2)
      {
        if ((nodoen_lista[kop].eskuinean >= 0 && nodoen_lista[kop].eskuinean <= INF && nodoen_lista[kop].ezkerretan >= 0 && nodoen_lista[kop].ezkerretan <= INF) ||
          (nodoen_lista[kop].goian >= 0 && nodoen_lista[kop].goian <= INF && nodoen_lista[kop].behean >= 0 && nodoen_lista[kop].behean <= INF)) nodoa = 0;
        else nodoa = 1;
      }
      else nodoa = 1;

      if (nodoa == 1) //nodoa da, listan sartu  
      {
        nodoen_lista[kop].i = i;
        nodoen_lista[kop].j = j;
        kop++;
      }
      else
      {
        nodoen_lista[kop].goian = INF;
        nodoen_lista[kop].eskuinean = INF;
        nodoen_lista[kop].behean = INF;
        nodoen_lista[kop].ezkerretan = INF;
      }
    }
    if (j >= tamaina_mapa_x)
    {
      j = 0;
      i++;
      printf("\n");
    }
    else j++;
    if (i == tamaina_mapa_y + 1) amaitu = 1;
  }
  *nodo_kop = kop;
}

void nodoen_matrizea_sortu_2(NODOA nodoen_lista[N_MAX * N_MAX], NODOA Nodoen_m[N_MAX][N_MAX], int nodo_kop, int* tamaina_n, int Nodoak[N_MAX][N_MAX], int tamaina_mapa_x, int tamaina_mapa_y)
{
  int i = 0, j = 0;
  int n = 0;
  int nodoa = 0;
  int nodo_ordena = 1;

  // BEGIRATU MAPAREN HILARA / FILA GUZTIAK ETA NODO BAT BALDIN BADO HILARA/FILA BATEAN Nodoen_matrizearen tamaina handitu.


  for (i = 0; i < tamaina_mapa_y; i++)
  {
    for (j = 0; j < tamaina_mapa_x; j++)
    {
      while (n < nodo_kop && nodoa == 0)
      {
        if (nodoen_lista[n].i == i && nodoen_lista[n].j == j)
        {
          nodoa = 1;
        }
        n++;
      }
      if (nodoa == 1)
      {
        n--;
        nodoa = 0;
        Nodoak[i][j] = nodo_ordena;
        Nodoen_m[i][j] = nodoen_lista[n];
        nodo_ordena++;
      }
      else Nodoak[i][j] = 0;
      n = 0;
    }
  }

  *tamaina_n = nodo_kop;
}

void nodoen_bizilagunak_aurkitu_2(NODOA nodoen_lista[N_MAX])
{
  int i = 0;
  int j = 0;

  while (nodoen_lista[i].i >= 0 && nodoen_lista[i].j >= 0) // aurkitu zein nodora lotuta dauden
  {
    if (nodoen_lista[i].goian >= 0)
    {
      j = i;
      while (j >= 0)
      {
        if (nodoen_lista[j].j == nodoen_lista[i].j && nodoen_lista[j].i < nodoen_lista[i].i)
        {
          nodoen_lista[i].goian = j;
          j = -1;
        }
        j--;
      }
      j = 0;
    }
    if (nodoen_lista[i].eskuinean >= 0)
    {
      nodoen_lista[i].eskuinean = i + 1;
    }
    if (nodoen_lista[i].behean >= 0)
    {
      while (j < N_MAX)
      {
        if (nodoen_lista[j].j == nodoen_lista[i].j && nodoen_lista[j].i > nodoen_lista[i].i)
        {
          nodoen_lista[i].behean = j;
          j = N_MAX;
        }
        j++;
      }
      j = 0;
    }
    if (nodoen_lista[i].ezkerretan >= 0)
    {
      nodoen_lista[i].ezkerretan = i - 1;
    }
    i++;
  }
}

void F_kalkulatu_nodoekin_2(NODOA nodoen_lista[N_MAX], int tamaina_n, int F[N_MAX][N_MAX])
{
  int i = 0;
  int j = 0;
  for (i = 0; i < tamaina_n; i++)
  {
    for (j = 0; j < tamaina_n; j++)
    {
      if (i == j)
      {
        F[i][j] = 0;
      }
      else if (nodoen_lista[i].goian == j || nodoen_lista[i].eskuinean == j || nodoen_lista[i].behean == j || nodoen_lista[i].ezkerretan == j)
      {
        F[i][j] = 1;
      }
      else
      {
        F[i][j] = INF;
      }
    }
  }
}

void galdetu_irakurri_beharrekoa_2(char fitx_izena[MAX_STR])
{
  FILE* fitx = 0;
  int amaitu = 0;

  while (amaitu == 0)
  {
    system("clear");

    printf("\n  Zein fitxategietan dago mapa?\n\t> ");
    fgets(fitx_izena, MAX_STR, stdin);
    fitx_izena[strlen(fitx_izena) - 1] = '\0';

    fitx = fopen(fitx_izena, "r");
    if (fitx > 0)
    {
      amaitu = 1;
      fclose(fitx);
      printf("\n\n\n\nEz sakatu ezer. Kargatzen...");
    }
    else
    {
      printf("[ERROREA] Ezin izan da fitxategia irakurri.");
      getchar();
    }
  }
}

void menua_floyd_2(int mapa[N_MAX][N_MAX], NODOA nodoen_lista[N_MAX], int tamaina_mapa_x, int tamaina_mapa_y, int tamaina_n, int F[N_MAX][N_MAX], int S[N_MAX][N_MAX], int ibilbidea[N_MAX], int* A, int* B, NODOA Nodoen_m[N_MAX][N_MAX], int Nodoak[N_MAX][N_MAX], int ibilbidea_giroekin[N_MAX], int x, int y)
{
  char str[MAX_STR];
  int aukera;
  int amaitu = 0;

  while (amaitu == 0)
  {
    system("clear");
    printf("\n\n========================== MENUA ==============================================");
    printf("\n\n\t1. Bistaratu MAPA");
    printf("\n\n\t2. Bistaratu PISU eta IBILBIDE matrizea.");
    printf("\n\n\t3. Kalkulatu eta exekutatu IBILBIDE LABURRENA.");
    printf("\n\n\t0. irten.");
    printf("\n\n  Zer nahi duzu egin?\n\t> ");
    fgets(str, MAX_STR, stdin);
    sscanf(str, "%d", &aukera);
    switch (aukera)
    {
    case 1:
      bistaratu_mapa_2(mapa, nodoen_lista, tamaina_mapa_x, tamaina_mapa_y, tamaina_n, Nodoak);
      getchar();
      break;
    case 2:
      system("clear");
      printf_matrizearen_pisua_2(F, tamaina_n);
      printf_matrizearen_ibilbidea_2(S, tamaina_n);
      getchar();
      break;
    case 3:
      robota_funtzioak_2(mapa, A, B, nodoen_lista, tamaina_mapa_x, tamaina_mapa_y, tamaina_n, ibilbidea, S, Nodoen_m, Nodoak, ibilbidea_giroekin, x, y);
      break;
    case 0:
      amaitu = 1;
      break;
    default:
      break;
    }
  }
}

void bistaratu_mapa_2(int mapa[N_MAX][N_MAX], NODOA nodoen_lista[N_MAX], int tamaina_mapa_x, int tamaina_mapa_y, int tamaina_n, int Nodoak[N_MAX][N_MAX])
{
  int i, j;
  int n = 0;
  int nodoa = 0;
  int amaitu = 0;

  system("clear");

  printf("\n\n========================== MAPA ===============================================\n\n   ");

  for (i = 0; i < tamaina_mapa_y; i++)
  {
    for (j = 0; j < tamaina_mapa_x; j++)
    {
      while (amaitu != 1 && n < tamaina_n)
      {
        if (nodoen_lista[n].i == i && nodoen_lista[n].j == j) //aurkitu nodoaren posizioa
        {
          amaitu = 1;
          n--;
        }
        n++;
      }
      if (nodoen_lista[n].i == i && nodoen_lista[n].j == j && amaitu == 1)
      {
        printf("%c ", 'A' + nodoa);
        nodoa++;
      }
      else
      {
        switch (mapa[i][j])
        {
        case 1:
          if (mapa[i - 1][j] == 1 && mapa[i + 1][j] == 1 && (mapa[i][j - 1] <= 0 || mapa[i][j - 1] > 1) && (mapa[i][j + 1] <= 0 || mapa[i][j + 1] > 1)) printf("| ");
          if ((mapa[i - 1][j] <= 0 || mapa[i - 1][j] > 1) && (mapa[i + 1][j] <= 0 || mapa[i + 1][j] > 1) && mapa[i][j - 1] == 1 && mapa[i][j + 1] == 1) printf("- ");
          break;
        case 0:
          printf("  ");
          break;
        default:
          break;
        }
      }
      n = 0;
      amaitu = 0;
    }
    printf("\n   ");
  }
  printf("\n");
}

