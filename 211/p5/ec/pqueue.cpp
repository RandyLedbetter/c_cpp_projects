//pqueue.cpp
//Ledbetter, Randy
//rml

/*
 * =====================================================================================
 *
 *      Filename:       pqueue.cpp
 *
 *   Description:       Implementation file pqueue.cpp: This is the Implementation file for
 *                      the class Pqueue.
 *       Version:       2.0
 *       Created:       Thu 18 Oct 2012 08:48:29 PM PDT
 *      Revision:       none
 *      Compiler:       gcc/g++
 *
 *        Author:       Randy Michael Ledbetter (rml), rledbetter@mail.csuchico.edu
 *  Organization:       CSU Chico Computer Science Department
 *
 * =====================================================================================
 */

#include <iostream>
#include <cstdlib>
#include "pqueue.h"

using namespace std;


//Class Constructor
Pqueue::Pqueue()
{
    m_front = NULL;
    m_back = NULL;
}

//Class Destructor
Pqueue::~Pqueue()
{
    while(!empty())
    {
        remove(); //remove() calls delete.
    }
}

//Class Member Functions

int Pqueue::get_first_priority()
{
    int priority = m_front->m_priority;
    return priority;
}

void Pqueue::remove()
{
    if(empty())
    {
        cerr << "Error: Removing an item from an empty queue." << endl;
        exit(1);
    }

    PqueueNode *discard;
    discard = m_front;
    m_front = m_front->m_next;

    if(m_front == NULL) //If the last node was removed
    {
        m_back = NULL;
    }

    delete discard;
}

bool Pqueue::empty()
{
    if(m_front == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Pqueue::insert_by_priority(int priority, Cust *pointer_to_customer)
{
    if(m_front == NULL) //Check for empty queue special case
    {
        PqueueNode *new_customer = new PqueueNode(priority, pointer_to_customer, NULL);
        m_front = new_customer;
        m_back = new_customer;
        return;
    }

    if(m_front->m_next == NULL) //Check for one item in the queue special case
    {
        if(m_front->m_priority <= priority)
        {
            PqueueNode *new_customer = new PqueueNode(priority, pointer_to_customer, NULL);
            m_front->m_next = new_customer;
            m_back = new_customer;
            return;
        }
        else
        {
            PqueueNode *new_customer = new PqueueNode(priority, pointer_to_customer, m_front);
            m_front = new_customer;
            return;
        }
    }

    PqueueNode *ptr = m_front;

    
    while(ptr->m_next != NULL && ptr->m_next->m_priority <= priority)
    {
        ptr = ptr->m_next;
    }


    if(ptr->m_priority > priority)
    {
        PqueueNode *new_customer = new PqueueNode(priority, pointer_to_customer, ptr);
        m_front = new_customer;
    }
    else
    {
        PqueueNode *new_customer = new PqueueNode(priority, pointer_to_customer, ptr->m_next);
        ptr->m_next = new_customer;
    }
}

void Pqueue::enqueue(int priority, Cust *pointer_to_customer)
{
    if(m_front == NULL) //Check for empty queue special case
    {
        m_front = new PqueueNode(priority, pointer_to_customer, NULL);
        m_back = m_front;
        return;
    }
    else
    {
        //Insert new node at end of the queue

        PqueueNode *new_customer = new PqueueNode(priority, pointer_to_customer, NULL);
        m_back->m_next = new_customer;
        m_back = new_customer;
    }
}

bool Pqueue::dequeue(Cust **removed_customer)
{
    if(m_front == NULL) //Check for empty queue special case
    {
       // cerr << "Error: Removing an item from an empty queue." << endl;
        return false;
    }
    *removed_customer = m_front->m_customer;
    m_front = m_front->m_next;

    if(m_front == NULL) //If the last node in the queue has been removed
    {
        m_back = NULL;
    }

    return true;
}

Cust* Pqueue::dequeue()
{
    if(m_front == NULL) //Check for empty queue special case
    {
       // cerr << "Error: Removing an item from an empty queue." << endl;
        return NULL;
    }
    Cust *removed_customer = m_front->m_customer;
    m_front = m_front->m_next;

    if(m_front == NULL) //If the last node in the queue has been removed
    {
        m_back = NULL;
    }

    return removed_customer;
}

int Pqueue::size()
{
    //Declare and initialize local variables

        int size = 0;
        PqueueNode *ptr = m_front;

        while(ptr)
        {
            size++;
            ptr = ptr->m_next;
        }

        return size;
}
