//cust.cpp
//Ledbetter, Randy
//rml

/*
 * =====================================================================================
 *
 *      Filename:       cust.cpp
 *
 *   Description:       Implemtation file cust.cpp: This is the Implementation for
 *                      the class Cust.
 *       Version:       1.0
 *       Created:       Thu 18 Oct 2012 12:12:18 PM PDT
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

#include "cust.h"

using namespace std;

//Class Cust Constructor
Cust::Cust(string name, string customer_type, int arrival_time, int number_of_items)
{
    m_name = name;
    m_arrival_time = arrival_time;
    m_number_of_items = number_of_items;
    m_customer_type = customer_type;
}

//Accessor Functions

string Cust::get_m_name()
{
    return m_name;
}

string Cust::get_m_customer_type()
{
    return m_customer_type;
}

int Cust::get_m_arrival_time()
{
    return m_arrival_time;
}

int Cust::get_m_number_of_items()
{
    return m_number_of_items;
}

//Public Member Functions

void Cust::print_enters_store(ostream &os, int clock)
{
    os << clock << ": " << m_name << " entered store" << endl;
}

void Cust::print_finished_shopping(ostream &os, int clock)
{
    os << clock << ": " << m_name << " done shopping" << endl;
}

void Cust::print_started_checkout(ostream &os, int clock, int checker_number)
{
    os << clock << ": " << m_name << " started checkout with checker " << checker_number << endl;
}

void Cust::print_finished_checkout(ostream &os, int clock, int checker_number)
{
    os << clock << ": " << m_name << " paid $" << (m_number_of_items * 3) << " for "
       << m_number_of_items << " to checker " << checker_number << endl;
}

void Cust::print_finished_stealing(ostream &os, int clock, int checker_number, int amount_stolen)
{
    os << clock << ": " << m_name << " stole $" << ((m_number_of_items * 3) + amount_stolen)
       << " and " << m_number_of_items << " from checker " << checker_number << endl;
}

void Cust::print_register_totals(ostream &os, char registers[], int size)
{
    for(int index = 0; index < size; index++)
    {
        os << "resisters[" << index << "] = $" << registers[index] << endl;
    }
}

