#include "ArvB.h"


int main(){
    Raiz root = NULL;

    Circulo A = criaCirc(3,10,10,10,"blue","blue");
    root = insert(root, get_circ_ID(A),A);

    Circulo B = criaCirc(1,15,15,10,"green","blue");
    insert(root, get_circ_ID(B),B);

    Circulo C = criaCirc(2,20,20,10,"pink","blue");
    insert(root, get_circ_ID(C),C);

    Circulo D = criaCirc(4,25,25,10,"red","blue");
    insert(root, get_circ_ID(D),D);

    Circulo E = criaCirc(7,50,25,10,"red","blue");
    insert(root, get_circ_ID(E),E);

    Circulo F = criaCirc(5,40,25,10,"red","blue");
    insert(root, get_circ_ID(F),F);

    Circulo G = criaCirc(6,20,50,10,"red","blue");
    insert(root, get_circ_ID(G),G);
    // imprime os nós em ordem crescente
    inOrderTraversal(root);
    printf("\n");
    
    Raiz acha = search(root,6);
    set_circ_corp(get_data(acha),"green");
    delete(root,5);
    inOrderTraversal(root);
    
    ArqSvg svg =  abreEscritaSvg("Circulos.svg");
    EscreveSvg(root,svg);
    fechaSvg(svg);

    freeTree(root);
}