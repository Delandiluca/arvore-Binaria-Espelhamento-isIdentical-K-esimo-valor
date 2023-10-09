#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *left;
  struct node *right;
};


typedef struct node Node;

Node *newNode(int data);
void createTree(Node **tree);
void insertBST(Node **node, int data);
int treeIsEmpty(Node *node);
int isIdentical(Node *one, Node *two);
void invertTree(Node *root);
void preOrder(Node *root);
int returnKLargest(Node* root, int k);

int main(void) {
  Node *rootOne;
  Node *rootTwo;
  createTree(&rootOne);
  createTree(&rootTwo);

  insertBST(&rootOne, 10);
  insertBST(&rootOne, 5);
  insertBST(&rootOne, 15);
  insertBST(&rootOne, 2);
  insertBST(&rootOne, 6);
  insertBST(&rootOne, 12);
  insertBST(&rootOne, 17);

  insertBST(&rootTwo, 5);
  insertBST(&rootTwo, 1);
  insertBST(&rootTwo, 4);

  // if (isIdentical(rootOne, rootTwo)) {
  // puts("\nSÃO IGUAIS");
  //} else {
  // puts("\nNÃO SÃO IGUAIS");
  //}

  //invertTree(rootOne);
  //preOrder(rootOne);
  int data = returnKLargest(rootOne, 2);
  

  return 0;
}

void createTree(Node **tree) { *tree = NULL; }

int treeIsEmpty(Node *node) { return node == NULL; }

Node *newNode(int data) {
  // Aloca memória para newNode
  Node *node = (Node *)malloc(sizeof(Node));
  // Atribui o dado a newNode
  node->data = data;
  // Atribui NULL a left e right
  node->left = NULL;
  node->right = NULL;
  return (node);
}

void insertBST(Node **node, int data) {
  if (treeIsEmpty(*node)) {
    *node = newNode(data);
  } else {
    if (data < (*node)->data) { // ESQUERDA SE FOR MENOR
      insertBST(&(*node)->left, data);
    }
    if (data > (*node)->data) { // DIREITA SE FOR MAIOR
      insertBST(&(*node)->right, data);
    }
  }
}

int isIdentical(Node *one, Node *two) {
  if ((one == NULL) && (two == NULL)) {
    return 1;
  }

  return ((one != NULL) && (two != NULL)) && ((one->data == two->data)) &&
         isIdentical(one->left, two->left) &&
         isIdentical(one->right, two->right);
}

int returnKLargest(Node* root, int k) {
    int count = 0;
    if (root == NULL) {
        return 0;
    }
    int result = returnKLargest(root->right, k);
    if (result != 0) {
        return result;
    }
    count++;
    if (count == k) {
        return root->data;
    }
    return returnKLargest(root->left, k);
}

void invertTree(Node *root) {
  if (root == NULL) {
    return;
  }

  Node *temp = root->left;
  root->left = root->right;
  root->right = temp;

  invertTree(root->left);
  invertTree(root->right);
}

void preOrder(Node *root) {
  if (root != NULL) {
    printf("\n%i", root->data);
    preOrder(root->left);
    preOrder(root->right);
  }
}
