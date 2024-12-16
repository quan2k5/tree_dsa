#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
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
    }
    else if (data > node->data) {
        node->right = insertNode(node->right, data);
    }
    
    return node;
}

void preorderTraversal(Node* node) {
    if (node != NULL) {
        printf("%d\t", node->data);  
        preorderTraversal(node->left);
        preorderTraversal(node->right);
    }
}

void inorderTraversal(Node* node) {
    if (node != NULL) {
        inorderTraversal(node->left);
        printf("%d\t", node->data);    
        inorderTraversal(node->right); 
    }
}

void postorderTraversal(Node* node) {
    if (node != NULL) {
        postorderTraversal(node->left);  
        postorderTraversal(node->right); 
        printf("%d\t", node->data);    
    }
}

int search(Node* node, int value) {
    if (node == NULL) {
        return 0;  
    }
    if (node->data == value) {
        return 1; 
    } else if (value < node->data) {
        return search(node->left, value);
    } else {
        return search(node->right, value); 
    }
}

int main() {
    Node* tree = NULL; 
    int choice, value;

    while (1) {
        printf("\n--- Menu ---\n");
        printf("1. Chen gia tri\n");
        printf("2. Tim kiem\n");
        printf("3. Duyet theo inorder\n");
        printf("4. Thoat\n");
        printf("Nhap yeu cau: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Nhap gia tri: ");
                scanf("%d", &value);
                tree = insertNode(tree, value);
                printf("Da chen gia tri %d vao cay.\n", value);
                break;

            case 2:
                printf("Nhap gia tri: ");
                scanf("%d", &value);
                if (search(tree, value)) {
                    printf("Tim thay %d trong cay.\n", value);
                } else {
                    printf("Ko tim thay %d trong cay.\n", value);
                }
                break;

            case 3:
                inorderTraversal(tree);
                printf("\n");
                break;

            case 4:
                exit(0);

            default:
                printf("L?a ch?n không h?p l?. Vui l?ng ch?n l?i.\n");
        }
    }

    return 0;
}
