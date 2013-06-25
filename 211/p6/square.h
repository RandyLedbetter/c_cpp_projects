//square.h
//Ledbetter, Randy
//rml

/*
 * =====================================================================================
 *
 *      Filename:       square.h
 *
 *   Description:       Header file shapes.h: This is the Definition/Interface for
 *                      the Base Class Square.
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

#ifndef H_SQUARE
#define H_SQUARE



#include "shape.h"


class Square : public Shape
{

    public:

        Square(int x, int y, int size) : Shape(x, y) {m_size = size;}
        ~Square() {}

        virtual void draw(Grid &grid)
        {
            for(int row = m_y; row < (m_y + m_size); row++)
            {
                if(row == m_y || row == (m_y + m_size - 1))
                {
                    for(int index = m_x; index < (m_x + m_size); index++)
                    {
                        grid.set(index, row, '*');
                    }
                }
                else
                {
                    grid.set( m_x, row,  '*');
                    grid.set((m_x + m_size - 1), row,  '*');
                }
            }
        }

    private:

        int m_size;

};
#endif
