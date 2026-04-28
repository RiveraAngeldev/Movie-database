#ifndef genreDLL_H
#define genreDLL_H

#include <iostream>
#include <string>
#include <moviesSLL.h> 
using namespace std; 

class GenreNode 
{
    public:
            string genreTitle;
            moviesSLL* movies;      //SLL of movies
            GenreNode* prev;
            GenreNode* next;

            GenreNode(string titles);
            ~GenreNode();

};

class genreDLList
{

};

#endif // !genreDLL_H
