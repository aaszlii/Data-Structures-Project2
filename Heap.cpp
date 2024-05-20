#include "Heap.hpp"
#include <iostream>
#include <random>
using namespace std;

Heap::Heap(int capacity) : capacity(capacity), size(0) {
    heapArray = new Node[capacity];
}

Heap::Heap(const Heap& other) : capacity(other.capacity), size(other.size) {
    heapArray = new Node[capacity];
    for (int i = 0; i < size; ++i) {
        heapArray[i] = other.heapArray[i];
    }
}

Heap::~Heap() {
    delete[] heapArray;
}

Heap& Heap::operator=(const Heap& other) {
    if (this != &other) {
        delete[] heapArray;

        capacity = other.capacity;
        size = other.size;

        heapArray = new Node[capacity];
        for (int i = 0; i < size; ++i) {
            heapArray[i] = other.heapArray[i];
        }
    }
    return *this;
}

void Heap::insert(int data, int priority) {
    if (size == capacity) {
        cout << "Kopiec jest pełny" << endl;
        return;
    }

    int index = size;
    size++;
    heapArray[index].data = data;
    heapArray[index].priority = priority;
    heapifyUp(index);
}

void Heap::heapifyUp(int index) {
    while (index > 0 && heapArray[index].priority > heapArray[(index - 1) / 2].priority) {
        swap(heapArray[index], heapArray[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
}

int Heap::extractMax() {
    if (size == 0) {
        cout << "Kopiec jest pusty" << endl;
        exit(1);
    }

    int maxData = heapArray[0].data;
    heapArray[0] = heapArray[size - 1];
    size--;
    heapifyDown(0);

    return maxData;
}

void Heap::heapifyDown(int index) {
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;
    int maxIndex = index;

    if (leftChild < size && heapArray[leftChild].priority > heapArray[maxIndex].priority) {
        maxIndex = leftChild;
    }

    if (rightChild < size && heapArray[rightChild].priority > heapArray[maxIndex].priority) {
        maxIndex = rightChild;
    }

    if (maxIndex != index) {
        swap(heapArray[index], heapArray[maxIndex]);
        heapifyDown(maxIndex);
    }
}

int Heap::peek() {
    if (size == 0) {
        cout << "Kopiec jest pusty" << endl;
        exit(1);
    }

    return heapArray[0].data;
}

void Heap::modifyKey(int data, int newPriority) {
    for (int i = 0; i < size; i++) {
        if (heapArray[i].data == data) {
            int oldPriority = heapArray[i].priority;
            heapArray[i].priority = newPriority;

            if (newPriority > oldPriority) {
                heapifyUp(i);
            }
            else if (newPriority < oldPriority) {
                heapifyDown(i);
            }
            return;
        }
    }
    cout << "Nie znaleziono podanej wartosci." << endl;
}

int Heap::getSize() {
    return size;
}

void Heap::generateRandomNumbers(int count) {
    mt19937 rng(time(nullptr));
    uniform_int_distribution<int> distribution(1, 100); // Zakres priorytetów

    for (int i = 0; i < count; ++i) {
        int data = rng() % 1000000 + 1; // Generowanie losowej liczby z zakresu 1-1000000
        int priority = distribution(rng); // Losowy priorytet z zakresu 1-100
        insert(data, priority); // Wstawienie danych do kopca (wywołanie metody insert klasy Heap)
    }
}
