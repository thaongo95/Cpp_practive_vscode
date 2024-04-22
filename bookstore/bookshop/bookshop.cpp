#include "bookshop.h"
#include <fstream>
#include <iomanip>
// #include <iostream>

Book get_book_from_line(std::string line){
    Book book;
    std::vector<std::string> features;
    std::string temp;
    for (int i{0}; i<line.size(); i++){
        if (line[i]=='-'){
            features.push_back(temp);
            temp = "";
        }
        else{
            temp+=line[i];
        } 
    }
    book.init(features[0],features[1],features[2],features[3],features[4],
              std::stoi(features[5]),std::stoi(features[6]),std::stod(features[7]),
              std::stod(features[8]),std::stoi(temp));
    return book;
}

BookShop::BookShop()
{
    std::ifstream fin;
    std::string line;
    fin.open("bookstore.txt");
    while (std::getline(fin, line)){
        Book book;
        book = get_book_from_line(line);
        books.push_back(book);
    }
    fin.close();
    
}

BookShop::~BookShop()
{ 
    std::ofstream fout;
    std::string line;
    fout.open("bookstore.txt");
    for (int i{0}; i<books.size();i++){
        line = books[i].get_id() + "-" + books[i].get_name() + "-" + 
            books[i].get_author() + "-" + books[i].get_type() + "-" +
            books[i].get_language() + "-" + std::to_string(books[i].get_publish_year())
             + "-" + std::to_string(books[i].get_pages()) + "-" + std::to_string(books[i].get_score())
             + "-" + std::to_string(books[i].get_price()) + "-" + std::to_string(books[i].get_number());
        fout << line << std::endl;
    }
    fout.close();
}

void BookShop::append_data()
{
    std::ofstream fout;
    std::string line;
    std::cout << "Input Format: NAME-AUTHOR-TYPE-LANGUAGE-YEAR-PAGES-SCORE-PRICE-NUMBERS"<< std::endl;
    fout.open("bookstore.txt", std::ios::app);   //app is append
    while (fout){
        std::getline(std::cin, line);
        std::string id_calculated;
        id_calculated += line[0];
        for (int i=0; i< line.size(); i++){
            if ((line[i]=='-')&&(id_calculated.size()<8)){
                id_calculated+= line[i+1];
            }
        }
        if (line=="-1")
            break;
        fout << id_calculated + "-" +line << std::endl;
        Book book;
        book = get_book_from_line(id_calculated + "-" +line);
        books.push_back(book);
    }
    fout.close();
}

void BookShop::show_books_info()
{
    for (int i{0}; i<books.size(); i++){
        books[i].book_info();  
    }
}

void BookShop::purchase()
{
    std::vector<Book*> waiting_list;
    std::vector<int> purchase_number;
    double total_price{0};
    while(true){
        std::string book_id, number;
        std::cout << "Input the ID of the books you want to buy: " << std::endl;
        std::getline(std::cin, book_id);

        for (int i{0}; i<books.size(); i++){
            if (book_id==books[i].get_id()){
                waiting_list.push_back(&books[i]);
                std::cout << "This book has " << books[i].get_number() << " available" << std::endl;
            }
        }
        std::cout << "How many copies of this book you want to buy:" << std::endl;
        std::getline(std::cin, number);
        Book * book_temp = waiting_list[waiting_list.size()-1];
        if (std::stoi(number) > book_temp->get_number()){
            std::cout << "out of stock" << std::endl;
            waiting_list.pop_back();
        }
        else {
            purchase_number.push_back(std::stoi(number));
        }
        std::string flag;
        std::cout << "do you want to continue ?" << std::endl;
        std::getline(std::cin, flag);
        if(flag != "yes")
            break;
    }
    std::cout << "########################################################" << std::endl;
    std::cout << "########################################################" << std::endl;
    std::cout << "You selected " << waiting_list.size() << " books" << std::endl;
    for (int i{0}; i<waiting_list.size(); i++){
        std::cout << "   " << i << ". " << waiting_list[i]->get_name() << "  " << purchase_number[i] 
                  << "   " <<  purchase_number[i]*waiting_list[i]->get_price() << std::endl;
        total_price += purchase_number[i]*waiting_list[i]->get_price();
    }
    std::cout << "    Total Price: " << total_price << std::endl;

    std::string purchase_flag;
    std::cout << "do you want to purchase ?" << std::endl;
    std::getline(std::cin, purchase_flag);
    if (purchase_flag=="yes"){
        for (int i{0}; i<waiting_list.size(); i++){
            waiting_list[i]->set_number(waiting_list[i]->get_number()-purchase_number[i]);
        }
        std::cout << "Purchase Completed!" << std::endl;
    }
    else {
        std::cout << "Purchase Failed!" << std::endl;
    }

}


void BookShop::find_book()
{

}

void BookShop::set_rank()
{
}
