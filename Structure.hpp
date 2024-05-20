#pragma once

class Structure {
public:
    virtual void insert(int data, int priority) = 0;
    virtual int extractMax() = 0;
    virtual int peek() = 0;
    virtual void modifyKey(int data, int newPriority) = 0;
    virtual int getSize() = 0;
    virtual void generateRandomNumbers(int count) = 0;
};
