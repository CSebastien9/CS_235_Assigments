/**
 * C.F. Sebastien Dalencourt
 * CSCI-235
 * Professor Sadat Chowdhury
 * Project_3
 * December 28, 2015
 */


#include <iostream>
#include <cassert>
#include <stdexcept>
#include <string>
#include <sstream>
#include "StringMap.hpp"

/****************************************************************************\
 *							     PUBLIC METHODS								*
\****************************************************************************/

//Default Ctor and private memeber variable initialization
StringMap::StringMap():rootNode(nullptr), size(0), NodeValue(""){}

//Copy Ctor
StringMap::StringMap(const StringMap& newMap){
    
    copyMap(newMap.rootNode, rootNode);
}
//Assignment Operator
StringMap& StringMap::operator=(const StringMap& rhs){
    
    if(this != &rhs){
        destroyMap(rootNode);
        copyMap(rhs.rootNode, rootNode);
    }
    return *this;
}

bool StringMap::isEmpty(){
    return rootNode == nullptr;
}

int StringMap::getSize(){
    return size;
}

bool StringMap::addValue(string key, string value){
    
    bool validity=false;
    //Check for valid arguments
    if(key !="" && value !=""){
        validity = true;
        insert_Elements(rootNode, key, value);
        size++;
    }
    return validity;
}

bool StringMap::contains(string key){
    
    bool exist=false;
    //Checks whether value associated with this key exist
    if(retrieveValue(rootNode, key) !="")
        exist=true;
    
    return exist;
}

string StringMap::getValue(string key){
    
    if(contains(key))
        NodeValue = retrieveValue(rootNode, key);
    else
        throw std::runtime_error("**NO VALUE ASSOCIATED WITH THIS KEY**");
    
    return NodeValue;
}

bool StringMap::deleteValue(string key){
    
    bool deletion_status=false;

    if(contains(key)){
        delTreeVal(rootNode, key);
        deletion_status=true;
        size--;
    }
    return deletion_status;
}

void StringMap::clear(){
    destroyMap(rootNode);
    size = 0;
}

/****************************************************************************\
 *							PROTECTED METHODS								*
\****************************************************************************/

void StringMap::copyMap(TreeNode *treePtr, TreeNode *& newtreePtr) const{
    
    if(treePtr == nullptr)
        newtreePtr = nullptr;
    else{
    	//Copies node in map
        newtreePtr = new TreeNode(treePtr->getKEY(), treePtr->value, nullptr, nullptr);
        copyMap(treePtr->leftChildPtr, newtreePtr->leftChildPtr);
        copyMap(treePtr->rightChildPtr, newtreePtr->rightChildPtr);
    }
}

void StringMap::insert_Elements(TreeNode *&treePtr, const string& key, const string& value){
    
    if(treePtr == nullptr)
        //Positon of insertion found, create & insert new node
        treePtr = new TreeNode(key, value, nullptr, nullptr);
    
    else if(key < treePtr->getKEY())
    	//searches left subtree
        insert_Elements(treePtr->leftChildPtr, key, value);
    else
    	//searches right subtree
        insert_Elements(treePtr->rightChildPtr, key, value);
}

string StringMap::retrieveValue(TreeNode *treePtr, string key){
    
    if(treePtr == nullptr)
        NodeValue="";
    else if(key == treePtr->getKEY())
    	//Node found
        NodeValue = treePtr->value;
    else if(key < treePtr->getKEY())
    	//searches left subtree
        retrieveValue(treePtr->leftChildPtr, key);
    else
    	//searches right subtree
        retrieveValue(treePtr->rightChildPtr, key);
    
    return NodeValue;
}

void StringMap::delTreeVal(TreeNode *&treePtr, string key){
    
    if(key == treePtr->getKEY())
    	//Node found
        treePtr->value ="";
    else if(key < treePtr->getKEY())
    	//searches left subtree
        delTreeVal(treePtr->leftChildPtr, key);
    else
    	//searches right subtree
        delTreeVal(treePtr->rightChildPtr, key);
}

void StringMap::destroyMap(TreeNode *& treePtr){
    //Post order traversal
    if(treePtr != nullptr){
        destroyMap(treePtr->leftChildPtr);
        destroyMap(treePtr->rightChildPtr);
        delete treePtr;
        treePtr = nullptr;
    }
}






