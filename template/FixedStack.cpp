/**
 *
 * @file	FixedStack.h
 * @author	folz
 * @date	24.06.2018
 */
#ifndef FIXEDSTACK_H_
#define FIXEDSTACK_H_

#include <iostream>
#include <utility>
using namespace std;
#include "require.h"
#include "AbstractStack.h"


// ist seit neuestem notwendig
template<typename T> class FixedStack;
template<typename T>
ostream& operator<<(ostream&, const FixedStack<T>&);

/**
 * Klassen-Template fuer einen Stack implementiert mit Hilfe eines Arrays
 */
template<typename T>
class FixedStack: public AbstractStack<T> {
public:
    using AbstractStack<T>::nb_elements;
    using AbstractStack<T>::isEmpty;

    FixedStack(int = FixedStack::DEFAULT_SIZE);
    FixedStack(const FixedStack&);
    FixedStack& operator=(FixedStack);

    virtual ~FixedStack() {
        delete[] tab;
    }

    /**
     * Wert in Stack ablegen
     * Exception logic_error, falls Stack voll
     * @param t
     */
    virtual void push(const T& t);
    /**
     * Wert aus Stack herausholen
     * Exception logic_error, falls Stack leer
     * @return oberster Wert
     */
    virtual T pop();
    /**
     * Oberster Wert?
     * Exception logic_error, falls Stack leer
     * @return oberster Wert
     */
    virtual T top() const;
    virtual bool full() const {
        return (max_size == nb_elements);
    }
    friend ostream& operator<< <> (ostream&, const FixedStack&);
private:
    static const int DEFAULT_SIZE;
    T *tab; // Implementierungs-Array
    int max_size; // Größe des Arrays
};

template<typename T>
const int FixedStack<T>::DEFAULT_SIZE = 100;

template<typename T>
ostream& operator<<(ostream& o, const FixedStack<T>& s) {
    for (int i = s.nb_elements - 1; i >= 0; --i)
        o << s.tab[i] << ' ';
    return o;
}

template <typename T>
FixedStack<T>::FixedStack(int n) {
    assertx(n > 0);
    tab = new T[n];
    max_size = n;
}

// Kopierkonstruktor
template <typename T>
FixedStack<T>::FixedStack(const FixedStack<T>& s) {
    max_size = s.max_size;
    tab = new T[s.max_size];
    nb_elements = s.nb_elements;
    for (int i = 0; i < max_size; i++)
        tab[i] = s.tab[i];
}

// Zuweisungsoperator
template <typename T>
FixedStack<T>& FixedStack<T>::operator= (FixedStack<T> s) {
    swap(tab, s.tab);
    swap(max_size, s.max_size);
    swap(nb_elements, s.nb_elements);
    return *this;
}

template <typename T>
void FixedStack<T>::push (const T& t) {
    assertx(!full());
    tab[nb_elements++] = t;
}

template <typename T>
T FixedStack<T>::pop() {
    assertx(!isEmpty());
    nb_elements--;
    return tab[nb_elements];
}

template <typename T>
T FixedStack<T>::top() const {
    assertx(!isEmpty());
    return tab[nb_elements - 1];
}

template class FixedStack <int>;
template class FixedStack <double>;

#endif
