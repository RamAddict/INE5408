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
    void push_back(const T& data);
    // void push_front(const T& data);
    // void insert(const T& data, std::size_t index);
    // void insert_sorted(const T& data);
    T pop(std::size_t index);
    // T pop_back();
    // T pop_front();
    // void remove(const T& data);
    bool full() const;
    bool empty() const;
    // bool contains(const T& data) const;
    //! finds an element with value data and returns its position 
    //! returns (unsigned) -1 if not found
    std::size_t find(const T& data) const;
    std::size_t size() const;
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
  return ( size_ == 0 );
}

template<typename T>
void ArrayList<T>::push_back(const T& data){
  if( size_ == max_size_ ){
    throw std::out_of_range("out of range.");
  } else {
    contents[ size_ ] = data;
  }
  size_++;
}

template<typename T>
bool ArrayList<T>::full() const{
  return ( size_ == max_size_ );
}

template<typename T>
T ArrayList<T>::pop(std::size_t index){
  if( size_ <= index ) {
    throw std::out_of_range("out of range");
  } else {
    auto rot = contents[ index ];
    for( auto i = index; i != size_ -1; i++) {
        contents[ i ] = contents[ i+1 ];
    }
    size_--;
    return rot;
  }
}
template<typename T>
std::size_t ArrayList<T>::find(const T& data) const {
    for(auto i = 0; i != max_size_; i++)
    {
         if (data == contents[ i ]) {
             return i;
         }
    }
    return -1;
}
template<typename T>
std::size_t ArrayList<T>::size() const {
    return size_;
}
} // namespace structures
#endif