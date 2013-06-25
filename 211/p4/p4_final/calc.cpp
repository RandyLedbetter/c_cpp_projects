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
#include <cctype> //for isdigit()
#include <cmath>
#include "dstack.h"

using namespace std;

//Function Declarations

bool get_operands(double &number_1, double &number_2, Dstack &stack);

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
                
                                if ((valid = get_operands(number_1, number_2, math_stack)))
                                {  // cout << "Inside Addition case" << endl;
                                    result = number_1 + number_2;
                                    math_stack.push(result);
                                }

                                break;
                        
                    case 1: //Subtraction Sign Entered

                                if ((valid = get_operands(number_1, number_2, math_stack)))
                                {
                                    result = number_1 - number_2;
                                    math_stack.push(result);
                                }

                                break;

                    case 2: //Multiplication Sign Entered

                                if ((valid = get_operands(number_1, number_2, math_stack)))
                                {
                                    result = number_1 * number_2;
                                    math_stack.push(result);
                                }

                                break;

                    case 3: //Division Sign Entered

                                if ((valid = get_operands(number_1, number_2, math_stack)))
                                {
                                    if (number_2 == 0) // Check for possible division by zero
                                    {
                                        valid = false;
                                    }
                                    else
                                    {
                                        result = number_1 / number_2;
                                        math_stack.push(result);
                                    }
                                }

                                break;
        
                    case 4: //Power Sign Entered

                                if ((valid = get_operands(number_1, number_2, math_stack)))
                                {
                                    result = pow(number_1, number_2);
                                    math_stack.push(result);
                                   // cout << "pow result = " << result << endl;
                                }

                                break;

                    case 5: //Decimal Point Entered
                
                               
                                if(isdigit(cin.peek()))
                                {
                                    cin.unget(); //Return decimal point to input stream
                                    cin >> input_string;
                                    
                                    number = atof(input_string);

                                    if ((number >= 0.0))
                                    {
                                        math_stack.push(number);
                                    }
                                }
                                else
                                {
                                        valid = false;
                                }
            
                                break;

    
                    default: //Do Nothing

                                break;

                } //End switch block

            
                if (!valid)
                {
                    cerr << "Error: Invalid expression." << endl;
                    exit(1); //Terminate program with error status.
                }
            }
            else
            {
                //Other Character or White Space Entered.
                   // cout << "Inside cin.ignore condition" << endl;
                    if (isalpha(input))
                    {
                        valid = false;
                    }
                    else
                    {               
                        cin.ignore();
                    }
            }
        } //End of while loop.

        if(math_stack.valid_result())
        {  // cout << "Inside valid result condition" << endl;
            result = math_stack.pop();
            cout << result << endl;
        }
        else
        {
            cerr << "Error: Invalid expression." << endl;
            exit(1); //Terminate program with error status.
        }


return 0;
}

bool get_operands(double &number_1, double &number_2, Dstack &stack)
{
    //Declare and initialize local variables

    int count = 1;

    for (count = 1; count <= 2; count++)
    {
        if (stack.empty())
        {
            return false;
        }
        else if (count == 1)
        {
            number_2 = stack.pop();
        }
        else
        {
            number_1 = stack.pop();
        }
    }

    return true;
}
