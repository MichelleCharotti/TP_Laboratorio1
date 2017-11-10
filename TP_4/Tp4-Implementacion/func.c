#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>
#include "ArrayList.h"
#include "func.h"

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

void mayuscula(char nombre[])
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
}

int validacionInt(char auxChar[])
{
    int auxInt;
    int flag=0;
    int flagN=0;

    do
    {
        flag=0;
        while((validacion(auxChar))==0)
        {
            flag=1;
            printf("Error.Contiene letras.\n Reingrese: ");
            fflush(stdin);
            gets(auxChar);
        }
        auxInt=atoi(auxChar);
        flagN=0;

        if(auxInt<0)
        {
            flagN=1;
            printf("Error.Numero negativo.\n Reingrese: ");
            fflush(stdin);
            gets(auxChar);
        }

    }while(flag!=0 && flagN!=0);

    return auxInt;
}

ePelicula* newPelicula(int id,char titulo[],char genero[],char descripcion[])
{
    ePelicula* returnAux=NULL;
    ePelicula* nuevaPelicula=(ePelicula*)malloc(sizeof(ePelicula));

    if(nuevaPelicula!=NULL)
    {
        nuevaPelicula->id=id;
        strcpy(nuevaPelicula->titulo,titulo);
        strcpy(nuevaPelicula->genero,genero);
        strcpy(nuevaPelicula->descripcion,descripcion);
        returnAux=nuevaPelicula;
    }
    return returnAux;
}

void alta(ArrayList* pelicula)
{
    ePelicula* nuevaPelicula;
    char* id=(char*)malloc(sizeof(char)*10);
    char titulo[100];
    char genero[100];
    char descripcion[100];
    int auxInt;

    printf("Ingrese el ID: ");
    fflush(stdin);
    gets(id);
    auxInt=validacionInt(id);

    printf("Ingrese el titulo: ");
    fflush(stdin);
    gets(titulo);

    printf("Ingrese el genero: ");
    fflush(stdin);
    gets(genero);

    while((validacion(genero))==1)
    {
        printf("\nError.Contiene numeros.\nReingrese genero: ");
        fflush(stdin);
        gets(genero);
    }
    mayuscula(genero);

    printf("Ingrese descripcion: ");
    fflush(stdin);
    gets(descripcion);

    mayuscula(descripcion);

    nuevaPelicula=newPelicula(auxInt,titulo,genero,descripcion);
    if(nuevaPelicula!=NULL)
    {
        pelicula->add(pelicula,nuevaPelicula);
    }
    else
    {
        printf("Error!!!");
    }
    id++;
}

void mostrarUnaPelicula(ePelicula* pelicula)
{
    printf("%d  %s\t%s\t%s\n",pelicula->id,pelicula->titulo,pelicula->genero,pelicula->descripcion);
}

void mostrarLista(ArrayList* pelicula)
{
    int i;

     printf("ID  TITULO\tGENERO\tDESCRIPCION\n");

    for(i=0; i<pelicula->size; i++)
    {
        mostrarUnaPelicula(pelicula->pElements[i]);
    }
}

void borrar(ArrayList* pelicula)
{
    char* id=(char*)malloc(sizeof(char)*10);
    int auxInt;
    int index;
    char respuesta='n';

    mostrarLista(pelicula);

    printf("Ingrese el ID:\n");
    fflush(stdin);
    gets(id);
    auxInt=validacionInt(id);

    printf("Seguro que desea eliminarlo? s/n\n");
    fflush(stdin);
    scanf("%c",&respuesta);
    respuesta=tolower(respuesta);

    if(respuesta=='s')
    {
        index=buscarPorId(pelicula,auxInt);
        if(index!=-1)
        {
            if(!pelicula->remove(pelicula,index))
            {
                printf("La pelicula esta eliminada\n");
            }
        }
    }
    else
    {
        printf("Accion cancelada\n");
    }
}

int buscarPorId(ArrayList* pelicula,int idBuscar)
{
    ePelicula* auxPeli;
    int returnAux=-1;
    int i;
    for(i=0; i<pelicula->size; i++)
    {
        auxPeli=pelicula->get(pelicula,i);
        if(auxPeli->id==idBuscar)
        {
            returnAux=i;
            break;
        }
    }
    return returnAux;
}

int cargarArchivo(ArrayList* pelicula)
{
    int flag = 0;
    FILE *archivo;

    archivo=fopen("bin.dat", "rb");
    if(archivo==NULL)
    {
        archivo= fopen("bin.dat", "wb");
        if(archivo==NULL)
        {
            return 1;
        }
        flag=1;
    }

    if(flag ==0)
    {
        fread(pelicula,sizeof(ArrayList),pelicula->size,archivo);
    }

    fclose(archivo);
    return 0;

}

void crearTxt(ArrayList* pelicula)
{
    int i;
    FILE* archivo;
    archivo=fopen("ListaDePeliculas.txt", "w");

    if(archivo == NULL)
    {
        printf("No se pudo abrir el archivo\n");
    }
    else
    {
        fprintf(archivo,"Listado de peliculas\n\n\n");
        fprintf(archivo,"Id\tTitulo\tGenero\tDescripcion\n");

        for(i=0; i<pelicula->size; i++)
        {
         mostrarArchivo(pelicula->pElements[i],archivo);
        }
    }

    fclose(archivo);

    printf("Listado creado con exito\n");

}

void mostrarArchivo(ePelicula* movie,FILE* archivo)
{
    fprintf(archivo,"%d  %s\t%s\t%s\n",movie->id,movie->titulo,movie->genero,movie->descripcion);
}

int guardarArchivo(ArrayList* pelicula)
{
    FILE *archivo;

    archivo=fopen("bin.dat","wb");
    if(archivo == NULL)
    {
        return 1;
    }

    fwrite(pelicula,sizeof(ArrayList),pelicula->size,archivo);

    fclose(archivo);

    return 0;
}
