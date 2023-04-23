#include <stdio.h>
#include <stdlib.h>
#include "ArvB.h"

// estrutura do nó da árvore binária
typedef struct node {
    int ID;
    Item data;
    struct node* left;
    struct node* right;
} Node;

Item get_data(Raiz root){
    Node* node = (Node*)root;
    return node->data;
}

// função para criar um novo nó
Raiz newNode(int ID, Item info) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->ID = ID;
    node->data = info;
    node->left = NULL;
    node->right = NULL;
    return node;
}
// função de inserção
Raiz insert(Raiz root, int ID, Item info) {
    Node* node = (Node*)root;
    // se a árvore estiver vazia, retorna um novo nó
    if (node == NULL) {
        return newNode(ID,info);
    }
    
    // caso contrário, recorre pela árvore
    if (ID < node->ID) {
        node->left = insert(node->left, ID,info);
    } else if (ID > node->ID) {
        node->right = insert(node->right, ID, info);
    }
    
    // retorna o ponteiro do nó (inalterado)
    return node;
}
// função de busca
Raiz search(Raiz root, int ID) {
    Node* node = (Node*)root;
    // se a árvore estiver vazia ou o valor for encontrado na raiz
    if (node == NULL || node->ID == ID) {
        return node;
    }
    
    // se o valor for menor que a raiz, busca na subárvore esquerda
    if (ID < node->ID) {
        return search(node->left, ID);
    }
    
    // se o valor for maior que a raiz, busca na subárvore direita
    return search(node->right, ID);
}
// função para imprimir os nós em ordem crescente
void inOrderTraversal(Raiz root) {
    Node* node = (Node*)root;
    if (node == NULL) {
        return;
    }
    // printf("%d ", node->ID); AQUI ELE MOSTRA O CAMINHO DAS RECURÇOES
    inOrderTraversal(node->left);
    printf("%d ", node->ID);//AQUI ELE ESCREVE EM ORDEM CRESCENTE
    inOrderTraversal(node->right);
    // printf("%d ", node->ID); AQUI ELE ESCREVE O LADO ESQUERDO, DEPOIS O DIREITO , DEPOIS A RAIZ PRINCIPAL
}

void EscreveSvg(Raiz root,ArqSvg arq){
    Node* node = (Node*)root;
    if(node == NULL)return;

    EscreveSvg(node->left,arq);
    escreveCirculoSvg(arq,node->data);
    EscreveSvg(node->right,arq);
}
// função para liberar a memória usada pela árvore
void freeTree(Raiz root) {
    Node* node = (Node*)root;
    if (node == NULL) {
        return;
    }
    freeTree(node->left);
    freeTree(node->right);
    killCirc(node->data);
    free(node);
}

Raiz findMin(Raiz root) {
    Node* node = (Node*)root;
    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}

Raiz delete(Raiz root, int ID) {
    Node* node = (Node*)root;
    if (node == NULL)return NULL;
    if (ID < node->ID)node->left = delete(node->left, ID);
    else if (ID > node->ID){
        node->right = delete(node->right,ID);
    }
    else{
        if (node->left == NULL && node->right == NULL){
            free(node);
            return NULL;
        }
        else if (node->left == NULL){
            Node* temp = node->right;
            free(node);
            return temp;
        }
        else if (node->right == NULL){
            Node* temp = node->left;
            free(node);
            return temp;
        }
        else{
            Node* minNode = findMin(node->right);
            node->ID = minNode->ID;
            node->right = delete(node->right, minNode->ID);
        }
    }
    return node;
}
