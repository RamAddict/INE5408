// Copyright [2018] <Arthur>
#include <stdexcept>
#include <cstdint>
#include <memory>
#include <iostream>
#define CATCH_CONFIG_MAIN
namespace structures {


template<typename T>
class LinkedQueue {
 public:
    LinkedQueue() = default;

    ~LinkedQueue() {
        clear();
    }

    void clear() {
        auto runner = head;
        for (int i = 0; i != size_; i++) {
            auto to_kill = runner;
            runner = runner->next();
            delete to_kill;
        }
        size_ = 0;
    }

    void enqueue(const T& data) {
            auto new_dude = new Node(data);
        if (size_ == 0) {
            head = new_dude;
            tail = new_dude;
        } else {
            tail->next(new_dude);
            tail = new_dude;
        }
        size_++;
    } // enfilerar

    T dequeue() {
        if (size_ == 0) {
            throw std::out_of_range("Empty queue");
        }
        auto return_value = head->data();
        auto new_head = head->next();
        auto to_delete = head;
        head = new_head;
        delete to_delete;
        size_--;
        return return_value;
    } // desenfilerar

    T& front() const {
        if (size_ == 0) {
            throw std::out_of_range("Empty queue");
        } else {
            return head->data();
        }
    } // primeiro dado

    T& back() const {
        if (size_ == 0) {
            throw std::out_of_range("Empty queue");
        } else {
        return tail->data();
        }
    } // último dado

    bool empty() const {
        return (size_ == 0);
    } // fila vazia

    std::size_t size() const {
        return size_;
    } // tamanho

 private:
    class Node{
         public:
        explicit Node(const T& data):
        data_{data}
        {}
        Node(const T& data, Node* next):
        data_{data},
        next_{next}
        {}

        T& data() {
            return data_;
        }
        const T& data() const {
            return data_;
        }
        Node* next() {
            return next_;
        }
        const Node* next() const {
            return next_;
        }  // getter-constante: próximo

        void next(Node* next) {
            next_ = next;
        }  // setter: próximo
     private:
        Node* next_;
        T data_;
    };
    Node* head; // nodo-cabeça
    Node* tail; // nodo-fim
    std::size_t size_; // tamanho
};

}
