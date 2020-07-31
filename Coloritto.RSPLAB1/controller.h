#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED
#include "ll_list.h"
int controller_loadFromText(char* path , LinkedList* pArrayList);
int controller_saveAsText(char* path , LinkedList* pArrayList);
int controller_ListPais(LinkedList* pArrayList);

#endif // CONTROLLER_H_INCLUDED
