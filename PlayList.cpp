/*
 Author: Kasey Harvey
 Course: CSCI-235
 Assignment: Playlist.h, Project 2
 compliedwith = g++ -Wall -Wpedantic -Werror -g Playlist.cpp -o Playlist
 */

//  Playlist.cpp

#include "PlayList.h"
#include "LinkedSet.h"
#include <iostream>
using namespace std;

PlayList::PlayList() {} // default constructor

// parameterized constructor
PlayList::PlayList(const Song& a_song){
    add(a_song);
}

// Destructor :  needs to unloop()
PlayList::~PlayList(){
    unloop();
}
// Loops playlist
void PlayList::loop(){
    tail_ptr_ = head_ptr_;
}

//Unloops playlist
void PlayList::unloop(){
    tail_ptr_ = nullptr;
}

/*  add songs at the end of the PlayList
 if head ptr is empty add to head & set tail to point to head.
 ~head being the new node.
 else add to end of node chain*/

bool PlayList:: add(const Song& a_song){
    if(contains(a_song)){
        return false;
    }else{
        //     Add to beginning of chain if chain is empty: new node references rest of chain;
        //     (head_ptr_ is null if chain is empty)
        if(head_ptr_ == nullptr){
            Node<Song>* next_node_ptr = new Node<Song>();
            next_node_ptr->setItem(a_song);
            next_node_ptr->setNext(nullptr);  // New node points to chain
            
            head_ptr_ = next_node_ptr;          // New node is now first node
            tail_ptr_ = next_node_ptr;
            item_count_++;
            return true;
        } // end if
        else {
            getPointerToLastNode();    // Update last node
            Node<Song>* new_node_ptr = new Node<Song>();
            new_node_ptr->setItem(a_song);
            tail_ptr_->setNext(new_node_ptr);
            new_node_ptr->setNext(nullptr);  // New node points to chain
            
            tail_ptr_ = new_node_ptr;
            item_count_++;
            return true;
        }
        
        return true;
    }
}

//override remove() to preserve the order of the Songs.
/*  remove songs from the PlayList
 if head ptr is empty remove nothing
 else connect node '1&3' and delete node '2'*/
bool PlayList::remove(const Song& a_song){
    Node<Song>* prev_ptr = nullptr;
    Node<Song>* entry_node_ptr = getPointerTo(a_song,prev_ptr);
    bool can_remove_item = !isEmpty() && (entry_node_ptr != nullptr);
    if (can_remove_item)
    {
        if (entry_node_ptr == head_ptr_){
            Node<Song>* node_to_delete_ptr = head_ptr_;
            head_ptr_ = head_ptr_->getNext();
            delete node_to_delete_ptr;
            node_to_delete_ptr = nullptr;
            item_count_--;
            return can_remove_item;
        }//end if
        else{
            Node<Song>* cur_ptr = getPointerTo(a_song,prev_ptr);;
            Node<Song>* node_to_delete_ptr = entry_node_ptr;
            
            prev_ptr->setNext(cur_ptr-> getNext());
            delete node_to_delete_ptr;
            node_to_delete_ptr = nullptr;
            item_count_--;
            return can_remove_item;
            
        }// end else
    } // end if
    
    return can_remove_item;
}
// display contents of Playlist, via Playlist Vector
void PlayList::displayPlayList(){
    std::vector<Song> tunes = toVector();
    for (int i= 0; i< getCurrentSize(); i++) {
        std::cout << "*" << " Title: " << tunes[i].getTitle() << " *" << " Author: " << tunes[i].getAuthor() << " *" << " Album: " << tunes[i].getAlbum() << " *\n" ;
    }
    std::cout << "End of playlist\n" ;
}

// traverses the chain and
// returns tail pointer ; pointer to the last node
Node<Song>* PlayList::getPointerToLastNode() const{
    Node<Song>* cur_ptr = head_ptr_;
//    Node<Song>* next_ptr = head_ptr_->getNext()
    
    if (head_ptr_ == nullptr) {
        return nullptr;
    } else {
        while (cur_ptr->getNext()!= nullptr) cur_ptr = cur_ptr->getNext(); // end while
        //        cur_ptr = cur_ptr->getNext();
        return cur_ptr;
    }
}

// post: previous_ptr is null if target is not in PlayList or if target is the
// first node, otherwise it points to the node preceding target
// return: either a pointer to the node containing target
// or the null pointer if the target is not in the PlayList.
Node<Song>* PlayList::getPointerTo(const Song& target, Node<Song>*& previous_ptr)const{
    Node<Song>* cur_ptr = head_ptr_;
    previous_ptr = nullptr;
    bool found = false;
    
    if (!contains(target))
        return nullptr;
    
    while (!found && (cur_ptr != nullptr))
    {
        if (target == cur_ptr->getItem())
            found = true;
        else{
            previous_ptr = cur_ptr;
            cur_ptr = cur_ptr->getNext();
        }
    } // end while
    return cur_ptr;
}
