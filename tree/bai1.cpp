#include<stdio.h> 
#include<stdlib.h>

// dinh nghia 1 node 
typedef struct Node{
	int data;
	struct Node* left;
	struct Node* right; 
}Node; 

// tao ra 1 nut
Node* createNode(int data){
	// cap phat bo nho
	Node* newNode = (Node*) malloc(sizeof(Node));
	newNode -> data = data;
	newNode -> left = NULL;
	newNode -> right = NULL; 
	return newNode; 
} 

// chen 1 nut vao cay
Node* insertNode(Node* node, int data){
	if(node == NULL){
		node = createNode(data);
		
	} 
	if(data < node -> data){
		node -> left = insertNode( node -> left, data); 
	} else if(data > node -> data){
		node -> right = insertNode( node -> right, data); 
	} 
	return node; 
} 

// duyet cay theo phuong phap tien thu tu preorder 
void preorderTraversal(Node* node){
	if(node != NULL){
		printf("%d\t", node -> data);
		preorderTraversal(node -> left);
		preorderTraversal(node -> right);
	} 
	
} 

// duyet cay theo phuong phap trung thu tu inorder
void inorderTraversal(Node* node){
	if(node != NULL){
		preorderTraversal(node -> left);
		printf("%d\t", node -> data);
		preorderTraversal(node -> right);
	} 
} 

// duyet cay theo phuong phap hau thu tu postorder
void postorderTraversal(Node* node){
	if(node != NULL){
		preorderTraversal(node -> left);
		preorderTraversal(node -> right);
		printf("%d\t", node -> data);
	} 
} 

int main(){
	Node* tree = NULL; 
	// insert  
	tree = insertNode(tree, 3);
	tree = insertNode(tree, 2);
	tree = insertNode(tree, 5);
	tree = insertNode(tree, 4);
	tree = insertNode(tree, 6);
	printf("duyet tree theo phuong phap tien thu tu:\n"); 
	preorderTraversal(tree);
	printf("\n");
	printf("duyet tree theo phuong phap trung thu tu:\n"); 
	printf("\n");
	inorderTraversal(tree);
	printf("\n");
	printf("duyet tree theo phuong phap hau thu tu:\n"); 
	printf("\n");
	postorderTraversal(tree);
	return 0; 
} 
