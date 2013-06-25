//shape.cpp
//Ledbetter, Randy
//rml

/*
 * =====================================================================================
 *
 *      Filename:       shape.cpp
 *
 *   Description:       Implementation file shape.cpp: This is the Implementation for
 *                      the class Shape.
 *                              
 *       Version:       3.0
 *       Created:       11/09/2012
 *      Revision:       none
 *      Compiler:       gcc/g++
 *
 *        Author:       Randy Michael Ledbetter (rml), rledbetter@mail.csuchico.edu
 *  Organization:       CSU Chico Computer Science Department
 *
 * =====================================================================================
 */

#include <iostream>

#include "shape.h"

using namespace std;


// Shape class constructor. Initializes m_x and m_y.
Shape::Shape(int x, int y)
{
    m_x = x;
    m_y = y;
}
 


