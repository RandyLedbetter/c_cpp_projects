//grid.cpp
//Ledbetter, Randy
//rml

/*
 * =====================================================================================
 *
 *      Filename:       grid.cpp
 *
 *   Description:       Implementation file grid.cpp: This is the Implementation for
 *                      the class Grid.
 *                              
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

#include <iostream>


#include "grid.h"
using namespace std;

// Grid class constructor. Initializes elements of m_grid to spaces.
Grid::Grid()
{
    //Initialize the 2D array m_grid to spaces.

        for(int row = 0; row < 24; row++)
        {
            for(int column = 0; column < 60; column++)
            {
                m_grid[row][column] = ' ';
            }
        }
}


void Grid::set(int x, int y, char c)
{
    // Insert the value of the passed parameter c
    // into m_grid at coordinates x, y.

        if(x < 60 && y < 24)
        {
            m_grid[y][x] = c;
        }
}


void Grid::print()
{
    // Output elements of of the 2D array m_grid to the screen.

        for(int row = 0; row < 24; row++)
        {
            for(int column = 0; column < 60; column++)
            {
                cout << m_grid[row][column];
            }

            cout << endl;
        }
}
