// Name      :Kristian Griffith
// Id No     :*****************
// Date      :Due 2nd March 2025
//
// Definition:
// Header file to define the class "Stack" and it's data members for managing a stack of songs
//
// QueueStackss follow the LIFO (Last In, First Out) principle of storing information
// This means the last song added to the stack is the first one removed
//
// - head: Pointer to the first node i.e. the front of the stack
//
// The operations done to the data through the head include:
// - push: Adds a new song to the top of the stack
// - pop: Removes and returns the song from the top of the stack

#ifndef STACK_H
#define STACK_H

#include "Node.h"

class Stack
{
    private:
        Node* head;
        Node* tail;

    public:
        //Constructor Function for Stack
        Stack(){head = NULL;}                                           // Default constructor for Stack (initializes head to NULL)/
        Stack(string, int, string, string, string, int);

        //Mutator Function
        void push(string, int, string, string, string, int);
        string pop();

        //Accessor Function
        string displayAll();
        bool isEmpty(){return (head == NULL);}     //Returns true if stack is empty

        string front();
        string back();

};


//Constructor's Function's Definition
Stack::Stack(string mon, int yr, string aname, string song, string lbl, int wks)
{
    head = new Node(mon, yr, aname, song, lbl, wks);
}


//Push Function for Stack
void Stack::push(string mon, int yr, string aname, string song, string lbl, int wks)
{
    //Create a New Node called "cur"
    Node* cur = new Node(mon, yr, aname, song, lbl, wks);

    if (head == NULL)                               //If stack is empty
    {
        head = cur;
    }
    else                                            //If stack is not empty
    {
        cur ->setNextPtr(head);
        head = cur;
    }
    return;
}


//Pop Function for Stack
string Stack::pop()
{
    if (head == NULL)
    {
        return ("The container is EMPTY");
    }
    else
    {
        string str = head->getRecord();
        Node* cur  = head;
        head       = head->getNextPtr();             //Moves head to next node
        delete cur;
        return str;
    }
}


string Stack::front()
{
  if (head != NULL)
  {
    return head->getRecord();
  }
  else
  {
    return "Stack is empty";
  }
};
string Stack::back()
{
    if (tail != NULL)
    {
        return tail->getRecord();
    }
    else
    {
        return "Stack is empty";
    }
}

//Displays all songs currently in the stack
string Stack::displayAll()
{
    string str = "";

    Node* cur = head;
    while(cur != NULL)
    {
        str.append(cur->getRecord() + "\n");
        cur = cur->getNextPtr();
    }
    return str;
}
#endif
