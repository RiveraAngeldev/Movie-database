#ifndef MOVIE_H
#define MOVIE_H

#include <string>
#include <iostream>
#include "CastSLL.h"
using namespace std;

class Movie {
private:
    string title;
    string director;
    string synopsis;
    int year;
    CastSLL castList;

public:
    Movie();
    Movie(string t, string d, string s, int y);

    string getTitle() const;
    
    void setTitle( string t);
    void setDirector( string d);
    void setSynopsis( string s);
    void setYear(int y);

    void print() const;
    void printShort() const;
    void addCastMember(string name, string role);

    bool operator<(const Movie& other) const;
};

Movie::Movie() {
    title = "";
    director = "";
    synopsis = "";
    year = 0;
}

Movie::Movie(string t, string d, string s, int y) {
    title = t;
    director = d;
    synopsis = s;
    year = y;
}

string Movie::getTitle() const {
    return title;
}

void Movie::setTitle(string t)  {
    title = t;
}

void Movie::setDirector(string d) {
    director = d;
}

void Movie::setSynopsis(string s) {
    synopsis = s;
} 

void Movie::setYear(int y) {
    year = y;
}

void Movie::print() const {
    cout << "Title: " << title << endl;
    cout << "Director: " << director << endl;
    cout << "Year: " << year << endl;
    cout << "Synopsis: " << synopsis << endl;
    cout << "Cast & Crew: " << endl;
    castList.printCast();
}

void Movie::printShort() const {
    cout << title << "(" << year << ") - Dir: " << director << "\n";
}

bool Movie::operator<(const Movie& other) const {
    return this->title < other.title;
}

void Movie::addCastMember(string name, string role)
{
    castList.addActor(name,role);
}

#endif