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
    void modifyMovie(string title);
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
        MovieNode* node = temp->movies.findMovieByTitle(title);
        if (node != nullptr) {
            cout << "Movie found in genre " << temp->name << "\n";
            node->getInfo().print();
        }
        temp = temp->next;
    }
    cout << "Movie not found.\n";
}

void GenreDLL::modifyMovie(string title) {
    GenreNode* temp = head;
    while(temp != nullptr) {
        MovieNode* node = temp->movies.findMovieByTitle(title);
        if(node != nullptr) {
            cout << "Movie found in genre " << temp->name << "\n";
            node->getInfo().print();
        
            string confirm;
            cout <<"\nDo you want to modify this Movie? Y/N: ";
            getline(cin, confirm);
            
            if(confirm != "Y" && confirm != "y") {
                cout << "Modification cancelled.\n";
                return;
            }

            string director, synopsis;
            int year;

            cout << "Enter the new director: "; 
            getline(cin, director);

            cout << "Enter the new Synopsis: ";
            getline(cin, synopsis);

            cout << "Enter the new Year: ";
            cin >> year;

            node->getInfo().setDirector(director);
            node->getInfo().setSynopsis(synopsis);
            node->getInfo().setYear(year);

            cout <<"Movie modified successfully.\n";
            return;
        }
        temp = temp->next;
    }
    cout <<"Movie not found.\n";
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