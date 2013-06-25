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
#include <regex.h>
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

void Vlist::copy_list(Vlist list_to_copy)
{
    //Declare and initialize local variables

    string title, url, comment;
    float length = 0.0;
    int rating = 0;
    //Check for empty list

        if (list_to_copy.m_head == NULL)
        {
          //Intentionally Empty
        }
        else
        {

            Node *ptr = list_to_copy.m_head;
            Node *ptr_copy = m_head;

            //Create head node for the duplicate list
           
                    title = ptr->m_video->get_title();
                    url = ptr->m_video->get_url();
                    comment = ptr->m_video->get_comment();
                    length = ptr->m_video->get_length();
                    rating = ptr->m_video->get_rating();

                    Video *video_copy = new Video(title, url, comment, length, rating);
                    
                    ptr_copy  =  new Node (video_copy,NULL);
                    m_head = ptr_copy;
                   

                    ptr = ptr->m_next;
                    

            //Copy list nodes

             

                while (ptr != NULL)
                {
                    title = ptr->m_video->get_title();
                    url = ptr->m_video->get_url();
                    comment = ptr->m_video->get_comment();
                    length = ptr->m_video->get_length();
                    rating = ptr->m_video->get_rating();

                    Video *video_copy = new Video(title, url, comment, length, rating);
                    ptr_copy  = ptr_copy->m_next =  new Node (video_copy, ptr->m_next);
                    ptr = ptr->m_next;
                    delete video_copy;             
                }
                
                  
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

bool Vlist::lookup_expression(string expression)
{

    //Declare and initialize local variables

    regex_t reg_expression;
    
    int result = 0;
    int count = 0;

    //Check to see if the regular expression passed in is valid

        result = regcomp(&reg_expression, expression.c_str(), REG_EXTENDED);

    //If the expression is invalid, print an error message to the screen.
    if (result)
    {
        return false;
    }


    Node *ptr = m_head;

    //Search list for instances of the valid regular expression.

        while (ptr != NULL)
        {
            result = regexec(&reg_expression, ptr->m_video->get_title().c_str(), 0, 0, 0);

            if (result == 0)
            {
                ptr->m_video->print_video_info();
                count++;
            }
    
            ptr = ptr->m_next;
        }

    if (count == 0)
    {
        return false;
    }
    
    return true;
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


void Vlist::sort_by_length()
{
    //Declare and initialize local variables

        Node *current = m_head;
        int count = 0, index_1 = 0, index_2 = 0;

        while (current != NULL)
        {
            count++;
            current = current->m_next;
        }

        for (index_1 = count; index_1 > 1; index_1--)
        {
            Node *temp, *swap_1;
            swap_1 = m_head;

            for (index_2 = 0; index_2 < count - 1; index_2++)
            {
                if (swap_1->m_video->get_length() > swap_1->m_next->m_video->get_length())
                {
                    
                    Node *swap_2 = swap_1->m_next;
                    swap_1->m_next = swap_2->m_next;
                    swap_2->m_next = swap_1;

                    if (swap_1 == m_head)
                    {
                        m_head = swap_2;
                        swap_1 = swap_2;
                    }
                    else
                    {
                        swap_1 = swap_2;
                        temp->m_next = swap_2;
                    }
                }

                temp = swap_1;
                swap_1 = swap_1->m_next;
            }
        }
        
   /*     current = m_head;
        while (current != NULL)
        {
            current->m_video->print_video_info();
            current = current->m_next;
        }*/
}


void Vlist::sort_by_rating()
{
    //Declare and initialize local variables

    bool swapped = true;
    Node *end_of_list = NULL;

    while (end_of_list != m_head && swapped == true)
    {
        swapped = false;
        Node *temp = NULL;
        Node *swap_a = m_head;

        while (swap_a->m_video->get_rating() <= swap_a->m_next->m_video->get_rating()
                && swap_a->m_video->get_title() >= swap_a->m_next->m_video->get_title())
        {
            Node *swap_b = swap_a->m_next;
            swap_a->m_next = swap_b->m_next;
            swap_b->m_next = swap_a;

            swapped = true;

                if (swap_a == m_head)
                {
                    m_head = swap_b;
                    swap_a = swap_b;
                }
                else
                {
                    swap_a = swap_b;
                    temp->m_next = swap_b;
                }

        temp = swap_a;
        swap_a = swap_a->m_next;

        }

    //Advance position of end of list to the last sorted list element.
        
        end_of_list = swap_a; 
    
    }

}


