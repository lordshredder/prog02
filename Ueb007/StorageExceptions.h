/**
 *
 *  @file StorageExceptions.h
 *  @authors David Berres, Nico Schorr
 *  @date 25.06.2020
 */
#pragma once
#include <stdexcept>
using namespace std;

class StorageException : public logic_error {
public:
    StorageException(const string& msg = "") : logic_error(msg) {

    }
};

class ArticleException : public logic_error {
public:
    ArticleException(const string& msg = "") : logic_error(msg) {

    }
};

class ClothingException : public ArticleException {
public:
    ClothingException(const string& msg = "") : ArticleException(msg) {

    }
};

class ElectronicDeviceException : public ArticleException {
public:
    ElectronicDeviceException(const string& msg = "") : ArticleException(msg) {

    }
};

