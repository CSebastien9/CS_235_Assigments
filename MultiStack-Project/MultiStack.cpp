/**
 * C.F. Sebastien Dalencourt
 * CSCI-235
 * Professor Sadat Chowdhury
 * Project 2
 * November 22, 2015
 */

#include <iostream>
#include <cassert>
#include <stdexcept>
#include "MultiStack.hpp"
using namespace std;

//Initializes private data variables
MultiStack::MultiStack(): headPtr(nullptr), size(0){} 

MultiStack::MultiStack(const MultiStack& anotherMultiStack) {
	
	//Copies list size of former object to new object
    size = anotherMultiStack.size;

    //If headPtr of former object is null,
    //headPtr of new object also gets null.
   	if(anotherMultiStack.headPtr == nullptr)
        headPtr = nullptr;
    
    //Deep Copy
    else {
        //Copies first node
        headPtr = new Node;
        headPtr->item = anotherMultiStack.headPtr->item;
        Node *current = headPtr;
        
        //Since first node is already copied, move pointer
        //of former object to the second element in the list
        Node *anotherPtr = anotherMultiStack.headPtr->next;
        
        //Copies rest of stack
        while(anotherPtr != nullptr) {
            current->next = new Node;
            current = current->next;
            current->item = anotherPtr->item;
            
            anotherPtr = anotherPtr->next;
		}
        current->next = nullptr;
    }
}

MultiStack MultiStack::operator=(const MultiStack& anotherMultiStack) {

    //Copies list size of former object to new object
    size = anotherMultiStack.size;
    
    if(anotherMultiStack.headPtr != nullptr) {
        if(headPtr != nullptr) {
            Node *current = headPtr;
            
            //Clears stack of new object for new content
            while(current != nullptr) {
            	headPtr = headPtr->next;
            	current->next = nullptr;
            	delete current;

                //Resets current location to first node
            	current = headPtr;
            }
        }
	    
        //Deep Copy

        //Copies first node
	    headPtr = new Node;
        headPtr->item = anotherMultiStack.headPtr->item;
       	Node *current = headPtr;

        Node *anotherPtr = anotherMultiStack.headPtr->next;
        
        //Rest of stack is copied
        while(anotherPtr != nullptr) {

            current->next = new Node;
            current = current->next;
            current->item = anotherPtr->item;
            
            anotherPtr = anotherPtr->next;
		}
        current->next = nullptr;
    }
    else {

        if(headPtr != nullptr) {
			Node *current = headPtr;
            
            //Clears stack if not empty
            while(current != nullptr) {
            	headPtr = headPtr->next;
            	current->next = nullptr;
            	delete current;

            	current = headPtr;
            }        
        	headPtr = nullptr;
    	}
    }
    return *this;
}

void MultiStack::push(char c) {
    
    ++size; 				  //Keeps track of the number of items added
    
    Node *newPtr = new Node; //New node is created
    newPtr->item = c;		 //Node now contains character that was passed as parameter
    newPtr->next = headPtr;  //Makes pointer of new node point to first node in stack 
    headPtr = newPtr; 		 //Makes headPtr point to newly created node
}

void MultiStack::display() {

	if(isEmpty())
        //Throws exception if stack is empty
		throw std::runtime_error("Stack is Empty. Nothing To Be Displayed."); 
    else {
    	//Prints content of stack
    	Node *current = headPtr;
   	 	while(current != nullptr) {
        	cout << current->item << endl;
        	current = current->next;
    	}
    }
}

char MultiStack::pop() {

	char topChar;
    
    if(isEmpty())
        //Throws exception if stack is empty
        throw std::runtime_error("\"Stack Is Empty. Nothing Can Be Removed.\"");     
    else {
        --size;                     //Keeps track of number of items removed

        topChar = headPtr->item;    //Variable topChar gets last added item from the stack
        
        Node *newPtr = headPtr;     //Creates new pointer that points to first node
        headPtr = headPtr->next;    //Now headPtr is pointing to second pointer in list/stack
        
        newPtr->next = nullptr;     //Makes pointer in node that is to be removed null
        delete newPtr;              //Returns memory allocated to first node to memory
        newPtr = nullptr;           //safeguard
    }
    return topChar;
}

char MultiStack::multiPop() {
    
    char topChar;
    
    if(isEmpty())
        //Throws exception if stack is empty
        throw std::runtime_error("\"Stack Is Empty. Nothing Can Be Removed.\"");    
    else {
        --size;
        
        topChar = headPtr->item;           
        
        //Procedure for the removal of the first node
        Node *temp = headPtr;              
        headPtr = headPtr->next;
        temp->next = nullptr;
        delete temp;
        temp = nullptr; //Safeguard
        
        Node *current = headPtr;   
        Node *prev = nullptr; 	  
        
        while(current != nullptr) {
            /* Checks if we are at the first node in the stack.
             * This step is necessary because it is essential 
             * that the trail pointer always be behind the 
             * current pointer.
             */
            if(prev == nullptr && (current->item == topChar)) {
                //Item is removed if it is an instance of topChar
                --size;
                headPtr = headPtr->next;  
                current->next = nullptr;
                delete current;
                
                //Resets current pointer to first node in list
                current = headPtr;
            }
            else {

                if(current->item == topChar) {
                    //Instance of topChar is removed
                    --size;
                    prev->next = current->next;
                    current->next = nullptr;
                    delete current;
                    
                    //Resets current and prev pointers locations
                    current = headPtr;
                    prev = nullptr;
                }
                else {
                    //Move on to next character in list
                    //if no instances of topChar was found.
                    prev = current;
                    current = current->next;
                }
            }
        }
    }
    return topChar;
}

int MultiStack::getRepeatCounts() {
    
    int count;
    
    if(isEmpty()) 
        count = 0;
    else {
        count = 1; 							//If stack not empty, there must be at least 1 character
        char topChar = headPtr->item;       //Variable topChar gets last added item in stack    
        Node *current = headPtr->next;
        
        //Searches for instances of topChar in stack to be counted
        while(current != nullptr) {
            
            if(current->item == topChar) {
                ++count;
            }
            current = current->next;
        }
    }
    return count;
}

bool MultiStack::isEmpty() {
    
    return headPtr == nullptr;
}

int MultiStack::getSize() {
    
    return size;
}

int MultiStack::getUniqueCount() {
    
    int UniqueCount = 0;
    MultiStack copyStack(*this);    
    
    while(!copyStack.isEmpty()) {
		copyStack.multiPop();
		++UniqueCount;
    }	
    return UniqueCount;
}

MultiStack::~MultiStack() {
    
    while(!isEmpty()) {
        pop();
    }
	headPtr = nullptr; //safeguard
}










