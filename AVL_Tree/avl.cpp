/* AVL Tree Implementation in C++   */
/* Harish R                         */


#include<iostream>

using namespace std;

class BST
{
    struct node
    {
        int data;
        node* left;
        node* right;
        int height;
    };

    node* root;

    void makeEmpty(node* t)
    {
        if(t == NULL)
            return;
        makeEmpty(t->left);
        makeEmpty(t->right);
        delete t;
    }

    node* insert(int x, node* t)
    {
        if(t == NULL)
        {
            t = new node;
            t->data = x;
            t->height = 0;
            t->left = t->right = NULL;
        }
        else if(x < t->data)
        {
            t->left = insert(x, t->left);
            if(height(t->left) - height(t->right) == 2)
            {
                if(x < t->left->data)
                    t = singleRightRotate(t);
                else
                    t = doubleRightRotate(t);
            }
        }
        else if(x > t->data)
        {
            t->right = insert(x, t->right);
            if(height(t->right) - height(t->left) == 2)
            {
                if(x > t->right->data)
                    t = singleLeftRotate(t);
                else
                    t = doubleLeftRotate(t);
            }
        }

        t->height = max(height(t->left), height(t->right))+1;
        return t;
    }

    node* singleRightRotate(node* &t)
    {
        node* u = t->left;
        t->left = u->right;
        u->right = t;
        t->height = max(height(t->left), height(t->right))+1;
        u->height = max(height(u->left), t->height)+1;
        return u;
    }

    node* singleLeftRotate(node* &t)
    {
        node* u = t->right;
        t->right = u->left;
        u->left = t;
        t->height = max(height(t->left), height(t->right))+1;
        u->height = max(height(t->right), t->height)+1 ;
        return u;
    }

    node* doubleLeftRotate(node* &t)
    {
        t->right = singleRightRotate(t->right);
        return singleLeftRotate(t);
    }

    node* doubleRightRotate(node* &t)
    {
        t->left = singleLeftRotate(t->left);
        return singleRightRotate(t);
    }

    node* findMin(node* t)
    {
        if(t == NULL)
            return NULL;
        else if(t->left == NULL)
            return t;
        else
            return findMin(t->left);
    }

    node* findMax(node* t)
    {
        if(t == NULL)
            return NULL;
        else if(t->right == NULL)
            return t;
        else
            return findMax(t->right);
    }

    node* remove(int x, node* t)
    {
        node* temp;

        // Element not found
        if(t == NULL)
            return NULL;

        // Searching for element
        else if(x < t->data)
            t->left = remove(x, t->left);
        else if(x > t->data)
            t->right = remove(x, t->right);

        // Element found
        // With 2 children
        else if(t->left && t->right)
        {
            temp = findMin(t->right);
            t->data = temp->data;
            t->right = remove(t->data, t->right);
        }
        // With one or zero child
        else
        {
            temp = t;
            if(t->left == NULL)
                t = t->right;
            else if(t->right == NULL)
                t = t->left;
            delete temp;
        }
        if(t == NULL)
            return t;

        t->height = max(height(t->left), height(t->right))+1;

        // If node is unbalanced
        // If left node is deleted, right case
        if(height(t->left) - height(t->right) == 2)
        {
            // right right case
            if(height(t->left->left) - height(t->left->right) == 1)
                return singleLeftRotate(t);
            // right left case
            else
                return doubleLeftRotate(t);
        }
        // If right node is deleted, left case
        else if(height(t->right) - height(t->left) == 2)
        {
            // left left case
            if(height(t->right->right) - height(t->right->left) == 1)
                return singleRightRotate(t);
            // left right case
            else
                return doubleRightRotate(t);
        }
        return t;
    }

    int height(node* t)
    {
        return (t == NULL ? -1 : t->height);
    }

    int getBalance(node* t)
    {
        if(t == NULL)
            return 0;
        else
            return height(t->left) - height(t->right);
    }

    void inorder(node* t)
    {
        if(t == NULL)
            return;
        inorder(t->left);
        cout << t->data << " ";
        inorder(t->right);
    }

public:
    BST()
    {
        root = NULL;
    }

    void insert(int x)
    {
        root = insert(x, root);
    }

    void remove(int x)
    {
        root = remove(x, root);
    }

    void display()
    {
        inorder(root);
        cout << endl;
    }
};

int main()
{
    BST t;
    t.insert(20);
    t.insert(25);
    t.insert(15);
    t.insert(10);
    t.insert(30);
    t.insert(5);
    t.insert(35);
    t.insert(67);
    t.insert(43);
    t.insert(21);
    t.insert(10);
    t.insert(89);
    t.insert(38);
    t.insert(69);
    t.display();
    t.remove(5);
    t.remove(35);
    t.remove(65);
    t.remove(89);
    t.remove(43);
    t.remove(88);
    t.remove(20);
    t.remove(38);
    t.display();
}


// #include "array_list.h"

// namespace structures {
// template<typename T>
// class AVLTree {
// public:
//     struct Node
//     {
//         T key;
//         Node* left;
//         Node* right;
//         int height;
//     };

//     Node* newNode(int data) {
//     struct Node* node = (struct Node*) 
//                         malloc(sizeof(struct Node)); 
//         node->key = data;
//         node->left = NULL;
//         node->right = NULL;
//         node->height = 1;
//         return node;
//     }

//     int max(int a, int b) {
//         return ((a > b) ? a : b);
//     }

//     int avl_height(Node* node) {
//         if (node == NULL) {
//             return 0;
//         } else {
//             return node->height;
//         }
//     }

//     Node* simpleRight(Node* node) {
//         auto* x = node->left;
//         auto* T2 = x->right;

//         x->right = node;
//         node->left = T2;

//         node->height = max(avl_height(node->left), avl_height(node->right))+1;
//         x->height    = max(avl_height(x->left), avl_height(x->right))+1;

//         return x;
//     }

//     Node* simpleLeft(Node* node) {
//         auto* y = node->right;
//         auto* T2 = y->left;
    
//         y->left = node;
//         node->right = T2;

//         node->height = max(avl_height(node->left), avl_height(node->right))+1;
//         y->height    = max(avl_height(y->left), avl_height(y->right))+1;

//         return y;
//     }

//     int balance(Node* node) {
//         if (node == NULL)
//             return 0;
//         return avl_height(node->left) - avl_height(node->right);
//     }
    
//     Node* insert(Node* node, T data) {
//         if (node == NULL)
//             return newNode(data);
//         if (data < node->key)
//             node->left = insert(node->left, data);
//         else if (data > node->key)
//             node->right = insert(node->right, data);
//         else
//             return node;

//         node->height = 1 + max(avl_height(node->left),
//                                avl_height(node->right));

//         auto balance_ = balance(node);

//         if (balance_ > 1 && data < node->left->key)
//             return simpleRight(node);
        
//         if (balance_ < -1 && data > node->right->key)
//             return simpleLeft(node);

//         if (balance_ > 1 && data > node->left->key) {
//             node->left = simpleLeft(node->left);
//             return simpleRight(node);
//         }

//         if (balance_ < -1 && data < node->right->key) {
//             node->right = simpleRight(node->right);
//             return simpleLeft(node);
//         }

//         return node;
//     }

//     Node* min_node(struct Node* node) {
//         auto* current = node;
        
//         while (current->left != NULL)
//             current = current->left;
        
//         return current;
//     }

//     Node* deleteNode(Node* node, T key) {
//         if (node == NULL)
//             return node;

//         if (key < node->key)
//             node->left = deleteNode(node->left, key);
        
//         else if (key > node->key)
//             node->right = deleteNode(node->right, key);
        
//         else {
//             if ((node->left == NULL) || (node->right == NULL)) {
//                 auto* temp = node->left ? node->left : node->right;
            
//                 if (temp == NULL) {
//                     temp = node;
//                     node = NULL;
//                 } else {
//                     *node = *temp;
//                 }
//                 delete temp;
//             } else {
//                 auto temp = min_node(node->right);
//                 node->key = temp->key;
//                 node->right = deleteNode(node->right, temp->key);
//             }
//         }

//         if (node == NULL)
//             return node;
        
//         node->height = 1+ max(avl_height(node->left), avl_height(node->right));
    
//         auto balance_ = balance(node);

//         if (balance_ > 1 && balance(node->left) >= 0)
//             return simpleRight(node);
        
//         if (balance_ > 1 && balance(node->left) < 0) {
//             node->left = simpleLeft(node->left);
//             return simpleRight(node);
//         }

//         if (balance_ < -1 && balance(node->right) <= 0)
//             return simpleLeft(node);

//         if (balance_ < -1 && balance(node) > 0) {
//             node->right = simpleRight(node->right);
//             return simpleLeft(node);
//         }

//         return node;
//     }

//     bool contains(Node* node, T data) const {
//         if (node->key == data)
//             return true;
//         else if (node->key > data)
//                 if (node->left != NULL)
//                     return contains(node->left, data);
//                 else return false; 
//         else if (node->right != NULL)
//             return contains(node->right, data);
//         else return false;
//     }

//     Node* root;
//     int size_;

//     AVLTree() {
//         size_ = 0;
//         root = NULL;
//     }

//     ~AVLTree() {
//         clear(root);
//     }

//     void clear(Node* tree) {
//         if (tree != NULL) {
//             clear(tree->right);
//             clear(tree->left);
//             delete tree;
//         }
//         tree = nullptr;
//     }

//     void insert(T data) {
//         root = insert(root, data);
//         size_++;
//     }

//     void remove(T data) {
//         root = deleteNode(root, data);
//         size_--;
//     }

//     bool contains(const T& data) const {
//         return contains(root, data);
//     }

//     bool empty() const {
//         return (size_ == 0)? true : false;
//     }

//     int size() const {
//         return size_;
//     }

//     void preOrder(ArrayList<T>& ar, Node* pre) {
//         if (pre != NULL) {
//             ar.push_back(pre->key);
//             preOrder(ar, pre->left);
//             preOrder(ar, pre->right);
//         }
//     }

//     ArrayList<T> pre_order() {
//         ArrayList<T> ar{size_};
//         preOrder(ar, root);
//         return ar;
//     }

//     void inOrder(ArrayList<T>& ar, Node* pre) {
//         if (pre != NULL) {
//             preOrder(ar, pre->left);
//             ar.push_back(pre->key);
//             preOrder(ar, pre->right);
//         }
//     }

//     ArrayList<T> in_order() {
//         ArrayList<T> ar{size_};
//         inOrder(ar, root);
//         return ar;
//     }

//     void postOrder(ArrayList<T>& ar, Node* pre) {
//         if (pre != NULL) {
//             preOrder(ar, pre->left);
//             preOrder(ar, pre->right);
//             ar.push_back(pre->key);
//         }
//     }

//     ArrayList<T> post_order() {
//         ArrayList<T> ar{size_};
//         postOrder(ar, root);
//         return ar;
//     }

// };

// }
