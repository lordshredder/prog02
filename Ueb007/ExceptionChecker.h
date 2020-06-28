/**
 *
 *  @file ExceptionChecker.h
 *  @authors David Berres, Nico Schorr
 *  @date 25.06.2020
 */
#pragma once
#include <string>

/*
 * Check condition and if false, throw exception of type EXCEPTION.
 * @param condition
 * @param msg
 */
template <typename EXCEPTION>
inline void check(bool condition, const std::string& msg){
    if (!condition) throw EXCEPTION(msg);
}