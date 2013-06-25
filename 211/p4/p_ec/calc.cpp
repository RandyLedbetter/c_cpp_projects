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
 *       Version:       4.0
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
#include <cassert>
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
        int index = 0, count = 0;
            

        char input_string[80];
        string temp, string_copy;
        string sqr_root = "sqrt";
        string sine = "sin";
        string cosine = "cos";
        string average = "ave";

        string operator_array ("+-*/^.");

        Dstack math_stack;

    //Validate and read-in postfix expression

        while ((input = cin.peek()) != EOF && valid == true)
        {
            if (isdigit(input))
            { 
                cin >> number;
                math_stack.push(number);
                
                if (cin.peek() == '.')
                {
                    cin.ignore();
                }
            }
            else if ((found = operator_array.find(input)) != (string::npos))
            {
                cin >> input;
                switch (int(found))
                {
                    case 0: //Addition Sign Entered
                
                                if ((valid = get_operands(number_1, number_2, math_stack)))
                                {  
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
                                }

                                break;

                    case 5: //Decimal Point Entered
                
                               
                                if (isdigit(cin.peek()))
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
            else if (input == 's')
            {
                if (input == 's')
                {
                    cin >> input;

                    if (cin.peek() == 'i')
                    {
                        cin.unget();
                        char *input_string = new char[4];

                        for (index = 0; index < 3; index++)
                        {
                            cin >> input;
                            input_string[index] = input;
                        }

                        input_string[3] = '\0';
    
                        string_copy = input_string;
                        delete [] input_string;
                        if (string_copy == "sin" && (!math_stack.empty()))
                        {
                            number = math_stack.pop();
                            result = sin(number * (M_PI/180));
                            math_stack.push(result);
                        }
                    }
                    else if (cin.peek() == 'q')
                    {
                        cin.unget();
                        char *input_string = new char[5];
    
                        for(index = 0; index < 4; index++)
                        {
                            cin >> input;
                            input_string[index] = input;
                        }
                        
                        input_string[4] = '\0';
                        string_copy = input_string;
                        delete [] input_string;

                        if (string_copy == "sqrt" && (!math_stack.empty()))
                        {
                            number = math_stack.pop();
            
                            if (number > 0)
                            {
                            result = sqrt(number);
                            math_stack.push(result);
                            }
                            else
                            {
                                cerr << "Error: Invalid expression." << endl;
                                exit(1); //Terminate program with error status.             
                            }
                        }
                        else
                        {
                            cerr << "Error: Invalid expression." << endl;
                            exit(1); //Terminate program with error status.
                        }
                    }
                    else
                    {
                        valid = false;
                    }
                }
            }
            else if ( input == 'a')
            {
                char *input_string = new char[4];

                for(index = 0; index < 3; index++)
                {
                    cin >> input;
                    input_string[index] = input;
                }
        
                input_string[3] = '\0';

                string_copy = input_string;
                delete [] input_string;

                if (string_copy == "ave" && (!math_stack.empty()))
                {
                    count = 0;
                    number = 0.0;

                    while(!math_stack.empty())
                    {
                        number = number +( math_stack.pop()); 
                        count++;
                    }
                
                    result = number/count;
                    math_stack.push(result);
                }
                else
                {
                    valid = false;
                }
            }
            else if (input == 'c')
            {
                char *input_string = new char[4];

                for(index = 0; index < 3; index++)
                {
                    cin >> input;
                    input_string[index] = input;
                }
        
                input_string[3] = '\0';

                string_copy = input_string;
                delete [] input_string;

                if (string_copy == "cos" && (!math_stack.empty()))
                {
                    number = math_stack.pop();
                    result = cos(number * (M_PI/180));
                    math_stack.push(result);
                }
                else
                {
                    valid = false;
                }
            }   
            else
            {
                //Other Character or White Space Entered.
                      
                    cin.ignore();
            }


        } //End of while loop.

        if(math_stack.valid_result())
        {
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
