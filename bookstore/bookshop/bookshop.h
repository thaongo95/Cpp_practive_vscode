#ifndef BOOKSHOP_H
#define BOOKSHOP_H
#include <vector>
#include "../book/book.h"
class BookShop{
    std::vector<Book> books;
    std::vector<Book> top_books;
    public:
        BookShop();
        ~BookShop();
        void append_data();
        void show_books_info();
        void purchase();
        void find_book();
        void set_rank();
};



#endif