//stree.h
//Ledbetter, Randy
//rml

/*
 * =====================================================================================
 *
 *      Filename:       stree.h
 *
 *   Description:       Header file stree.h: This is the Definition/Interface for
 *                      the class Stree.
 *       Version:       4.0
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
 #include <vector>
 #include <algorithm>
 #include <cassert>

 using namespace std;

 #ifndef STREE_H
 #define STREE_H

 class Stree
 {
    public:
        
        //Stree Constructor and Destructor. Defined in stree.cpp

            Stree();
            ~Stree();

        //Public Member Function Prototypes. Defined in stree.cpp

            bool insert(string origination, string destination, int data);
            bool lookup(string target, string &parent, int &parent_distance,
                        string &left_child, int &left_child_distance,
                        string &right_child, int &right_child_distance);
            bool get_path(string origination, string destination, vector<string> &path);
            bool get_distance(string origination, string destination, int &distance);
            bool remove(string city);


    private:

        class StreeNode
        {
            public:

                //StreeNode Constructor and Destructor. Defined in stree.cpp

                    StreeNode(string str, int data, StreeNode *parent);               
                    ~StreeNode(); 

                //Member Variable Declarations

                    string m_str;
                    int m_data;
                    StreeNode *m_parent;
                    StreeNode *m_left;
                    StreeNode *m_right;

        };

        //Private Member Function Prototypes. Defined in stree.cpp

            bool search_tree(string str, StreeNode *node, StreeNode *&location);
            bool get_path(StreeNode *cur_node, StreeNode *target_node,  std::vector<string> &path);
            bool get_distance(StreeNode *cur_node, StreeNode *target_node,  std::vector<int> &path);

        //Private Member Variables

            StreeNode *m_root;

 };

 #endif
