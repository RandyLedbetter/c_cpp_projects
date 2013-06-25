//triangle.h
//Ledbetter, Randy
//rml

/*
 * =====================================================================================
 *
 *      Filename:       triangle.h
 *
 *   Description:       Header file shapes.h: This is the Definition/Interface for
 *                      the Base Class Triangle.
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

#ifndef H_TRIANGLE
#define H_TRIANGLE




#include "shape.h"


class Triangle: public Shape, public Grid
{
    public:

        Triangle(int x, int y) : Shape(x, y) { /* Intentially Empty */ }
        ~Triangle() {}

        virtual void draw(Grid &grid)
        {
            grid.set(m_x + 2, m_y, '+');
            grid.set(m_x + 1, m_y + 1, '+');
            grid.set(m_x + 3, m_y + 1, '+');
            for(int count = m_x; count < m_x + 5; count++)
            {
                grid.set(count, m_y + 2, '+');
            }
        }
};

#endif
