#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#define TAM 10

typedef struct{
    char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[70];
    int puntaje;
    char linkImagen[70];
    int estado;
    int id;
}eMovie;

/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */
int obtenerEspacioLibre(eMovie[]);


/** \brief Obtiene el primer indice del array.
 * \param Recibe la estructura persona.
 * \param Recibe el tamanio del array.
 * \return Retorna los estados en cero.
 */
void  estados (eMovie[]);

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

/**
 *  Agrega una pelicula al archivo binario
 *  @param movie la estructura a ser agregada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo agregar la pelicula o no
 */
int agregarPelicula(eMovie movie[]);

/**
 *  Borra una pelicula del archivo binario
 *  @param movie la estructura a ser eliminada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo eliminar la pelicula o no
 */
int borrarPelicula(eMovie movie[]);

/** \brief Modifica la puntuacion.
 * \param Recibe la estructura eMovie.
 * \return Retorna si lo modifico o no.
 */
int modificarPelicula(eMovie[]);

/**
 *  Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 *  @param lista la lista de peliculas a ser agregadas en el archivo.
 *  @return Retorna si se creo el archivo o no.
 */
void generarPagina(eMovie lista[]);

/** \brief Carga el archivo.
 * \param Recibe la estructura eMovie.
 * \return Retorna el archivo.
 */
int cargarArchivo(eMovie*);

/** \brief Crea un txt con los datos.
 * \param Recive la estructura eMovie.
 * \return Retorna si se creo o no.
 */
void crearTxt(eMovie*);

/** \brief Abre y escribe el archivo.
 * \param Recibe la estructura eMovie.
 * \return Devuelve el archivo con los datos.
 */
int guardarArchivo(eMovie*);

/** \brief Muestra los datos.
 * \param Obtiene la estructura eMovie.
 * \return Retorna los datos a mostrar.
 */
void mostrar(eMovie[]);
#endif // FUNCIONES_H_INCLUDED
