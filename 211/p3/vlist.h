//vlist.h
//Ledbetter, Randy
//rml

/*
 * =====================================================================================
 *
 *      Filename:       vlist.h
 *
 *   Description:       Header file vlist.h: This is the Definition/Interface for
 *                      the class Vlist.
 *       Version:       3.0
 *       Created:       Fri 21 Sep 2012 10:54:04 AM PDT
 *      Revision:       none
 *      Compiler:       gcc/g++
 *
 *        Author:       Randy Michael Ledbetter (rml), rledbetter@mail.csuchico.edu
 *  Organization:       CSU Chico Computer Science Department
 *
 * =====================================================================================
 */

#include <iostream>
#include <string>
#include "video.h"
using namespace std;

#ifndef VLIST_H
#define VLIST_H

class Vlist
{
    public:

        Vlist();//Vlist class constructor

        ~Vlist();//Vlist class destructor
        
        void copy_list(Vlist list_to_copy);

        bool insert(string title, string url, string comment, float length, int rating);
        //Precondition:     All formal parameters have been properly initialized
        //                  and passed to the function.
        //Postcondition:    A new object of type Video has been created and initialized
        //                  with the values passed to the function, and a new list item
        //                  of type Node has had it's pointer member variable set to
        //                  point to the Video object. Additionally, the new list item
        //                  has been inserted into the list alphabetically. If the video
        //                  title passed to the function is already existent in the list,
        //                  a new Video object is not created and the function returns
        //                  1, otherwise, the function returns 0.

        void print();
        //Precondition:     An object of type Vlist has been created and used to call
        //                  the function.
        //Postcondition:    All video information contained within the Vlist list, if
        //                  any, have been printed to the screen in the format
        //                  prescribed by Project 2 "Video List."
       
        int length();
        //Precondition:     An object of type Vlist has been created and used to call
        //                  the function.
        //Postcondition:    The number of noded in the Vlist list have been counted
        //                  and the result has been returned as an integer to the
        //                  calling function.

        bool lookup(string title);
        //Precondition:     An object of type Vlist has been created and used to call
        //                  the function and a parameter of type string has been passed.
        //Postcondition:    The list of type Vlist has been searched to see if any Video
        //                  object pointed to by the nodes in the Vlist list contain
        //                  a video title == the passed parameter 'title.' If the title
        //                  was in the list, the function returns 0, otherwise it returns
        //                  1.

        bool lookup_expression(string expression);
        //Precondition:     An object of type Vlist has been created and used to call
        //                  the funciton and a parameter of type string has been passed.
        //Postcondition:    The value of the passed parameter "expression" has been
        //                  tested to see if it represents a valid regular expression. If
        //                  it is, the entire linked list is searched for instances
        //                  of that regular expression. If instances are found, the
        //                  function returns true. If the expression is not valid, or
        //                  no instances of the expression were found in the list,
        //                  the function returns false.

        bool remove(string title);
        //Precondition:    An object of type Vlist has been created and used to call
        //                 the function and a parameter of type string has been passed.
        //Postconditon:    If the value of the passed parameter 'title' already exists
        //                 in one of the Video objects pointed to by the nodes comprising
        //                 the Vlist list, both the list node and the Video object pointed
        //                 to have been deleted and the function returns 0. Otherwise,
        //                 the function returns 1.

        void sort_by_length();
        //Precondition:    An object of type Vlist has been created and used to call
        //                 the function.
        //Postcondition:   All list elements have been sorted by length from shortest
        //                 to longest. If the lengths of any two elements are the
        //                 same, they are sorted alphabetically as well. 

        void sort_by_rating();
        //Precondition:    An object of type Vlist has been created and used to call
        //                 the function.
        //Postcondition:   All list elements have been sorted by rating from highest rating
        //                 to lowest rating. If the ratings of any two elements are the
        //                 same, they are sorted alphabetically as well. 


        
    private:

        class Node
        {
            public:

                Node(Video *video, Node *next)
                {m_video = video; m_next = next;}

                Video *m_video;
                Node *m_next;
        };

        Node *m_head;
};

#endif
