#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    char seguir='s';
    int opcion=0,numeroA,numeroB;
    int flag1 = 0,flag2 = 0;

    do
    {
        printf("Bienvenido\n\n");
        printf("1- Ingresar 1er operando (A=x).\n");
        printf("2- Ingresar 2do operando (B=y).\n");
        printf("3- Calcular la suma (A+B).\n");
        printf("4- Calcular la resta (A-B).\n");
        printf("5- Calcular la division (A/B).\n");
        printf("6- Calcular la multiplicacion (A*B).\n");
        printf("7- Calcular el factorial (A!).\n");
        printf("8- Calcular todas las operaciones.\n");
        printf("9- Salir.\n\n");
        printf("Ingrese opcion : ");

        scanf("%d",&opcion);

        if (opcion < 1 || opcion > 9)
        {
            system("cls");
            printf("ERROR!!\n\nReingrese una opcion valida del 1 al 9.\n");
            system("pause");
            system("cls");
        }

        switch(opcion)
        {
        case 1:
            numeroA = ingresarNumero("ingrese primer numero : ");
            flag1= 1;
            break;
        case 2:
            numeroB = ingresarNumero("ingrese segundo numero : ");
            flag2= 1;
            break;
        case 3:
            if (flag1 == 0 || flag2 == 0)
            {
                printf("Tiene Que Completar El Punto 1 y 2 Para Realizar Esta Operacion.\n");
                system("pause");
                system("cls");
            }
            else
            {
                system("cls");
                mostrarIngresados (numeroA,numeroB);
                suma(numeroA,numeroB);
                system("pause");
                system("cls");
            }

            break;
        case 4:
            if (flag1 == 0 || flag2 == 0)
            {
                printf("Tiene Que Completar El Punto 1 y 2 Para Realizar Esta Operacion.\n");
                system("pause");
                system("cls");
            }
            else
            {
                system("cls");
                mostrarIngresados (numeroA,numeroB);
                resta(numeroA,numeroB);
                system("pause");
                system("cls");
            }
            break;
        case 5:
            if (flag1 == 0 || flag2 == 0)
            {
                printf("Tiene Que Completar El Punto 1 y 2 Para Realizar Esta Operacion.\n");
                system("pause");
                system("cls");
            }
            else
            {
                system("cls");
                mostrarIngresados (numeroA,numeroB);
                dividir(numeroA,numeroB);
                system("pause");
                system("cls");
            }
            break;
        case 6:
            if (flag1 == 0 || flag2 == 0)
            {
                printf("Tiene Que Completar El Punto 1 y 2 Para Realizar Esta Operacion.\n");
                system("pause");
                system("cls");
            }
            else
            {
                system("cls");
                mostrarIngresados (numeroA,numeroB);
                multiplicar (numeroA,numeroB);
                system("pause");
                system("cls");
            }
            break;
        case 7:
            if (flag1 == 0 || flag2 == 0)
            {
                printf("Tiene Que Completar El Punto 1 y 2 Para Realizar Esta Operacion.\n");
                system("pause");
                system("cls");
            }
            else
            {
                system("cls");
                mostrarIngresados (numeroA,numeroB);
                factorial(numeroA);
                system("pause");
                system("cls");
            }
            break;
        case 8:
            if (flag1 == 0 || flag2 == 0)
            {
                printf("Tiene Que Completar El Punto 1 y 2 Para Realizar Esta Operacion.\n");
                system("pause");
                system("cls");
            }
            else
            {
                system("cls");
                mostrarIngresados (numeroA,numeroB);
                suma(numeroA,numeroB);
                resta(numeroA,numeroB);
                dividir(numeroA,numeroB);
                multiplicar (numeroA,numeroB);
                factorial(numeroA);
                system("pause");
                system("cls");
            }
            break;
        case 9:
            seguir = 'n';
            break;
        }
    }
    while (seguir=='s');
    return 0;
}
