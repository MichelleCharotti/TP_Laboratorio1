#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>
#include "funciones.h"



int main()
{
    char seguir='s';
    int opcion=0;
    char guardar;
    int retorno;
    eMovie movie[TAM];

    estados(movie);


    if(cargarArchivo(movie))
    {
        printf("No se pudo abrir el fichero");
    }
    else
    {
        printf("Se cargo con exito\n");
    }
    system("pause");
    system("cls");

    while(seguir=='s')
    {
        printf("1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Modificar pelicula\n");
        printf("4- Generar pagina web\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
            if((agregarPelicula(movie))!=0)
            {
                printf("No hay espacio.\n");
            }
            break;
        case 2:
            if((borrarPelicula(movie))==1)
            {
                printf("Eliminacion exitosa.\n");
            }
            else
            {
                printf("Accion cancelada.\n");
            }
            break;
        case 3:
            retorno=modificarPelicula(movie);
            if(retorno==-1)
            {
                printf("Id inecistente.\n");
            }
            else
            {
                if(retorno==2)
                {
                    printf("Accion cancelada.\n");
                }
            }
            break;
        case 4:
            crearTxt(movie);
            generarPagina(movie);
            break;

        case 5:
            printf("\nGuardar los cambios? s/n: ");
            guardar = tolower(getche());

            if(guardar == 's')
            {
                if(guardarArchivo(movie))
                {
                    printf("\nNo se pudo abrir el fichero\n");
                }
                else
                {
                    printf("\nSe guardo la informacion con exito\n");
                }
            }
            seguir = 'n';
            break;
        default:
            printf("Error. Opcion incorrecta.\n");
            break;
        }

        system("pause");
        system("cls");
    }

    return 0;
}
