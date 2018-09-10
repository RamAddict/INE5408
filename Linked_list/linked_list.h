//! Copyright [year] <Copyright Owner>
#ifndef STRUCTURES_LINKED_LIST_H
#define STRUCTURES_LINKED_LIST_H

#include <cstdint>
#include <stdexcept>
#include <memory>
#define CATCH_CONFIG_MAIN

namespace structures {

//! ...
template<typename T>
class LinkedList {
 public:
    //! ...
    LinkedList();
      // construtor padrão
    //! ...
    ~LinkedList();  // destrutor
    //! ...
    void clear();  // limpar lista
    //! ...
    void push_back(const T& data);  // inserir no fim
    //! ...
    void push_front(const T& data);  // inserir no início
    //! ...
    void insert(const T& data, std::size_t index);  // inserir na posição
    //! ...
    //void insert_sorted(const T& data);  // inserir em ordem
    //! ...
    T& at(std::size_t index);  // acessar um elemento na posição index
    //! ...
    //T pop(std::size_t index);  // retirar da posição
    //! ...
    //T pop_back();  // retirar do fim
    //! ...
    //T pop_front();  // retirar do início
    //! ...
    //void remove(const T& data);  // remover específico
    //! ...
    bool empty() const;  // lista vazia
    //! ...
    //bool contains(const T& data) const;  // contém
    //! ...
    //std::size_t find(const T& data) const;  // posição do dado
    //! ...
    std::size_t size() const;  // tamanho da lista
    //! ...
 protected:
    class Node {  // Elemento
     public:
        explicit Node(const T& data):
            data_{data}
        {}

        Node(const T& data, Node* next):
            data_{data},
            next_{next}
        {}

        T& data() {  // getter: dado
            return data_;
        }

        const T& data() const {  // getter const: dado
            return data_;
        }

        Node* next() {  // getter: próximo
            return next_;
        }

        const Node* next() const {  // getter const: próximo
            return next_;
        }

        void next(Node* node) {  // setter: próximo
            next_ = node;
        }

     protected:
        T data_;
        Node* next_{nullptr};
    };

    Node* end() {  // último nodo da lista
      auto it = head;
      for (auto i = 1u; i < size_; ++i) {
        it = it->next();
      }
      return it;
    }

    Node* head{nullptr};
    std::size_t size_{0u};

};

template <typename T>
LinkedList<T>::LinkedList() {
  Node* head{nullptr};
  std::size_t size_{0u};
}
template <typename T>
LinkedList<T>::~LinkedList() {
  auto jair = head;
  for (int i = 0; i != size_; i++) {
    jair = jair->next();
    delete jair;
  }
  delete[] head;
}
template <typename T>
void LinkedList<T>::clear() {
  auto jair = head;
  for (int i = 0; i != size_; i++) {
    jair = jair->next();
    delete[] jair;
  }
  size_ = 0;
}
template <typename T>
void LinkedList<T>::insert(const T& data, std::size_t index) {
  if (index > size_) {
    throw std::out_of_range("bigger than size");
  } else if (empty()) {
    push_front(data);
  } else if (index == size_) {
    push_back(data);
  } else {
    auto newNode = new Node(data);
    
    size_++;
  }
}
template <typename T>
bool LinkedList<T>::empty() const{
  if (size_ == 0) {
    return true;
  } else {
    return false;
  }
}
template <typename T>
void LinkedList<T>::push_front(const T& data) {
  Node* newNode = new Node(data);
  if (!empty()) {
    newNode->next(head);  // o próximo de newNode será para quem head está apontando
  }
    head = newNode; // head passa a apontar pro novo
    size_++;
}
template <typename T>
std::size_t LinkedList<T>::size() const {
  return size_;
}
template <typename T>
T& LinkedList<T>::at(std::size_t index) {
  if (index >= size_ || index < 0) {
    throw std::out_of_range("too big");
  } else {
    auto runner = head;
    for (auto i = 0; i != index; i++) {
      runner = runner->next();
    }
    return runner->data();
  }
}
template<typename T>
void LinkedList<T>::push_back(const T& data) {
  Node* newNode = new Node(data);
  if (empty()) {
    push_front(data);
  } else {
    auto runner = head;
    for (auto i = 0; i != size_-1; i++) {
      runner = runner->next();
    }
    runner->next(newNode);
    size_++;
  }
}
}  // namespace structures
#endif
