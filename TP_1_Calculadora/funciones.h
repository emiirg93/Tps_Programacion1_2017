#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

/** \brief Permite ingresar un numero, guardarlo en una variable y retornarlo.
 *
 * \param mensaje a ser mostrado.
 * \return el numero ingresado por el usuario.
 *
 */

int ingresarNumero(char texto[]);

/** \brief Permite realizar la suma entre dos numeros.
 *
 * \param primer numero a sumar.
 * \param segundo numero a sumar.
 * \return el resultado de la suma entre los dos numeros.
 *
 */

int suma (int a,int b);

/** \brief Permite realizar la resta entre dos numeros.
 *
 * \param primer numero a restar.
 * \param segundo numero a restar.
 * \return el resultado de la suma entre los dos numeros.
 *
 */

int resta (int a,int b);

/** \brief Permite realizar la division entre dos numeros.
 *
 * \param primer numero (dividendo).
 * \param segundo numero (divisor).
 * \return el resultado de la division entre los dos numeros.
 *
 */

float dividir (int a,int b);

/** \brief permite realizar la multiplicacion entre dos numeros.
 *
 * \param primer numero a multiplicar.
 * \param segundo numero a multiplicar.
 * \return el resultado de la multiplicacion entre los dos numeros.
 *
 */

int multiplicar (int a,int b);

/** \brief permite realizar el factorial de un numero.
 *
 * \param numero "A" a sacar su factor.
 * \return muestra el factorial del numero "A".
 *
 */

int factorial(int a);

/** \brief permite mostrar los numeros ingresados.
 *
 * \param primer numero ingresado.
 * \param segundo numero ingresado.
 *
 */

void mostrarIngresados (int a,int b);

#endif // FUNCIONES_H_INCLUDED
