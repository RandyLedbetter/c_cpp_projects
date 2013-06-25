//circle.h
//Ledbetter, Randy
//rml

/*
 * =====================================================================================
 *
 *      Filename:       circle.h
 *
 *   Description:       Header file shapes.h: This is the Definition/Interface for
 *                      the Base Class Circle.
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

#ifndef H_CIRCLE
#define H_CIRCLE



#include "shape.h"


class Circle : public Shape
{

    public:

        Circle(int x, int y) : Shape(x, y) { /* Intentially Empty */ }
        ~Circle() {}

        virtual void draw(Grid &grid)
        {
            grid.set(m_x + 1, m_y, 'o');
            grid.set(m_x + 2, m_y, 'o');
            grid.set(m_x, m_y + 1, 'o');
            grid.set(m_x + 3, m_y + 1, 'o');
            grid.set(m_x, m_y + 2, 'o');
            grid.set(m_x + 3, m_y + 2, 'o');
            grid.set(m_x + 1, m_y + 3, 'o');
            grid.set(m_x + 2, m_y + 3, 'o');            

        }


};

#endif
