// Classes and Objects
// Create a class for Book. A book has unique isbn (string), title, a list of authors, and a price. Write relevant
// functions. Now write a class BookStore which has a list of books. There may be multiple copies of a book in the
// book store. Write relevant member functions. Write a function books() that returns list of unique isbn numbers of
// the books, a function noOfCopies() that returns the number of copies available for a given isbn number and a
// function totalPrice() that returns the total price of all the books. Create a book store having a number of books
// (multiple copies). Now, for each book, print number of copies of that book along with its title.




#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

class Book {
    string isbn;
    string title;
    vector<string> authors;
    int price;

   public:
    Book(){};
    Book(string isbm, string title, vector<string> authors, int price) {
        this->isbn = isbn;
        this->title = title;
        for (int i = 0; i < authors.size(); i++)
            this->authors.push_back(authors[i]);
        this->price = price;
    }

    string getIsbn() { return isbn; }

    string getTitle() { return title; }

    vector<string> getAuthors() { return authors; }

    int getPrice() { return price; }

    bool equals(const Book& that) { return this->isbn.compare(that.isbn) == 0; }
};

class BookStore {
    vector<pair<Book, int>> bookList;

   public:
    BookStore(){};

    BookStore(vector<pair<Book, int>> b) {
        for (int i = 0; i < b.size(); i++) bookList.push_back(b[i]);
    }

    void addBook(Book b, int amt) {
        for (int i = 0; i < bookList.size(); i++) {
            if (b.equals(bookList[i].first)) {
                bookList[i].second += amt;
                return;
            }
        }
        bookList.push_back({b, amt});
    }

    vector<string> books() {
        vector<string> list;
        for (int i = 0; i < bookList.size(); i++)
            list.push_back(bookList[i].first.getIsbn());
        return list;
    }

    int noOfCopies(string isbn) {
        for (int i = 0; i < bookList.size(); i++)
            if (bookList[i].first.getIsbn().compare(isbn) == 0)
                return bookList[i].second;
        return 0;
    }

    int totalPrice() {
        int total = 0;
        for (int i = 0; i < bookList.size(); i++)
            total += (bookList[i].first.getPrice() * bookList[i].second);
        return total;
    }

    void printBooks() {
        cout << "_Amt_ | ___Title___" << endl;
        for (int i = 0; i < bookList.size(); i++)
            cout << setw(4) << bookList[i].second
                 << "  |  " << bookList[i].first.getTitle() << endl;
    }
};

int main() {
    vector<string> author;
    author.push_back("Author #1");
    Book b1("abcde", "Book #1", author, 100);
    author[0] = "Author #2";
    Book b2("fghij", "Book #2", author, 120);
    author[0] = "Author #3";
    Book b3("jklmn", "Book #3", author, 80);
    vector<pair<Book, int>> books;
    books.push_back({b1, 10});
    books.push_back({b2, 12});
    books.push_back({b3, 8});
    BookStore bs(books);
    bs.printBooks();
}
