/**
 *
 *  @file main.cpp
 *  @authors David Berres, Nico Schorr
 *  @date 03.07.2020
 */

#include <iostream>
#include <iomanip>
#include "ProjectComponent.h"
#include "Task.h"
#include "ProjectDialogue.h"

using namespace std;


int main() {

    try {
        ProjectDialogue dialogue;
        dialogue.startDialogue();
    } catch (const std::string& e) {
        std::cerr << e << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "\nERROR: " << e.what() << std::endl;
    } catch(...){
        std::cerr << "FATAL ERROR" << std::endl;
    }
/*    weak_ptr<Project> w;
    shared_ptr<Task> t = make_shared<Task>("ttt", "sdasd", 5);
    {
        shared_ptr<Task> tt = make_shared<Task>("test", "sdasd", 5);
        shared_ptr<Project> p = make_shared<Project>("sdfsf", "sdasd", 10);
        cout << "1DEBUG share_ptr count: " << p.use_count() << endl;
        cout << "2DEBUG share_ptr count: " << p->weak_from_this().use_count() << endl;
        p->add(t);

        tt->setRoot(p);
        t->setRoot(p);
        w = p;
    }*/


    return 0;
}
