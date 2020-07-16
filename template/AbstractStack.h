/**
 *
 * @file	Stack.h
 * @author	folz
 * @date	02.07.2012
 */
#ifndef ABSTRACTSTACK_H_
#define ABSTRACTSTACK_H_
/**
 * Abstraktes Klassen-Template fuer einen Stack
 */
template <class T>
class AbstractStack {
public:
    AbstractStack() : nb_elements(0) {};
    virtual ~AbstractStack() { }

    /**
     * Wert in Stack ablegen
     * @param t
     */
    virtual void push(const T& t) = 0;
    /**
     * Wert aus Stack herausholen
     * @return oberster Wert
     */
    virtual T pop() = 0;
    /**
     * Oberster Wert?
     * @return oberster Wert
     */
    virtual T top() const = 0;
    /**
     * Anzahl Elemente im Stack
     * @return anzahl
     */
    int size () const  { return nb_elements; }
    /**
     * Stack leer?
     * @return true, falls ja, false sonst
     */
    virtual bool isEmpty() const  {
        return (nb_elements == 0);
    }
    /**
     * Stack voll?
     * @return true falls ja, false sonst
     */
    virtual bool isFull () const  { return false; }

protected:
    int nb_elements;	 // Anzahl Elemente des Stacks
};

#endif
