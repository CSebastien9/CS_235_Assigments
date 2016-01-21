/**
 * C.F. Sebastien Dalencourt
 * CSCI-235
 * Professor Sadat Chowdhury
 * Project 2
 * November 22, 2015
 */


#ifndef MultiStack_hpp
#define MultiStack_hpp

#include <stdio.h>

class MultiStack {
    
private:
    
    struct Node {
        char item;  //Data item on the stack
        Node *next; //Pointer to the next node
    };
    
    Node *headPtr;  //Pointer to the first node in the stack
    int size;		//Number of items in the stack
    
public:
    
    /** Default constructor **/
    MultiStack();
    
    /** Copy constructor
     *  Copies private variables of an already existing object
     *  to this newly created object. 
     *	@pre anotherMultiStack represents an already existing object.
     *	@post if pointer of already existing object is not null,
     *	 deep copy of content is performed, otherwise, pointer
     *	 of newly created object gets null.
     */
    MultiStack(const MultiStack& anotherMultiStack);
    
    /** Assignment operator
     * 	Copies private variables of an already existing object.
     *  to this newly created object. 
     *  @pre anotherMultiStack represents already existing object.
     *  @post Also makes deep copy given appropriate conditions.
     *   Idea similar to copy ctor - see copy ctor details.
     */
    MultiStack operator=(const MultiStack& anotherMultiStack);
    
    /** Adds an item to the top of the stack.
     *  @pre c is the item to be added.
     *  @post If insertion is successful, item will be on the stack.
     *  @param c of char type.  
     */
    void push(char c);

    /** Prints out content of stack.
     *  @pre None.
     *  @post If stack is not empty, content of stack is displayed.
     *  @throw Exception if stack is empty.
     */
    void display();    
    
    /** Removes top item of this stack.
     *  @pre None.
     *  @post If stack is not empty, item that was the most recently added is removed.
     *  @returns top item of the stack before removal.
     *  @throw Exception if stack is empty.
     */
    char pop();
    
    /** Removes all instances of the top item that appears in the stack.
     * 	@pre None.
     *  @post If stack is not empty, top item and all its instances are removed.
     *  @return top item of the stack before removal.
     * 	@throw Exception if stack is empty.
     */
    char multiPop();
    
    /** Returns a count of the number of times the last character in the stack appears. 
     *  @pre None.
     *  @post If stack is not empty, number of count is returned. Otherwise 0 is returned.
     */
    int getRepeatCounts();

    /** Determines whether stack is empty.
     *  @pre None.
     *  @post None.
     *	@return True if stack is empty, otherwise returns false.
     */
    bool isEmpty();
    
    /** Returns the total number of characters in the stack irrespective of repeats.
     *  @pre None.
     *  @post If not empty, size of stack is returned, otherwise 0 is returned.
     */
    int getSize();
    
    /** Returns the unique number of characters in the stack.
     *  @pre None.
     *  @post If stack not empty, unique number of characters
     *   is returned. Otherwise, 0 is returned.
     */
    int getUniqueCount();
        
   	/** Destructor**/
   	~MultiStack();
    
};

#endif /* MultiStack_hpp */

