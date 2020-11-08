/*
 Author: Kasey Harvey
 Course: CSCI-235
 Assignment: Song.cpp, Project 2
 compliedwith = g++ -Wall -Wpedantic -Werror -g Song.cpp -o Song
 */

//  Song.cpp
#include "Song.h"
#include <iostream>
using namespace std;


Song::Song() {}          //default constructor
Song::Song(const std::string& title, const std::string& author , const std::string& album){
    title_ = title;
    author_= author;
    album_ = album;
    
}  //parameterized constructor

void Song::setTitle(std::string title){
    title_= title;
}

void Song::setAuthor(std::string author){
    author_= author;
}

void Song::setAlbum(std::string album){
    album_= album;
}

//return title_
std::string Song::getTitle() const{
    return title_;
}

//return author_
std::string Song::getAuthor() const{
    return author_;
}

//return album_
std::string Song::getAlbum() const{
    return album_;
}

bool operator==(const Song& lhs, const Song& rhs){
    return lhs.title_ == rhs.title_ && lhs.author_ == rhs.author_ && lhs.album_ == rhs.album_;
}

