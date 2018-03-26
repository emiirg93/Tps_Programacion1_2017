#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>
#include "funciones.h"
#define P 20

int main()
{
    char seguir='s';
    int opcion=0, i, flag=0;
    EPersona persona[P];
    inicializar(persona,P);

    while(seguir=='s')
    {
        switch(menu())
        {
        case 1:
            altaPersona(persona,P);
            break;
        case 2:
            darBaja(persona,P);
            break;
        case 3:
            ordenarPersonas(persona,P);
            mostrarPersonas(persona,P);
            break;
        case 4:
            graficoEdades(persona,P);
            break;
        case 5:
            seguir = 'n';
            break;
        }
    }

    return 0;
}
