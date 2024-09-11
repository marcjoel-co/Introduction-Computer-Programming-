/* With the help of copilot AI and resources like Youtube I was able to implement 
the very first labratory activity in which The local community library is having
trouble managing its book collection and track check-outs and returns due to its 
exponentially growing collection, they often face challenges locating books and 
managing overdue items. The library uses a manual registry to record book transactions.*/

// 1.Start
#include <stdio.h>
#include <string.h>

//note to self: You have to treat strings as a litteral array in C lol  
#define MAX_BOOKS 100 // if ever library grows more increase this value
#define MAX_CHECKOUTS 50 // if every exceed max checkouts increase this value
#define MAX_TITLE 100 
#define MAX_AUTHOR 100 
#define MAX_BORROWER 100

// Structure to let the program know what a book should contain 
typedef struct {
    int id;
    char title[MAX_TITLE];
    char author[MAX_AUTHOR];
    int copies;
    int location; // shelfing unit
} Book;

// Structure to store the borrower information
typedef struct {
    int borrower_id;
    char name[MAX_BORROWER];
} Borrower;

typedef struct {
    int book_id;
    Borrower borrower;
    int due_date;
}

// arrays for the previous instructions
Book library[MAX_BOOKS];
Checkout checkouts[MAX_CHECKOUTS];

// Initialize Global variable to track the number of books and checkouts 
int book_count = 0;
int checkout_count = 0;

// protype the functions that we will shortly define
void manage_book_location(int book_id, int new_location);
void add_new_book(int id, const char *title, const char *author, int copies, int location);
void remove_book(int book_id);
void track_checked_out_books(int book_id, Borrower borrower, int due_date);
void track_available_books(int book_id);
void calculate_late_fee(int book_id, int today_is,int daily_fee);

int main() {}
    
void manage_book_location(int book_id, int new_location){
    for (int i = 0; i < book_count; i++) {
        if (library[i].id == book_id) {
            library[i].location = new_location;
            printf("Book ID %d moved to location %d. \n", book_id, new_location);
        }

    }
}


