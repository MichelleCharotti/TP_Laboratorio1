#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "funciones.h"


int validarNumero(int flag1,int flag2)
{
    if(flag1==0 || flag2==0)
   {
       printf("Error.Falta algun operador.\n");
       return 1;
   }
   return 0;
}

int validacion(float numero)
{
        if(!(isdigit(numero)))
    {
        return 1;
    }

    return 0;
}

float IngresoOperador(char mensaje[])
{
    float numero;

    printf(mensaje);
    scanf("%f", &numero);

    if((validacion(numero))==0)
    {
        printf("Error.No es un numero.\n");
        return 0;
    }
    return numero;
}

float suma(float numero1,float numero2)
{
    float sumas;

    sumas=numero1+numero2;

    printf("La suma es %.2f\n",sumas);
    return sumas;
}

float resta(float numero1,float numero2)
{
    float restas;

    restas=numero1-numero2;

    printf("La resta es %.2f\n",restas);
    return restas;
}

float division(float numero1,float numero2)
{
    float divisiones;
    if(numero2==0)
    {
        printf("Error.El 1er operando no se puede dividir por cero.");
    }
    else
    {
        divisiones= numero1/numero2;

        printf("La division es %.2f\n",divisiones);
    }
    return divisiones;
}

float multiplicacion(float numero1,float numero2)
{
    float multiplica;

    multiplica=numero1*numero2;

    printf("La multiplicacion es %.2f\n",multiplica);
    return multiplica;
}

int factorial(float numero1)
{
    int resultado;

    if(numero1<0)
    {
        printf("Error.El numero tiene que ser entero y positivo para hacer el factorial.\n");
        return -1;
    }
    else
    {
        if(numero1==0)
        {
            return 1;
        }
        resultado=numero1*factorial(numero1-1);

        return resultado;
    }
}





