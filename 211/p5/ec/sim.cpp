//sim.cpp
//Ledbetter, Randy
//rml

/*
 * =====================================================================================
 *
 *      Filename:       sim.cpp
 *
 *   Description:       Application file sim.cpp: This is the Application/Driver for
 *                      the class Cust and for the Project 5 "Kwik E Mart Simulation"
 *                      Extra Credit.
 *       Version:       2.0
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
#include "pqueue.h"

using namespace std;


//Returns true if the character string contains only digits.
//Otherwise, the function returns false.
bool legal_int(char *str);

//Runs the Kwik E Mart simulation for Project 5
void run_simulation(Pqueue &arrival_queue, int num_checkers, ostream &os);

//Outputs the int values contained with the array registers[] to
//the output stream specified by os
void print_register_totals(ostream &os, int registers[], int size);


int main(int argc, char *argv[])
{
    //Declare and initialize local variables

        int number_of_checkers = 0, input_value = 0, arrival_time = 0, number_of_items = 0;
        string input_string, name, customer_type, input_filename, output_filename;

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
            input_filename = argv[2];
            cerr << "Error: could not open input file <" << input_filename << ">." << endl;
            exit(1);
        }

    //Open output file specified by argv[3].

        ofstream output_file(argv[3], ios::out);

    //If 'output_file cannot be opened, issue error and exit program.

        if(!output_file)
        {
            output_filename = argv[3];
            cerr << "Error: could not open output file <" << output_filename << ">." << endl;
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

    //Read in input from 'input_file' until EOF

        Pqueue arrival_q;

        while(input_file >> input_string)
        {
            name = input_string;
            input_file >> input_string;
            customer_type = input_string;
            input_file >> input_value;
            arrival_time = input_value;
            input_file >> input_value;
            number_of_items = input_value;

            //Instantiate a Cust object initialized to input data

                Cust *new_customer = new Cust(name, customer_type, arrival_time, number_of_items);
            
            //Insert new customer into arrival_q by arrival time as a test

                arrival_q.insert_by_priority(arrival_time, new_customer);
        }
            
        run_simulation(arrival_q, number_of_checkers, output_file);

    return 0;
}

//Function Definitions

bool legal_int(char *str)
{
    int i = 0;

    for(i = 0; str[i]; i++)
    {
        if(!(isdigit(str[i])))
        {
            return false;
        }
    }

    return true;
}

void run_simulation(Pqueue &arrival_queue, int num_checkers, ostream &os)
{
    //Declare and initialize local variables and arrays

        int num_customers = arrival_queue.size();
        int i = 0, clock = 1, cust_at_checker = 0, shortest_queue = 0, queue_length = 0;
        Cust **checkers = new Cust*[num_checkers];
        int *register_totals = new int[num_checkers];
        Pqueue shopping_queue;
        Pqueue *checker_queues = new Pqueue[num_checkers];

    //Initialize checkers and resister_totals

        for(i = 0; i < num_checkers; i++)
        {
            checkers[i] = NULL;
            register_totals[i] = 100;
        }

    //Begin Kwik E Mart Simulation

    for(clock = 1; num_customers > 0; clock++)
    {
        for(i = 0; i < num_checkers; i++)
        {
            if(checkers[i] != NULL && checkers[i]->done_checkout(clock))
            {
                checkers[i]->print_finished_checkout(os, clock, i);
                delete checkers[i];
                num_customers--;
                checkers[i] = NULL;
            }
        }
        
        while((!arrival_queue.empty()) && arrival_queue.get_first_priority() == clock)
        {
            Cust *customer = arrival_queue.dequeue();
            customer->print_enters_store(os, clock);
            shopping_queue.insert_by_priority(customer->get_m_done_time(), customer);
        }

        while((!shopping_queue.empty()) && shopping_queue.get_first_priority() == clock)
        {
            Cust *customer = shopping_queue.dequeue();


            if(checkers[0] == NULL)
            {
                cust_at_checker = 0;
            }
            else
            {
                cust_at_checker = 1;
            }

            shortest_queue = 0;
            queue_length = checker_queues[0].size() + cust_at_checker;

            for(i=1; i < num_checkers; i++)
            {
                if(checkers[i] == NULL)
                {
                    cust_at_checker = 0;
                }
                else
                {
                    cust_at_checker = 1;
                }

                if((checker_queues[i].size() + cust_at_checker) < queue_length)
                {
                    shortest_queue = i;
                    queue_length = checker_queues[i].size() + cust_at_checker;
                }
            }

            customer->print_finished_shopping(os, clock, shortest_queue);
            checker_queues[shortest_queue].insert_by_priority(1, customer);
        }
       
        for(i=0; i < num_checkers; i++)
        { 
            if(checkers[i] == NULL && (!checker_queues[i].empty()))
            {
                Cust *customer =  checker_queues[i].dequeue();
                checkers[i] = customer;
                int checkout_time = 0;
                customer->print_started_checkout(os, clock, i); 
                if(customer->get_m_customer_type() == "shopper")
                {
                    register_totals[i] = register_totals[i] + (3 * customer->get_m_number_of_items());
                    checkout_time = clock + (2 * (customer->get_m_number_of_items()));
                    customer->set_m_done_checkout_time(checkout_time);
                }
                else
                {   
                    customer->set_m_money(register_totals[i]);
                    register_totals[i] = 0;
                    checkout_time = clock + 2;
                    customer->set_m_done_checkout_time(checkout_time);
                }
            }
        } 
        

    }

    print_register_totals(os, register_totals, num_checkers);
 
}


void print_register_totals(ostream &os, int registers[], int size)
{
    for(int index = 0; index < size; index++)
    {
        os << "registers[" << index << "] = $" << registers[index] << endl;
    }
}

