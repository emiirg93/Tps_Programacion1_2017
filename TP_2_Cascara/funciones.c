#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>
#include "funciones.h"

int menu ()
{
    int opcion;
    system("cls");
    printf("Bienvenido.\n\n1- Agregar persona\n");
    printf("2- Borrar persona\n");
    printf("3- Imprimir lista ordenada por  nombre\n");
    printf("4- Imprimir grafico de edades\n\n");
    printf("5- Salir\n\nIngrese opcion : ");

    scanf("%d",&opcion);

    while(opcion <1 || opcion>5)
    {
        printf("Opcion invalida.\nIngrese una opcion del 1 al 5 : ");
        scanf("%d",&opcion);
    }

    return opcion;
}

void inicializar(EPersona persona[],int tam)
{
    int i;

    for (i=0; i<tam; i++)
    {
        persona[i].estado = 0;
    }
}

int buscarLibre(EPersona persona[],int tam)
{
    int i;
    int flag = -1;
    for (i=0; i<tam ; i++)
    {
        if(persona[i].estado==0)
        {
            flag=i;
            break;
        }
    }

    return flag;
}
void altaPersona(EPersona persona[],int tam)
{
    EPersona nuevaPersona;
    int lugar,esta=0,i;
    long int dni;
    system("cls");
    lugar = buscarLibre(persona,tam);
    if (lugar !=-1)
    {
        printf("Ingrese DNI : ");
        scanf("%ld",&dni);

        for(i=0; i<tam; i++)
        {
            while(dni == persona[i].dni)
            {
                printf("\nDNI YA EXISTENTE.\nRengrese DNI : ");
                scanf("%ld",&dni);
            }
        }

        nuevaPersona.dni=dni;
        printf("Ingrese nombre : ");
        fflush(stdin);
        gets (nuevaPersona.nombre);

        printf("Ingrese edad : ");
        scanf("%d",&nuevaPersona.edad);
        nuevaPersona.estado = 1;


        persona[lugar]=nuevaPersona;
    }
    else
    {
        printf("NO HAY MAS ESPACIO.\n");
    }

}

int buscarPersona(long int dni,EPersona persona[],int tam)
{
    int i;
    int flag=-1;

    for(i=0; i<tam; i++)
    {
        if(persona[i].estado==1 && persona[i].dni==dni)
        {
            flag=i;
            break;
        }
    }
    return flag;
}

void darBaja (EPersona persona[],int tam)
{
    int buscar;
    long int dni;
    char respuesta;
    system("cls");
    printf("Ingrese el DNI de la persona a dar de baja : ");
    scanf("%ld",&dni);

    buscar=buscarPersona(dni,persona,tam);

    while (buscar == -1)
    {
        printf("DNI no encontrado\n\nReingrese DNI : ");
        scanf("%ld",dni);
        buscar=buscarPersona(dni,persona,tam);
    }

    mostrarPersona(persona[buscar]);

    printf("Desea dar de baja a esta persona? s/n ");
    fflush(stdin);
    respuesta=getch();

    if(respuesta== 's')
    {
        persona[buscar].estado = 0;
        persona[buscar].dni = 0;
        printf("Se ha dado de baja satisfactoriamente la persona.\n");
    }
    else
    {
        printf("Se ha cancelado la operacion.\n");
    }


}
void mostrarPersona(EPersona persona)
{
    printf("DNI : %ld    Nombre : %s    Edad : %d\n",persona.dni,persona.nombre,persona.edad);
}

void mostrarPersonas(EPersona persona[],int tam)
{
    int i;
    int flag=0;
    for (i=0; i<tam; i++)
    {
        if (persona[i].estado==1)
        {
            mostrarPersona(persona[i]);
            flag = 1;
        }
    }
    if (flag==0)
    {
        printf("No hay personas para mostrar.\n");
    }
}

void graficoEdades(EPersona persona[],int tam)
{
    int i,contMenores=0,contHastaTC=0,contMasTC=0,max;
    system("cls");
    for(i=0; i<tam; i++)
    {
        if(persona[i].estado != 0 && persona[i].edad < 18)
        {
            contMenores++;
        }
        if(persona[i].estado != 0 && persona[i].edad >= 18 && persona[i].edad <= 35)
        {
            contHastaTC++;
        }
        if(persona[i].estado != 0 && persona[i].edad >35)
        {
            contMasTC++;
        }
    }

    if(contMenores > contHastaTC && contMenores > contMasTC)
    {
        max = contMenores;
    }
    else if(contHastaTC > contMasTC)
        max = contHastaTC;
    else
        max = contMasTC;

    for(i=max; i>0; i--)
    {
        if(i <= contMenores)
        {
            printf("  *");
        }

        if(i <= contHastaTC)
        {
            printf("\t  *");
        }
        else
        {
            printf("\t");
        }

        if(i <= contMasTC)
        {
            printf("\t *");
        }

        printf("\n");
    }
    printf(" <18 \t18-35\t>35\n");
    getch();
}

void ordenarPersonas (EPersona persona[],int tam)
{
    EPersona aux;
    int i, j;

    for (i=0; i<tam-1; i++)
    {
        for(j=1; j<tam; j++)
        {
            if (stricmp(persona[i].nombre,persona[j].nombre)>0)
            {
                aux=persona[i];
                persona[i]=persona[j];
                persona[j]=aux;
            }
        }
    }
}

