/**
 * C.F. Sebastien Dalencourt
 * CSCI-235
 * Professor Sadat Chowdhury
 * Project_3
 * December 28, 2015
 */

#ifndef StringMap_hpp
#define StringMap_hpp

#include <string>
#include "TreeNode.hpp"
#include <stdio.h>
using namespace std;

class StringMap{

private:
    TreeNode *rootNode;
    string NodeValue;
    int size;
    
public:
    //Default Constructor
    StringMap();
    
    //Copy Constructor
    StringMap(const StringMap& OtherMap);
    
    //Overloaded Assignment Operator
    StringMap& operator=(const StringMap& rhs);
    
    /** Determines whether the Map is empty.
     *	@return True if Map/tree is empty;
     *	otherwise returns fasle.
     */
    bool isEmpty();
    
    /** Determines the number of elements
     *	stored in the Map.
     *	@return number of elemets in Map.
     *	Returns 0 if Map empty.
     */
    int getSize();
    
    /** Inserts Key-Value pair(elements) in the Map.
     *	@pre Key-Value pair to be inserted in the Map
     *  are key and value.
     *	@post Key-Value pair are in their proper order
     *	in the Map.
     *  @return True if insertion is successful and
     *	Key-Value pair are valid.
     *  Returns false if invalid.
     */
    bool addValue(string key, string value);
    
    /** Determines whether or not a value
     *	is associated with given key.
     *  @pre key is the item to be inserted
     *  into the map.
     *	@return True if value exists, otherwise
     *  returns false.
     */
    bool contains(string key);

    /** Determines the value associated
     *	with the given key.
     *	@pre key is the search key to be
     *  retrieved from the Map.
     *	@post If the retrieval was succesful,
     *  value associated with key is returned,
     *  otherwise an exception is thrown.
     */
    string getValue(string key);
    
    /** Deletes a value with a given key
     *	from the map.
     *  @pre value associated with given key
     *  is the item to be deleted.
     *  @post Value deleted from node if it exists
     *	@return True if value is deleted, otherwise,
     *	returns false.
     */
    bool deleteValue(string key);
    
    /** Remove all elements from map.
     *	@post Map is empty.
     */
    void clear();

protected:
    /** Copies the tree rooted at treePtr into
     *	the rooted at newtreePtr
     *	@post map is copied
     */
    void copyMap(TreeNode *treePtr, TreeNode *& newtreePtr) const;

    /** Recursively inserts Key-Value pair(elements) into the Map.
     *	@pre treePtr points to a node in the bst,
     *  Key-Value pair are to be inserted in the Map.
     *	@post Key-Value pair are in their proper order
     *	in the Map.
     */
    void insert_Elements(TreeNode *&treePtr, const string& key, const string& value);
    
    /** Recursively retrieves value from the map.
     *	@pre treePtr points to a bst. Key is the
     *  searchkey for the node to be retrieved.
     *	@post If the retrieval was successful,
     *  the value associated with the key is returned.
     */
    string retrieveValue(TreeNode *treePtr, string key);
    
    /** Recursively deletes value from the map.
     *	@pre treePtr points to a bst. Key is the
     *  searchkey for the node to be retrieved.
     *	@post Value associated with this key is deleted.
     */
    void delTreeVal(TreeNode *&treePtr, string key);

    /** Recursively deallocates memory for the map.
     *	Map is destroyed.
     *	@post Map is empty.
     */
    void destroyMap(TreeNode *& treePtr);
    
};

#endif /*StringMap_hpp */






