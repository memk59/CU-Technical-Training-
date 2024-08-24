#include<bits/stdc++.h> 
using namespace std; 
  
class Node{ 
    public: 
      string data; 
      Node* left; 
      Node* right; 
      Node(string d) 
      { 
          data=d; 
          left=NULL; 
          right=NULL; 
      } 
}; 
  
class BinarySearchTree { 
  
    // Root of BST 
    public: 
    Node *root; 
  
    // Constructor 
    BinarySearchTree() 
    { 
        root = NULL; 
    } 
  
    // Utility function for inorder traversal of the tree 
    void inorderUtil(Node* node) 
    { 
        if (node == NULL) 
            return; 
  
        inorderUtil(node->left); 
        cout << node->data << " "; 
        inorderUtil(node->right); 
    } 
  
    // Inorder traversal of the tree 
    void inorder() 
    { 
        inorderUtil(this->root); 
    } 
  
    /* A recursive function to insert a new key in BST */
    Node* insertRec(Node* root, string data) 
    { 
  
        /* If the tree is empty, return a new node */
        if (root == NULL) { 
            root = new Node(data); 
            return root; 
        } 
  
        /* Otherwise, recur down the tree */
        if (data < root->data) 
            root->left = insertRec(root->left, data); 
        else if (data > root->data) 
            root->right = insertRec(root->right, data); 
  
        return root; 
    } 
  
    // This method mainly calls insertRec() 
    void insert(string key) 
    { 
        root = insertRec(root, key); 
    } 
  
  
    // Method that adds values of given BST into vector 
    // and hence returns the vector 
    vector<string> treeToList(Node* node, vector<string>& list) 
    { 
        // Base Case 
        if (node == NULL) 
            return list; 
  
        treeToList(node->left, list); 
        list.push_back(node->data); 
        treeToList(node->right, list); 
  
        return list; 
    } 
  
    // method that checks if there is a pair present 
    bool isPairPresent(Node* node, string target) 
    { 
        // This list a1 is passed as an argument 
        // in treeToList method 
        // which is later on filled by the values of BST 
        vector<string> a1; 
  
        // a2 list contains all the values of BST 
        // returned by treeToList method 
        vector<string> a2 = treeToList(node, a1); 
  
        int start = 0; // Starting index of a2 
  
        int end = (int)a2.size() - 1; // Ending index of a2 
  
        while (start < end) { 
  
            if (a2[start] + a2[end] == target) // Target Found! 
            { 
                cout << "Pair Found: " << a2[start] << " + " << a2[end] << " = " << target << '\n'; 
                return true; 
            } 
  
            if (a2[start] + a2[end]  > target) // decrements end 
            { 
                end--; 
            } 
  
            if (a2[start] + a2[end]  < target) // increments start 
            { 
                start++; 
            } 
        } 
  
        cout << "No such values are found!\n"; 
        return false; 
    } 
}; 
  
// Driver function 
int main() 
{ 
    BinarySearchTree *tree = new BinarySearchTree(); 
    /* 
            15 
            /     \ 
        10     20 
        / \     / \ 
        8 12 16 25 */
    tree->insert("Dog"); 
    tree->insert("Bat"); 
    tree->insert("Fan"); 
    tree->insert("Apple"); 
    tree->insert("Cat"); 
    tree->insert("Eagle"); 
    tree->insert("Goat"); 
  
    tree->isPairPresent(tree->root, "AppleGoat"); 
}
