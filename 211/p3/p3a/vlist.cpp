//vlist.cpp
//Ledbetter, Randy
//rml

/*
 * =====================================================================================
 *
 *      Filename:       vlist.cpp
 *
 *   Description:       Implementation file vlist.cpp: This is the Implementation file for
 *                      the class Vlist.
 *       Version:       1.0
 *       Created:       Fri 21 Sep 2012 11:06:47 AM PDT
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
#include <cassert>

#include "vlist.h"
#include "video.h"

using namespace std;

//Member function definitions


//Vlist Constructor
Vlist::Vlist() 
{
    m_head = NULL;
}

// always insert video at the front of the list
bool Vlist::insert(string title, string url, string comment, float length, int rating)
{
    //Declare and initialize local variables
     
        Node *ptr = m_head;   
        bool error_state = false;
    
    //Create new video

        Video *pointer_to_video = new Video(title, url, comment, length, rating);

    //Check to see if the title of the video is already in the list
    //Return an error state if it is.

        while (ptr != NULL)
        {
            if (ptr->m_video->get_title() == title)
            {
                delete pointer_to_video;
                return error_state = true;
            }
            else
            {
                ptr = ptr->m_next;
            }   
        }
    
        delete ptr; 

    //Insert new video into linked list

        m_head = new Node(pointer_to_video, m_head);
    
    return error_state;
}

void Vlist::print()
{
    //Declare and initialize local variables

        Node *ptr = m_head;

    //Print all elements in the linked list

        while (ptr != NULL)
        {
            ptr->m_video->print_video_info();
            ptr = ptr->m_next;
        }
    
    delete ptr;
    
}

int Vlist::length()
{
    //Declare and initialize local variables

        int count = 0;
        Node *ptr = m_head;

    //Count all elements in the list

        while (ptr != NULL)
        {
            ptr = ptr->m_next;
            count++;
        }

    return count;
}

bool Vlist::lookup(string title)
{
    //Declare and initialize local variables

        Node *ptr = m_head;
        bool error_state = false;

    //Search for title in the video list. Return an error state of false if it is.

        while (ptr != NULL)
        {
            if (ptr->m_video->get_title() == title)
            {
                ptr->m_video->print_video_info();
                return error_state;
            }
            else
            {
                ptr = ptr->m_next;
            }
        }

    //Title is not in list. Return error state of true.

        return error_state = true;
}

//Non-member friend function definitions




//Non-member function definitions

