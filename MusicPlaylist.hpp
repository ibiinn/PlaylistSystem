//
//  MusicPlaylist.hpp
//  PlaylistSystem
//
//  Created by Muhammad BIntang on 25/12/25.
//

#ifndef MusicPlaylist_hpp
#define MusicPlaylist_hpp

#include <stdio.h>
#include "Song.hpp"
#include <iostream>
using namespace std;

class MusicPlaylist {
private:
    address root;
    
    address insertNode(address node, int id, infotype title, infotype artist, int duration);
    void preOrder(address node);
    void inOrder(address node);
    void postOrder(address node);
    address searchNode(address node, int id);
    address minValueNode(address node);
    address deleteNode(address root, int id);
    int countNodes(address node);
    address searchByTitle(address node, infotype title);
    
public:
    MusicPlaylist();
    
    void addSong(int id, infotype title, infotype artist, int duration);
    void displayPreOrder();
    void displayInOrder();
    void displayPostOrder();
    void searchSong(int id);
    void searchSongByTitle(infotype title);
    void removeSong(int id);
    int getTotalSongs();
    void displayMenu();
    bool isEmpty();
};

#endif /* MusicPlaylist_hpp */
