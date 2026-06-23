#include "funtzioak.h"
#include "motorra_funtzioak.h"

void galdetu_irakurri_beharrekoa(char fitx_izena[MAX_STR])
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
void irakurri_mapa(char fitx_izena[], int mapa[N_MAX][N_MAX], int* tamaina_mapa_x, int* tamaina_mapa_y, NODOA nodoen_lista[N_MAX * N_MAX])
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
        else if (n == 32); // hutsuneak saltatu
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
void menua(int mapa[N_MAX][N_MAX], NODOA nodoen_lista[N_MAX], int tamaina_mapa_x, int tamaina_mapa_y, int tamaina_n, int F[N_MAX][N_MAX], int S[N_MAX][N_MAX], int ibilbidea[N_MAX], int* A, int* B, NODOA Nodoen_m[N_MAX][N_MAX], int Nodoak[N_MAX][N_MAX], int ibilbidea_giroekin[N_MAX], int x, int y)
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
            bistaratu_mapa(mapa, nodoen_lista, tamaina_mapa_x, tamaina_mapa_y, tamaina_n, Nodoak);
            getchar();
            break;
        case 2:
            system("clear");
            printf_F(F, tamaina_n);
            printf_S(S, tamaina_n);
            getchar();
            break;
        case 3:
            robota_funtzioak(mapa, A, B, nodoen_lista, tamaina_mapa_x, tamaina_mapa_y, tamaina_n, ibilbidea, S, Nodoen_m, Nodoak, ibilbidea_giroekin, x, y);
            break;
        case 0:
            amaitu = 1;
            break;
        default:
            break;
        }
    }
}
void bistaratu_mapa(int mapa[N_MAX][N_MAX], NODOA nodoen_lista[N_MAX], int tamaina_mapa_x, int tamaina_mapa_y, int tamaina_n, int Nodoak[N_MAX][N_MAX])
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
void printf_F(int F[N_MAX][N_MAX], int tamaina_n) //PISU MATRIZEA PRINTEATU
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
void printf_S(int S[N_MAX][N_MAX], int tamaina_n) //IBILBIDE MATRIZEA PRINTEATU
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
void robota_funtzioak(int mapa[N_MAX][N_MAX], int* A, int* B, NODOA nodoen_lista[N_MAX * N_MAX], int tamaina_mapa_x, int tamaina_mapa_y, int tamaina_n, int ibilbidea[N_MAX], int S[N_MAX][N_MAX], NODOA Nodoen_m[N_MAX][N_MAX], int Nodoak[N_MAX][N_MAX], int ibilbidea_giroekin[N_MAX], int x, int y)
{
    char str[MAX_STR];
    int aukera;
    int egoera = 0;

    int i = 0;

    bistaratu_mapa(mapa, nodoen_lista, tamaina_mapa_x, tamaina_mapa_y, tamaina_n, Nodoak);


    //IBILBIDEA ETA IBILBIDEA_GIROEKIN BORRATU / BALOREAK -1 BIHURTU
    for (i = 0; i < N_MAX; i++) ibilbidea[i] = -1;
    for (i = 0; i < N_MAX; i++) ibilbidea_giroekin[i] = -1;

    eskatu_ibilbidea(A, B, tamaina_n);

    ibilbidea[0] = *A;
    ibilbidea_kalk(S, *A, *B, ibilbidea, tamaina_n); //IBILBIDE LABURRENA KALKULATU

    printf_ibilbidea(ibilbidea); //IBILBIDEA BISTARATU

    printf_kotxearen_pausuak(Nodoen_m, Nodoak, ibilbidea, ibilbidea_giroekin, nodoen_lista); //PAUSU GUZTIAK BISTARATU

    while (egoera == 0) //KOTXEA HASIERATZEKO ( 1 ) HASI, ( 0 ) GELDI HUTSI
    {
        printf("\nKotxea martxan jartzea nahi duzu? (1/0)\n\t> ");
        fgets(str, MAX_STR, stdin);
        egoera = sscanf(str, "%d", &aukera);

        if (aukera == 1)
        {
            egoera = 1; //KOTXEA HASI
            main_mugitu(ibilbidea_giroekin, ibilbidea);
        }
    }
}
void eskatu_ibilbidea(int* A, int* B, int tamaina_n) //PUNTUAK ESKATU, PUNTU BATETIK BESTERA IBILBIDEA EGITEKO
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
            printf("[ERROREA] Emandako puntua matrizetik kanpo dago.\n"); //ERROREA
            egoera = 0;
        }
    }
}
void bilatu_matrizean(int Nodoak[N_MAX][N_MAX], int orain, int* n, int* m, NODOA nodoen_lista[N_MAX * N_MAX]) //EMANDAKO PUNTUAK MATRIZEAN TOPATU
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
void ibilbidea_kalk(int S[N_MAX][N_MAX], int A, int B, int ibilbidea[], int tamaina_n) //EMANDAKO PUNTUEKIN, IBILBIDEA KALKULATZEKO
{
    int i = 0;
    int amaitu = 0;

    A -= 1; //1 FILA MATRIZEAREN 0 FILA IZATEKO 
    B -= 1;
    int aux = S[A][B];

    if (aux != B + 1)
    {
        //ERA ERREKURTSIBOAN FUNTZIOARI DEHITU
        ibilbidea_kalk(S, A + 1, aux, ibilbidea, tamaina_n);
        ibilbidea_kalk(S, aux, B + 1, ibilbidea, tamaina_n);
    }
    else
    {
        while (amaitu == 0 && i < tamaina_n) //AZKEN POSIZIOAN SARTU DATU BERRIA
        {
            if (ibilbidea[i] < 0)
            {
                ibilbidea[i] = aux;
                amaitu = 1;
            }
            i++;
        }
        amaitu = 0; //BUKAERA
        i = 0;
    }
}
void bilatu_nora(NODOA Nodoen_m[N_MAX][N_MAX], int helmuga, int n, int m, int* norabidea)
{
    //HELMUGA BILATZEKO
    helmuga -= 1;
    if (Nodoen_m[n][m].behean == helmuga) *norabidea = BEHERA;
    if (Nodoen_m[n][m].goian == helmuga) *norabidea = GORA;
    if (Nodoen_m[n][m].eskuinean == helmuga) *norabidea = ESKUINERA;
    if (Nodoen_m[n][m].ezkerretan == helmuga) *norabidea = EZKERRERA;
}
void norabidea_galdetu(int* kotxea_norabidea)
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
void S_prestatu(int S[N_MAX][N_MAX], int tamaina_n) //MATRIZEA PRESTATU
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
void Floyd(int F[N_MAX][N_MAX], int S[N_MAX][N_MAX], int tamaina_n) //FLOYD-WARSHALL HASIERATU
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
void printf_ibilbidea(int ibilbidea[N_MAX]) //IBILBIDEA BISTARATU
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
void printf_kotxearen_pausuak(NODOA Nodoen_m[N_MAX][N_MAX], int Nodoak[N_MAX][N_MAX], int ibilbidea[N_MAX], int ibilbidea_giroekin[N_MAX], NODOA nodoen_lista[N_MAX * N_MAX]) //KOTXEAREN PAUSU GUZTIAK BISTARATU
{
    int i = 0;
    int j = 0;

    int n = 0;
    int m = 0;

    int norabidea;
    int kotxea_norabidea = GORA;
    int atzera = 0;

    norabidea_galdetu(&kotxea_norabidea);

    printf("\n\n  KOTXEAREN PAUSUAK:\n\n");

    while (ibilbidea[i + 1] >= 0 && ibilbidea[i + 1] < INF) //PISU MATRIZEAREKIN KONPARATU
    {
        bilatu_matrizean(Nodoak, ibilbidea[i], &n, &m, nodoen_lista); //AURKITU POSIZIOA MATRIZEAN
        bilatu_nora(Nodoen_m, ibilbidea[i + 1], n, m, &norabidea); // IKUSI IBILBIDEAREN HURRENGOA NORA DEN
        if (norabidea == BEHERA)
        {
            switch (kotxea_norabidea)
            {
            case GORA: //GIRATU BI ALDIZ
                printf("\tEz giratu\n");
                atzera = 1;
                break;
            case BEHERA:
                printf("\tEz giratu\n");
                break;
            case ESKUINERA:
                printf("\tEskuinera giratu\n");
                ibilbidea_giroekin[j] = ESKUINERA_GIRATU;
                j++;
                break;
            case EZKERRERA:
                printf("\tEzkerrera giratu\n");
                ibilbidea_giroekin[j] = EZKERRERA_GIRATU;
                j++;
                break;
            default:
                break;
            }
            if (atzera != 1) kotxea_norabidea = BEHERA;
        }
        if (norabidea == GORA)
        {
            switch (kotxea_norabidea)
            {
            case GORA: //GIRATU BI ALDIZ
                printf("\tEz giratu\n");
                break;
            case BEHERA:
                printf("\tEz giratu\n");
                atzera = 1;
                break;
            case ESKUINERA:
                printf("\tEzkerrera giratu\n");
                ibilbidea_giroekin[j] = EZKERRERA_GIRATU;
                j++;
                break;
            case EZKERRERA:
                printf("\tEskuinera giratu\n");
                ibilbidea_giroekin[j] = ESKUINERA_GIRATU;
                j++;
                break;
            default:
                break;
            }
            if (atzera == 0) kotxea_norabidea = GORA;
        }
        if (norabidea == ESKUINERA)
        {
            switch (kotxea_norabidea)
            {
            case GORA: //GIRATU BI ALDIZ
                printf("\tEskuinera giratu\n");
                ibilbidea_giroekin[j] = ESKUINERA_GIRATU;
                j++;
                break;
            case BEHERA:
                printf("\tEzkerrera giratu\n");
                ibilbidea_giroekin[j] = EZKERRERA_GIRATU;
                j++;
                break;
            case ESKUINERA:
                printf("\tEz giratu\n");
                break;
            case EZKERRERA:
                printf("\tEz giratu\n");
                atzera = 1;
                break;
            default:
                break;
            }
            if (atzera == 0) kotxea_norabidea = ESKUINERA;
        }
        if (norabidea == EZKERRERA)
        {
            switch (kotxea_norabidea)
            {
            case GORA: //GIRATU BI ALDIZ
                printf("\tEzkerrera giratu\n");
                ibilbidea_giroekin[j] = EZKERRERA_GIRATU;
                j++;
                break;
            case BEHERA:
                printf("\tEskuinera giratu\n");
                ibilbidea_giroekin[j] = ESKUINERA_GIRATU;
                j++;
                break;
            case ESKUINERA:
                printf("\tEz giratu\n");
                atzera = 1;
                break;
            case EZKERRERA:
                printf("\tEz giratu\n");
                break;
            default:
                break;
            }
            if (atzera == 0) kotxea_norabidea = EZKERRERA;
        }
        if (atzera == 0 && ibilbidea[i] != ibilbidea[i + 1])
        {
            printf("\t Aurrera\n");//MUGITU
            ibilbidea_giroekin[j] = AURRERA;
            j++;
        }
        else if (ibilbidea[i] != ibilbidea[i + 1])
        {
            printf("\t Atzera\n");
            ibilbidea_giroekin[j] = ATZERA;
            j++;
        }
        atzera = 0;
        i++;
    }
    ibilbidea_giroekin[j] = AMAITU;
}
void main_mugitu(int ibilbidea_giroekin[N_MAX], int ibilbidea[N_MAX])
{
    int i = 0;
    float t_aurrera = 1;
    float t_giro = 0.65;

    hasieratu();

    gpioInitialise();

    if (ibilbidea[i] == ibilbidea[i + 1])
    {
        printf("\nHelmugan dago!");
        hasieratu();
        gpioInitialise();
        eskuinera_tanke_while(0.1);
        ezkerrera_tanke_while(0.1);
        amaitu();
    }
    else
    {
        while (ibilbidea_giroekin[i] != AMAITU)
        {
            switch (ibilbidea_giroekin[i])
            {
            case ATZERA: //ATZERA
                atzera_while(t_aurrera);
                break;
            case AURRERA: //AURRERA
                aurrera_while(t_aurrera);
                break;
            case ESKUINERA: //ESKUINERA
                eskuinera_tanke_while(t_giro);
                break;
            case EZKERRERA: //EZKERRERA
                ezkerrera_tanke_while(t_giro);
                break;
            default:
                break;
            }
            i++;
        }
    }
    amaitu();
    printf("\n\tPROGRAMA AMAITU DA");
}
void aurrera_while(float t)
{
    clock_t start = clock();
    float pasatako_denbora = 0.0;

    while (pasatako_denbora <= t)
    {
        clock_t current = clock();
        pasatako_denbora = (float)(current - start) / CLOCKS_PER_SEC;
        printf("\naurrera %f", pasatako_denbora);
        aurrera();
    }
}
void atzera_while(float t)
{
    clock_t start = clock();
    float pasatako_denbora = 0.0;

    while (pasatako_denbora <= t)
    {
        clock_t current = clock();
        pasatako_denbora = (float)(current - start) / CLOCKS_PER_SEC;
        printf("\natzera %f", pasatako_denbora);
        atzera();
    }
}
void eskuinera_tanke_while(float t)
{
    clock_t start = clock();
    float pasatako_denbora = 0.0;

    while (pasatako_denbora <= t)
    {
        clock_t current = clock();
        pasatako_denbora = (float)(current - start) / CLOCKS_PER_SEC;
        printf("\neskuinera_tanke %f", pasatako_denbora);
        eskubi_tanke();
    }
}
void ezkerrera_tanke_while(float t)
{
    clock_t start = clock();
    float pasatako_denbora = 0.0;

    while (pasatako_denbora <= t)
    {
        clock_t current = clock();
        pasatako_denbora = (float)(current - start) / CLOCKS_PER_SEC;
        printf("\nezkerra_tanke %f", pasatako_denbora);
        ezker_tanke();
    }
}
void nodoak_aurkitu(int mapa[N_MAX][N_MAX], NODOA nodoen_lista[N_MAX], int tamaina_mapa_x, int tamaina_mapa_y, int* nodo_kop)
{
    int amaitu = 0;
    int i = 0, j = 0;
    int irteera_kop = 0;
    int nodoa = 0; //TRUE EDO FALSE
    int kop = 0;

    while (amaitu == 0)
    {
        irteera_kop = 0;
        if (mapa[i][j] == 1) //AZTERTU EA NODOA DEN
        {
            if (mapa[i - 1][j] == 1) //EZ DAKIGU ZEIN NODOTARA LOTUTA DAUDEN, IBILBIDEEKIN NAHASTU DAITEKE, GERO KALKULATUKO DA 
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

            if (nodoa == 1) //NODOA DA, LISTAN SARTU
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
void prestatu_nodoak(NODOA Nodoen_m[N_MAX][N_MAX], int Nodoak[N_MAX][N_MAX], int x, int y)
{
    int i, j;
    for (i = 0; i < y; i++)
    {
        for (j = 0; j < x; j++)
        {
            if (Nodoak[i - 1][j] >= 0 && Nodoak[i - 1][j] < INF && i - 1 >= 0) Nodoen_m[i][j].goian = Nodoak[i - 1][j]; //BALDIN ETA GOIKOA MATRIZEAN BADAGO
            if (Nodoak[i + 1][j] >= 0 && Nodoak[i + 1][j] < INF && i + 1 <= y) Nodoen_m[i][j].behean = Nodoak[i + 1][j];
            if (Nodoak[i][j - 1] >= 0 && Nodoak[i][j - 1] < INF && j - 1 >= 0) Nodoen_m[i][j].ezkerretan = Nodoak[i][j - 1];
            if (Nodoak[i][j + 1] >= 0 && Nodoak[i][j + 1] < INF && j + 1 <= x) Nodoen_m[i][j].eskuinean = Nodoak[i][j + 1];
        }
    }
}
void nodoen_matrizea_sortu(NODOA nodoen_lista[N_MAX * N_MAX], NODOA Nodoen_m[N_MAX][N_MAX], int nodo_kop, int* tamaina_n, int Nodoak[N_MAX][N_MAX], int tamaina_mapa_x, int tamaina_mapa_y)
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
void nodoak_funtzioak(int mapa[N_MAX][N_MAX], int F[N_MAX][N_MAX], int Nodoak[N_MAX][N_MAX], int* tamaina_n, int* x, int* y, NODOA Nodoen_m[N_MAX][N_MAX], int tamaina_mapa_x, int tamaina_mapa_y, NODOA nodoen_lista[N_MAX * N_MAX]) //tamaina_n gaizki dago, nodoen_kop/2 da, beraz aurreko funtziotik ezin da lortu
{
    //NODO FUNTZIO GUZTIEI DEIAK
    int nodo_kop = 0;

    nodoak_aurkitu(mapa, nodoen_lista, tamaina_mapa_x, tamaina_mapa_y, &nodo_kop);

    nodoen_bizilagunak_aurkitu(nodoen_lista);

    nodoen_matrizea_sortu(nodoen_lista, Nodoen_m, nodo_kop, tamaina_n, Nodoak, tamaina_mapa_x, tamaina_mapa_y);

    F_kalkulatu_nodoekin(nodoen_lista, *tamaina_n, F);
}
void nodoen_bizilagunak_aurkitu(NODOA nodoen_lista[N_MAX])
{
    int i = 0;
    int j = 0;

    while (nodoen_lista[i].i >= 0 && nodoen_lista[i].j >= 0) //AURKITU ZEIN NODORA LOTUTA DAUDEN
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
void F_kalkulatu_nodoekin(NODOA nodoen_lista[N_MAX], int tamaina_n, int F[N_MAX][N_MAX])
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