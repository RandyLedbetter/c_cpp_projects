//routes.cpp
//Ledbetter, Randy
//rml

/*
 * =====================================================================================
 *
 *      Filename:       routes.cpp
 *
 *   Description:       Application file routes.cpp: This is the Application/Driver for
 *                      the class Cust and for the Project 7 "Shipping Routes".
 *       Version:       4
 *       Created:       11/19/2012
 *      Revision:       none
 *      Compiler:       gcc/g++
 *
 *        Author:       Randy Michael Ledbetter (rml), rledbetter@mail.csuchico.edu
 *  Organization:       CSU Chico Computer Science Department
 *
 * =====================================================================================
 */

#include <iostream>
#include <limits>
#include <cstdlib>

using namespace std;

#include "stree.h"

// Function Declarations

void print_lookup_results(string target, string parent, int parent_distance,
                        string left_child, int left_child_distance,
                        string right_child, int right_child_distance);


int main()
{
    Stree routes;
    string command, origination, destination, target, parent, left_child, right_child, city;
    int distance = 0, parent_distance = 0, left_child_distance = 0, right_child_distance = 0;
    vector<string> path;
    

    while(cin >> command)
    {
        if(command == "insert")
        {
            cin >> origination;
            cin >> destination;
            cin >> distance;

            if(!routes.insert(origination, destination, distance))
            {
                cerr << "Error: could not insert " << origination << ", " << destination << endl;
            }
        }

        else if(command == "lookup")
        {
            cin >> target;

            if(routes.lookup(target, parent, parent_distance, left_child, left_child_distance,
                             right_child, right_child_distance))
            {
                print_lookup_results(target, parent, parent_distance, left_child, left_child_distance,
                                     right_child, right_child_distance);
            }
            else
            {
                cerr << "Error: " << target << " not in tree" << endl;
            }
        }

        else if(command == "path")
        {
            cin >> origination;
            cin >> destination;

            if(routes.get_path(origination, destination, path))
            {
                cout << path[0];

                for(vector<string>::iterator iter = path.begin() + 1;
                    iter != path.end();
                    iter++)
                {
                    cout << " --> " << *iter ;
                }

                cout << endl;
            }
            else
            {
                cerr << "Error: no path between " << origination << " and " << destination << endl;
            }
        }

        else if(command == "distance")
        {
            cin >> origination;
            cin >> destination;

            if(routes.get_distance(origination, destination, distance))
            {
                if(distance == 1)
                {
                    cout << origination << " to " << destination << " is " << distance << " mile" << endl;
                }
                else
                {
                    cout << origination << " to " << destination << " is " << distance << " miles" << endl;
                }
            }
            else
            {
                cerr << "Error: no path between " << origination << " and " << destination << endl;
            }
        }

        else if(command == "remove")
        {
            cin >> city;

            if(!routes.remove(city))
            {
                cerr << "Error: could not remove " << city << endl;
            }
        }

        else
        {
            cerr << "Error: <" << command << "> is not a valid command" << endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }


            
            
    }


    return 0;
}



void print_lookup_results(string target, string parent, int parent_distance,
                        string left_child, int left_child_distance,
                        string right_child, int right_child_distance)
{

    if(parent == "none" && left_child != "none" && right_child != "none")
    {
        cout << target << ": none, " << left_child << "(" << left_child_distance << "), "
             << right_child << "(" << right_child_distance << ")" << endl;
    }
    else if(parent != "none" && left_child == "none" && right_child != "none")
    {
        cout << target << ": " << parent << "(" << parent_distance << "), none, "
             << right_child << "(" << right_child_distance << ")" << endl;
    }
    else if(parent != "none" && left_child != "none" && right_child == "none")
    {
        cout << target << ": " << parent << "(" << parent_distance << "), "
             << left_child << "(" << left_child_distance << "), none" << endl;
    }
    else if(parent == "none" && left_child == "none" && right_child != "none")
    {
        cout << target << ": none, none, " << right_child << "(" << right_child_distance
             << ")" << endl;
    }
    else if(parent != "none" && left_child == "none" && right_child == "none")
    {
        cout << target << ": " << parent << "(" << parent_distance << "), none, none" << endl;
    }
    else if(parent == "none" && left_child != "none" && right_child == "none")
    {
        cout << target << ": none, " << left_child << "(" << left_child_distance
             << "), none" << endl;
    }
    else if(parent == "none" && left_child == "none" && right_child == "none")
    {
        cout << target << ": none, none, none" << endl;
    }
    else
    {
        cout << target << ": " << parent << "(" << parent_distance << "), "
             << left_child << "(" << left_child_distance << "), " << right_child
             << "(" << right_child_distance << ")" << endl;
    }
}
