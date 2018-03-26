#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

EMovie* crearLista (int sizeLista);
void inicializarLista (EMovie* lista, int sizeLista);
void mostrarMovies (EMovie* lista, int sizeLista);
void leerArchivo (EMovie* lista,FILE* archivo, int sizeLista);
int main()
{
    EMovie * lista;
    FILE* archivo;
    int TAM = 4;
    int respuestaAlta,i;
    lista = crearLista(TAM);
    leerArchivo (lista,archivo,TAM);
    inicializarLista(lista,TAM);

    char seguir='s';
    int opcion=0;

    while(seguir=='s')
    {
        printf("1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Modificar Pelicula\n");
        printf("4- Generar pagina web\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
            respuestaAlta = alta(lista,TAM);
            if (respuestaAlta != 0)
            {
                TAM = agrandarEspacio(lista,TAM);
            }
            else
            {
                guardar (lista,archivo,TAM);
            }
            break;
        case 2:
            bajaPelicula(lista,TAM);
            guardar (lista,archivo,TAM);
            break;
        case 3:
            mostrarPeliculas(lista,TAM);
            modificarPelicula(lista,TAM);
            guardar (lista,archivo,TAM);
            break;
        case 4:
            crearHTML(lista,TAM);
            break;
        case 5:
            seguir = 'n';
            break;
        }
    }

    return 0;
}




