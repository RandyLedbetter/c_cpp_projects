//main.cpp
//Ledbetter, Randy
//rml

/*
 * =====================================================================================
 *
 *      Filename:       main.cpp
 *
 *   Description:       Application file main.cpp: This file serves as the driver
 *                      program for the Project 3 "Video Rating System" assignment.
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

#include "video.h"
using namespace std;

//Declare and Initialize Global Constants.
const int MAX = 100;

int main()
{
    //Declare and Initalize Local Variables.

        string sorting_method;
        Video *video_list[MAX];

        //Initialize video_list[]
        int index = 0;
        for(index = 0; index < MAX; index++)
        {
            video_list[index] = NULL;
        }

    
    //Call the Function read_videos() to Create an Array of Pointers to
    //Objects of type Video, Read-In Video Information Sequentially, and
    //Dynamically Create an Object for each Video Read-In.

        read_videos(video_list, MAX, sorting_method);


    //Call the Function sort_videos_by_method() to Sort the Video Descriptions
    //Pointed to by video_list[] in Accordance with the Filter Set by sorting_method.

        sort_videos_by_method(video_list, MAX, sorting_method);


    //Call the Function print() to Print the Sorted Video Descriptions
    //to the Screen to Conform to the Project 3 Guidelines.    

        print(video_list, MAX);

    return 0;
}



