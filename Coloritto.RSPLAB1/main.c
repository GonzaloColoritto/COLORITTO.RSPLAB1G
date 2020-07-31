#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "menu.h"
#include "ll_list.h"
#include "Controller.h"
#include "informes.h"
#include<time.h>
int main()
{
    srand (time(NULL));

    char seguir = 's';
    char confirmacion;
    int flag=0;


    LinkedList* listaPaises = ll_newLinkedList();
    LinkedList* listaPaisesExitosos=NULL;
    LinkedList* listaPaisesEnElHorno=NULL;

    do
    {
        switch(menuInicio())
        {
        case 1:

            if(controller_loadFromText("pandemia.csv",listaPaises)==0)
            {
                printf("Datos Cargados con exito\n");
                flag=1;
            }
            else
            {

                printf("Error en la carga de datos\n");

            }

            break;

        case 2:
            if(flag==1)
            {
                if(!controller_ListPais(listaPaises))
                {

                    printf("Listadas con exito\n");
                }
                else
                {
                    printf("Error al listar\n");
                }
            }
            else
            {
                printf("ERROR. Debe primero abrir el archivo\n\n");
            }
            break;

        case 3:
            if(flag==1)
            {
                listaPaises=ll_map(listaPaises,setearRecuperados);
                listaPaises=ll_map(listaPaises,setearInfectados);
                listaPaises=ll_map(listaPaises,setearMuertos);
                if(!controller_ListPais(listaPaises))
                {

                    printf("Listados con exito\n");
                }
                else
                {
                    printf("Error al listar\n");
                }
            }
            else
            {
                printf("ERROR. Debe primero abrir el archivo\n\n");

            }
            break;

        case 4:
            if(flag==1)
            {
                listaPaisesExitosos=ll_newLinkedList();
                listaPaisesExitosos=ll_filter(listaPaises,filtrarPorMuertos);
                if(!controller_ListPais(listaPaisesExitosos))
                {
                    controller_saveAsText("paisesExitosos.csv",listaPaisesExitosos);
                    printf("Filtrados y guardadas con exito en 'paisesExitosos.csv' \n");
                }
                else
                {
                    printf("Error al filtrar\n");
                }
            }
            else
            {
                printf("ERROR. Debe primero abrir el archivo\n\n");
            }
            break;

        case 5:
            if(flag==1)
            {
                listaPaisesEnElHorno=ll_newLinkedList();
                listaPaisesEnElHorno=ll_filter(listaPaises,filtrarPorEnElHorno);
                if(!controller_ListPais(listaPaisesEnElHorno))
                {
                    controller_saveAsText("paisesEnElHorno.csv",listaPaisesEnElHorno);
                    printf("Filtrados y guardadas con exito en 'paisesEnElHorno.csv' \n");
                }
                else
                {
                    printf("Error al filtrar\n");
                }
            }
            else
            {
                printf("ERROR. Debe primero abrir el archivo\n\n");
            }
            break;

        case 6:
            if(flag==1)
            {
                if(ll_sort(listaPaises,ordenarPorInfectados,0)==0)
                {

                    if(!controller_ListPais(listaPaises))
                    {

                        printf("Orden mostrado de forma descendente\n");
                    }
                    else
                    {
                        printf("Error al listar en orden\n");
                    }

                }
            }
            else
            {
                printf("ERROR. Debe primero abrir el archivo\n\n");
            }

            break;

        case 7:
            if(flag==1)
            {
                ll_buscarMasAlto(listaPaises);
            }
            else
            {
                printf("ERROR. Debe primero abrir el archivo\n\n");
            }
            break;

        case 8:
            do
            {
                printf(" ¿Desea salir? S/N: ");
                fflush(stdin);
                scanf("%c",&confirmacion);

                confirmacion=tolower(confirmacion);
            }
            while(confirmacion!='s'&&confirmacion!='n');
            if(confirmacion=='s')
            {
                seguir = 'n';
                printf("Gracias por usar el programa.\n");
            }
            if(confirmacion=='n')
            {
                printf("______________________________________\n");
                printf("Puede continuar utilizando el programa\n");
            }
            break;


        }
        system("pause");
    }
    while(seguir=='s');
}
