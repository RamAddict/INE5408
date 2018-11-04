#include "array_list.h"
#include <iostream>

namespace structures {
template <typename T>
class AVLTree {
public:
    AVLTree():
    size_{0},
    root{nullptr}    
    {};
    ~AVLTree() {
        
    }

    //! return tree size;
    int size() {
        return size_;
    }
    //! insert elements
    void insert(const T& data) {
        root->insert(root, data);
        size_++;
    }
    //! print in pre_order
    ArrayList<T> pre_order() {
        auto list = new ArrayList<T>{};
        root->pre_order(*list);
        return *list;
    }
    //! print in_order
    ArrayList<T> in_order() {
        ArrayList<T> list{size_};
        root->in_order(list);
        return list;
    }
    //! print in post_order
    ArrayList<T> post_order() {
        ArrayList<T> list{size_};
        root->post_order(list);
        return list;
    }
 private:
    //! node struct
    struct Node
    {
        T key;
        unsigned char _height;
        Node* left;
        Node* right;
        //! single parameter constructor
        explicit Node(T m) {
            key = m;
            left = nullptr;
            right = nullptr;
            _height = 1;
        }
        //! get height of p
        unsigned char height(Node* p) {
            return p ? p->_height : 0;
        }
        //! get balance factor of p
        int b_factor(Node* p) {
            return height(p->right) - height(p->left);
        }
        //! update height
        void fix_height(Node* p) {
            unsigned char hl = height(p->left);
            unsigned char hr = height(p->right);
            p->_height = (hl > hr ? hl : hr) + 1;
        }
        //! right rotate around p
        Node* right_rotate(Node* p) {
            Node* q = p->left;
            p->left = q->right;
            q->right = p;
            fix_height(p);
            fix_height(q);
            return q;
        }
        //! left rotate around q
        Node* left_rotate(Node* q) {
            Node* p = q->right;
            q->right = p->left;
            p->left = q;
            fix_height(q);
            fix_height(p);
            return p;
        }
        //! balance node p
        Node* balance(Node* p) {
            fix_height(p);
            if (b_factor(p) == 2) {
                if (b_factor(p->right) < 0)
                    p->right = right_rotate(p->right);
                return left_rotate(p);
            }
            if (b_factor(p) == -2) {
                if (b_factor(p->left) > 0)
                    p->left = left_rotate(p->left);
                return right_rotate(p);
            }
            return p;
        }
        //! insert node p with key k into avl tree
        Node* insert(Node* p, T k) {
            if (!p) return new Node(k);
            if (k < p->key)
                p->left = insert(p->left, k);
            else
                p->right = insert(p->right, k);
            return balance(p);
        }
        //! returns minimal key in the tree
        Node* find_min(Node* p) {
            return p->left ? find_min(p->left) : p;
        }
        //! removes minimal node
        Node* remove_min(Node* p) {
            if (p->left == 0)
                return p->right;
            p->left = remove_min(p->left);
            return balance(p);
        }
        //! remove a node from the tree
        Node* remove(Node* p, T k) {
            if (!p) return 0;
            if (k < p->key)
                p->left = remove(p->left, k);
            else if (k > p->key)
                p->right = remove(p->right, k);
            else {
                Node* q = p->left;
                Node* r = p->right;
                delete p;
                if (!r) return q;
                Node* min = find_min(r);
                min->right = remove_min(r);
                min->left = q;
                return balance(min);
            }
            return balance(p);
        }

        void pre_order(ArrayList<T>& v) {
            v.push_back(key);
                std::cout <<" 2kill me\n";
            if (left != nullptr){
                left->pre_order(v);
            }
            if (right != nullptr) {
                right->pre_order(v);
            std::cout <<" kill me\n";
            }
        }

        void in_order(ArrayList<T>& v) {
            if (left != nullptr)
                left->in_order(v);
            v.push_back(key);
            if (right != nullptr)
                right->in_order(v);
        }

        void post_order(ArrayList<T>& v) {
            if (left != nullptr)
                left->post_order(v);
            if (right != nullptr)
                right->post_order(v);
            v.push_back(key);
        }
    };
    Node* root;
    int size_;
};

}