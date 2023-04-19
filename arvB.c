#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct Node* insert(struct Node* node, int data) {
    if (node == NULL)return createNode(data);
    
    if (data > node->data)node->left = insert(node->left, data);
        else if (node->data > data)node->right = insert(node->right, data);

    return node;
}

void inorderTraversal(struct Node* node) {
    if (node == NULL)return;
    
    inorderTraversal(node->left);
    printf("%d ", node->data);
    inorderTraversal(node->right);
}

int main() {
    struct Node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    printf("Inorder traversal of binary tree: ");
    inorderTraversal(root);
    return 0;
}
