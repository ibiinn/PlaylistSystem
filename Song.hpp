//
//  Song.hpp
//  PlaylistSystem
//
//  Created by Muhammad BIntang on 25/12/25.
//

#ifndef Song_hpp
#define Song_hpp

#include <stdio.h>
#include <string>
using namespace std;

typedef string infotype;
typedef struct elmlist *address;

struct elmlist {
    int id;
    infotype title;
    infotype artist;
    int duration;
    address left;
    address right;
};

address createNode(int songId, infotype songTitle, infotype songArtist, int songDuration);

#endif /* Song_hpp */
