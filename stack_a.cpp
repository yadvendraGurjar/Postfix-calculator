#include "stack_a.h"
#include <iostream>
using namespace std;

// Constructor
Stack_A::Stack_A()
{
    size = 0;
}

void Stack_A::push(int data)
{
    if (size < 1024)
    {
        stk[size] = data;
        size++;
    }
    else
    {
        throw runtime_error("Stack Full");
    }
}

int Stack_A::pop()
{
    if (size == 0)
    {
        throw runtime_error("Empty Stack");
    }
    size--;
    return stk[size];
}

int Stack_A::get_element_from_top(int idx)
{
    if (idx > size - 1)
    {
        throw runtime_error("Index out of range");
    }
    return stk[size - 1 - idx];
}

int Stack_A::get_element_from_bottom(int idx)
{
    if (idx > size - 1)
    {
        throw runtime_error("Index out of range");
    }
    return stk[idx];
}

void Stack_A::print_stack(bool top_or_bottom)
{
    if (top_or_bottom == 1)
    {
        for (int i = 0; i < size; i++)
        {
            cout << stk[size - 1 - i] << "\n";
        }
    }
    else
    {
        for (int i = 0; i < size; i++)
        {
            cout << stk[i] << "\n";
        }
    }
}

int Stack_A::add()
{
    if (size < 2)
    {
        throw runtime_error("Not Enough Arguments");
    }
    int a = pop() + pop();
    push(a);
    return a;
}

int Stack_A::subtract()
{
    if (size < 2)
    {
        throw runtime_error("Not Enough Arguments");
    }
    int a = pop();
    int b = pop();
    push(b - a);
    return b - a;
}

int Stack_A::multiply()
{
    if (size < 2)
    {
        throw runtime_error("Not Enough Arguments");
    }
    int a = pop() * pop();
    push(a);
    return a;
}

int Stack_A::divide()
{
    if (size < 2)
    {
        throw runtime_error("Not Enough Arguments");
    }
    int a = pop();
    int b = pop();
    if (a == 0)
    {
        throw runtime_error("Divide by Zero Error");
    }
    else if (a < 0)
    {
        if (b <= 0)
            push(b / a);
        else if (b % a != 0)
            push(b / a - 1);
        else
            push(b / a);
    }
    else
    {
        if (b >= 0)
            push(b / a);
        else if (b % a != 0)
            push(b / a - 1);
        else
            push(b / a);
    }
    return stk[size - 1];
}

int *Stack_A::get_stack()
{
    return stk;
} // Get a pointer to the array

int Stack_A::get_size()
{
    return size;
} // Get the size of the stack
