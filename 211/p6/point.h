//point.h
//Ledbetter, Randy
//rml

/*
 * =====================================================================================
 *
 *      Filename:       point.h
 *
 *   Description:       Header file shapes.h: This is the Definition/Interface for
 *                      the Base Class Point.
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

#ifndef H_POINT
#define H_POINT



#include "shape.h"


class Point : public Shape
{

    public:

        Point(int x, int y, char c) : Shape(x, y) { m_c = c;}
        ~Point() {}
 

        virtual void draw(Grid &grid)
        {
            grid.set(m_x, m_y, m_c);
        }

    private:

        char m_c;

};

#endif
