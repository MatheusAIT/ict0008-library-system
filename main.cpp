#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    string title;
    string author;
    string isbn;
    bool available;
    string dateAdd;

public:
    Book() : available(true) {}

    void setBookDetails(const string& t, const string& a,
                        const string& i, bool avail, const string& d) {
        title = t;
        author = a;
        isbn = i;
        available = avail;
        dateAdd = d;
    }

    void displayBookDetails() const {
        cout << "Title: " << title
             << " | Author: " << author
             << " | ISBN: " << isbn
             << " | Available: " << (available ? "Yes" : "No")
             << " | DateAdd: " << dateAdd << '\n';
    }

    bool borrowBook() {
        if (available) {
            available = false;
            return true;
        }
        return false;
    }

    void returnBook() {
        available = true;
    }

    const string& getISBN() const { return isbn; }
    bool isAvailable() const { return available; }

    // Sort books by ISBN (simple bubble sort)
    static void sortBookData(Book arr[], int n) {
        for (int i = 0; i < n - 1; ++i) {
            for (int j = 0; j < n - i - 1; ++j) {
                if (arr[j].isbn > arr[j + 1].isbn) {
                    Book tmp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = tmp;
                }
            }
        }
    }
};

int main() {
    const int N = 5;
    Book books[N];

    // Initialize 5 books
    books[0].setBookDetails("Clean Code", "Robert Martin", "9780132350884", true, "2023-02-10");
    books[1].setBookDetails("The C++ Programming Language", "Bjarne Stroustrup", "9780321563842", true, "2022-11-05");
    books[2].setBookDetails("Effective Modern C++", "Scott Meyers", "9781491903995", true, "2024-04-01");
    books[3].setBookDetails("Algorithms", "S. Dasgupta", "9780073523408", true, "2021-08-18");
    books[4].setBookDetails("Design Patterns", "GoF", "9780201633610", true, "2020-06-30");

    // Sort by ISBN
    Book::sortBookData(books, N);

    cout << "Library System - Borrow by ISBN\n";
    cout << "Enter 0 to exit.\n\n";

    while (true) {
        cout << "Current books:\n";
        for (int i = 0; i < N; ++i) {
            books[i].displayBookDetails();
        }

        cout << "\nEnter an ISBN to borrow (or 0 to exit): ";
        string input;
        cin >> input;

        if (input == "0") {
            cout << "Goodbye.\n";
            break;
        }

        bool found = false;
        for (int i = 0; i < N; ++i) {
            if (books[i].getISBN() == input) {
                found = true;

                if (books[i].borrowBook()) {
                    cout << "Borrow success.\n\n";
                } else {
                    cout << "Error: Book not available.\n\n";
                }
                break;
            }
        }

        if (!found) {
            cout << "Error: ISBN not found.\n\n";
        }
    }

    return 0;
}
