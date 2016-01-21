/**
 * C.F. Sebastien Dalencourt
 * CSCI-235
 * Professor Sadat Chowdhury
 * Project_3
 * December 28, 2015
 */

#ifndef TreeNode_hpp
#define TreeNode_hpp

#include <stdio.h>
#include "KEY.hpp"
#include <string>
using namespace std;

class TreeNode : public KEY{
    
    //Default Constructor
    TreeNode():KEY(){}
    
    //Parametized Constructor
    TreeNode(const string& NodeKey, const string& NodeValue, TreeNode *left = nullptr, TreeNode *right = nullptr)
    : KEY(NodeKey), value(NodeValue), leftChildPtr(left), rightChildPtr(right){}
    
    string value;
    TreeNode *leftChildPtr;
    TreeNode *rightChildPtr;
    
    //Allows Class StringMap to have access to these private variables
    friend class StringMap;
};

#endif /*TreeNode_hpp */
