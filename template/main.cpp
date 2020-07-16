#include <iostream>

#include "Array.h"

template class Array<double>;

int main()
{
    Array<double> doubleArr(7);
    //std::cin >> doubleArr;
    //Array<double> doubleArrCopy{ doubleArr };

    //std::cout << std::boolalpha;
    //std::cout << "doubleArr contains:\n\t" << doubleArr << std::endl;
    //std::cout << "doubleArr is equal to doubleArrCopy: " << (doubleArr == doubleArrCopy) << std::endl;
    //std::cout << "Element 3 of doubleArr is: " << doubleArr[3];
    return 0;
}