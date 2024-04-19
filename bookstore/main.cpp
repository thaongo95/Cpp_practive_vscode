#include "book/book.h"
#include "book/book.cpp"
#include "bookshop/bookshop.h"
#include "bookshop/bookshop.cpp"
#include <vector>

int main(){
    BookShop bookshop;
    bookshop.show_books_info();
    std::cout << std::endl;
    bookshop.purchase();
}