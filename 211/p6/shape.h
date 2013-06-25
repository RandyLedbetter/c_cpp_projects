//shape.h
//Ledbetter, Randy
//rml

/*
 * =====================================================================================
 *
 *      Filename:       shape.h
 *
 *   Description:       Header file shapes.h: This is the Definition/Interface for
 *                      the Base Class Shape.
 *       Version:       1.0
 *       Created:       11/09/2012
 *      Revision:       none
 *      Compiler:       gcc/g++
 *
 *        Author:       Randy Michael Ledbetter (rml), rledbetter@mail.csuchico.edu
 *  Organization:       CSU Chico Computer Science Department
 *
 * =====================================================================================
 */

#ifndef H_SHAPE
#define H_SHAPE

#include <iostream>
#include "grid.h"

class Shape
{

    public:

        Shape(int x, int y); // Shape class constructor. Initializes m_x and m_y.
        virtual ~Shape() {}

        virtual void draw(Grid &grid) = 0; // Pure Virtual Function. Must be overridden in each
                                           // class derived from this base class Shape.

    protected:

        int m_x;
        int m_y;


};

#endif

