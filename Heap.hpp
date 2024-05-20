#pragma once
#include "Structure.hpp"
#include "Node.hpp"

class Heap : public Structure {
private:
    Node* heapArray;
    int capacity;
    int size;

public:
    Heap(int capacity= 1000000);
    Heap(const Heap& other); // Konstruktor kopiujący
    ~Heap();

    Heap& operator=(const Heap& other); // Operator przypisania

    void insert(int data, int priority) override;
    int extractMax() override;
    int peek() override;
    void modifyKey(int data, int newPriority) override;
    int getSize() override;
    void generateRandomNumbers(int count) override; // Dodana implementacja tej funkcji, zgodnie z interfejsem Structure

private:
    void heapifyUp(int index);
    void heapifyDown(int index);
};
