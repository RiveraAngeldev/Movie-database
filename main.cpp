#include <iostream>
#include <string>
#include "genreDLL.h"
#include "Movie.h"

using namespace std;

void displayMenu();

int main()
{
    int choice;
    GenreDLL dbG;


    cout << "\tWelcome to the MOVIE DATABASE MANAGEMENT SYSTEM!" << endl;

    do {
       
        displayMenu();
        cin >> choice;
       cin.ignore(1000, '\n');

        switch (choice)
        {
        case 1:
        {
            string genre;
            cout << "Please enter a genre: " << endl;
            getline(cin, genre);
            dbG.addGenre(genre);
            break;
        }
        
        case 2:
        {
            string title, director, sypnopsis, genreName;
            int year;
            cout << "Available genres: \n";
            dbG.printGenres();

            cout << "Select genre: \n";
            getline(cin, genreName);
            GenreNode* genre = dbG.findGenre(genreName);

            if(genre == nullptr) {
                cout << "Genre not found.\n";
                break;
            }
            cout << "Enter title: ";
            getline(cin, title);

            cout << "Enter director: ";
            getline(cin, director);

            cout << "Enter sypnopsis: ";
            getline(cin, sypnopsis);

            cout << "Enter year: ";
            cin >> year;

            Movie movie(title, director, sypnopsis, year);
            genre->movies.addInOrder(movie);

            cout << "Movie added successfully!\n";
            break;
        }
            
        case 3:
        {
            string title;
            cout << "Please select a movie to modify: "  << endl;
            getline(cin, title);
            dbG.modifyMovie(title);
            break;
        }   
            
        case 4:
        {
            cout << "Showing all genres\n";
            dbG.printGenres(); 
            break;
        }
            
        case 5:
        {
            string genreName, title;
            cout << "Please select the genre of the movie you want to delete: " << endl;
            getline(cin,genreName);

            GenreNode* g = dbG.findGenre(genreName);
            if(g != nullptr)
            {
                cout << "Please select the movie to delete: " << endl;
                getline(cin,title);

                if (g->movies.deleteByTitle(title))
                {
                    cout << "Movie deleted successfully deleted" << endl;
                }   else {
                    cout << "Movie  not found!" << endl;
                }
            }   else {
                cout << "Genre not found!" << endl;
            }

            break;
        }
            
        case 6:
        {
            string genreName;
            cout << "Showing available genres: " << endl;
            dbG.printGenres();
            cout << "Enter the genre: ";
            getline(cin, genreName);
            cout << "Showing all the movies from the selected genre: " << endl;
            dbG.listMoviesByGenre(genreName);
            break;
        }
            
        case 7:
        {
            string title;
            cout << "Please select the movie to search" << endl;
            getline(cin,title);
            dbG.searchMovie(title);
            break;
        }
            
        case 8:
        
        {
            cout << "Goodbye!" << endl;
           
            break;
        }
        
        default:
            
            cout << "Invalid choice!!!! Choose bewteen 1-8" << endl;
            
        }

        if (choice != 8)
        {
            cout << "\nPress enter to return to the menu...";
            cin.ignore(1000, '\n');
        }
        

    }   while (choice != 8);



    return 0;
}


void displayMenu()
{
    cout << "\n\n======================================\n";
    cout << "1. Add a genre\n";
    cout << "2. Add a movie\n";
    cout << "3. Modify a movie\n";
    cout << "4. List all genres\n";
    cout << "5. Delete a movie\n";
    cout << "6. List all movies from a selected genre\n";
    cout << "7. Search for a movie\n";
    cout << "8. Exit\n";  
    cout << "Enter your choice: \n";  
}