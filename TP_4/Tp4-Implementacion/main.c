#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include "ArrayList.h"
#include "func.h"

int main()
{
    char seguir='s';
    int opcion=0;
    char guardar;

    ePelicula* movie;
    ArrayList* pelicula=al_newArrayList();

     if(cargarArchivo(pelicula))
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
    printf("1.Agregar pelicula\n2.Borrar pelicula\n3.Mostrar\n4.Salir\n");
    scanf("%d",&opcion);

    switch(opcion)
    {
    case 1:
        alta(pelicula);
        break;
        case 2:
            borrar(pelicula);
        break;
        case 3:
            mostrarLista(pelicula);
        break;
         case 4:
             printf("\nGuardar los cambios?s/n");
             guardar=tolower(getche());
             if(guardar=='s')
             {
 if(guardarArchivo(pelicula))
                {
                    printf("\nNo se pudo abrir el fichero\n");
                }
                else
                {
                    printf("\nSe guardo la informacion con exito\n");
                }
             }
             crearTxt(pelicula);
             seguir='n';
        break;
    default:
        printf("Error.Opcion incorrecta.\n");
        break;
    }
    system("pause");
    system("cls");
}
    return 0;
}
