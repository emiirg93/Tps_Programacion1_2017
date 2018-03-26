#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

EMovie* crearLista (int sizeLista) // reservar la memoria de la lista.
{
    EMovie* aux = (EMovie*)malloc(sizeof(EMovie)*sizeLista);

    if (aux == NULL)
    {
        printf("No hay lugar en memoria\n");
    }
    else
    {
        printf("Se creo la lista correctamente.\n\n\n");
    }

    return aux;
}

void inicializarLista (EMovie* lista, int sizeLista)
{
    int i;


    for(i=0; i<sizeLista; i++)
    {
        strcpy((lista+i)->titulo,"Nada");
        strcpy((lista+i)->genero,"Nada");
        (lista+i)->duracion = 0;
        strcpy((lista+i)->descripcion,"Nada");
        (lista+i)->puntaje = 0;
        strcpy((lista+i)->linkImagen,"Nada");
        (lista+i)->estado = 0;
        (lista+i)->id = 0;
    }
}

void inicializarPelicula (EMovie* lista,int indice)
{
    strcpy((lista+indice)->titulo,"Nada");
    strcpy((lista+indice)->genero,"Nada");
    (lista+indice)->duracion = 0;
    strcpy((lista+indice)->descripcion,"Nada");
    (lista+indice)->puntaje = 0;
    strcpy((lista+indice)->linkImagen,"Nada");
    (lista+indice)->estado = 0;
    (lista+indice)->id = 0;
}

void mostrarPeliculas (EMovie* lista, int sizeLista)
{
    int i;

    for(i=0; i<sizeLista; i++)
    {
       // if((lista+i)->estado == 1)
        //{
            mostrarPelicula(lista,i);
        }
    //}
}
void mostrarPelicula (EMovie* lista, int indice)
{
    printf("PELICULA.\n\ntitulo: %s \nID Pelicula: %d \nGenero: %s \nDescripcion:%s \nduracion : %d \npuntaje: %d \n\n",(lista+indice)->titulo,(lista+indice)->id,(lista+indice)->genero,(lista+indice)->descripcion,(lista+indice)->duracion,(lista+indice)->puntaje);
}

void leerArchivo (EMovie* lista,FILE* archivo, int sizeLista)
{
    archivo = fopen("archivo.bin","rb");
    int i = 0;

    if(archivo == NULL ) // si no existe el archivo.
    {
        archivo = fopen("archivo.bin","wb"); // crea un archivo.

        if(archivo == NULL )
        {
            printf("No se pudo crear el archivo.\n");
            exit(0);
        }
    }

    while(!feof(archivo))
    {
        fread((lista+i),sizeof(EMovie),1,archivo); // lee el archivo
        i++;

    }

    fclose(archivo);
}

int alta (EMovie* lista,int sizeLista)
{
    int i;
    int libre,aux;
    int encontro= 0 ;
    int valorRespuesta = -1;

    libre = buscarLibre(lista,sizeLista);

    if (libre != -1)
    {
        printf("\nIngresar ID de pelicula : ");
        scanf("%d",&aux);

        for(i=0; i<sizeLista; i++)
        {
            if (aux == (lista+i)->id)
            {
                encontro = 1;
                break;
            }
        }
        if (encontro != 1)
        {
            printf("Ingresar Titulo: ");
            fflush(stdin);
            gets((lista+libre)->titulo);

            printf("Ingresar Genero: ");
            fflush(stdin);
            gets((lista+libre)->genero);

            printf("Ingresar Descripcion: ");
            fflush(stdin);
            gets((lista+libre)->descripcion);

            printf("Ingresar LinkImagen: ");
            fflush(stdin);
            gets((lista+libre)->linkImagen);

            printf("\nIngresar puntaje : ");
            scanf("%d",&(lista+libre)->puntaje);

            while((((lista+libre)->puntaje)<1) || (((lista+libre)->puntaje)>10))
            {
                printf("\nError!\nReingrese un puntaje del 1 al 10 : ");
                scanf("%d",&(lista+libre)->puntaje);
            }

            printf("\nIngresar Duracion : ");
            scanf("%d",&(lista+libre)->duracion);

            (lista+libre)->id = aux;
            (lista+libre)->estado=1;
            valorRespuesta = 0;

        }
        else
        {
            printf("El ID ya existe.");
        }
    }
    else
    {
        printf("No hay mas espacio.\n");
    }

    return valorRespuesta;
}

void bajaPelicula (EMovie* lista, int sizeLista)
{
    int auxId,indice;
    char confirma;
    printf("Ingrese ID De Pelicula A La Baja : ");
    scanf("%d",&auxId);

    indice = BuscarPelicula(auxId,lista,sizeLista);

    if (indice != -1)
    {
        mostrarPelicula(lista,indice);
        printf("\nConfirma la baja? s/n: ");
        fflush(stdin);
        confirma=getchar();

        if (confirma == 's')
        {
            inicializarPelicula(lista,indice);
        }
        else
        {
            printf("Se Cancelo La Accion Por El Usuario.");
        }
    }
    else
    {
        printf("No Se Encontro La Pelicula");
    }
}

EMovie* agrandarEspacio (EMovie* lista, int sizeLista)
{
    EMovie* auxLista;
    int auxSize;
    sizeLista++;
    auxSize = sizeof(EMovie)*sizeLista;
    auxLista = realloc(lista, auxSize);

    if(auxLista == NULL)
    {
        printf("No hay mas memoria disponible.\n");
    }
    else
    {
        lista = auxLista;
        inicializarLista(lista,sizeLista);
    }

    return sizeLista;
}

int buscarLibre(EMovie* lista,int sizeLista)
{
    int index=-1;
    int i;
    for(i=0; i <sizeLista; i++)
    {
        if((lista+i)->estado==0)
        {
            index=i;
            break;
        }
    }

    return index;
}

void guardar (EMovie* lista, FILE* archivo,int sizeLista)
{
    int i;
    archivo = fopen("archivo.bin","wb");
    if (archivo == NULL)
    {
        printf("No Se Pudo Crear Correctamente El Archivo.");
        exit(0);
    }
    else
    {
        for (i=0; i<sizeLista; i++)
        {
            fwrite((lista+i),sizeof(EMovie),1,archivo);
        }
    }
    fclose(archivo);
}

int BuscarPelicula (int id, EMovie* lista, int sizeLista)
{
    int i;
    int indice = -1;

    for(i=0; i<sizeLista; i++)
    {
        if(id == (lista+i)->id)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

void modificarPelicula (EMovie* lista,int sizeLista)
{
    int auxId,indice,opcion;
    int salir = 0;
    char confirma;

    printf("Ingrese ID De Pelicula A Modificar : ");
    scanf("%d",&auxId);

    indice = BuscarPelicula(auxId,lista,sizeLista);

    if(indice != -1)
    {
        mostrarPelicula(lista,indice);
        printf("Quiere Modificar Esta Pelicula s/n\nRespuesta : ");
        fflush(stdin);
        confirma=getchar();

        if(confirma == 's')
        {
            do
            {
                printf("Que Campo Desea Modificar?");
                printf("1- Titulo.\n2- Genero.\n3- Descripcion.\n4- Duracion.\n5- Puntaje.\n6- Link Imagen.\n7- Salir De La Modificacion\n\nRespuesta : ");
                scanf("%d",&opcion);

                switch(opcion)
                {
                case 1:
                    printf("\nIngrese Titulo: ");
                    fflush(stdin);
                    gets((lista+indice)->titulo);
                    printf("Se Modifico Con Exito El Titulo.");
                    break;
                case 2:
                    printf("\nIngrese Genero: ");
                    fflush(stdin);
                    gets((lista+indice)->genero);
                    printf("Se Modifico Con Exito El Genero.");
                    break;
                case 3:
                    printf("\nIngrese Descripcion: ");
                    fflush(stdin);
                    gets((lista+indice)->descripcion);
                    printf("Se Modifico Con Exito La Descripcion.");
                    break;
                case 4:
                    printf("\nIngrese Duracion: ");
                    scanf("%d",&(lista+indice)->duracion);
                    printf("Se Modifico Con Exito La Duracion");
                    break;
                case 5:
                    printf("\nIngrese Duracion: ");
                    scanf("%d",&(lista+indice)->puntaje);
                    printf("Se Modifico Con Exito El Puntaje");
                    break;
                case 6:
                    printf("\nIngrese Link De Imagen: ");
                    fflush(stdin);
                    gets((lista+indice)->linkImagen);
                    printf("Se Modifico Con Exito La Imagen.");
                    break;
                case 7:
                    salir = 1;
                    break;

                }
            }
            while (salir != 1);

        }
        else
        {
            printf("Accion Cancelada.");
        }
    }
    else
    {
        printf("No Se Encontro La Pelicula.");
    }
}

void crearHTML (EMovie* lista,int sizeLista)
{
    int i;
    FILE* pelicula;

    pelicula = fopen("pagina.html","w");

    for (i=0; i<sizeLista; i++)
    {
        if((lista+i)->estado == 1)
        {
            fprintf(pelicula,"<article class='col-md-4 article-intro'>\n<a href='#'>\n<img class='img-responsive img-rounded' src='%s' alt=''>\n</a>\n<h3>\n<a href='#'>%s</a>\n</h3>\n<ul>\n<li>Género:%s</li>\n<li>Puntaje:%d</li>\n<li>Duración:%d</li>\n</ul>\n <p>%s</p>\n</article>",(lista+i)->linkImagen,(lista+i)->titulo,(lista+i)->genero,(lista+i)->puntaje,(lista+i)->duracion,(lista+i)->descripcion);
        }


    }

    //fprintf(pelicula,"</div></div><script src='js/jquery-1.11.3.min.js'></script><script src='js/bootstrap.min.js'></script><script src='js/ie10-viewport-bug-workaround.js'></script><script src='js/holder.min.js'></script></body></html>");

    fclose(pelicula);
}
