/**
 * Einige einfache Pruefungen angelehnt an require.h von Bruce Eckel TIC++
 * Ergänzt um Standardausnahmeklassen
 *
 * @file	require.h
 *
 * @author	folz
 * @date	30.06.2012
 */

#ifndef REQUIRE_H
#define REQUIRE_H

#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
#include <sstream>
//using namespace std;

inline void _assertx (const char* e, const char* file, int line) {
    std::ostringstream o;
    o << "file: " << file
      << ", line: " << line
      << ", assertion failed: " << e;
    throw std::logic_error(o.str());
}

#define assertx(e)       ((e) ? (void)0 : _assertx(#e, __FILE__, __LINE__))

inline void require(bool requirement, const std::string& msg = "Requirement failed") {
    if (!requirement) {
        throw std::logic_error(msg);
    }
}

inline void assure(std::ifstream& in, const std::string& filename = "") {
    if (!in) {
        throw std::logic_error("Could not open file " + filename);
    }
}

inline void assure(std::ofstream& out, const std::string& filename = "") {
    if (!out) {
        throw std::logic_error("Could not open file " + filename);
    }
}
#endif // REQUIRE_H




