/**
 *
 *  @file main.cpp
 *  @authors David Berres, Nico Schorr
 *  @date 21.06.2021
 */
#include <string>
#include "FileAnalyzer.h"

using namespace std;

int main(int argc, char *argv[]) {
    try {
        FileAnalyzer analyzer;
        analyzer.analyzeFiles(argc, argv);
    } catch (const string& e) {
        cout << "\nERROR: " << e << "\n";
    } catch (std::exception &e) {
        cout << e.what() << std::endl;
    } catch (...) {
        cout << "\nSomething went terribly wrong." << endl;
    }
    return 0;
}
