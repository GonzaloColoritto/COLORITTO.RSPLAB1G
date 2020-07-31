#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "pais.h"
#include "ll_list.h"
#include <time.h>
/** \brief devuelve un numero aleatorio entre 50000 y 1000000
 *
 * \param
 * \param
 * \return devuelve el numero
 *
 */

int getRamdomRecuperados(void)
{
    int aleatorio;

    aleatorio=rand() %(960001)+40000;

    return aleatorio;
}

/** \brief devuelve un numero aleatorio entre 500000 y 2000000
 *
 * \param
 * \param
 * \return devuelve el numero
 *
 */
int getRamdomInfectados(void)
{
    int aleatorio;

    aleatorio=rand() %(1880001)+120000;

    return aleatorio;
}

/** \brief devuelve un numero aleatorio entre 1000 y 50000
 *
 * \param
 * \param
 * \return devuelve el numero
 *
 */
int getRamdomMuertos(void)
{
    int aleatorio;

    aleatorio=rand() % (49001)+1000;

    return aleatorio;
}
/** \brief castea el primer parametro a ePais* y  le carga un numero aleatorio en el campo recuperados a traves de una funcion
 *
 * \param puntero a void
 * \param
 * \return retorna el primer parametro casteado a ePais*
 *
 */

void* setearRecuperados(void* pais)
{

    ePais* auxPais;

    if(pais!=NULL)
    {
        auxPais = (ePais*) pais;
        pais_setRecuperados(auxPais,getRamdomRecuperados());

    }
    return auxPais;
}
/** \brief castea el primer parametro a ePais* y  le carga un numero aleatorio en el campo infectados a traves de una funcion
 *
 * \param puntero a void
 * \param
 * \return retorna el primer parametro casteado a ePais*
 *
 */
void* setearInfectados(void* pais)
{

    ePais* auxPais;

    if(pais!=NULL)
    {
        auxPais = (ePais*) pais;
        pais_setInfectados(auxPais,getRamdomInfectados());

    }
    return auxPais;
}
/** \brief castea el primer parametro a ePais* y  le carga un numero aleatorio en el campo muertos a traves de una funcion
 *
 * \param puntero a void
 * \param
 * \return retorna el primer parametro casteado a ePais*
 *
 */
void* setearMuertos(void* pais)
{

    ePais* auxPais;

    if(pais!=NULL)
    {
        auxPais = (ePais*) pais;
        pais_setMuertos(auxPais,getRamdomMuertos());

    }
    return auxPais;
}
/** \brief filtra el parametro para ver si en el campo muertos tiene menos de 5000
 *
 * \param puntero a void
 * \param
 * \return  1 si el parametro tiene menos de 5000 en el campo muertos | 0 si tiene mas de 5000 en el campo muertos
 *
 */

int filtrarPorMuertos(void* pais)
{

    int retorno=0;
    ePais* auxPais;

    if(pais!=NULL)
    {
        auxPais = (ePais*) pais;
        if(auxPais->muertos<5000)
        {
            retorno=1;
        }
    }
    return retorno;
}
/** \brief filtra los paises que tengan mas del triple de infectados que de recuperados
 *
 * \param puntero a void
 * \param
 * \return 1 si el parametro tiene el triple de infectados que de recuperados | 0 si no los tiene
 *
 */

int filtrarPorEnElHorno(void* pais)
{

    int retorno=0;
    ePais* auxPais;

    if(pais!=NULL)
    {
        auxPais = (ePais*) pais;
        if(auxPais->infectados>(auxPais->recuperados)*3)
        {
            retorno=1;
        }
    }
    return retorno;
}
/** \brief verifica si el primer parametro tiene mas infectados que el segundo
 *
 * \param puntero a void 1
 * \param puntero a void 2
 * \return  1 si el primer parametro es mayor | -1 si el segundo es mayor | 0 si soon iguales
 *
 */

int ordenarPorInfectados(void* infectados1, void* infectados2)
{


    int infectados_1;
    int infectados_2;
    int retorno = 0 ;

    pais_getInfectados(infectados1, &infectados_1);
    pais_getInfectados(infectados2,&infectados_2);

    if (infectados_1> infectados_2)
    {
        retorno = 1 ;
    }
    else  if (infectados_1 < infectados_2)
    {
        retorno = -1 ;
    }
    return retorno;
}


