/**
 * C.F. Sebastien Dalencourt
 * CSCI-235
 * Professor Sadat Chowdhury
 * Project_3
 * December 28, 2015
 */

#ifndef KEY_hpp
#define KEY_hpp

#include <stdio.h>
#include <string>
using namespace std;

class KEY{
    
public:
    //Default Constructor
    KEY(){}
    
    //Parametized Constructor
    KEY(const string& searchkey): key(searchkey){}
    
    //Accessor function
    string getKEY()const {return key;}
    
private:
    string key;
};

#endif /*KEY_hpp */
