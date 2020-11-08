/*
 Author: Kasey Harvey
 Course: CSCI-235
 Assignment: Set.cpp, Project 2
 compliedwith = g++ -Wall -Wpedantic -Werror -g Set.h -o Set
 */

//  Set.cpp

#include "Set.h"

//return The integer number of entries currently in the set.
template<class ItemType>
int Set<ItemType>::getCurrentSize()const{
    return item_count_;
} // end getCurrentSize

//return True if the set is empty, or false if not.
template<class ItemType>
bool Set<ItemType>::isEmpty()const{
    return item_count_ == 0;
} // end isEmpty

/** Adds a new entry to this set.
 @post  If successful, newEntry is stored in the set and
 the count of items in the set has increased by 1.
 @param newEntry  The object to be added as a new entry.
 @return  True if addition was successful, or false if not. */
template<class ItemType>
bool Set<ItemType>::add(const ItemType& newEntry){
    if (getIndexOf(newEntry) == -1){
        if (item_count_ < max_items_){
            items_[item_count_] = newEntry;
            item_count_++;
            return true;
            }// end if
        }  // end if
    return false;
} // end add

/** Removes a given entry from this set,if possible.
 @post  If successful, anEntry has been removed from the set
 and the count of items in the set has decreased by 1.
 @param anEntry  The entry to be removed.
 @return  True if removal was successful, or false if not. */
template<class ItemType>
bool Set<ItemType>::remove(const ItemType& anEntry){
    bool found = false;
    int result = -1;
    int search_index = 0; // If the bag is empty, item_count_ is zero, so loop is skipped 
    while (!found && (search_index < item_count_)){
        if (items_[search_index] == anEntry){
            found = true;
            result = search_index;
        }else{
            search_index ++;
        } //end if
    } // end while
    return result;
} // end getIndexOf

/** Removes all entries from this set.
 @post  set contains no items, and the count of items is 0. */
template<class ItemType>
void Set<ItemType>::clear(){
    item_count_=0;
} // end clear

/** Tests whether this set contains a given entry.
 @param anEntry  The entry to locate.
 @return  True if set contains anEntry, or false otherwise. */
template<class ItemType>
bool Set<ItemType>::contains(const ItemType& anEntry) const{
    return getIndexOf(anEntry) > -1;
} // end contains

/** Fills a vector with all entries that are in this set.
 @return  A vector containing all the entries in the set. */
template<class ItemType>
std::vector<ItemType> Set<ItemType>::toVector()const{
    std::vector<ItemType> itemList;
    for (int i=0; i< item_count_; i++)
        itemList.push_back(items_[i]);
    // end for_i
    return itemList;
}  // end toVector

/** post: Either returns the index of target in the array items_
 or -1 if the array does not contain the target*/
template<class ItemType>
int Set<ItemType>::getIndexOf(const ItemType& target) const{
    bool found = false;
    int result = -1;
    int search_index = 0;
    // If the bag is empty, item_count_ is zero, so loop is skipped 
    while (!found && (search_index < item_count_))
    {
        if (items_[search_index] == target){
            found = true;
            result = search_index;
        }else{
            search_index ++;
        } //endif
    } // end while 
    return result;
} // end getIndexOf
