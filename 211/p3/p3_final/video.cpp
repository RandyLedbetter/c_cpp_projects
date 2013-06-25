//video.cpp
//Ledbetter, Randy
//rml

/*
 * =====================================================================================
 *
 *      Filename:       video.cpp
 *
 *   Description:       Implementation file video.cpp: This is the Implementation for
 *                      the class Video.
 *                              
 *       Version:       3.0
 *       Created:       Thu 13 Sep 2012 12:02:21 PM PDT
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

#include "video.h"
using namespace std;

//Constructor Definition

    Video::Video(string title, string url, string comment, float length, int rating)
    {
        m_title = title;
        m_url = url;
        m_comment = comment;
        m_length = length;
        m_rating = rating;
    }

//Public Member Function Definitions

    void Video::print_video_info()
    {
    
        //Declare and Initialize Local Variables

            int count = 0;

        
                cout << m_title << ", " << m_url 
                     << ", " << m_comment << ", " 
                     << m_length << ", ";

                //Convert the Value of m_rating to an Equal Number of Asterisks.
                    for (count = 0; count < m_rating; count++)
                    {   
                    cout << "*";
                    }   
           
                cout << endl;
    }
    

//Public Non-Member Friend Function Definitions
       
    void read_videos(Video *video_list[], const int MAX, string &sorting_method)
    {
        //Declare local variables.

            int index = 0, rating = 0;
            float length = 0.0;
            string input_string, title, url, comment;
            string video_rating = "rating";
            string video_length = "length";
            string video_title  = "title";

        //Read-In Sorting Method.

            getline(cin, input_string);
            sorting_method = input_string;
            
        //Test the Validity of Read-In sorting_method and Output an
        //Error Message if the Input is InValid

            if ((sorting_method != video_rating) && (sorting_method != video_length)
                && (sorting_method != video_title))
                {
                    cerr << sorting_method
                         << " is not a legal sorting method, giving up." << endl;
                    
                    //Terminate Program with Error Status
                        
                        exit(1);
                }

            

        //Read-in up to MAX video descriptions. Assign the read-in title,
        //url, comment, length, and rating to the corresponding member
        //variables of each dynamically-created Video object.

            while (getline(cin,input_string))
            {
              //Test for more then MAX videos being entered.

                if(index ==  MAX)
                {
                    cerr << "Too many videos, giving up." << endl;
                    exit(1);
                }


              title = input_string;
              getline(cin, input_string);
              url = input_string;
              getline(cin, input_string);
              comment = input_string;
              cin >> length;
              cin >> rating;
                    
                       
              //Get rid of extraneous live feed.

                cin.ignore();
                               
              
              video_list[index] = new Video(title, url, comment, length, rating);
  
              index++;
              
              
                           
            }
    } 

    void swap_videos(Video  *&video_a, Video *&video_b)
    {
        //Declare and initialize local variables.

            Video *temp = NULL;
       
            temp = video_a;
            video_a = video_b;
            video_b = temp;
    }
 
    void sort_videos_by_method(Video *video_list[], const int MAX, string sorting_method)
    {
        //Declare and initialize local variables.

            int index, index2;
            bool swapped = true;           
          
          

        //Start sorting video_list[] using the method specified by the value of the
        //passed parameter sorting_method.

            if (sorting_method == "rating")
            {   
                while(swapped)
                {
                    swapped = false;
                        
                    for (index2 = MAX - 1; index2 > 0; index2--)
                    {
                        for (index = 0; index < index2 && video_list[index + 1] != NULL; index++)
                        {
                            if (video_list[index]->get_rating() < video_list[index + 1]->get_rating())
                            { 
                                swap_videos(video_list[index], video_list[index + 1]);
                                swapped = true;
                            }
                         }   
                     }
                } 
            }
            
            
            if (sorting_method == "length")
            {   
                swapped = true;

                while(swapped)
                {
                    swapped = false;
                        
                    for (index2 = MAX - 1; index2 > 0; index2--)
                    {
                        for (index = 0; index < index2 && video_list[index + 1] != NULL; index++)
                        {
                            if (video_list[index]->get_length() > video_list[index + 1]->get_length())
                            { 
                                swap_videos(video_list[index], video_list[index + 1]);
                                swapped = true;
                            }
                         }   
                     }
                } 
            }


            if (sorting_method == "title")
            {   
                swapped = true;
    
                while(swapped)
                {
                    swapped = false;
                        
                    for (index2 = MAX - 1; index2 > 0; index2--)
                    {
                        for (index = 0; index < index2 && video_list[index + 1] != NULL; index++)
                        {
                            if (video_list[index]->get_title() > video_list[index + 1]->get_title())
                            { 
                                swap_videos(video_list[index], video_list[index + 1]);
                                swapped = true;
                            }
                         }   
                     }
                } 
            }

    }

    void print(Video *video_list[], const int MAX)
    {
        //Declare and Initialize Local Variables.

            int index = 0;

        //Call the Member Function print_video_info() to Print the Sorted Video Descriptions
        //to the Screen to Conform to the Project Guidelines.    

        
            for(index = 0; (index < MAX) && (video_list[index] != NULL) ; index++)
            {
                video_list[index]->print_video_info();
            }
    }

//Public Accessor Function Definitions

    int Video::get_rating()
    {
        return m_rating;
    }


    float Video::get_length()
    {
        return m_length;
    }

    
    string Video::get_title()
    {
        return m_title;
    }

    
    string Video::get_url()
    {
        return m_url;
    }

    
    string Video::get_comment()
    {
        return m_comment;
    }
