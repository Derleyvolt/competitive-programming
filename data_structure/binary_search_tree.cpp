#include <bits/stdc++.h>

using namespace std;

#include <bits/stdc++.h>
  
using namespace std;
  
struct node {
    struct node* left;  
    struct node* right;  
    int data;  
};  
  
// cria um nó
node* newNode(int data)  {  
    node* root   = new node;
    node->data   = data;  
    node->left   = NULL;  
    node->right  = NULL;  
    return root;
}  
 
node* search(node* root, int data) {
	// case base: a raiz é null ou o raiz tem o valor que procuramos
    if (root == NULL || root->data == data)
       return root;
    
	// valor é maior que o valor da raiz
    if (root->data < data)
       return search(root->right, data);
 
    // valor é menor que o valor da raiz
    return search(root->left, data);
}
 
node* insert(node* root, int data) {
    // Se a árvore não é vazia, retorne um novo nó
    if (root == NULL)
        return newNode(data);
 
    // busque recursivamente
    if (data < root->data)
        root->left  = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
 
    // retorne o nó, sem alteração
    return root;
}

node* delete_node(node* root, int data) {
   if (root == NULL) return root;
      if (data < root->data)
         root->left  = delete_node(root->left, data);
      else if (data > root->key)
         root->right = delete_node(root->right, data);
   else {
      if (root->left == NULL) {
         node *temp = root->right;
         delete root;
         return temp;
      }
      else if (root->right == NULL) {
         node *temp = root->left;
         delete root;
         return temp;
      }
      node* temp  = min_value(root->right);
      root->data  = temp->data;
      root->right = delete_node(root->right, temp->data);
   }
   return root;
}

void inorder(node* root) {
    if (root != NULL) {
        inorder(root->left);
	cout << root->key << endl;
        inorder(root->right);
    }
}

// o nó passado não deve ser nulo, senão levará a um comportamento indefinido..
int minValue(struct node* node) {  
    struct node* current = node;  

    /* loop down to find the leftmost leaf */
    while (current->left != NULL) {  
        current = current->left;  
    }  
    return(current->data);  
}  

// versão recursiva
int min_value(node* root) {
    if(root->left == NULL)
        return root->data;
    return min_value(root->left);
}

int main() {
    return 0;
}
