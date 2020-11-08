/*
 Author: Kasey Harvey
 Course: CSCI-235
 Assignment: Playlist.h, Project 2
 compliedwith = g++ -Wall -Wpedantic -Werror -g Playlist.h -o Playlist
 */

//  Playlist.h


#ifndef PlayList_hpp
#define PlayList_hpp

#include "LinkedSet.h"
#include "Song.h"
//#include "Song.cpp"
#include <iostream>
using namespace std;

class PlayList : public LinkedSet<Song> {
public:
    PlayList();                     //default constructor
    PlayList(const Song& a_song);   //parameterized constructor
    PlayList(const PlayList& a_play_list): LinkedSet(a_play_list){
        head_ptr_ = a_play_list.head_ptr_;
        tail_ptr_=a_play_list.getPointerToLastNode();
    }; // copy constructor : intialize tail pointer
    ~PlayList(); // Destructor
    bool add(const Song& new_song) override; //  add songs at the end of the PlayList
    bool remove(const Song& new_song) override; //override remove() to preserve the order of the Songs.
    void loop(); // loops playlist
    void unloop(); //unloops playlist
    void displayPlayList(); // shows playlist
    //    Node<Song>* head_ptr_; // Pointer to first node
private:
    Node<Song>* tail_ptr_; // Pointer to last node
    
    // post: previous_ptr is null if target is not in PlayList or if target is the
    // first node, otherwise it points to the node preceding target
    // return: either a pointer to the node containing target
    // or the null pointer if the target is not in the PlayList.
    Node<Song>* getPointerTo(const Song& target, Node<Song>*& previous_ptr) const;
    
    // traverses the chain and returns a pointer to the last node
    Node<Song>* getPointerToLastNode() const;
};
#endif /* PlayList_h */
