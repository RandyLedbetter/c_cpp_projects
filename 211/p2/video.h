//video.h
//Ledbetter, Randy
//rml

/*
 * =====================================================================================
 *
 *      Filename:       video.h
 *
 *   Description:       Header file video.h: This is the Definition/Interface for
 *                      the class Video.
 *       Version:       3.0
 *       Created:       Thu 13 Sep 2012 11:17:48 AM PDT
 *      Revision:       none
 *      Compiler:       gcc/g++
 *
 *        Author:       Randy Michael Ledbetter (rml), rledbetter@mail.csuchico.edu
 *  Organization:       CSU Chico Computer Science Department
 *
 * =====================================================================================
 */

#ifndef VIDEO_H
#define VIDEO_H

#include <string>
using namespace std;

class Video
{
    public:
        
        //Constructor

            Video(string title, string url, string comment, float length, int rating);
            //Precondition:     The formal parameters have been properly passed to
            //                  the constructor.
            //Postcondition:    The instantiation of the associated Video object has
            //                  been initialized.

        
        //Public Member Function Declarations

            void print_video_info();
            //Precondition:     An instantiation of an associated Video Object exists.
            //Postcondition:    The associated Video object's member variables have
            //                  been output to the screen with formatting.

        //Non-Member Friend Function Declarations


            friend void read_videos(Video *video_list[], const int MAX, string &sorting_method);
            //Precondition:     The video.h header file has been included in the
            //                  application program using this function, and an array
            //                  of pointers to objects of type Video has been created
            //                  and passed to the function as *video_list[].
            //Postcondition:    All video information has
            //                  been read-in, and each object pointed to from the 
            //                  array has had its member variables initialized to
            //                  the values read-in. A pointer to the location of
            //                  the array has been returned to the calling function.


            friend void swap_videos(Video *&video_a, Video *&video_b);
            //Precondition:     Two objects of type Video have been passed to the function.
            //Postcondition:    The parameters video_a and video_b have exchanged places
            //                  in memory.

            friend void sort_videos_by_method(Video *video_list[], const int MAX,
                                              string sorting_method);
            //Precondition:     All parameters have been properly initialized and passed
            //                  to the function.
            //Postcondition:    The array video_list has been sorted utilizing the bubble
            //                  sort method in using one of the following as a search
            //                  filter: by rating, by title, or by length. This method
            //                  is determined by the value of the passed parameter
            //                  sorting_method.

            friend void print(Video *video_list[], const int MAX);
            //Precondition:     The video.h header file has been included in the
            //                  application program using this function, and an array
            //                  of pointers to objects of type Video has been created
            //                  and passed to the function as *video_list[].
            //Postcondtion:     All Video objects pointed to by *video_list[], have had
            //                  their member variables printed to the screen in accordance
            //                  with the guidelines set forth in the Project 3 guidelines.


        //Public Accessor Function Declarations

            int get_rating();
            //Precondition:     An instantiation of an associated Video Object exits.
            //Postcondition:    The value of the private member variable m_rating has been returned.

            float get_length();
            //Precondition:     An instantiation of an associated Video Object exits.
            //Postcondition:    The value of the private member variable m_length has been returned.

            string get_title();
            //Precondition:     An instantiation of an associated Video Object exits.
            //Postcondition:    The value of the private member variable m_title has been returned.

            string get_url();
            //Precondition:     An instantiation of an associated Video Object exits.
            //Postcondition:    The value of the private member variable m_url has been returned.

            string get_comment();
            //Precondition:     An instantiation of an associated Video Object exits.
            //Postcondition:    The value of the private member variable m_comment has been returned.


    private:

        //Declare Private Member Variables

            string m_title;
            string m_url;
            string m_comment;
            float  m_length;
            int    m_rating;
};

#endif     
