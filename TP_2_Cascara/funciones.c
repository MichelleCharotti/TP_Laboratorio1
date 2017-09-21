#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>
#include "funciones.h"


int obtenerEspacioLibre(EPersona lista[],int tam)
{
    int i;

    for(i=0; i<tam; i++)
    {
        if(lista[i].estado==0)
        {
            return 0;
        }

    }
    return -1;
}

int buscarPorDni(EPersona lista[], int dni,int tam)
{
    int i;

    for(i=0; i<tam; i++)
    {
        if(lista[i].dni==dni)
        {
            return 1;
        }
    }

    return -1;
}

void  estados (EPersona persona[], int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        persona[i].estado=0;
    }
}

int validacion(char nombre[])
{
    int j;
    int cant;
    int flagDig=0;

    cant = strlen(nombre);

    for(j=0; j<cant; j++)
    {
        if(isdigit(nombre[j]))
        {
            flagDig = 1;
        }
    }

    return flagDig;
}

char mayuscula(char nombre[])
{
    int j;

    strlwr(nombre);
    nombre[0]=toupper(nombre[0]);

    for(j=0; j<strlen(nombre); j++)
    {
        if(isspace(nombre[j]))
        {
            nombre[j+1]=toupper(nombre[j+1]);
        }
    }

    return nombre;
}

int validacionEdad(int edad)
{
    int flagEdad=0;

    if (edad<0||edad>120)
    {
        flagEdad=1;
    }

    return flagEdad;
}

void altaPersona(EPersona persona[],int tam)
{
    int i;
    int flag=0;
    char auxChar[50];
    int auxInt;


    for(i=0; i<tam; i++)
    {
        if(persona[i].estado==0)
        {
            flag=1;
            printf("Ingrese nombre:");
            fflush(stdin);
            gets(auxChar);

            while((validacion(auxChar))==1)
            {
                printf("\nError.Contiene numeros.\nReingrese nombre: ");
                fflush(stdin);
                gets(auxChar);
            }

            mayuscula(auxChar);
            strcpy(persona[i].nombre,auxChar);


            printf("Ingrese edad:");
            fflush(stdin);
            gets(auxChar);


            while((validacion(auxChar))==0)
            {
                printf("Error.Contiene letras.\n Reingrese edad:");
               fflush(stdin);
            gets(auxChar);
            }

            auxInt=atoi(auxChar);

            while((validacionEdad(auxInt))==1)
            {
                printf("Error. Reingrese edad:");
                scanf("%d",&auxInt);
               ;
            }


            persona[i].edad=auxInt;

            printf("Ingrese DNI:");
            fflush(stdin);
            gets(auxChar);

            while((validacion(auxChar))==0)
            {
                printf("Error.Contiene letras.\n Reingrese DNI:");
                fflush(stdin);
            gets(auxChar);
            }

            persona[i].dni=atoi(auxChar);

            persona[i].estado=1;
            break;
        }

    }
    if(flag==0)
    {
        printf("No hay mas espacio.\n");
    }
}



void borrarPersona(EPersona persona[],int tam)
{
    int auxDni;
    int flag=0;
    int i;
    char respuesta;

    printf("Ingrese DNI:");
    scanf("%d",&auxDni);

    for(i=0; i<tam; i++)
    {
        if((buscarPorDni(persona,auxDni,tam))==1)
        {
            flag=1;
            mostrar(persona[i]);
            printf("Desea eliminar?? s/n\n");
            respuesta=getche();

            if(respuesta=='s')
            {
                persona[i].estado=-1;
            }
            else
            {
                printf("Accion cancelada.\n");
            }
            break;
        }
    }
    if(flag==0)
    {
        printf("DNI inecistente.\n");
    }
}

void mostrar(EPersona persona)
{
    printf("%s\t%2d\t%2d\n",persona.nombre,persona.edad,persona.dni);
}


void ordenarPorNombre(EPersona persona[],int tam)
{
    int i;
    int j;
    EPersona auxPersona;

    for(i=0; i<tam-1; i++)
    {
        for(j=i+1; j<tam; j++)
        {
            if(persona[i].estado==1 && persona[j].estado==1)
            {
                if((stricmp(persona[i].nombre,persona[j].nombre))>0)
                {
                    auxPersona=persona[i];
                    persona[i]=persona[j];
                    persona[j]=auxPersona;
                }
                else
                {
                    if((strcmp(persona[i].nombre,persona[j].nombre))==0)
                    {
                        if(persona[i].dni>persona[i].dni)
                        {
                            auxPersona=persona[i];
                            persona[i]=persona[j];
                            persona[j]=auxPersona;
                        }

                    }
                }
            }
        }
    }

    for(i=0; i<tam; i++)
    {
        if(persona[i].estado!=0)
        {
            printf("%s\t%2d\t%2d\n",persona[i].nombre,persona[i].edad,persona[i].dni);
        }
    }
}

void grafico(EPersona persona[],int tam)
{
    int i,j;
    int contMen=0;
    int cont=0;
    int contMay=0;
    int maximo;
    int dato[3]= {};

    contMen=valor(persona,19,0,tam);
    cont=valor(persona,36,18,tam);
    contMay=valor(persona,120,35,tam);

    dato[0]=contMen;
    dato[1]=cont;
    dato[2]=contMay;

    maximo=0;

    for (i = 0; i < 3; i++)
    {
        if (dato[i] >= maximo)
        {
            maximo =  dato[i];
        }
    }

    for (i = maximo; i > 0; i--)
    {

        for (j = 0; j < 3; j++)
        {
            if (dato[j] >= i)
            {
                printf("\t*");

            }
            else
            {
                printf("  ");
            }
        }
        printf("\n");

    }

    printf("\t<18\t19-35\t>35\n\n");

    return;
}

int valor(EPersona persona[],int mayor,int menor,int tam)
{
    int i;
    int contador=0;

    for(i=0; i<tam; i++)
    {
        if(persona[i].estado==1)
        {
            if(persona[i].edad>menor && persona[i].edad<mayor)
            {
                contador++;
            }
        }
        else
        {
            break;
        }
    }
    return contador;
}

