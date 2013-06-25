//main.cpp
//Ledbetter, Randy
//rml

/*
 * =====================================================================================
 *
 *      Filename:       main.cpp
 *
 *   Description:       Application file main.cpp: This file serves as the driver
 *                      program for the Project 3 "Linked List of Video Objects" assignment.
 *
 *       Version:       3.0
 *       Created:       Thu 13 Sep 2012 12:31:01 PM PDT
 *      Revision:       none
 *      Compiler:       gcc/g++
 *
 *        Author:       Randy Michael Ledbetter (rml), rledbetter@mail.csuchico.edu
 *  Organization:       CSU Chico Computer Science Department
 *
 * =====================================================================================
 */

#include <iostream>
#include <cstdlib>
#include <string>
#include <cassert>
#include <regex.h>
#include "video.h"
#include "vlist.h"

using namespace std;



int main()
{
    //Declare and Initalize Local Variables.
    
    bool error_state = false;

    int rating = 0, number_of_videos = 0;
    float length = 0.0;

    string command, input_string, title, url, comment;
    string video_rating = "rating";
    string video_length = "length";
    string video_title  = "title";
    string expression;

    Vlist vlist;
    Vlist vlist_copy;
   

    //Read input
   
        while(getline(cin, command))
        {
            //Determine which command was entered

            if (command == "insert")
            {
              getline(cin, input_string);
              title = input_string;
              getline(cin, input_string);
              url = input_string;
              getline(cin, input_string);
              comment = input_string;
              cin >> length;
              cin >> rating;


              //Get rid of extraneous live feed.
          
                 cin.ignore();

                 error_state = vlist.insert(title, url, comment, length, rating);

                 if (error_state)
                 {
                    cerr << "Could not insert video <" << title << ">, already in list." << endl;
                 }
            }
            else if (command == "print")
            {
                //Print all videos in the list to the screen
                    
                    vlist.print();
            }
            else if (command == "length")
            {
                //Count all the videos in the list and return the number

                    number_of_videos =  vlist.length();

                //Output the number of videos in the list to the screen

                    cout << number_of_videos << endl;
            }
            else if (command == "lookup")
            {
                //Get the title from input stream
                    
                    getline(cin, title);

                //Check to see if the title is in the video list. Print the video information
                //if it is, otherwise make error_state equal to true.

                    error_state = vlist.lookup(title); 

                //If the title was not in the list, issue an error message

                    if (error_state)
                    {
                        cerr << "Title <" << title << "> not in list." << endl;
                        exit(0);
                        
                    }
            }
            else if (command == "remove")
            {

                //Get the title from input stream
                    
                    getline(cin, title);
                
                error_state = vlist.remove(title);

                if (error_state)
                {
                    cerr << "Title <" << title << "> not in list, could not delete." << endl;
                }
            }
            else if (command == "print_by_length")
            {
                //make copy of vlist and sort the list by video length
                    
                   

                    

                    
            }
            else if (command == "print_by_rating")
            {
                //make copy of vlist and sort the list by video rating

                   

                    
            }
            else if (command == "lookup_expression")
            {
                //Get input regular expression

                    getline(cin, expression);

                    error_state = vlist.lookup_expression(expression);

                    if (!error_state)
                    {
                        cerr << "Regular expression <" << expression << "> does not match "
                             << "any titles in list." << endl;
                    }
            }
            else
            {
                //Invalid command. Print error message to the screen and end program.

                    cerr << "<" << command << "> is not a legal command, giving up." << endl;
                    exit(1);//Terminate program with error status.
            }
        }

    return 0;
}



