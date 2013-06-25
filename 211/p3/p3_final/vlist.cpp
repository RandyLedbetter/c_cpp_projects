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
 *       Version:       3.0
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

//Vlist Destructor
Vlist::~Vlist()
{
    //Declare and initialize local variables

    Node *ptr = m_head;

    while (ptr != NULL)
    {
        Node *temp;

        temp = ptr;
        ptr = ptr->m_next;
        delete temp;
    }
}


bool Vlist::insert(string title, string url, string comment, float length, int rating)
{
    //Create new video

        Video *pointer_to_video = new Video(title, url, comment, length, rating);

    //Check for empty list condition
        
        if (m_head == NULL)
        {
            m_head = new Node(pointer_to_video, m_head);
            return false;
        }
        else
        {
            //Check if the title is already in the video list.
            //If so, do not insert and return false.

            Node *ptr = m_head;
    
            while (ptr != NULL)
            {
                if (ptr->m_video->get_title() == title)
                {
                    delete pointer_to_video;
                    return true;
                }

                ptr = ptr->m_next;
            }

            delete ptr;
        }

            //Insert new video alphabetically into the video list
          
            if (m_head->m_video->get_title() > title)
            {
                m_head = new Node(pointer_to_video, m_head);
            }
            else
            {
           
                Node *after_me = m_head;

                while (after_me->m_next != NULL && after_me->m_next->m_video->get_title() <= title)
                {
                    after_me = after_me->m_next;
                }
          
                after_me->m_next = new Node(pointer_to_video, after_me->m_next);
                
            }
              
             
            return false;        
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


bool Vlist::remove(string title)
{

    //Declare and initialize local variables

        Node *ptr = m_head;
        Node *temp = NULL;

    //Check for empty list condition.
        
        if (m_head == NULL)
        {
            return true;
        }

    //Check for one item in the list condition.

        if (m_head != NULL && m_head->m_video->get_title() == title)
        {
            temp = m_head;
            m_head = m_head->m_next;
            delete temp->m_video;
            delete temp;
            return false;
        }
   

    //Search list for title and delete it if present.

        while (ptr->m_next != NULL && ptr->m_next->m_video->get_title() != title)
        {
            ptr = ptr->m_next;
        }
    

    if (ptr->m_next != NULL && ptr->m_next->m_video->get_title() == title)
    {
        temp = ptr->m_next;
        ptr->m_next = temp->m_next;
        delete temp->m_video;
        delete temp;
        return false;
    }
  
           
    //Title not in the list.

    return true;
}

