#include <iostream>
#include "genreDLL.h"
#include "MovieSLL.h"

using namespace std;

void displayMenu();

int main()
{
    int choice;
    GenreDLL dbG;
    MovieSLL dbM;

    cout << "\tWelcome to the MOVIE DATABASE MANAGEMENT SYSTEM!" << endl;

    do {
       
        displayMenu();
        cin >> choice;
        cin.ignore();
       
        switch (choice)
        {
        case 1:
        {
            string genre;
            cout << "Please enter a genre: " << endl;
            getline(cin,genre);
            dbG.addGenre(genre);

            break;
        }
        
        case 2:
        {

        }
            break;

        case 3:
        {

        }   
            break;
            
        case 4:
        {

        }
            break;

        case 5:
        {

        }
            break;

        case 6:
        {

        }
            break;
        
        case 7:
        {

        }
            break;

        case 8:
        
        {
            cout << "Goodbye!" << endl;
            break;

        }
        
        default:
            
            cout << "Invalid choice!!!! Choose bewteen 1-8" << endl;
            
        }
    }   while (choice != 8);



    return 0;
}


void displayMenu()
{
    cout << "1. Add a genre\n";
    cout << "2. Add a movie\n";
    cout << "3. Modify a movie\n";
    cout << "4. List all genres\n";
    cout << "5. Delete a movie\n";
    cout << "6. List all movies from a selected genre\n";
    cout << "7. Search for a movie\n";
    cout << "8. Exit\n";    
}