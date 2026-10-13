#include <stdio.h>

#define SIZE 8

void displayBooks(int books[], int size);
int countAvailable(int books[], int size);
int checkOutBook(int books[], int size, int bookNumber);
int returnBook(int books[], int size, int bookID);

int main(void){
 int books[SIZE] = {0, 1, 0, 0, 1, 0, 1, 0};
 int choice = 0;
 int bookID;

printf("Library Management System\n");
printf("1. Display Books\n");
printf("2. Check Out Book\n");
printf("3. Return Book\n");
printf("Please enter your choice: ");
scanf("%d", &choice);

 switch(choice){
    case 1:
        displayBooks(books, SIZE);
        break;
    case 2:
    printf("Enter book ID to check out (0-(%d-1)): ", SIZE);
    scanf("%d", &bookID);
    checkOutBook(books, SIZE, bookID); // Example book number to check out
    break;
    case 3:
        printf("Enter book ID to return (0-(%d-1)): ", SIZE);
        scanf("%d", &bookID);
        returnBook(books, SIZE, bookID); // Example book ID to return
        break;
    default:
        printf("Invalid choice.\n");
        break;
 }
 

 return 0;
}

void displayBooks(int books[], int size){
    for(int i = 0; i < size; i++){
        printf("Book %d: %s\n", i, books[i] ? "Checked Out" : "Available");
    }
}

int countAvailable(int books[], int size){
    int avaliable = 0;
    for(int i = 0; i < size; i++){
        if(books[i] == 0){
            avaliable++;
        }
    }
    return avaliable;
}
/**
 * this function only exists to match the output on the lab.
 * calls the function above to get the number of available books and then prints the number of available and checked out books.
 */
void availableBookFormat(int books[], int size){
    int available = countAvailable(books, size);
    int checkedOut = size - available;
    printf("Available Books: %d\n", available);
    printf("Checked Out Books: %d\n", checkedOut);
}

int checkOutBook(int books[], int size, int bookNumber){
    if(bookNumber < 0 || bookNumber >= size){
        printf("Invalid book number.\n");
        return -1;
    }
    if(books[bookNumber] == 1){
        printf("Book %d is already checked out.\n\n", bookNumber);
        availableBookFormat(books, size);
        return -1;
    }
    books[bookNumber] = 1;
    printf("Book %d has been checked out.\n\n", bookNumber);
    availableBookFormat(books, size);
    return 0;
}

int returnBook(int books[], int size, int bookID){
    if(bookID < 0 || bookID >= size){
        printf("Invalid book number.\n");
        return -1;
    }
    if(books[bookID] == 0){
        printf("Book %d is not checked out.\n\n", bookID);
        availableBookFormat(books, size);
        return -1;
    }
    books[bookID] = 0;
    printf("Book %d has been returned.\n\n", bookID);
    availableBookFormat(books, size);
    return 0;
}


/**
 * Checkoff Questions:
 * 1. you get null pointer exception because  books[8] is out of bounds. The array has indices 0-7, so books[8] is invalid.
 * 2. the pointer from 0 to 1 indiates that the book is checked out.
 * 3. the function checkoutbooks() needs to validate the book id before accessing the array becase the book id could be out of bounds and not an actual value in the array.
 * 4. modifying books[] inside of a function will modify the original array because arrays are passed by reference in C. This means that any changes made to the array inside the function will affect the original array outside the function.
 * 5.the difference between returning 1 from checkoutbook() and setting books[bookid] to 1 is that returning 1 indicates that the function has completed successfully, while setting books[bookid] to 1 indicates that the book has been checked out. Returning 1 does not change the state of the book, while setting books[bookid] to 1 does.
 */