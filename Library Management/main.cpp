#include <iostream>
#include <vector>
#include "bookClass.h"
#include "patronClass.h"
#include "libraryClass.h"

using namespace std;

// passes lib by reference
void createPatron(library &lib)
{
    string name;
    int id = 0;

    cout << "Enter a name for the new patron: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter an unique ID for the patron: ";
    cin >> id;
    vector<book> empty;

    patron newPatron(name, id, empty);
    lib.addPatron(newPatron);
}

void createBook(library &lib)
{
    string name;
    string author;
    string genre;
    bool checkedOut = false; // intially book is never checked out
    int id;

    cout << "Enter a name for the new book: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter a author for the new book: ";
    // cin.ignore();
    getline(cin, author);
    cout << "Enter a genre for the new book: ";
    // cin.ignore();
    getline(cin, genre);
    cout << "Enter an unique ID for the book: ";
    cin >> id;

    book newBook(name, author, genre, checkedOut, id);
    lib.addBook(newBook);
}

void checkOutBook(library &lib)
{
    int patronId = 0;
    int bookId = 0;

    cout << "Enter Patron ID: ";
    cin >> patronId;
    cout << "Enter Book ID: ";
    cin >> bookId;

//fix this
    if (lib.getPatronById(patronId) != -1 && lib.getBookById(bookId) != -1)
    {
    }
}

int userChoice()
{
    int choice = -1;
    while (choice < 0 || choice > 6)
    {
        cout << "Enter 1 (add new patron), 2 (add new book), 3 (print all books), 4 (print all patrons)\b"
             << "5 (let customer check out book), 6 (let customer return book), 0 (to end) ";
        cin >> choice;
    }
    return choice;
}

int main()
{
    // declare library
    // create two patrons
    // create three books

    library centerLibrary;
    int choice = userChoice();

    while (choice != 0)
    {
        if (choice == 1)
            createPatron(centerLibrary);
        else if (choice == 2)
            createBook(centerLibrary);
        else if (choice == 3)
            centerLibrary.printAllBooks();
        else if (choice == 4)
            centerLibrary.printAllPatrons();
        else if (choice == 5)

            choice = userChoice();
    }
    cout << "Ending Program\n"
         << endl;
    return 0;
}