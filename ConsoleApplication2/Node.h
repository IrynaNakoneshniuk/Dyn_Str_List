#pragma once
template <typename T>
class Node
{
    public:
    T value;
    Node* next;
    Node* prev;

    Node() {
        value = 0;
        next = nullptr;
        prev = nullptr;
    };
    Node(T value)
    {
        this->value = value;
        next = nullptr;
        prev = nullptr;
    }

    T getValue() { return this->value; };
    void setValue(T value) {this->value=value; };
};

