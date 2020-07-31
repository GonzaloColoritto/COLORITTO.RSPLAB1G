#include <stdio.h>
#include <stdlib.h>
#include "ll_list.h"
#include "pais.h"
#include "parser.h"
#include "utn.h"

/** \brief carga los datos desde un archivo
 *
 * \param path es el archivo.
 * \param pArrayList es la la linkedlist.
 * \return 0=Funciona -1=Error.
 *
 */
int controller_loadFromText(char *path, LinkedList *pArrayList)
{

    FILE* pFile;
    int paso = -1;


    pFile = fopen("pandemia.csv", "r");
    if (pFile != NULL)
    {
        parser_FromText(pFile, pArrayList);

        paso = 0;
    }
    fclose(pFile);
    return paso;
}

/** \brief lista los paises del linkedlist
 *
 * \param pArrayList es la linkedlist
 * \return 0=Funciona -1=Error.
 *
 */


int controller_ListPais(LinkedList* pArrayList)
{

    int retorno=-1;
    ePais* lista;
    int id;
    char nombre[20];
    int recuperados;
    int infectados;
    int muertos;


    if(pArrayList==NULL)
    {

        printf("No hay paises para listar\n");

    }
    else
    {

        printf("ID                     NOMBRE        RECUPERADOS           INFECTADOS             MUERTOS\n\n");
        retorno=0;
        for (int i=0; i<ll_len(pArrayList); i++)
        {

            lista = ll_get(pArrayList,i);

            pais_getId(lista,&id);
            pais_getNombre(lista,nombre);
            pais_getRecuperados(lista,&recuperados);
            pais_getInfectados(lista,&infectados);
            pais_getMuertos(lista,&muertos);


            printf("ID:%03d   %20s             %06d              %07d             %07d \n",id,nombre,recuperados,infectados, muertos);

        }

    }
    return retorno;
}

/** \brief guarda el pArrayList en un archivo de texto.
 *
 * \param path es el archivo en donde se guarda. Si no existe lo crea.
 * \param pArrayList es el linkedlist.
 * \return 0=Funciona -1=Error.
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayList)
{
    int paso=0;
    ePais* lista;
    FILE* pfile = fopen(path, "w");
    int id;
    char nombre[20];
    int recuperados;
    int infectados;
    int muertos;
    int flag=0;



    if(path!=NULL && pArrayList!=NULL)
    {

        for(int i=0; i<ll_len(pArrayList); i++)
        {

            lista = ll_get(pArrayList,i);
            pais_getId(lista,&id);
            pais_getNombre(lista,nombre);
            pais_getRecuperados(lista,&recuperados);
            pais_getInfectados(lista,&infectados);
            pais_getMuertos(lista,&muertos);
            if(!flag)
            {
                fprintf(pfile,"%s,%s,%s,%s,%s\n","id","nombre","recuperados","infectados","muertos");
                flag=1;
            }

            fprintf(pfile,"%d,%s,%d,%d,%d\n",id,nombre,recuperados,infectados,muertos);

        }
        paso=1;

    }
    fclose(pfile);



    return paso;
}
