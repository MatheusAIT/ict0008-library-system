#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string>

class Book {
private:
    std::string title;
    std::string author;
    std::string isbn;
    bool available;
    std::string dateAdd;

public:
    Book() : available(true) {}

    Book(const std::string& t,
         const std::string& a,
         const std::string& i,
         bool avail,
         const std::string& d)
        : title(t),
          author(a),
          isbn(i),
          available(avail),
          dateAdd(d) {}

    void setBookDetails(const std::string& t,
                        const std::string& a,
                        const std::string& i,
                        bool avail,
                        const std::string& d) {
        title = t;
        author = a;
        isbn = i;
        available = avail;
        dateAdd = d;
    }

    void displayBookDetails() const {
        std::cout << "Title: " << title
                  << " | Author: " << author
                  << " | ISBN: " << isbn
                  << " | Available: " << (available ? "Yes" : "No")
                  << " | DateAdd: " << dateAdd;
    }

    const std::string& getISBN() const {
        return isbn;
    }

    bool isAvailable() const {
        return available;
    }

    // Sort ascending by ISBN (smallest -> largest)
    static void sortAscending(Book arr[], int n) {
        for (int i = 0; i < n - 1; ++i) {
            for (int j = 0; j < n - i - 1; ++j) {
                if (arr[j].isbn > arr[j + 1].isbn) {
                    Book tmp = arr[j];
                    arr[j]   = arr[j + 1];
                    arr[j + 1] = tmp;
                }
            }
        }
    }

    // Sort descending by ISBN (largest -> smallest)
    static void sortDescending(Book arr[], int n) {
        for (int i = 0; i < n - 1; ++i) {
            for (int j = 0; j < n - i - 1; ++j) {
                if (arr[j].isbn < arr[j + 1].isbn) {
                    Book tmp = arr[j];
                    arr[j]   = arr[j + 1];
                    arr[j + 1] = tmp;
                }
            }
        }
    }
};

#endif // BOOK_H
