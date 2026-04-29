#include <iostream>
#include "MovieNode.h"

class MovieSLL {
private:
    MovieNode* head;

public:
    MovieSLL();

    void addInOrder(Movie val);
    bool deleteByTitle(std::string title);
    void printList();

    MovieNode* getHead();
};

MovieSLL::MovieSLL() {
    head = nullptr;
}

void MovieSLL::addInOrder(Movie val) {
    MovieNode* newNode = new MovieNode(val);

    if (head == nullptr || val < head->getInfo()) {
        newNode->setNext(head);
        head = newNode;
        return;
    }

    MovieNode* temp = head;

    while (temp->getNext() != nullptr &&
           temp->getNext()->getInfo() < val) {
        temp = temp->getNext();
    }

    newNode->setNext(temp->getNext());
    temp->setNext(newNode);
}

bool MovieSLL::deleteByTitle(std::string title) {
    if (head == nullptr) return false;

    if (head->getInfo().getTitle() == title) {
        MovieNode* toDelete = head;
        head = head->getNext();
        delete toDelete;
        return true;
    }

    MovieNode* temp = head;

    while (temp->getNext() != nullptr &&
           temp->getNext()->getInfo().getTitle() != title) {
        temp = temp->getNext();
    }

    if (temp->getNext() != nullptr) {
        MovieNode* toDelete = temp->getNext();
        temp->setNext(toDelete->getNext());
        delete toDelete;
        return true;
    }

    return false;
}

void MovieSLL::printList() {
    MovieNode* temp = head;

    while (temp != nullptr) {
        temp->getInfo().print();
        std::cout << "------------------\n";
        temp = temp->getNext();
    }
}


MovieNode* MovieSLL::getHead() {
    return head;
}
