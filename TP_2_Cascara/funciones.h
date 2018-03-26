#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct
{

    char nombre[50];
    int edad;
    int estado;
    long int dni;

} EPersona;

/**
/** \brief Obtiene el primer indice libre del array.
 * @param lista del array
 * @param el tamanio del array.
 * @return el primer indice disponible
 */
int buscarLibre(EPersona persona[],int tam);

/**
/** \brief Obtiene el indice que coincide con el dni pasado por parametro.
 * @param dni a buscar.
 * @param lista del array
 * @param tamanio del array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int buscarPersona(long int dni,EPersona persona[],int tam);

/** \brief Menu del programa.
 *
 * \return la opcion del menu a ejecutar.
 *
 */
int menu ();
/** \brief Inicia los estados en 0.
 *
 * \param lista del array.
 * \param tamanio del array
 * \return void
 *
 */
void inicializar(EPersona [],int tam);
/** \brief Permite ingresar una persona al sistema.
 *
 * \param lista del array.
 * \param tamanio del array
 * \return void
 *
 */
void altaPersona(EPersona persona[],int tam);
/** \brief Permite dar la baja de una persona ingresada.
 *
 * \param lista del array.
 * \param tamanio del array.
 * \return void.
 *
 */
void darBaja (EPersona persona[],int tam);
/** \brief Muestra los datos ingresados de una sola persona.
 *
 * \param lista del array.
 * \return void
 *
 */
void mostrarPersona(EPersona persona);
/** \brief Permite mostrar de forma grafica las personas segun su edad.
 *
 * \param lista del array.
 * \param tamanio del array.
 * \return void.
 *
 */
void graficoEdades(EPersona persona[],int tam);
/** \brief Muestra los datos de todas las personas ingresadas.
 *
 * \param lista del array.
 * \param tamanio del array.
 * \return void.
 *
 */
void mostrarPersonas(EPersona persona[],int tam);
/** \brief Ordena las personas ingresadas segun nombre.
 *
 * \param lista del array.
 * \param tamanio del array.
 * \return void.
 *
 */
void ordenarPersonas (EPersona persona[],int tam);
/** \brief busca una persona si es que esta ingresada.
 *
 * \param dni de la persona a buscar.
 * \param lista del array.
 * \param tamanio del array.
 * \return el indice en donde esta guardado el dni.
 *
 */
int buscarPersona(long int dni,EPersona persona[],int tam);


#endif // FUNCIONES_H_INCLUDED
