#ifndef BOOK_H
#define BOOK_H
#include <string>
#include <iostream>

class Book{
private:
    std::string id;
    std::string name;
    std::string author;
    int pages{0};
    std::string type;
    std::string language;
    int publish_year{0};
    double score{0};
    int rank{0};
    double price{0};
    
public:
    Book(){};
    ~Book(){};
    void init(std::string id, std::string name, std::string author, std::string type,
            std::string language, int publish_year, int pages, double score, double price);
    void init();
    void book_info();
    std::string get_type();
    std::string get_id();
    std::string get_name();
    double get_price();
    int get_pages();
    double get_score();
    int get_publish_year();
    int number_available{0};
};


#endif