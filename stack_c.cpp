#include "stack_c.h"
#include <iostream>
using namespace std;

/* PART B */
/* Stacks using Linked Lists */

// Constructor
Stack_C::Stack_C()
{
    stk = new List();
}

// Destructor
Stack_C::~Stack_C()
{
    delete[] stk;
}

void Stack_C::push(int data)
{
    try
    {
        stk->insert(data);
    }
    catch (const std::exception &e)
    {
        throw runtime_error("Out of Memory");
    }
}

int Stack_C::pop()
{
    if (stk->get_size() < 1)
    {
        throw runtime_error("Empty Stack");
    }
    int val = stk->delete_tail();
    return val;
}

int Stack_C::get_element_from_top(int idx)
{
    if (idx > stk->get_size() - 1)
    {
        throw runtime_error("Index out of range");
    }
    Node *N = stk->get_head()->prev->prev;
    while (idx > 0)
    {
        N = N->prev;
        idx--;
    }
    return N->get_value();
}

int Stack_C::get_element_from_bottom(int idx)
{
    if (idx > stk->get_size() - 1)
    {
        throw runtime_error("Index out of range");
    }
    Node *N = stk->get_head()->next;
    while (idx > 0)
    {
        N = N->next;
        idx--;
    }
    return N->get_value();
}

void Stack_C::print_stack(bool top_or_bottom)
{
    if (top_or_bottom == 1)
    {
        Node *N = stk->get_head()->prev;
        for (int i = 0; i < stk->get_size(); i++)
        {
            N = N->prev;
            cout << N->get_value() << "\n";
        }
    }
    else
    {
        Node *N = stk->get_head();
        for (int i = 0; i < stk->get_size(); i++)
        {
            N = N->next;
            cout << N->get_value() << "\n";
        }
    }
}

int Stack_C::add()
{
    if (stk->get_size() < 2)
    {
        throw runtime_error("Not Enough Arguments");
    }
    int a = pop() + pop();
    push(a);
    return a;
}

int Stack_C::subtract(){
    if (stk->get_size() < 2)
    {
        throw runtime_error("Not Enough Arguments");
    }
    int a = pop();
    int b = pop();
    push(b - a);
    return b - a;
}

int Stack_C::multiply(){
    if (stk->get_size() < 2)
    {
        throw runtime_error("Not Enough Arguments");
    }
    int a = pop() * pop();
    push(a);
    return a;
}

int Stack_C::divide(){
    if (stk->get_size() < 2)
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
    return stk->get_head()->prev->prev->get_value();
}

List *Stack_C::get_stack(){
    return stk;
} // Get a pointer to the linked list representing the stack

int Stack_C::get_size(){
    return stk->get_size();
} // Get the size of the stack
