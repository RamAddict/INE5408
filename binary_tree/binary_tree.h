  //! Copyright [2018] <Arthur Bianco>
#include "array_list.h"

namespace structures {
template<typename T>
  //! binary tree'
class BinaryTree {
struct Node;
 public:
    BinaryTree() {
        root = nullptr;
        size_ = 0;
    }
    ~BinaryTree() = default;
    //! insert
    void insert(const T& data) {
        if (root == nullptr) {
            root = new Node(data);
        } else if (data > root->data()) {
            if (root->right() == nullptr) {
                root->right(new Node(data));
            } else {
                root->right()->insert(data);
            }
        } else {
            if (root->left() == nullptr) {
                root->left(new Node(data));
            } else {
                root->left()->insert(data);
            }
        }
        size_++;
    }
    //! remove
    void remove(const T& data) {
        if (size_ == 0)
            throw std::out_of_range("empty");
        if (!contains(data))
            throw std::out_of_range("does not contain data to remove");
        size_--;
    }
    //! contains
    bool contains(const T& data) const {
        if (size_ == 0)
            return false;
        return root->contains(data);
    }
    //! empty
    bool empty() const {
        if (size_ == 0) {
            return true;
        } else {
            return false;
        }
    }
    //! size
    std::size_t size() const {
        return size_;
    }
    //! print in pre_order
    ArrayList<T> pre_order() const {
        ArrayList<T> list{size_};
        root->pre_order(list);
        return list;
    }
    //! print in_order
    ArrayList<T> in_order() const {
        ArrayList<T> list{size_};
        root->in_order(list);
        return list;
    }
    //! print in post_order
    ArrayList<T> post_order() const {
        ArrayList<T> list{size_};
        root->post_order(list);
        return list;
    }

 private:
    //! node
    struct Node {
        explicit Node(const T& data_) {
            _data = data_;
            _left = nullptr;
            _right = nullptr;
        }

        T _data;
        Node* _left;
        Node* _right;
        T data() {
            return _data;
        }

        Node* left() {
            return _left;
        }

        Node* right() {
            return _right;
        }

        void data(T data) {
            _data = data;
        }

        void left(Node* left) {
            _left = left;
        }

        void right(Node* right) {
            _right = right;
        }

        void insert(const T& data_) {
            if (data_ > _data) {
                if (_right == nullptr) {
                    _right = new Node(data_);
                } else {
                    _right->insert(data_);
                }
            } else {
                if (_left == nullptr) {
                    _left = new Node(data_);
                } else {
                    _left->insert(data_);
                }
            }
        }

        bool remove(const T& data_) {
            if (data_ == _data) {
                
            }
        }

        bool contains(const T& data_) const {
            if (data_ == _data) {
                return true;
            } else if (data_ > _data) {
                if (_right == nullptr) {
                    return false;
                } else {
                    return _right->contains(data_);
                }
            } else {
                if (_left == nullptr) {
                    return false;
                } else {
                    return _left->contains(data_);
                }
            }
        }

        bool is_leaf() {
            return (this->right == nullptr && this->left == nullptr);
        }

        void pre_order(ArrayList<T>& v) const {
            v.push_back(_data);
            if (_left != nullptr)
                _left->pre_order(v);
            if (_right != nullptr)
                _right->pre_order(v);
        }

        void in_order(ArrayList<T>& v) const {
            if (_left != nullptr)
                _left->in_order(v);
            v.push_back(_data);
            if (_right != nullptr)
                _right->in_order(v);
        }

        void post_order(ArrayList<T>& v) const {
            if (_left != nullptr)
                _left->post_order(v);
            if (_right != nullptr)
                _right->post_order(v);
            v.push_back(_data);
        }
    };

    Node* root;
    std::size_t size_;
    structures::ArrayList<T> list_ {};
};

}  //! namespace structures
