// Name      :Kristian Griffith
// Id No     :*****************
// Date      :Due 2nd March 2025
//
// Definition:
// Header file to define the class "PQueue" (Priority Queue) and it's data members for managing a queue of songs
//
// The highest priority song is always at the front, and the lowest priority song is at the back.
// The data members represent the head and tail of the priority container.
//
// - head: Pointer to the first node, i.e., the song with the highest priority (most weeks at number one)
// - tail: Pointer to the last node, i.e., the song with the lowest priority (fewest weeks at number one)
// The operations done to the data include:
// - enqueue: Adds a new song to the back of the queue
// - dequeue: Removes and returns the song from the front of the queue
// - displayAll: Displays all songs in the container in order of priority, from the highest to the lowest priority
// - isEmpty: Checks if the container is empty

#ifndef PQUEUE_H
#define PQUEUE_H

#include "Node.h"

class PQueue
{
    private:
        Node* head;
        Node* tail;

    public:
        //Constructor Function for Priority Queue
        PQueue(){head = tail = NULL;}
        PQueue(string, int, string, string, string, int);

        //Mutator Function
        void enqueue(string, int, string, string, string, int);
        string dequeue();

        //Accessor Function
        string displayAll();
        bool isEmpty(){return (head == NULL);}     //Returns true if Priority queue is empty

        string front();
        string back();

};


PQueue::PQueue(string mon, int yr, string aname, string song, string lbl, int wks)
{
    head = tail = new Node(mon, yr, aname, song, lbl, wks);
}

//Enqueue has two cases:
//case 1: If the container is empty
//case 2: If there is already atleast one node in the container and the new node has a higher priority than the current head
//case 3: If the container has multiple nodes and the new node's priority is lower than the current
//case 4: If the new node has the lowest priority
void PQueue::enqueue(string mon, int yr, string aname, string song, string lbl, int wks)
{
    //Create a New Node called "cur"
    Node* cur = new Node(mon, yr, aname, song, lbl, wks);

    if (isEmpty())                                                                  //case 1
    {
        head = tail = cur;
    }
    else
    {
        Node* current  = head;
        Node* previous = NULL;

        //Cycle through the list to find the right position for priority
        while (current != NULL && current->getWeeks() >= cur->getWeeks()) {
            previous = current;
            current = current->getNextPtr();
        }


        // Insert the new node
        if (previous == NULL)                                                       //case 2
        {
            // Inserting at the front of the list (highest priority)
            cur->setNextPtr(head);
            head = cur;
        }
        else if (current == NULL)                                                   //case 3
        {
            // Inserting at the end of the list (low priority)
            previous->setNextPtr(cur);
            tail = cur;
        }
        else                                                                        //case 4
        {
            // Inserting  in the middle
            previous->setNextPtr(cur);
            cur->setNextPtr(current);
        }

    }
}


//Dequeue has three case:
//case 1: if the container is empty
//case 2: if the container only has one node, i.e. tail == head
//case 3: if the container has more than one node
string PQueue::dequeue()
{
    if (isEmpty())                                                                  //case 1
    {
        return "The container is EMPTY";
    }

    string str = head->getRecord();     // Get the record at the front
    Node* cur = head;
    if (head == tail)                                                               //case 2
    {
        tail = NULL;
        delete head;
        head = NULL;
    }
    else                                                                            //case 3
    {
        head = head ->getNextPtr();      // Move head to next node
    }
    delete cur;
    return str;
}

string PQueue::front()
{
  if (head != NULL)
  {
    return head->getRecord();
  } else {
    return "PQueue is empty";
  }
};

string PQueue::back()
{
  if (tail != NULL)
  {
    return tail->getRecord();
  } else {
    return "PQueue is empty";
  }
};


//Displays all songs currently in the priority queue
string PQueue::displayAll()
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
