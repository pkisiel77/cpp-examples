
```cpp
#include <iostream>

using namespace std;

// Node structure containing a value and two children
struct Node {
  int data;
  Node* left;
  Node* right;
};

// Function to create a new node with the given value
Node* newNode(int data) {
  Node* node = new Node;
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return node;
}

// Function to insert a new node into the binary tree
Node* insert(Node* node, int data) {
  // If the tree is empty, assign a new node address to the root
  if (node == NULL) {
    return newNode(data);
  } else {
    // Else, recur down the tree
    if (data <= node->data)
      node->left = insert(node->left, data);
    else
      node->right = insert(node->right, data);
  }
  return node;
}

// Function to do inorder traversal of the binary tree
void inorder(Node* node) {
  if (node != NULL) {
    inorder(node->left);
    cout << node->data << " ";
    inorder(node->right);
  }
}

// Function to do preorder traversal of the binary tree
void preorder(Node* node) {
  if (node != NULL) {
    cout << node->data << " ";
    preorder(node->left);
    preorder(node->right);
  }
}

// Function to do postorder traversal of the binary tree
void postorder(Node* node) {
  if (node != NULL) {
    postorder(node->left);
    postorder(node->right);
    cout << node->data << " ";
  }
}

// Main function
int main() {
  Node* root = NULL;
  root = insert(root, 5);
  root = insert(root, 3);
  root = insert(root, 2);
  root = insert(root, 4);
  root = insert(root, 7);
  root = insert(root, 6);
  root = insert(root, 8);
  
  cout << "Inorder traversal: ";
  inorder(root);
  cout << "\n";

  cout << "Preorder traversal: ";
  preorder(root);
  cout << "\n";

  cout << "Postorder traversal: ";
  postorder(root);
  cout << "\n";
  
  return 0;
}

```
