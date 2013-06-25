//dstack.cpp
//Ledbetter, Randy
//rml

/*
 * =====================================================================================
 *
 *      Filename:       dstack.cpp
 *
 *   Description:       Implementation file dstack.cpp: This is the Implementation for
 *                      the class Dstack.
 *       Version:       1.0
 *       Created:       Fri 05 Oct 2012 03:20:17 PM PDT
 *      Revision:       none
 *      Compiler:       gcc/g++
 *
 *        Author:       Randy Michael Ledbetter (rml), rledbetter@mail.csuchico.edu
 *  Organization:       CSU Chico Computer Science Department
 *
 * =====================================================================================
 */


#include <iostream>
#include <cstdlib> //for exit();
#include "dstack.h"

//Dstack Member Functions


//Class Constructor
Dstack::Dstack()
{
    m_top = NULL;
}


//Class Destructor
Dstack::~Dstack()
{
    double value;

    while(!empty())
    {
        value = pop(); //pop() calls delete.
    }
}


//Tests to see if a stack is empty
bool Dstack::empty()
{
    return (m_top == NULL);
}

double Dstack::get_value()
{
    return m_top->m_value;
}
//Retrieves the value held in the top-most
//node of the stack and then deletes the node
double Dstack::pop()
{

    //Declare and initialize local variables

        double value = 0.0;
    
    //Retrieve m_top->m_value and remove top node from the stack

        value = m_top->m_value;

        Node *temp = m_top;
        m_top = m_top->m_next;

        delete temp;


   return value;
}


//Creates new node on the top of the stack and
//assigns the parameter 'value' to the member variable
//'m_value'
void Dstack::push(double value) 
{

    //Create new Node

        Node *new_top = new Node(value, m_top);
        
    //Update m_top to this top-most node

        m_top = new_top;
}

            
bool Dstack::valid_result()
{

    //Check for empty list

        if (empty() || m_top->m_next != NULL)
        {
            return false;
        }
   
    return true;
}

