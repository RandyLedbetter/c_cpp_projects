//dstack.h
//Ledbetter, Randy
//rml

/*
 * =====================================================================================
 *
 *      Filename:       dstack.h
 *
 *   Description:       Header file dstack.h: This is the Definition/Interface for
 *                      the class Dstack.
 *       Version:       2.0
 *       Created:       Fri 05 Oct 2012 03:15:01 PM PDT
 *      Revision:       none
 *      Compiler:       gcc/g++
 *
 *        Author:       Randy Michael Ledbetter (rml), rledbetter@mail.csuchico.edu
 *  Organization:       CSU Chico Computer Science Department
 *
 * =====================================================================================
 */

#include <iostream>
using namespace std;

#ifndef DSTACK_H
#define DSTACK_H

class Dstack
{
    public:

        Dstack(); //Dstack constructor
        ~Dstack(); //Dstack destructor

        void push(double value);
        double pop();
        bool empty();
        bool valid_result();
        double get_value();

    private:

            class Node
            {
                public:
                    
                    Node (double value, Node *next)
                        {m_value = value; m_next = next;}
            
                    double m_value;
                    Node *m_next;
            };

    Node *m_top;




};

#endif



