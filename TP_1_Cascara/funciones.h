#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

/** \brief Valida que se haya ingresado los valores
 * \param Recibe dos valores
 * \return Retorna 1 si no se ingreso algun valor y 0 si se an ingresado los dos valores
 */
int validarNumero(int,int);

/** \brief Valida si el valor ingresado si es un numero
 * \param Recibe el operando a validar
 * \return Devuelve 1 si no es un numero y 0 si lo es
 */
int validacion(float);

/** \brief Se ingresan los numeros a utilizar
 * \param mensaje, muestra al usuario lo que debe ingresar
 * \return Retorna el numero ingresado
 */
float IngresoOperador(char[]);

/** \brief Suma dos operadores
 * \param Recibe dos numeros para sumar
 * \return Retorna el resultado de la suma de los operandos
 */
float suma(float,float);

/** \brief Resta dos valores
 * \param Recibe dos numeros para restar
 * \return Devuelve el resultado de la resta de los valores
 */
float resta(float,float);

/** \brief Divide dos valores mientras que el segundo velor no sea cero
 * \param Recibe dos valores para dividir
 * \return Retorna el resultado de la division
 */
float division(float,float);

/** \brief Multiplica dos numeros
 * \param Recibe dos numeros para multiplicar
 * \return Devuelve el producto de la multiplicacion
 */
float multiplicacion(float,float);

/** \brief Factoriza un valor, mientras que este no sea negativo
 * \param Recive un numero para factorizar
 * \return Retorna el resultado de la factorizacion
 */
int factorial(float);



#endif // FUNCIONES_H_INCLUDED
