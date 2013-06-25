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
 *       Version:       1.0
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

        Vlist();

        bool insert(string title, string url, string comment, float length, int rating);
        void print();
        int length();
        bool lookup(string title); 

        
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
