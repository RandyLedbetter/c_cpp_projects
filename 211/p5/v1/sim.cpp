//sim.cpp
//Ledbetter, Randy
//rml

/*
 * =====================================================================================
 *
 *      Filename:       sim.cpp
 *
 *   Description:       Application file sim.cpp: This is the Application/Driver for
 *                      the class Cust and for the Project 5 "Kwik E Mart Simulation".
 *       Version:       1.0
 *       Created:       Thu 18 Oct 2012 08:29:38 PM PDT
 *      Revision:       none
 *      Compiler:       gcc/g++
 *
 *        Author:       Randy Michael Ledbetter (rml), rledbetter@mail.csuchico.edu
 *  Organization:       CSU Chico Computer Science Department
 *
 * =====================================================================================
 */

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

#include "cust.h"

using namespace std;


//Returns true is the character string contains only digits.
//Otherwise, the function returns false.
bool legal_int(char *str);


int main(int argc, char *argv[])
{
    //Declare and initialize local variables

        int number_of_checkers = 0;

    //Make sure a valid number of command line arguments were entered.

        if (argc != 4)
        {
            cerr << "Error: invalid number of command line arguments." << endl;
            exit(1);
        }

    //Open input file specified by argv[2].

        ifstream input_file(argv[2], ios::in);

    //If 'input_file' cannot be opened, issue error and exit program.

        if(!input_file)
        {
            cerr << "Error: could not open input file <" << input_file << ">." << endl;
            exit(1);
        }

    //Open output file specified by argv[3].

        ofstream output_file(argv[3], ios::out);

    //If 'output_file cannot be opened, issue error and exit program.

        if(!output_file)
        {
            cerr << "Error: could not open output file <" << output_file << ">." << endl;
            exit(1);
        }

    //Check that a valid number of checkers has been entered.
    //If not, issue error and exit program.

        if(legal_int(argv[1]))
        {
            number_of_checkers = atoi(argv[1]);
        }
    
        if(number_of_checkers < 1)
        {
            cerr << "Error: invalid number of checkers specified." << endl;
            exit(1);
        }

    return 0;
}


bool legal_int(char *str)
{
    int i = 0;

    for(i = 0; str[i]; i++)
    {
        
           // cout << "str = " << str << endl;
        if(!(isdigit(str[i])))
        {//cout << "insided isdigit fail condition" << endl;
            return false;
        }

    }

    return true;

}

