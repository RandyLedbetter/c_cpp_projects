//grid.h
//Ledbetter, Randy
//rml

/*
 * =====================================================================================
 *
 *      Filename:       grid.h
 *
 *   Description:       Header file grid.h: This is the Definition/Interface for
 *                      the Class Grid.
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

#ifndef H_GRID
#define H_GRID

#include <iostream>

class Grid
{
    public:

        Grid(); // Grid class constructor. Initializes elements of m_grid to spaces.
        ~Grid() {}

        void set(int x, int y, char c);
        //Precondition:     An object of type Grid has been instantiated and parameters
        //                  x, y, and c have been initialized and passed to set.
        //Postcondition:    A character matching the character passed in as parameter
        //                  c has been inserted into the private 2D array m_grid at
        //                  the row and column intersection specified by the parameters
        //                  x and y.

        void print();
        //Precondition:     An object of type Grid has been instantiated.
        //Postcondition:    The array, m_grid, has been printed to the screen.

    private:

        char m_grid[24][60];


};

#endif
