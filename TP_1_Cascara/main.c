#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    char seguir='s';
    int opcion=0;
    float numero1;
    float numero2;
    int Factorial;
    int flagX=0;
    int flagY=0;


    while(seguir=='s')
    {
        if(opcion==1 || flagX==1)
        {
            printf("1- Ingresar 1er operando (A=%.2f)\n",numero1);
            flagX=1;
        }
        else
        {
            printf("1- Ingresar 1er operando (A=x)\n");
        }

        if(opcion==2 || flagY==1)
        {
            printf("2- Ingresar 2do operando (B=%.2f)\n",numero2);
            flagY=1;
        }
        else
        {
            printf("2- Ingresar 2do operando (B=y)\n");
        }

        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operacione\n");
        printf("9- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
            numero1=IngresoOperador("Ingrese un numero entero: ");
            break;
        case 2:
            numero2=IngresoOperador("Ingrese un numero entero: ");
            break;
        case 3:
            if((validarNumero(flagX,flagY)) ==0)
            {
                suma(numero1,numero2);
            }
            break;
        case 4:
            if((validarNumero(flagX,flagY)) ==0)
            {
                resta(numero1,numero2);
            }
            break;
        case 5:
            if((validarNumero(flagX,flagY)) ==0)
            {
                division(numero1,numero2);
            }
            break;
        case 6:
            if((validarNumero(flagX,flagY)) ==0)
            {
                multiplicacion(numero1,numero2);
            }
            break;
        case 7:
            if((validarNumero(flagX,1)) ==0)
            {
                Factorial=factorial(numero1);
                if(Factorial!=-1)
                {
                    printf("El factorial es %d\n",Factorial);
                }
            }
            break;
        case 8:
            if((validarNumero(flagX,flagY)) ==0)
            {
                suma(numero1,numero2);
                resta(numero1,numero2);
                division(numero1,numero2);
                multiplicacion(numero1,numero2);
                Factorial=factorial(numero1);
                if(Factorial!=-1)
                {
                    printf("El factorial es %d\n",Factorial);
                }
            }
            break;
        case 9:
            seguir = 'n';
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
