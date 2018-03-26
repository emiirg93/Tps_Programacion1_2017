#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int ingresarNumero(char texto[])
{
    int a;
    system("cls");
    printf("%s",texto);
    scanf("%d",&a);
    system("cls");
    printf("Numero ingresado con exito!!\n\n");
    system("pause");
    system("cls");

    return a;
}

int suma (int a,int b)
{
    int suma;

    suma = a+b;

    return printf("La suma de los numeros ingresados es : %d\n",suma);
}

int resta (int a,int b)
{
    int resta;
    if (a > 0 || b > 0)
    {
        resta = a-b;
    }
    else
    {
        resta = a -(-b);
    }

    return printf("La resta de los numeros ingresados es : %d\n",resta);
}

float dividir (int a,int b)
{
    float resultado;

    if (b==0)
    {
        printf("No se puede dividir por 0");
    }
    else
    {
        resultado = (float)a/b;
        printf("la division de los numeros ingresados es : %.2f\n",resultado);
    }

    return 0;
}

int multiplicar (int a,int b)
{
    int resultado;

    resultado = a*b;
    return printf("La multiplicacion entre los numeros ingresados es : %d\n",resultado);
}

int factorial(int a)
{
    int b;
    long long int resultado=1;

    for(b=a; b>1; b--)

    {
        resultado=resultado*b;
    }

    return printf("El factor es de: %lli \n\n",resultado);
}

void mostrarIngresados (int a,int b)
{
    printf("Numeros ingresados : \n-A = %d\n-B = %d\n\n", a,b);
}

