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

    Clothing* lol = new Clothing(1111, "cloth", 0.0, "XL", "Blue", 4);
    Article* lol2 = new Clothing(*lol);
    cout << *lol << endl;
    cout << *lol2 << endl;

    try {
        StorageDialogue dialogue;
        dialogue.startDialogue();
    } catch (const std::string& e) {
        std::cerr << e << std::endl;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    } catch(...){
        std::cerr << "FATAL ERROR" << std::endl;
    }
    return 0;
}
