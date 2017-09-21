#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct
{
    char nombre[50];
    int edad;
    unsigned int dni;
    int estado;
} EPersona;

/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */
int obtenerEspacioLibre(EPersona[],int);

/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int buscarPorDni(EPersona[],int,int);

/** \brief Obtiene el primer incide del array.
 * \param Recibe la estructura perosna.
 * \param Recibe el tamanio del array.
 * \return Retorna los estados en cero.
 */
void  estados (EPersona[],int);

/** \brief Valida si contiene numeros.
 * \param Recibe elemento a validar.
 * \return Retorna uno si tiene numeros o cero si no tiene ninguno.
 */
int validacion(char[]);

/** \brief Pone en mayuscula la primer letra de la una palabra y en minuscula las demas letras.
 * \param Recibe las palabras a modificar.
 * \return Devuelve las palabras modificadas.
 */
char mayuscula(char[]);

/** \brief Valida el rago de edad.
 * \param Obtiene un numero a validar.
 * \return Devuelve 1 si no esta en el rango de numeros y 0 si lo esta.
 */
int validacionEdad(int);

/** \brief Se ingresan los datos.
 * \param Se pasa la estructura persona.
 * \param Recibe el tamanio del array.
 * \return Retorna los datos ingresados.
 */
void altaPersona(EPersona[],int);

/** \brief Busca si el dato existe y lo borra.
 * \param Recibe como parametro la estructura persona.
 * \param Obtiene el tamanio del array;
 * \return Devuelve el estado del dato.
 */
void borrarPersona(EPersona[],int);

/** \brief Muestra los datos de la estructura.
 * \param Recibe la estructura persona.
 * \return Devuelve los datos a mostrar.
 */
void mostrar(EPersona);

/** \brief Ordena los datos por nombre y si son iguales por dni.
 * \param Recibe la estructura persona.
 * \param Recibe el tamaño del array.
 * \return Devuelve los valores ingresados ordenados.
 */
void ordenarPorNombre(EPersona[],int);

/** \brief Tabula un grafico de barras segun los vgalores de la edad.
 * \param Se pasa como parametro la estructura persona.
 * \param se pasa el tamanio del array.
 * \return Devuelve el grafico.
 */
void grafico(EPersona[],int);

/** \brief Cuenta segun si esta dentro del rango de numeros.
 * \param Obtiene  un rango mayor.
 * \param Obtiene un rango menor.
 * \param Recibe el tamanio del array.
 * \return Retorna el valor del contador.
 */
int valor(EPersona[],int,int,int);
#endif // FUNCIONES_H_INCLUDED
