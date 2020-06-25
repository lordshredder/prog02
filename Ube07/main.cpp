/**
 *
 *  @file main.cpp
 *  @authors David Berres, Nico Schorr
 *  @date 23.05.2020
 */
#include <iostream>
#include <memory>
#include "StorageDialogue.h"

int main() {
    auto blibb = make_shared<Article>(1111, "sd", 0.0, 0);
    Article* blubb = new Article(1111, "sdff", 0.0, 0);
    vector<shared_ptr<Article>> test;
    cout << &blibb << endl;
    test.push_back(blibb);
    cout << &test[0] << endl;
    cout << test[0].use_count() << endl;

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
