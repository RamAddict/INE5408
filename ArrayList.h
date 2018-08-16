#ifndef STRUCTURES_ARRAY_LIST_H
#define STRUCTURES_ARRAY_LIST_H

#define CATCH_CONFIG_MAIN
#include <cstdint>
#include <iostream>
#include "catch.h"

namespace structures {

template<typename T>
class ArrayList {
public:
    ArrayList();
    ArrayList(std::size_t max_size);
    ~ArrayList();

    void clear();
    // void push_back(const T& data);
    // void push_front(const T& data);
    // void insert(const T& data, std::size_t index);
    // void insert_sorted(const T& data);
    // T pop(std::size_t index);
    // T pop_back();
    // T pop_front();
    // void remove(const T& data);
    // bool full() const;
     bool empty() const;
    // bool contains(const T& data) const;
    // std::size_t find(const T& data) const;
    // std::size_t size() const;
    // std::size_t max_size() const;
    // T& at(std::size_t index);
    // T& operator[](std::size_t index);
    // const T& at(std::size_t index) const;
    // const T& operator[](std::size_t index) const;

private:
    T* contents;
    std::size_t size_;
    std::size_t max_size_;

    const static auto DEFAULT_MAX = 10u;
};
template<typename T>
ArrayList<T>::ArrayList():
  contents{nullptr},
  size_{0},
  max_size_{DEFAULT_MAX}
{
  contents = new T[ DEFAULT_MAX ];
}
template<typename T>
ArrayList<T>::ArrayList(std::size_t max_size):
  contents{nullptr},
  size_{0},
  max_size_{ max_size }
{
  contents = new T[ max_size ];
}
template<typename T>
ArrayList<T>::~ArrayList()
{
  delete[] contents;
}
template<typename T>
void ArrayList<T>::clear(){
  size_ = 0;
}
template<typename T>
bool ArrayList<T>::empty() const{
  return (size_ == 0);
}


} // namespace structures















































#endif
