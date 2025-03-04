// Name      :Kristian Griffith
// Id No     :*****************
// Date      :Due 2nd March 2025
//
// Definition:
// Header file to define the class "Node" and it's data members for storing song information.
// These data members include:
// - Month of release
// - Year of release
// - Artist name
// - Song title
// - Record label
// - Weeks at number one.

#ifndef NODE_H
#define NODE_H

#include<iostream>
#include<string.h>

using namespace std;

class Node
{
    private:
        string month;
        int year;
        string artist;
        string title;
        string label;
        int weeks;
        //int priority;
        Node* nextPtr;

    public:

        //Constructor Function
        Node(string, int, string, string, string, int);

        //Mutator Function
        void setMonth   (string mon)        {month    = mon;}
        void setYear    (int yr)            {year     = yr;}
        void setArtist  (string aname)      {artist   = aname;}
        void setTitle   (string song)       {title    = song;}
        void setLabel   (string lbl)        {label    = lbl;}
        void setWeeks   (int wks)           {weeks    = wks;}
        //void setPriority(int p)             {priority = p;}
        void setNextPtr (Node* anotherPtr)  {nextPtr  = anotherPtr;}


        //Accessor Functions
        string getMonth()   {return month;}
        int getYear()       {return year;}
        string getArtist()  {return artist;}
        string getTitle()   {return title;}
        string getLabel()   {return label;}
        int getWeeks()      {return weeks;}
        //int getPriority()   {return priority;}
        Node* getNextPtr()  {return nextPtr;}
        string getRecord();

};

//Constructor's Function definition
Node::Node(string mon, int yr, string aname, string song, string lbl, int wks)
{
   month    = mon;
   year     = yr;
   artist   = aname;
   title    = song;
   label    = lbl;
   weeks    = wks;
   nextPtr  = NULL;
   //priority = 0;
}


//Returns a formatted string
string Node::getRecord()
{
    string str = (month);
    str.append("\t" + to_string(year));
    str.append("\t" + artist);
    str.append("\t" + title);
    str.append("\t" + label);
    str.append("\t" + to_string(weeks));

    return str;
}



#endif
