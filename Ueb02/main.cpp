/**
 *
 *  @file main.cpp
 *  @authors David Berres, Nico Schorr
 *  @date 11.05.2020
 */
#include <iostream>
#include "ArticleTest.h"

int main() {
    ArticleTest test;
    try {
        test.runFullTest();
    } catch (const string& e) {
        cout << e << endl;
    } catch (std::exception &e) {
        std::cout << "main: " << e.what() << std::endl;
    } catch (...) {
        std::cout << "EXTREME ERROR" << std::endl;
    }
    return 0;
}
