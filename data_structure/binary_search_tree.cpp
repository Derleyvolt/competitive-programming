#include <bits/stdc++.h>

using namespace std;

#include <bits/stdc++.h>
  
using namespace std;
  
struct node  {
    struct node* left;  
    struct node* right;  
    int data;  
};  
  
// cria um nó
node* newNode(int data)  {  
	node* node   = new ::node;
	node->data   = data;  
	node->left   = NULL;  
	node->right  = NULL;  
	return node;
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
    if(root->left == null)
        return root->data;
    return min_value(root->left);
}

int main() {
    return 0;
}
