#ifndef ARV_H_
#define ARV_H_

#include "arqsvg.h"
#include "Circulo.h"
typedef void* Raiz;
typedef void* Item;

Item get_data(Raiz root);

Raiz newNode(int ID, Item info);

Raiz insert(Raiz node, int ID, Item info) ;

Raiz search(Raiz node, int ID);

void inOrderTraversal(Raiz node);

void EscreveSvg(Raiz node,ArqSvg arq);

void freeTree(Raiz node);

Raiz findMin(Raiz root);

Raiz delete(Raiz root, int ID);

#endif