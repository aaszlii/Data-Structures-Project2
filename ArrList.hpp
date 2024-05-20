#pragma once
#include <iostream>
#include "Structure.hpp"
#include "Node.hpp"

using namespace std;

class ArrList : public Structure
{
private:
    Node* array; //Tablica przechowujaca elementy
    int size; // Aktualny rozmiar kolejki
    int capacity; // Pojemnosc tablicy

public:
    ArrList(int capacity);
    ArrList(const ArrList& other); // Konstruktor kopiujący
    ~ArrList();
    ArrList& operator=(const ArrList& other); // Operator przypisania

    void insert(int data, int priority);
    int extractMax();
    int peek();
    void modifyKey(int data, int newPriority);
    int getSize();
    virtual void generateRandomNumbers(int count) override;
};
