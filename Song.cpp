//
//  Song.cpp
//  PlaylistSystem
//
//  Created by Muhammad BIntang on 25/12/25.
//

#include "Song.hpp"
#include <stdlib.h>

address createNode(int songId, infotype songTitle, infotype songArtist, int songDuration) {
    address newNode = new elmlist;
    newNode->id = songId;
    newNode->title = songTitle;
    newNode->artist = songArtist;
    newNode->duration = songDuration;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
