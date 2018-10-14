  //! "Copyright [2018] <Arthur>"
#include <cstdint>
#include <stdexcept>

#define CATCH_CONFIG_MAIN
namespace structures {

template<typename T>
  //! ...
class DoublyCircularList {
 public:
    //! ...
    DoublyCircularList() {
    head = nullptr;  // primeiro da lista
    //! ...
    tail = nullptr;  // ultimo da lista
    //! ...
    size_ = 0;
    }
    //! ...
    ~DoublyCircularList() {
        clear();
    }
    //! ...
    void clear() {
        auto runner = head;
        for (int i = 0; i != size_; i++) {
            auto to_kill = runner;
            runner = runner->next();
            delete to_kill;
        }
        size_ = 0;
    }
    //! ...
    void push_back(const T& data) {
        auto new_dude = new Node(data, nullptr, nullptr);
        if (size_ == 0) {
            head = new_dude;
            tail = new_dude;
        } else {
            tail->next(new_dude);
            auto temp = tail;
            tail = new_dude;
            tail->prev(temp);
        }
        size_++;
    }  // insere no fim
    //! ...
    void push_front(const T& data) {
        if (size_ == 0) {
            push_back(data);
        } else {
            auto new_dude = new Node(data, nullptr, nullptr);
            head->prev(new_dude);
            auto temp = head;
            head = new_dude;
            head->next(temp);
            size_++;
        }
    }  // insere no início
    //! ...
    void insert(const T& data, std::size_t index) {
        if (index < 0 || index > size_) {
            throw std::out_of_range("out of range");
        }
        if (index == 0) {
            push_front(data);
        } else if (index == size_) {
            push_back(data);
        } else {
            printf("%lu", size_);
            auto runner = head;
            for (auto i = 0; i != index-1; i++) {
                runner = runner->next();
            }
            auto next_guy = runner->next();
            auto new_dude = new Node(data, runner, next_guy);
            runner->next(new_dude);
            next_guy->prev(new_dude);
            size_++;
        }
    }  // insere na posição
    //! ...
    void insert_sorted(const T& data) {
        auto runner = head;
        bool inserted = false;
        for (int i = 0; i != static_cast<int>(size_); i++) {
            if (runner->data() > data) {
                insert(data, (i));
                inserted = true;
                break;
            }
            runner = runner->next();
        }
        if (!inserted) {
            push_back(data);
        }
    }  // insere em ordem
    //! ...
    T pop(std::size_t index) {
        if (index < 0 || index >= size_) {
           throw std::out_of_range("out of bounds");
        }
        if (index == 0) {
            return pop_front();
        } else if (index == size_-1) {
            return pop_back();
        } else {
            auto runner = head;
            for (auto i = 0; i != index-1; i++) {
                runner = runner->next();
            }
            auto to_delete = runner->next();
            auto ret = to_delete->data();
            auto next_to_delete = to_delete->next();
            runner->next(to_delete);
            next_to_delete->prev(runner);
            delete to_delete;
            size_--;
            return ret;
        }
    }  // retira da posição
    //! ...
    T pop_back() {
        if (size_ <= 0) {
           throw std::out_of_range("out of bounds");
        }
        auto to_delet = tail;
        auto ret = to_delet->data();
        tail = tail->prev();
        // tail->next(nullptr);
        // delete to_delet;
        size_--;
        return ret;
    }  // retira do fim
    //! ...
    T pop_front() {
        if (size_ <= 0) {
           throw std::out_of_range("out of bounds");
        }
        // auto to_delet = head;
        auto ret = at(0);
        head = head->next();
        // head = head->next();
        // head->prev(nullptr);
        // delete to_delet;
        size_--;
        return ret;
    }  // retira do início
    //! ...
    void remove(const T& data) {
        auto runner = head;
        for (auto i = 0; i != size_; i++) {
            if (runner->data() == data) {
                pop(i);
                break;
            }
            runner = runner->next();
        }
    }  // retira específico
    //! ...
    bool empty() const {
        if (size_ == 0) {
            return true;
        } else {
            return false;
        }
    }  // lista vazia
    //! ...
    bool contains(const T& data) const {
        auto runner = head;
        for (auto i = 0; i != size_; i++) {
            if (runner->data() == data) {
                return true;
            }
            runner = runner->next();
        }
        return false;
    }  // contém
    //! ...
    T& at(std::size_t index) {
        if (index < 0 || index >= size_) {
           throw std::out_of_range("out of bounds");
        }
        auto runner = head;
        for (auto i = 0; i != index; i++) {
            runner = runner->next();
        }
        return runner->data();
    }  // acesso a um elemento (checando limites)
    //! ...
    const T& at(std::size_t index) const {
        if (index < 0 || index >= size_) {
           throw std::out_of_range("out of bounds");
        }
        auto runner = head;
        for (auto i = 0; i != index; i++) {
            runner = runner->next();
        }
        return runner->data();
    }  // getter constante a um elemento
    //! ...
    std::size_t find(const T& data) const {
        auto runner = head;
        for (auto i = 0; i != size_; i++) {
            if (data == runner->data()) {
                return i;
            }
            runner = runner->next();
        }
        return size_;
    }  // posição de um dado
    //! ...
    std::size_t size() const {
        return size_;
    }  // tamanho

 private:
    class Node {
     public:
        //! ...
        explicit Node(const T& data) {
            data_ = data;
        }
        //! ...
        Node(const T& data, Node* next) {
            data_ = data;
            next_ = next;
        }
        //! ...
        Node(const T& data, Node* prev, Node* next) {
            data_ = data;
            next_ = next;
            prev_ = prev;
        }
        //! ...
        T& data() {
            return data_;
        }
        //! ...
        const T& data() const {
            return data_;
        }
        //! ...
        Node* prev() {
            return prev_;
        }
        //! ...
        const Node* prev() const {
            return prev_;
        }
        //! ...
        void prev(Node* node) {
            prev_ = node;
        }
        //! ...
        Node* next() {
            return next_;
        }
        //! ...
        const Node* next() const {
            return next_;
        }
        //! ...
        void next(Node* node) {
            next_ = node;
        }

     private:
        //! ...
        T data_;
        //! ...
        Node* prev_;
        //! ...
        Node* next_;
    };
    //! ...
    Node* head;  // primeiro da lista
    //! ...
    Node* tail;  // ultimo da lista
    //! ...
    std::size_t size_;
};

}  //! namespace structures
