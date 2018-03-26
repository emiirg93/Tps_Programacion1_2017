#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct{
    char titulo[50];
    char genero[20];
    int duracion;
    char descripcion[200];
    int puntaje;
    char linkImagen[200];
    int estado;
    int id;
}EMovie;
EMovie* agrandarEspacio (EMovie* lista, int sizeLista);
EMovie* crearLista (int sizeLista);
void inicializarLista (EMovie* lista, int sizeLista);
void inicializarPelicula (EMovie* lista,int indice);
void mostrarPeliculas (EMovie* lista, int sizeLista);
void mostrarPelicula (EMovie* lista, int indice);
void leerArchivo (EMovie* lista,FILE* archivo, int sizeLista);
int alta (EMovie* lista,int sizeLista);
void bajaPelicula (EMovie* lista, int sizeLista);
int buscarLibre(EMovie* lista,int sizeLista);
void guardar (EMovie* lista, FILE* archivo,int sizeLista);
int BuscarPelicula (int id, EMovie* lista, int sizeLista);
void modificarPelicula (EMovie* lista,int sizeLista);
void crearHTML (EMovie* lista,int sizeLista);
/**
 *  Agrega una pelicula al archivo binario
 *  @param movie la estructura a ser agregada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo agregar la pelicula o no
 */
//int agregarPelicula(EMovie movie);

/**
 *  Borra una pelicula del archivo binario
 *  @param movie la estructura a ser eliminada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo eliminar la pelicula o no
 */
//int borrarPelicula(EMovie movie);

/**
 *  Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 *  @param lista la lista de peliculas a ser agregadas en el archivo.
 *  @param nombre el nombre para el archivo.
 */
//void generarPagina(EMovie lista[], char nombre[]);

#endif // FUNCIONES_H_INCLUDED
