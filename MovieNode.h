#include <iostream>
using namespace std;

template <class T>
class MovieNode {
private:
    T info;
    MovieNode<T>* next;

public:
    MovieNode();
    MovieNode(T val);
    
    T getInfo();
    MovieNode<T>* getNext();

    void setInfo(T val);
    void setNext(MovieNode<T>* n);
};

template <class T>
MovieNode<T>::MovieNode() {
    next = nullptr;
}

template <class T>
MovieNode<T>::MovieNode(T val) {
    info = val;
    next = nullptr;
}

template <class T>
T MovieNode<T>::getInfo() {
    return info;
}

template <class T>
MovieNode<T>* MovieNode<T>::getNext() {
    return next;
}

template <class T>
void MovieNode<T>::setInfo(T val) {
    info = val;
}

template <class T>
void MovieNode<T>::setNext(MovieNode<T>* n) {
    next = n;
}
