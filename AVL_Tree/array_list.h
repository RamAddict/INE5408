//  "Copyright [2018] <Arthur>"
#ifndef STRUCTURES_ARRAY_LIST_H
#define STRUCTURES_ARRAY_LIST_H

#define CATCH_CONFIG_MAIN
#include <cstdint>
#include <stdexcept>
namespace structures {

template<typename T>
  //! Minha classe
class ArrayList {
 public:
    ArrayList();
    //! ...
    explicit ArrayList(int max_size);
    ~ArrayList();
    //! ...
    void clear();
    //! ...
    void push_back(const T& data);
    //! ...
    void push_front(const T& data);
    //! ...
    void insert(const T& data, int index);
    //! ...
    void insert_sorted(const T& data);
    //! ...
    T pop(int index);
    //! ...
    T pop_back();
    //! ...
    T pop_front();
    //! ...
    void remove(const T& data);
    //! ...
    bool full() const;
    //! ...
    bool empty() const;
    //! ...
    bool contains(const T& data) const;
    //! ...
    int find(const T& data) const;
    //! ...
    int size() const;
    //! ...
    int max_size() const;
    //! ...
    T& at(int index);
    //! ...
    T& operator[](int index);
    //! ...
    const T& at(int index) const;
    //! ...
    const T& operator[](int index) const;

 private:
    T* contents;
    int size_;
    int max_size_;

    static const auto DEFAULT_MAX = 10u;
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
ArrayList<T>::ArrayList(int max_size) {
  contents = nullptr;
  size_ = 0;
  contents = new T[max_size];
  max_size_ = max_size;
}

template<typename T>
ArrayList<T>::~ArrayList() {
  // delete[] contents;
}

template<typename T>
void ArrayList<T>::clear() {
  size_ = 0;
}

template<typename T>
bool ArrayList<T>::empty() const {
  return ( size_ == 0 );
}

template<typename T>
void ArrayList<T>::push_back(const T& data) {
  if (size_ == max_size_) {
    throw std::out_of_range("out of range.");
  } else {
    contents[ size_ ] = data;
  }
  size_++;
}

template<typename T>
bool ArrayList<T>::full() const {
  return ( size_ == max_size_ );
}

template<typename T>
T ArrayList<T>::pop(int index) {
  if (size_ <= index) {
    throw std::out_of_range("out of range");
  } else {
    auto rot = contents[ index ];
    for (auto i = index; i != size_ -1; i++) {
        contents[ i ] = contents[ i+1 ];
    }
    size_--;
    return rot;
  }
}
template<typename T>
int ArrayList<T>::find(const T& data) const {
    for (auto i = 0; i != max_size_; i++) {
         if (data == contents[ i ]) {
             return i;
         }
    }
    return size_;
}

template<typename T>
int ArrayList<T>::size() const {
    return size_;
}

template<typename T>
int ArrayList<T>::max_size() const {
    return max_size_;
}

template<typename T>
const T& ArrayList<T>::at(int index) const {
    if (size_ <= index) {
      throw std::out_of_range("out of range");
    } else {
      return contents[ index ];
    }
}
template<typename T>
T& ArrayList<T>::at(int index) {
    if (size_ < index) {
      throw std::out_of_range("out of range");
    } else {
      return contents[ index ];
    }
}
template<typename T>
T& ArrayList<T>::operator[](int index) {
return at(index);
}
template<typename T>
const T& ArrayList<T>::operator[](int index) const {
return at(index);
}
template<typename T>
bool ArrayList<T>::contains(const T& data) const {
  return !(find(data) == size_ );
}
template<typename T>
T ArrayList<T>::pop_back() {
  auto rex = contents[size_ - 1 ];
  pop(size_ - 1);
  return rex;
}
template<typename T>
T ArrayList<T>::pop_front() {
  auto rex = contents[0];
  pop(0);
  return rex;
}
template<typename T>
void ArrayList<T>::remove(const T& data) {
  pop(find(data));
}
template<typename T>
void ArrayList<T>::push_front(const T& data) {
  if (size_ == max_size_) {
    throw std::out_of_range("out of range");
  } else {
      for (auto i = size_; i != 0; i--) {
        contents[ i ] = contents[ i-1 ];
      }
      contents[0] = data;
    size_++;
  }
}

template<typename T>
void ArrayList<T>::insert(const T& data, int index) {
  if (size_ == max_size_ || index >= max_size_) {
    throw std::out_of_range("out of range");
  } else {
      for (auto i = size_; i != index; i--) {
        contents[ i ] = contents[ i-1 ];
      }
      contents[index] = data;
    size_++;
  }
}
template<typename T>
void ArrayList<T>::insert_sorted(const T& data) {
  if (size_ == max_size_) {
    throw std::out_of_range("out of range");
  } else {
    push_back(data);
    for (auto j = 0; j != size_-1; j++) {
      for (auto i = 0; i != size_-1; i++) {
        auto rot = contents[i];
        if (contents[i] > contents[i+1]) {
          rot = contents[i+1];
          contents[i+1] = contents[i];
          contents[i] = rot;
        }
      }
    }
  }
}
}  //! namespace structures
#endif
