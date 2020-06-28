/**
 *
 *  @file main.cpp
 *  @authors David Berres, Nico Schorr
 *  @date 23.05.2020
 */
#include <iostream>
#include <memory>
#include "StorageDialogue.h"
#include "Clothing.h"

int main() {
    auto blibb = make_shared<Article>(1111, "sd", 0.0, 0);
    auto blubb = new Article(1111, "sdff", 0.0, 0);
    vector<shared_ptr<Article>> test;

    cout << &blibb << endl;
    test.push_back(blibb);
    cout << &test[0] << endl;
    cout << test[0].use_count() << endl;
    auto* one = new Article(1111, "dfsdf" , 0.0, 0);
    auto* two = new Article(*one);

    Clothing* article1 = new Clothing(1111, "cloth", 0.0, "XL", "Blue", 4);
    Article* article2 = new Clothing(*article1);

    Article* article3 = new Clothing(1111, "cloth", 0.0, "XL", "Blue", 4);
    //Clothing* tdfdf = dynamic_cast<Clothing*>(article3);
    Article* article4 = new Clothing(*dynamic_cast<Clothing*>(article3));
    cout << *one << endl;
    cout << *article1 << endl;
    cout << *article2 << endl;
    cout << *article3 << endl;
    cout << *article4 << endl;

    try {
        StorageDialogue dialogue;
        dialogue.startDialogue();
    } catch (const std::string& e) {
        std::cerr << e << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    } catch(...){
        std::cerr << "FATAL ERROR" << std::endl;
    }
    return 0;
}
