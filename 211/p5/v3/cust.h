//cust.h
//Ledbetter, Randy
//rml

/*
 * =====================================================================================
 *
 *      Filename:       cust.h
 *
 *   Description:       Header file cust.h: This is the Definition/Interface for
 *                      the class Cust.
 *       Version:       3.0
 *       Created:       Thu 18 Oct 2012 11:45:28 AM PDT
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

using namespace std;

#ifndef CUST_H
#define CUST_H

class Cust
{
    public:

        //Class Constructor

            Cust(string name, string customer_type, int arrival_time, int number_of_items);

        //Accessor Functions

            string get_m_name();
            string get_m_customer_type();
            int get_m_arrival_time();
            int get_m_number_of_items();

        //Public Member Functions

            void print_enters_store(ostream &os, int clock);
            void print_finished_shopping(ostream &os, int clock);
            void print_started_checkout(ostream &os, int clock, int checker_number);
            void print_finished_checkout(ostream &os, int clock, int checker_number);
            void print_finished_stealing(ostream &os, int clock, int checker_number,
                                         int amount_stolen);
            void print_register_totals(ostream &os, char registers[], int size);
            void print_test();
    private:

        string m_name;
        int m_arrival_time;
        int m_number_of_items;
        string m_customer_type;
        int m_done_time;
};

#endif



