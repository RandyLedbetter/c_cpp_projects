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
 *       Version:       4.0
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
    m_done_time = arrival_time + number_of_items;
    m_done_checkout_time = 0;
    m_money = 0;
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

int Cust::get_m_done_time()
{
    return m_done_time;
}

int Cust::get_m_money()
{
    return m_money;
}

//Mutator Functions

void Cust::set_m_done_time(int done_time)
{
    m_done_time = done_time;
}

void Cust::set_m_done_checkout_time(int done_checkout_time)
{
    m_done_checkout_time = done_checkout_time;
}

void Cust::set_m_money(int money)
{
    m_money = money;
}

//Public Member Functions

bool Cust::done_checkout(int clock)
{
    if(m_done_checkout_time == clock)
    {
        return true;
    }
    else
    {
        return false;
    }
}

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
    if(m_customer_type == "shopper")
    {
        if(m_number_of_items == 1)
        {
            os << clock << ": " << m_name << " paid $" << (m_number_of_items * 3) << " for "
            << m_number_of_items << " item to checker " << checker_number << endl;
        }
        else
        {
            os << clock << ": " << m_name << " paid $" << (m_number_of_items * 3) << " for "
            << m_number_of_items << " items to checker " << checker_number << endl;
        }
    }
    if(m_customer_type == "robber")
    {
        if(m_number_of_items == 1) 
        {
            os << clock << ": " << m_name << " stole $" << m_money
            << " and " << m_number_of_items << " item from checker " << checker_number << endl;
        }
        else
        {
            os << clock << ": " << m_name << " stole $" << m_money
            << " and " << m_number_of_items << " items from checker " << checker_number << endl;
        }
    }        
}

