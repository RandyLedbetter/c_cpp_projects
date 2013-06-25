//stree.cpp
//Ledbetter, Randy
//rml

/*
 * =====================================================================================
 *
 *      Filename:       stree.cpp
 *
 *   Description:       Implemtation file stree.cpp: This is the Implementation for
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

#include "stree.h"

//Constructor for class Stree
Stree::Stree()
{
    m_root = NULL;
}

//Destructor for class Stree
Stree::~Stree()
{
    delete m_root;
}

//Constructor for class StreeNode
Stree::StreeNode::StreeNode(string str, int data, StreeNode *parent)
{
    m_str = str; 
    m_data = data;  
    m_parent = parent;
    m_left = NULL;  
    m_right = NULL;
}

//Destructor for class StreeNode. Destructor is recursive
Stree::StreeNode::~StreeNode() 
{
    delete m_left; 
    delete m_right;
}

 bool Stree::insert(string origination, string destination, int data)
 {
    StreeNode *location;
    
    // Empty Tree Special Case
    if(m_root == NULL) 
    {
        //Insert origination at m_root.
            m_root = new StreeNode(origination, 0, NULL);

        //Insert destination relative to origination.
            m_root->m_left = new StreeNode(destination, data, m_root);
            
            assert(m_root->m_str == origination);
            assert(m_root->m_left->m_str == destination && m_root->m_left->m_data == data && m_root->m_left->m_parent == m_root);
        return true;
    }

    //If destination is not within the tree AND if origination is within
    //the tree AND the node containing origination has available children,
    //create a new node and insert passed parameter values into corresponding
    //node member variables and return true. Otherwise, do nothing and return 
    //false.
    assert(m_root != NULL);
    if((!search_tree(destination, m_root, location)) && (search_tree(origination,
        m_root, location) && (location->m_left == NULL || location->m_right == NULL)))
    {
        assert(!search_tree(destination, m_root, location));
        assert(search_tree(origination, m_root, location));
        assert((location->m_left == NULL || location->m_right == NULL));

        //Prioritize m_left insertion.
        if(location->m_left == NULL)
        {
            location->m_left = new StreeNode(destination, data, location);
            
            
        }
        else
        {
            location->m_right = new StreeNode(destination, data, location);
           
        }

        return true;
    }
    else
    {   
        return false;
    }
}

bool Stree::search_tree(string str, StreeNode *node, StreeNode *&location)
{
    if(node == NULL)
    {
        return false;
    }

    if(node->m_str == str)
    {
        location = node;
        return true;
    }
    else
    {
        return ((search_tree(str, node->m_left, location)) || (search_tree(str, node->m_right, location)));
    }
}

bool Stree::lookup(string target, string &parent, int &parent_distance,
                string &left_child, int &left_child_distance,
                string &right_child, int &right_child_distance)
{
    StreeNode *target_location;

    if(search_tree(target, m_root, target_location))
    {
        if(target_location->m_parent == NULL)
        {
            parent = "none";
        }
        else
        {
            parent = target_location->m_parent->m_str;
            parent_distance = target_location->m_data;
        }

        if(target_location->m_left == NULL)
        {
            left_child = "none";
        }
        else
        {
            left_child = target_location->m_left->m_str;
            left_child_distance = target_location->m_left->m_data;
        }

        if(target_location->m_right == NULL)
        {
            right_child = "none";
        }
        else
        {
            right_child = target_location->m_right->m_str;
            right_child_distance = target_location->m_right->m_data;
        }

        return true;
    }
    else
    {
        return false;
    }
}

bool Stree::get_path(string origination, string destination, vector<string> &path)
{
    path.clear();
    StreeNode *start_node, *target_node;

    // If origination and destination exist and a path exists between
    // them, return true. get_path traverses the specified path in
    // reverse order, hence start_node = destination node and
    // target_node = origination node. Although the vector, path,
    // is populated in reverse order, this is corrected via the
    // implementation of the reverse algorithm prior to returning to the calling function.
    if(search_tree(destination, m_root, start_node) &&
        search_tree(origination, m_root, target_node) &&
        get_path(start_node, target_node, path))
    {
        reverse(path.begin(), path.end());
        return true;
    }
    else
    {
        // The path does not exist. Empty the vector and return false.
        path.clear();
        return false;
    }
}

bool Stree::get_path(StreeNode *cur_node, StreeNode *target_node,  std::vector<string> &path)
{
    if(cur_node == NULL) // If cur_node equals NULL, path does not exist.
        return false;

    path.push_back(cur_node->m_str); // Add the value of m_str to the passed in vector.

    if(cur_node->m_str == target_node->m_str) // Path between cur_node and target_node exists.
    {
        return true;
    }
    else
    {
        return get_path(cur_node->m_parent, target_node,  path);
    }
}


bool Stree::get_distance(string origination, string destination, int &distance)
{
    std::vector<int> path;
    StreeNode *start_node, *target_node;
    int sum = 0;

    // If origination and destination exist and a path exists between
    // them, return true. get_distance traverses the specified path in
    // reverse order, hence start_node = destination node and
    // target_node = origination node. Although the vector, path,
    // is populated in reverse order, this is corrected via the
    // implementation of the reverse algorithm prior to returning to the calling function.
    if(search_tree(destination, m_root, start_node) &&
        search_tree(origination, m_root, target_node) &&
        get_distance(start_node, target_node, path))
    {
        for(vector<int>::iterator iter = path.begin();
            iter != path.end();
            iter++)
        {
            sum = sum + (*iter);
        }

        distance = sum;
        return true;
    }
    else
    {
        // The path does not exist.
        distance = sum;
        return false;
    }
}

bool Stree::get_distance(StreeNode *cur_node, StreeNode *target_node,  std::vector<int> &path)
{
    if(cur_node == NULL) // If cur_node equals NULL, path does not exist.
        return false;
    
    if(cur_node->m_str == target_node->m_str) // Path between cur_node and target_node exists.
    {
        return true;
    }    
    else    
    {
        path.push_back(cur_node->m_data); // Add the value of m_data to the passed in vector.
        return get_distance(cur_node->m_parent, target_node,  path);
    }
}

bool Stree::remove(string city)
{
    StreeNode *city_node;


    if(!search_tree(city, m_root, city_node)) // Target is not in the tree.
    {
        return false;
    }

    if(city_node == m_root) // Target is at the root of the tree. Special case.
    {        
        delete city_node;
        m_root = NULL;
        return true;
    }

    if(city_node->m_parent->m_left == city_node) // Determine which child city_node is.
    {
        city_node->m_parent->m_left = NULL;
    }
    else
    {
        city_node->m_parent->m_right = NULL;
    }

    delete city_node;
    return true;
}



