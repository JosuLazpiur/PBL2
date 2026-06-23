#define _CRT_SECURE_NO_WARNINGS_
#include <stdio.h>
#include <stdlib.h>
#include "menua.h"
#include "main.h"

#define MAX_STR 128

void sigueLineas()
{
  system("clear");
  main_sigue_lineas();
  //SIGUE-LINEAS
}

void caminoMasCortoFloyd()
{
  system("clear");
  main_floyd();
  //FLOYD-WARSHALL BIDEZ IBILBIDEA
}

void caminoMasCortoConSigueLineas()
{
  system("clear");
  main_sigue_lineas_floyd();
  //FLOYD-WARSHALL BIDEZ ETA SIGUE-LINEAS ERABILITA
}

void bluetooth(int argc, char* argv[])
{
  system("clear");
  main_remoto(argc, argv);
  //BLUETOOTH MANDOAREN BIDEZ KONTROLATZEKO
}

int main(int argc, char* argv[])
{
  int opcion = 0;
  char str[MAX_STR];
  
  do //MENUA
  {
    system("clear");
    printf("\t\\________________/"); printf("\t\t"); printf("	____________   __");
    printf("\n");
    printf("\t__/__/_______\\__\\__"); printf("\t\t"); printf(" ______/_/_____\\_\\__\\__/   ");
    printf("\n");
    printf("\t/ OO  [-PBL-]  OO \\"); printf("\t\t"); printf("/o___`___|   '/      |_");
    printf("\n");
    printf("\t|__/___________\\__|"); printf("\t\t"); printf("|'  ___  \\___/______  /");
    printf("\n");
    printf("\t\\ XX |_| _ |_| XX /"); printf("\t\t"); printf("\\__/(O)\\________/(O)\\_/");

    printf("\n");

    printf("     ___________________________________________________________________\n");
    printf("      \\===============================================================/\n");
    printf("      |                                                               |\n");
    printf("      |>=======================<[ PBL 2024 ]>========================<|\n");
    printf("      |_______________________________________________________________|\n");
    printf("      |                                                               |\n");
    printf("      |    1):     SIGUE-LINEAS                                       |\n");
    printf("      |_______________________________________________________________|\n");
    printf("      |_______________________________________________________________|\n");
    printf("      |                                                               |\n");
    printf("      |    2):     FLOYD-WARSHALL                                     |\n");
    printf("      |_______________________________________________________________|\n");
    printf("      |_______________________________________________________________|\n");
    printf("      |                                                               |\n");
    printf("      |    3):     IBILBIDE LABURRENA SIGUE-LINEA ERABILITA           |\n");
    printf("      |_______________________________________________________________|\n");
    printf("      |_______________________________________________________________|\n");
    printf("      |                                                               |\n");
    printf("      |    4):     BLUETOOTH                                          |\n");
    printf("      |_______________________________________________________________|\n");
    printf("      |_______________________________________________________________|\n");
    printf("      |                                                               |\n");
    printf("      |    5):     AMAITU PROGRAMA                                    |\n");
    printf("      |_______________________________________________________________|\n\n");
    printf("                      ZURE AUKERA : ");
    fgets(str, MAX_STR, stdin);
    sscanf(str, "%d", &opcion);

    switch (opcion)
    {
    case 1:
      sigueLineas(); //SIGUE-LINEAS
      break;
    case 2:
      caminoMasCortoFloyd(); //FLOYD-WARSHALL
      break;
    case 3:
      caminoMasCortoConSigueLineas(); //FLOYD ETA SIGUE-LINEAS
      break;
    case 4:
      bluetooth(argc, argv); //BLUETOOTH
      break;
    case 5:
      printf("Programa amaituta\n");
      break;
    default:
      printf("Aukera desegokia\n");
      break;
    }
  } while (opcion != 5);

  return 0;
}

