// Name      :Kristian Griffith
// Id No     :*****************
// Date      :Due 2nd March 2025
//
// Definition:
// Header file to define the class "Deque" (double-ended queue) and its data members for managing a deque of songs
//
//  A deque stores data in a linked list where nodes can be added or removed from both ends.
//  It allows for operations at both the front and the back of the deque.
//
// - head: Pointer to the first node (front of the deque)
// - tail: Pointer to the last node (back of the deque)
//
// The operations done to the data include:
// - enqueueFront: Adds a new song to the front of the deque
// - enqueueBack: Adds a new song to the back of the deque
// - dequeueFront: Removes and returns the song from the front of the deque
// - dequeueBack: Removes and returns the song from the back of the deque
// - displayAll: Displays all songs in the container
// - isEmpty: Checks if the container is empty

#ifndef DEQUE_H
#define DEQUE_H

#include "Node.h"

class Deque
{
    private:
        Node* head;
        Node* tail;

    public:
        // Constructor function for Deque
        Deque(){ head = tail = NULL;}
        Deque(string, int, string, string, string, int);

        // Mutator functions
        void enqueueFront(string, int, string, string, string, int);
        void enqueueBack(string, int, string, string, string, int);
        string dequeueFront();
        string dequeueBack();

        // Accessor functions
        string displayAll();
        bool isEmpty() { return (head == NULL); } // Returns true if Deque is empty

        string front();
        string back();

};

// Constructor function definition
Deque::Deque(string mon, int yr, string aname, string song, string lbl, int wks)
{
    head = tail = new Node(mon, yr, aname, song, lbl, wks);
}

//EnqueueFront has two cases:
//case 1: If the deque is empty
//case 2: If the deque is not empty
void Deque::enqueueFront(string mon, int yr, string aname, string song, string lbl, int wks)
{
    Node* cur = new Node(mon, yr, aname, song, lbl, wks);

    if (head == NULL)                             //case 1
    {
        head = tail = cur;
    }
    else                                          //case 2
    {
        cur->setNextPtr(head);
        head = cur;
    }
}

// EnqueueBack has two cases:
// case 1: If the deque is empty
// case 2: If the deque is not empty
void Deque::enqueueBack(string mon, int yr, string aname, string song, string lbl, int wks)
{
    Node* cur = new Node(mon, yr, aname, song, lbl, wks);

    if (tail == NULL)                               //case 1
    {
        head = tail = cur;
    }
    else                                            //case 2
    {
        tail->setNextPtr(cur);
        tail = cur;
    }
}

//DequeueFront has three cases:
//case 1: If the deque is empty
//case 2: If the deque has only one node (tail == head)
//case 3: If the deque has more than one node
string Deque::dequeueFront()
{
    if (isEmpty())                                  //case 1
    {
        return ("The container is EMPTY");
    }

    string str = "";

    if (head == tail)                               //case 2
    {
        str = head->getRecord();
        tail = NULL;
        delete head;
        head = NULL;
        return str;
    }
    else                                            //case 3
    {
        str = head->getRecord();
        Node* cur = head;
        head = head->getNextPtr();
        delete cur;
        return str;
    }
}

//DequeueBack has three cases:
//case 1: If the deque is empty
//case 2: If the deque has only one node (tail == head)
//case 3: If the deque has more than one node
string Deque::dequeueBack()
{
    if (isEmpty())                                  //case 1
    {
        return ("The container is EMPTY");
    }

    string str = "";

    if (head == tail)                               //case 2
    {
        str = tail->getRecord();
        tail = head = NULL;
        delete tail;
        return str;
    }
    else                                            //case 3
    {
        Node* cur = head;
        while (cur->getNextPtr() != tail)           // Traverse to the second-to-last node
        {
            cur = cur->getNextPtr();
        }
        str = tail->getRecord();
        delete tail;
        tail = cur;
        tail->setNextPtr(NULL);                     // Remove the reference to the last node
        return str;
    }
}

string Deque::front()
{
  if (head != NULL)
  {
    return head->getRecord();
  } else {
    return "Deque is empty";
  }
};

string Deque::back()
{
  if (tail != NULL)
  {
    return tail->getRecord();
  } else {
    return "Deque is empty";
  }
};

// Displays all songs currently in the deque
string Deque::displayAll()
{
    string str = "";

    Node* cur = head;
    while (cur != NULL)
    {
        str.append(cur->getRecord() + "\n");
        cur = cur->getNextPtr();
    }
    return str;
}

#endif
