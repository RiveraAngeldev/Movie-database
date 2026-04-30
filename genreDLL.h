#include <iostream>
#include <string>
#include "GenreNode.h"

using namespace std;

class GenreDLL {
private:
    GenreNode* head;

public:
    GenreDLL();
    void addGenre(string name);
    void printGenres();
    void listMoviesByGenre(const string& name);
    void searchMovie(const string& title);
    GenreNode* findGenre(string name);
};

GenreDLL::GenreDLL() {
    head = nullptr;
}

void GenreDLL::addGenre(string name) {
    GenreNode* newNode = new GenreNode(name);

    // Case 1: empty list
    if (head == nullptr) {
        head = newNode;
        cout << "Genre added successfully!\n";
        return;
    }

    // Case 2: Insert at the beginning
    if (name < head->name) {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        cout << "Genre added successfully!\n";
        return;
    }

    // Case 3: Find position
    GenreNode* temp = head;

    while (temp->next != nullptr && temp->next->name < name) {
        temp = temp->next;
    }

    // Insert in the middle or at the end
    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != nullptr) {
        temp->next->prev = newNode;
    }

    temp->next = newNode;

    cout << "Genre added successfully!\n";
}

void GenreDLL::printGenres() {
    if (head == nullptr) {
        cout << "No genres available\n";
        return;
    }

    GenreNode* temp = head;

    while (temp != nullptr) {
        cout << "- " << temp->name << "\n";
        temp = temp->next;
    }
}

void GenreDLL::listMoviesByGenre(const string& name) {
    GenreNode* genre = findGenre(name);
    if(genre == nullptr) {
        cout << "Genre not found\n";
        return;
    }

    cout << "Movies in " << name << '\n';
    genre->movies.printShortList();
}

void GenreDLL::searchMovie(const string& title) {
    GenreNode* temp = head;
    while(temp != nullptr) {
        Movie* movie = temp->movies.findMovieByTitle(title);
        if(movie != nullptr) {
            cout << "Movie find in genre " << temp-> name << "\n";
            movie->print();
            return;
        }
        temp = temp->next;
    }
    cout << "Movie not found.\n";
}


GenreNode* GenreDLL::findGenre(string name) {
    GenreNode* temp = head;

    while (temp != nullptr) {
        if (temp->name == name) {
            return temp;
        }
        temp = temp->next;
    }

    return nullptr;
}