#include <iostream>
#include "Rand.h"
#include "SparseMatrixTraits.h"
#include <string>
#include <cstdio>



template <typename T>
class Cell{

public:
    Cell(const Coordinates &coordinate) : coordinate(coordinate){}

    Cell() {
        std::cout << "test";
    }
    Coordinates coordinate;
    T data;
};

template <typename T>
class SparseMatrix : public SparseMatrixTraits<T>{
public:
    Cell<T> * * table;
    inline static int itemsNumber = 0;

    SparseMatrix(){
        table = new Cell<T>*[10000000];
    }

    const T &operator()(Coordinates pos) const override {
        Cell<T> * b = new Cell<T>(pos);
        table[SparseMatrix::itemsNumber] = b;
        SparseMatrix::itemsNumber++;
        T * a = new T(1);
        b->data = *a;
        return *a;
    }

    T &operator()(Coordinates pos) override {
        for (int i = 0; i < SparseMatrix::itemsNumber; ++i) {
            if(pos.col == table[i]->coordinate.col && pos.row == table[i]->coordinate.row){
                return table[i]->data;
            }
        }

        Cell<T> * b = new Cell<T>(pos);
        *(table + SparseMatrix::itemsNumber) = b;
        std::cout<< "===" << SparseMatrix::itemsNumber << "=====\n";
        SparseMatrix::itemsNumber = SparseMatrix::itemsNumber + 1;
        T * a = new T(0);
        b->data = *a;
        return *a;
    }

    void clear() override {
        delete[] table;
    }

    void print() override {
        std::cout << "This is a sparse table.";
    }
};