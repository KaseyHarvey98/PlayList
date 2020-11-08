/*
 Author: Kasey Harvey
 Course: CSCI-235
 Assignment: Song.h, Project 2
 compliedwith = g++ -Wall -Wpedantic -Werror -g Song.h -o Song_h
 */

//  Song.h

#ifndef Song_hpp
#define Song_hpp

#include <iostream>
using namespace std;

class Song{
public :
    Song();  //default constructor
    Song(const std::string& title, const std::string& author = "", const std::string& album = "");   //parameterized constructor
    
    void setTitle(std::string title);  //"set" in setTitle here means "give a value" and has nothing
    // to do with the Set class. Similarly for setAuthor and setAlbum
    void setAuthor(std::string author);
    void setAlbum(std::string album);
    
    //return title_
    std::string getTitle() const;
    
    //return author_
    std::string getAuthor() const;
    
    //return album_
    std::string getAlbum() const;
    
    // compare if 2 songs are the same
    friend bool operator==(const Song& lhs, const Song& rhs);

private:
    std::string title_;
    std::string author_;
    std::string album_;
}; // end Class

#endif /* Song_h */
