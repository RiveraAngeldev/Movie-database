#include <string>
#include "MovieSLL.h"
#include "Movie.h"

class GenreNode {
public:
    std::string name;
    MovieSLL movies;

    GenreNode* next;
    GenreNode* prev;

    GenreNode(std::string n);
};

GenreNode::GenreNode(std::string n) {
    name = n;
    next = prev = nullptr;
}