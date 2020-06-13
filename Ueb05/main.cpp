/**
 *
 * @file	LinListTst.cpp
 * @author	folz
 * @date	21.05.2012
 */
#include <iostream>
using namespace std;

#include "LinList.h"

int main() {
    LinList liste1;
    liste1.push_back("alpha");
    liste1.push_back("beta");
    liste1.push_back("34423423cgdg");
    liste1.push_front("lol");
    liste1.push_back("AAAAAAAAAAA");
    liste1.push_back("dfkshfhsjfh");
    cout << liste1 << endl;
    liste1.insert(15, "vor beta");
    cout << liste1 << endl;
    cout << "Please input something: ";
    cin >> liste1;
    cout << liste1 << endl;
    liste1.pop_front();
    cout << liste1 << endl;
    liste1.pop_back();
    cout << liste1 << endl;
    liste1.clear();
    cout << liste1 << endl;
    return 0;
}
