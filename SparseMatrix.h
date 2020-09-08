#include <iostream>
#include "SparseMatrixTraits.h"

template <typename T>
class Cell{
    T data;
    Coordinates coordinate;
public:
    Cell(const Coordinates &coordinate) : coordinate(coordinate){}

    Cell() {
        std::cout << "test";
    }
};


template <typename T>
class SparseMatrix : public SparseMatrixTraits<T>{
public:
    Cell<T> * * table;

    SparseMatrix(){
        table = new Cell<T>*[10000000];
    }

    const T &operator()(Coordinates pos) const override {
        Cell<T> * b = new Cell<T>(pos);
        T * a = new T(1);
        return *a;
    }

    T &operator()(Coordinates pos) override {
        Cell<T> * b = new Cell<T>(pos);
        T * a = new T(1);
        return *a;
    }

    void clear() override {

    }

    void print() override {

    }
};
