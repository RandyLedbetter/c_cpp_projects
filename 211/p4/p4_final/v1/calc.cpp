//calc.cpp
//Ledbetter, Randy
//rml

/*
 * =====================================================================================
 *
 *      Filename:       calc.cpp
 *
 *   Description:       Application file calc.cpp: This is the Application for the
 *                      Project 4 "Postfix Calculator".
 *       Version:       1.0
 *       Created:       Fri 05 Oct 2012 03:22:15 PM PDT
 *      Revision:       none
 *      Compiler:       gcc/g++
 *
 *        Author:       Randy Michael Ledbetter (rml), rledbetter@mail.csuchico.edu
 *  Organization:       CSU Chico Computer Science Department
 *
 * =====================================================================================
 */

#include <iostream>
#include <cstdlib> //for exit()
#include <cstdio>
#include "dstack.h"

using namespace std;



int main()
{

    //Declare and initialize local variables

        char input;
        double number = 0.0, number_1 = 0.0, number_2 = 0.0, result = 0.0;
        size_t found;
        bool valid = true;

        char input_string[80];

        string operator_array ("+-*/^.");

        Dstack math_stack;

    //Validate and read-in postfix expression

        while ((input = cin.peek()) != EOF && valid == true)
        {
            if (isdigit(input))
            {  // cout << "Inside isdigit() if statement" << endl;
                cin >> number;
                math_stack.push(number);
                
                if (cin.peek() == '.')
                {
                    cin.ignore();
                }
            }
            else if ((found = operator_array.find(input)) != (string::npos))
            {
               // cout << "Inside operator_array.find else if statement" << endl;
               // cout << "Found = " << int(found) << endl;
                cin >> input;
                switch (int(found))
                {
                    case 0: //Addition Sign Entered

                                break;
                        
                    case 1: //Subtraction Sign Entered


                                break;


    return true;
}
