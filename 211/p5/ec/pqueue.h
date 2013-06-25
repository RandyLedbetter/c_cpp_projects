//pqueue.h
//Ledbetter, Randy
//rml

/*
 * =====================================================================================
 *
 *      Filename:       pqueue.h
 *
 *   Description:       Header file pqueue.h: This is the Definition/Interface for
 *                      the class Pqueue.
 *       Version:       2.0
 *       Created:       Thu 18 Oct 2012 08:45:00 PM PDT
 *      Revision:       none
 *      Compiler:       gcc/g++
 *
 *        Author:       Randy Michael Ledbetter (rml), rledbetter@mail.csuchico.edu
 *  Organization:       CSU Chico Computer Science Department
 *
 * =====================================================================================
 */

#include <iostream>
#include "cust.h"

using namespace std;

#ifndef PQUEUE_H
#define PQUEUE_H

class Pqueue
{
    public:

        Pqueue();
        ~Pqueue();

        //Inserts nodes of type PqueueNode into an instantiation
        //of a priority queue of type Pqueue in sorted by the passed
        //parameter 'priority'
        void insert_by_priority(int priority, Cust *pointer_to_customer);

        //Inserts an item into the back of the instantiated queue of type Pqueue
        void enqueue(int priority, Cust *pointer_to_customer);

        //Removes an item from the front of the instantiated queue of type Pqueue
        //Returns true if dequeue was successful, false otherwise. The passed by
        //reference parameter removed_customer points to the removed item
        bool dequeue(Cust **removed_customer);

        //Removes an item from the front of the instantiated queue of type Pqueue
        Cust* dequeue();

        //Checks to see if the instantiated queue of type Pqueue is empty
        //If so, the function returns true, otherwise it returns false
        bool empty();

        //Removes the item at the front of the instantiated queue of type Pqueue
        void remove();

        //Calculates the size of the instantiated queue and returns the result
        int size();

        //Returns the value of the member_variable m_priority
        int get_first_priority();

    private:

            class PqueueNode
            {
                public:
                    
                    PqueueNode(int priority, Cust *customer, PqueueNode *next)
                    {m_priority = priority; m_customer = customer; m_next = next;}
                    int m_priority;
                    Cust *m_customer;
                    PqueueNode *m_next;
            };


        PqueueNode *m_front; //Points to the head of a linked list.
                             //Items are removed at this end.
        PqueueNode *m_back;  //Points to the node at the other end
                             //of the linked list. Items are added
                             //at this end.
};

#endif



