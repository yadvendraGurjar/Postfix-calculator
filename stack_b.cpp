#include "stack_b.h"
#include <iostream>
using namespace std;

/* PART B */
/* Dynamic Stacks */

// Constructor
Stack_B::Stack_B()
{
    stk = new int[1024];
    size = 0;
    capacity = 1024;
}

// Destructor
Stack_B::~Stack_B()
{
    delete[] stk;
}

void Stack_B::push(int data)
{
    if (size >= capacity)
    {
        capacity *= 2;
        int *newData = NULL;
        try
        {
            newData = new int[capacity];
        }
        catch (const std::exception &e)
        {
            throw runtime_error("Out of Memory");
        }
        for (int i = 0; i < size; i++)
        {
            newData[i] = stk[i];
        }
        delete[] stk;
        stk = newData;
    }
    stk[size] = data;
    size++;
}

int Stack_B::pop()
{
    if (size == 0)
    {
        throw runtime_error("Empty Stack");
    }
    else if (capacity > 1024 && size <= capacity / 4 - 1)
    {
        capacity /= 2;
        int *newData = new int[capacity];
        for (int i = 0; i < size; i++)
        {
            newData[i] = stk[i];
        }
        delete[] stk;
        stk = newData;
    }
    size--;
    return stk[size];
}

int Stack_B::get_element_from_top(int idx)
{
    if (idx > size - 1)
    {
        throw runtime_error("Index out of range");
    }
    return stk[size - 1 - idx];
}

int Stack_B::get_element_from_bottom(int idx)
{
    if (idx > size - 1)
    {
        throw runtime_error("Index out of range");
    }
    return stk[idx];
}

void Stack_B::print_stack(bool top_or_bottom)
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

int Stack_B::add()
{
    if (size < 2)
    {
        throw runtime_error("Not Enough Arguments");
    }
    int a = pop() + pop();
    push(a);
    return a;
}

int Stack_B::subtract()
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

int Stack_B::multiply()
{
    if (size < 2)
    {
        throw runtime_error("Not Enough Arguments");
    }
    int a = pop() * pop();
    push(a);
    return a;
}

int Stack_B::divide()
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

int *Stack_B::get_stack()
{
    return stk;
} // Get a pointer to the array

int Stack_B::get_size()
{
    return size;
} // Get the size of the stack
