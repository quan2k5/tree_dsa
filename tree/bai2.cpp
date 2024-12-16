#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int data){
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insertNode(Node* node, int data) {
    if (node == NULL) {
        return createNode(data);
    }
    if (data < node->data) {
        node->left = insertNode(node->left, data);
    } else if (data > node->data) {
        node->right = insertNode(node->right, data);
    }
    return node;
}

void preorderTraversal(Node* node){
    if (node != NULL) {
        printf("%d\t", node->data);
        preorderTraversal(node->left);
        preorderTraversal(node->right);
    }
}

void inorderTraversal(Node* node){
    if (node != NULL) {
        inorderTraversal(node->left);   
        printf("%d\t", node->data);    
        inorderTraversal(node->right);
    }
}

void postorderTraversal(Node* node){
    if (node != NULL) {
        postorderTraversal(node->left);   
        postorderTraversal(node->right);
        printf("%d\t", node->data);    
    }
}

void findLevel2Nodes(Node* root) {
    if (root == NULL) {
        return;
    }

    if (root->left != NULL) {
        if (root->left->left != NULL) {
            printf("Lv2: %d\n", root->left->left->data);
        }
        if (root->left->right != NULL) {
            printf("Lv2: %d\n", root->left->right->data);
        }
    }

    if (root->right != NULL) {
        if (root->right->left != NULL) {
            printf("Lv2: %d\n", root->right->left->data);
        }
        if (root->right->right != NULL) {
            printf("Lv2: %d\n", root->right->right->data);
        }
    }
}



int main(){
    Node* tree = NULL;
    int n;
    int value;
    printf("Nhap n: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Gia tri: ");
        scanf("%d", &value);
        tree = insertNode(tree, value);
    }

    printf("\nCac dinh o lv2:\n");
    findLevel2Nodes(tree);

    return 0;
}
