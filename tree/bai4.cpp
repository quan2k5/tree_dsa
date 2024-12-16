#include <stdio.h>
#include <stdlib.h>

// Dinh nghia 1 nut
typedef struct Node{
	int data;
	struct Node* left;
	struct Node* right;
}Node;

//Tao ra 1 nut
Node* createNode(int data){
	//cap phat bo nho
	Node* newNode = (Node*) malloc(sizeof(Node));
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

Node* insertNode(Node* node, int data) {
    if(node == NULL) {
        return createNode(data);
    }
    if(data < node->data) {
        node->left = insertNode(node->left, data);
    }
    else if(data > node->data) {
        node->right = insertNode(node->right, data);
    }
    return node;
}


void preorderTraversal(Node* node){
	if(node != NULL){
		printf("%d\t",node->data);
		preorderTraversal(node->left);
		preorderTraversal(node->right);
	}
}

void inorderTraversal(Node* node){
	if(node != NULL){
		inorderTraversal(node->left);   
        printf("%d\t", node->data);    
        inorderTraversal(node->right);
	}
}

void postorderTraversal(Node* node){
	if(node != NULL){
		postorderTraversal(node->left);   
        postorderTraversal(node->right);
        printf("%d\t", node->data);    
	}
}

int calculateHeight(Node* root) {
    if (root == NULL) {
        return 0;
    }

    int leftHeight = calculateHeight(root->left);

    int rightHeight = calculateHeight(root->right);

    int height;
    if (leftHeight > rightHeight) {
        height = leftHeight + 1;
    } else {
        height = rightHeight + 1;
    }

    return height;
}



int main(){
	
	Node* tree = NULL;
	tree = createNode(1);
  	tree->left = createNode(2);
    tree->right = createNode(3);
    tree->left->left = createNode(4);
    tree->left->right = createNode(5);
    tree->right->left = createNode(6);
	

   	int height = calculateHeight(tree);
    printf("\nChieu cao cua cay: %d\n", height);
	
	return 0;
}
