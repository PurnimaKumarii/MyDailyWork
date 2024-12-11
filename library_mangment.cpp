#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<time.h>
using namespace std;
struct Book{
  string title,author,isbn;
  bool isAvailable=true;
  Book(const string& t, const string& a, const string& i) : 
  title(t), author(a), isbn(i), isAvailable(true){}
};
struct Borrower{
    string borrowerName;
    string isbn;
    time_t checkoutTime; 
    Borrower(const string& i, const string& b, time_t c)
     : isbn(i), borrowerName(b), checkoutTime(c){}
};
class Library_mgmt
{
    private:
    vector <Book> books;
    vector <Borrower> transaction;
    public:
     void addBook(const string& title, const string& author, const string& isbn )
    {
         books.emplace_back(title, author,isbn);
    cout<<"Book Added: "<<title <<endl;
    }

void searchBook(const string& query, const string& type)
{   
    cout << "Search results for \"" << query << "\" (" << type << "):\n";
    for (const auto& book : books)
     { 
        if ((type == "title" && book.title == query) || (type == "author" && book.author == query) || (type == "isbn" && book.isbn == query))
         { 
            cout << "Title: " << book.title << ", Author: " << book.author << ", ISBN: " << book.isbn << ", Status: " << (book.isAvailable ? "Available" : "Checked out") << endl; 
            } 
    }
}


 void checkoutBook(const string& isbn, const string& borrowerName)
  {
     for (auto& book : books) 
     { 
        if (book.isbn == isbn && book.isAvailable) 
        {
             book.isAvailable = false;
              transaction.emplace_back(isbn, borrowerName, 
              time(nullptr)); 
              cout << "Book checked out: " << book.title << " to " << borrowerName << endl;
               return;
                } 
            } 
                cout << "Book not available or ISBN incorrect.\n";
  }


void returnBook() {
    string isbn;
    cout << "Enter ISBN: ";
    cin.ignore();
    getline(cin, isbn);

    for (auto& b : books) {
        if (b.isbn == isbn && !b.isAvailable) {
            b.isAvailable = true;
            cout << "Book returned.\n";
            transaction.erase(remove_if(transaction.begin(), transaction.end(),
                                               [&](Borrower& t) { return t.isbn == isbn; }), transaction.end());
            return;
        }
    }
    cout << "Not found or already returned.\n";
}
void displayBooks() 
{ 
    cout << "Library Books:\n";
     for (const auto& book : books) 
     { 
        cout << "Title: " << book.title << ", Author: " << book.author << ", ISBN: " << book.isbn << ", Status: " << (book.isAvailable ? "Available" : "Checked out") << endl;
         } 
         } 
    };
    int main() {
        Library_mgmt library;
        int choice;
        string title, author, ISBN, name, query, type; 
        while (true) { 
            cout << "\n1. Add Book\n";
            cout << "2. Search Books\n"; 
            cout << "3. Checkout Book\n"; 
            cout << "4. Return Book\n"; 
            cout << "5. View All Books\n"; 
            cout << "6. Exit\n"; 
            cout << "Enter your choice: "; 
            cin >> choice; 
            switch (choice) 
            { 
                case 1:
                cin.ignore(); 
                // To ignore the newline character left by std::cin 
                cout << "Enter title: "; 
                getline(cin, title); 
                cout << "Enter author: "; 
                getline(cin, author); 
                cout << "Enter ISBN: "; 
                getline(cin, ISBN);
                library.addBook(title, author, ISBN); 
                 break;
                case 2: 
                cin.ignore(); 
                // To ignore the newline character left by std::cin 
                cout << "Search by (title/author/ISBN): "; 
                getline(cin, type); 
                cout << "Enter query: ";
                getline(std::cin, query); 
                library.searchBook(query, type); 
                break;
                case 3: 
                cin.ignore(); 
                cout << "Enter ISBN: "; 
                getline(std::cin, ISBN); 
                cout << "Enter borrower name: "; 
                getline(std::cin, name); 
                library.checkoutBook(ISBN, name);
                break;
                case 4: library.returnBook(); 
                break; 
                case 5:
                library.displayBooks(); 
                 break;
                case 6: 
                cout << "Exiting...\n"; 
                 return 0;
                 default: 
                    cout << "Invalid choice. Please try again.\n"; 
                    break; 
            }
         
        }
        return 0;
}
