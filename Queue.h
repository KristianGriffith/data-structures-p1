// Name      :Kristian Griffith
// Id No     :*****************
// Date      :Due 2nd March 2025
//
// Definition:
// Header file to define the class "Queue" and it's data members for managing a queue of songs
//
// The queue stores data in a linked list where each node represents a song's information.
// Queues follow the FIFO (First In, First Out) principle of storing information
// This means the first song addedto the queue is the first one removed
// Data members are used to represent the head awnd tail of the queue
//
// - head: Pointer to the first node i.e. the front of the queue
// - tail: Pointer to the last node i.e the back of the queue
//
// The operations done to the data include:
// - enqueue: Adds a new song to the back of the queue
// - dequeue: Removes and returns the song from the front of the queue
// - displayAll: Displays all songs in the container in order of priority, from the highest to the lowest priority
// - isEmpty: Checks if the container is empty


#ifndef QUEUE_H
#define QUEUE_H

#include "Node.h"

class Queue
{
    private:
        Node* head;
        Node* tail;

    public:
        //Constructor Function for Queue
        Queue(){head = tail = NULL;}
        Queue(string, int, string, string, string, int);

        //Mutator Function
        void enqueue(string, int, string, string, string, int);
        string dequeue();

        //Accessor Function
        string displayAll();
        bool isEmpty(){return (head == NULL);}     //Returns true if queue is empty

        string front();
        string back();

};


//Constructor's Function Definition
Queue::Queue(string mon, int yr, string aname, string song, string lbl, int wks)
{
    head = tail = new Node(mon, yr, aname, song, lbl, wks);
}


//Enqueue has two cases:
//case 1: If the container is empty
//case 2: If there is already atleast one node in the container
void Queue::enqueue(string mon, int yr, string aname, string song, string lbl, int wks)
{
    //Create a New Node called "cur"
    Node* cur = new Node(mon, yr, aname, song, lbl, wks);

    if (head == NULL)                              //case 1
    {
        head = tail = cur;
    }
    else                                           //case 2
    {
        tail ->setNextPtr(cur);
        tail = cur;
    }
    return;
}


//Dequeue has three case:
//case 1: if the container is empty
//case 2: if the container only has one node, i.e. tail == head
//case 3: if the container has more than one node
string Queue::dequeue()
{
    if (isEmpty())                                  //case 1
    {
        return ("The container is EMPTY");
    }
    string str = "";

    if (head == tail)                               //case 2
    {
        str  = head->getRecord();
        tail = NULL;
        delete head;
        return str;
    }
    else                                            //case 3
    {
        str       = head->getRecord();
        Node* cur = head;
        head      = head->getNextPtr();             //Moves head to next node
        delete cur;
        return str;
    }
}

string Queue::front()
{
  if (head != NULL)
  {
    return head->getRecord();
  } else {
    return "Queue is empty";
  }
};

string Queue::back()
{
  if (tail != NULL)
  {
    return tail->getRecord();
  } else {
    return "Queue is empty";
  }
};


//Displays all songs currently in the queue
string Queue::displayAll()
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


