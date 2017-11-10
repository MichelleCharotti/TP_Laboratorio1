#include "ArrayList.h"

typedef struct
{
    int id;
    char titulo[20];
    char genero[20];
    char descripcion[70];
}ePelicula;

/** \brief Valida si contiene numeros.
 * \param Recibe elemento a validar.
 * \return Retorna uno si tiene numeros o cero si no tiene ninguno.
 */
int validacion(char[]);

/** \brief Pone en mayuscula la primer letra de la una palabra y en minuscula las demas letras.
 * \param Recibe las palabras a modificar.
 * \return Devuelve las palabras modificadas.
 */
void mayuscula(char[]);

/** \brief Valida si contiene letras y si es negativo.
 * \param Recibe el valor a validar.
 * \return Devuelve el valor validado.
 */
int validacionInt(char[]);

/**\brief Agrega una pelicula.
 *  \param Recibe el ArrayList.
 *  \return Da de alta un dato.
 */
void alta(ArrayList*);

/**\brief Borra una pelicula.
 * \param Recibe el ArrayList.
 *  \return Elimina el dato de la pelicula.
 */
void borrar(ArrayList*);

/** \brief
 * \param
 * \param
 * \return
 */
ePelicula* newPelicula(int,char[],char[],char[]);


int buscarPorId(ArrayList*,int);

/** \brief Muestra un dato.
 * \param Obtiene la estructura ePleicula.
 * \return Retorna el dato a mostrar.
 */
void mostrarUnaPelicula(ePelicula*);

/** \brief Muestra los datos.
 * \param Recibe el ArrayList.
 * \return Retorna los datos a mostrar.
 */
void mostrarLista(ArrayList*);

/** \brief Carga el archivo.
 * \param Recibe la estructura ePelicula.
 * \return Retorna el archivo.
 */
int cargarArchivo(ArrayList*);

/** \brief Crea un txt con los datos.
 * \param Recibe el ArrayList.
 * \return Retorna si se creo o no.
 */
void crearTxt(ArrayList*);

/** \brief Abre y escribe el archivo.
 * \param Recibe el ArrayList.
 * \return Devuelve el archivo con los datos.
 */
int guardarArchivo(ArrayList*);

/** \brief Copia la informacion en el archivo.
 * \param Recibe la estructura ePelicula.
 * \param Recibe el archivo FILE.
 * \return Retorna el archivo con los datos.
 */
void mostrarArchivo(ePelicula*,FILE*);

