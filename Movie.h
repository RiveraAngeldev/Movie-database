#include <string>
#include <iostream>
using namespace std;

class Movie {
private:
    string title;
    string director;
    string synopsis;
    int year;

public:
    Movie();
    Movie(string t, string d, string s, int y);

    string getTitle() const;

    void print() const;

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

void Movie::print() const {
    cout << "Title: " << title << endl;
    cout << "Director: " << director << endl;
    cout << "Year: " << year << endl;
    cout << "Synopsis: " << synopsis << endl;
}

bool Movie::operator<(const Movie& other) const {
    return this->title < other.title;
}