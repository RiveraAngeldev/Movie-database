#include "Movie.h"

class MovieNode {
private:
    Movie info;
    MovieNode* next;

public:
    MovieNode();
    MovieNode(Movie val);

    Movie getInfo();
    MovieNode* getNext();

    void setInfo(Movie val);
    void setNext(MovieNode* n);
};

MovieNode::MovieNode() {
    next = nullptr;
}

MovieNode::MovieNode(Movie val) {
    info = val;
    next = nullptr;
}

Movie MovieNode::getInfo() {
    return info;
}

MovieNode* MovieNode::getNext() {
    return next;
}

void MovieNode::setInfo(Movie val) {
    info = val;
}

void MovieNode::setNext(MovieNode* n) {
    next = n;
}