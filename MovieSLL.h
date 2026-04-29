#include "MovieNode.h"
#include <iostream>
using namespace std;

template <class T>
class MovieSLL {
private:
    MovieNode<T>* head;

public:
    MovieSLL();

    void addInOrder(T val);
    bool deleteByTitle(string title);
    void printList();

    MovieNode<T>* getHead();
};

template <class T>
MovieSLL<T>::MovieSLL() {
    head = nullptr;
}

template <class T>
void MovieSLL<T>::addInOrder(T val) {
    MovieNode<T>* newNode = new MovieNode<T>(val);

    if (head == nullptr || val < head->getInfo()) {
        newNode->setNext(head);
        head = newNode;
        return;
    }

    MovieNode<T>* temp = head;

    while (temp->getNext() != nullptr &&
           temp->getNext()->getInfo() < val) {
        temp = temp->getNext();
    }

    newNode->setNext(temp->getNext());
    temp->setNext(newNode);
}

template <class T>
bool MovieSLL<T>::deleteByTitle(string title) {
    if (head == nullptr) return false;

    if (head->getInfo().getTitle() == title) {
        MovieNode<T>* toDelete = head;
        head = head->getNext();
        delete toDelete;
        return true;
    }

    MovieNode<T>* temp = head;

    while (temp->getNext() != nullptr &&
           temp->getNext()->getInfo().getTitle() != title) {
        temp = temp->getNext();
    }

    if (temp->getNext() != nullptr) {
        MovieNode<T>* toDelete = temp->getNext();
        temp->setNext(toDelete->getNext());
        delete toDelete;
        return true;
    }

    return false;
}

template <class T>
void MovieSLL<T>::printList() {
    MovieNode<T>* temp = head;

    while (temp != nullptr) {
        temp->getInfo().print();
        cout << "------------------\n";
        temp = temp->getNext();
    }
}

template <class T>
MovieNode<T>* MovieSLL<T>::getHead() {
    return head;
}