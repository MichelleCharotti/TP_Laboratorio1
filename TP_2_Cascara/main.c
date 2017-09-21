#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

#define TAM 20

int main()
{
    char seguir='s';
    int opcion=0;
EPersona persona[TAM];
estados(persona,TAM);

    while(seguir=='s')
    {
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                altaPersona(persona,TAM);
                break;
            case 2:
                borrarPersona(persona,TAM);
                break;
            case 3:
                ordenarPorNombre(persona,TAM);
                break;
            case 4:
                grafico(persona,TAM);
                break;
            case 5:
                seguir = 'n';
                break;
            default:
                printf("Error.Opcion inesistente.");
        }
system("pause");
system("cls");
    }

    return 0;
}
