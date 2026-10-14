#pragma once
#include <string>

struct StackNode
{
    std::string data;
    int line = 0;
    StackNode* next = nullptr;
};

class Stack
{
public:
    Stack() { top = nullptr; }

    bool IsEmpty() { return top == nullptr; }

    void Push(const std::string& data, int line);

    std::string Pop();
    int Topline();

private:
    StackNode* top;
};