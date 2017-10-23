#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>
#include "funciones.h"

int obtenerEspacioLibre(eMovie lista[])
{
    int i;
    int retorno=-1;

    for(i=0; i<TAM; i++)
    {
        if(lista[i].estado==0)
        {
            retorno=0;
            break;
        }
    }
    return retorno;
}

void  estados (eMovie movie[])
{
    int i;
    for(i=0; i<TAM; i++)
    {
        movie[i].estado=0;
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

    }
    while(flag!=0 && flagN!=0);

    return auxInt;
}

int agregarPelicula(eMovie movie[])
{
    int i;
    int auxInt;
    char auxChar[70];
    int retorno=0;

    retorno=obtenerEspacioLibre(movie);

    if(retorno!=-1)
    {
        for(i=0; i<TAM; i++)
        {
            if(movie[i].estado==0)
            {
                printf("Ingrese titulo: ");
                fflush(stdin);
                gets(movie[i].titulo);

                printf("Ingrese genero: ");
                fflush(stdin);
                gets(auxChar);

                while((validacion(auxChar))==1)
                {
                    printf("\nError.Contiene numeros.\nReingrese genero: ");
                    fflush(stdin);
                    gets(auxChar);
                }
                mayuscula(auxChar);
                strcpy(movie[i].genero,auxChar);

                printf("Ingrese duracion en minuto: ");
                fflush(stdin);
                gets(auxChar);

                auxInt=validacionInt(auxChar);
                movie[i].duracion=auxInt;
                /*while((validacion(auxChar))==0)
                 {
                     printf("Error.Contiene letras.\n Reingrese duracion:");
                    fflush(stdin);
                 gets(auxChar);
                 }

                  movie[i].duracion=atoi(auxChar);*/

                printf("Ingrese descripcion: ");
                fflush(stdin);
                gets(auxChar);

                strlwr(auxChar);
                auxChar[0]=toupper(auxChar[0]);
                strcpy(movie[i].descripcion,auxChar);

                printf("Ingrese puntaje del 1 al 10: ");
                fflush(stdin);
                gets(auxChar);

                movie[i].puntaje=validacionInt(auxChar);

                printf("Ingrese link de la imagen: ");
                fflush(stdin);
                gets(movie[i].linkImagen);

                movie[i].id=i+1;

                movie[i].estado=1;
                break;
            }
        }
    }
    return retorno;
}

int modificarPelicula(eMovie movie[])
{
    int i;
    int auxInt;
    char auxChar[5];
    int retorno=-1;
    char respuesta;

    mostrar(movie);

    printf("\nIngrese id de la pelicula: ");
    scanf("%d",&auxInt);

    for(i=0; i<TAM; i++)
    {
        if(movie[i].estado==1 && movie[i].id==auxInt)
        {
            printf("Ingrese nuevo puntaje: ");
            fflush(stdin);
            gets(auxChar);
            auxInt=validacionInt(auxChar);

            printf("Desea realizar la modificacion? s/n \n");
            respuesta=tolower(getche());

            if(respuesta=='s')
            {
                movie[i].puntaje=auxInt;
                retorno=1;
            }
            else
            {
                retorno=2;
            }
            break;
        }
    }
    return retorno;
}

int borrarPelicula(eMovie movie[])
{
    int i;
    int auxInt;
    char respuesta;
    int flag=0;

mostrar(movie);

    printf("\nIngrese id de la pelicula a eliminar: ");
    scanf("%d",&auxInt);

    for(i=0; i<TAM; i++)
    {
        if(movie[i].id==auxInt && movie[i].estado==1)
        {
            printf("Desea eliminar?? s/n\n");
            respuesta=tolower(getche());

            if(respuesta=='s')
            {
                movie[i].estado=0;
                flag=1;
            }
            break;
        }
    }
    return flag;
}

int cargarArchivo(eMovie *movie)
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
        fread(movie,sizeof(eMovie),TAM,archivo);
    }

    fclose(archivo);
    return 0;

}

void crearTxt(eMovie *movie)
{
    int i;
    FILE *archivo;
    archivo=fopen("ListaDePeliculas.txt", "w");

    if(archivo == NULL)
    {
        printf("No se pudo abrir el archivo\n");
    }
    else
    {
        fprintf(archivo,"Listado de peliculas\n\n\n");
        fprintf(archivo,"Id\tTitulo\tGenero\tDuracion\tPuntaje\tDescripcion\n");

        for(i=0; i<TAM; i++)
        {
            if(movie[i].estado != 0)
            {
                fprintf(archivo,"%d\t%s %s\t%d\t%d\t%s\n", movie[i].id,movie[i].titulo,movie[i].genero,movie[i].duracion,movie[i].puntaje,movie[i].descripcion);
            }
        }
    }

    fclose(archivo);

    printf("Listado creado con exito\n");

}

int guardarArchivo(eMovie *movie)
{

    FILE *archivo;

    archivo=fopen("bin.dat","wb");
    if(archivo == NULL)
    {
        return 1;
    }

    fwrite(movie,sizeof(eMovie),TAM,archivo);

    fclose(archivo);

    return 0;
}

void generarPagina(eMovie lista[])
{
int i;
    FILE *fHtml;


    fHtml=fopen("Peliculas.html","w");

        if(fHtml!=NULL)
        {
            for(i=0;i<TAM;i++){
                if(lista[i].estado==1)
                {
            fprintf(fHtml,
                    "<!DOCTYPE html>\n"
                    "<html lang='en'>\n"
                     "<head>\n"
            "    <meta charset='utf-8'>\n"
            "    <meta http-equiv='X-UA-Compatible' content='IE=edge'>\n"
            "    <meta name='viewport' content='width=device-width, initial-scale=1'>\n"
            "    <title>Lista peliculas</title>\n"
            "    <link href='css/bootstrap.min.css' rel='stylesheet'>\n"
            "    <link href='css/custom.css' rel='stylesheet'>\n"
            "</head>\n"
                    "<body>\n"
                    "    <div class='container'>\n"
                    "        <div class='row'>\n"
                            "<article class='col-md-4 article-intro'>\n"
                            "<a href='#'>\n"
                            "<img class='img-responsive img-rounded' src=%s alt='ImagenPelicula'/>\n"
                            "</a>\n"
                            "<h3>\n"
                            "<a href='#'>%s</a>\n"
                            "</h3>\n"
                            "<ul>\n"
                            "<li>Genero:%s</li>\n"
                            "<li>Puntaje:%d</li>\n"
                            "<li>Duracion:%d minutos</li>\n"
                            "</ul>\n"
                            "<p>%s</p>\n"
                            " </article>\n",lista[i].linkImagen,lista[i].titulo,lista[i].genero,lista[i].puntaje,lista[i].duracion,lista[i].descripcion);
  }
}

            fprintf(fHtml,
                    "</div>\n"
                    "</div>\n"
                    "<script src='js/jquery-1.11.3.min.js'></script>\n"
            "<script src='js/bootstrap.min.js'></script>\n"
            "<script src='js/ie10-viewport-bug-workaround.js'></script>\n"
            "<script src='js/holder.min.js'></script>\n"
                    "</body>\n"
                    "</html>\n");
        }
        else
        {
            printf("\nNO SE PUDO CREAR EL HTML.\n");
        }
  fclose(fHtml);
    printf("\nPagina web creada con exito.\n\n");

}

void mostrar(eMovie movie[])
{
    int i;

      printf("Id  Titulo\tGenero\tDuracion  Puntaje\tDescripcion\n");

      for(i=0; i<TAM; i++)
        {
            if(movie[i].estado==1)
            {
                printf("%d  %2s\t%5s\t%5d\t%5d\t%7s\n", movie[i].id,movie[i].titulo,movie[i].genero,movie[i].duracion,movie[i].puntaje,movie[i].descripcion);
            }
        }
}





