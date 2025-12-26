//
//  MusicPlaylist.cpp
//  PlaylistSystem
//
//  Created by Muhammad BIntang on 25/12/25.
//

#include "MusicPlaylist.hpp"

MusicPlaylist::MusicPlaylist() {
    root = NULL;
}

address MusicPlaylist::insertNode(address node, int id, infotype title, infotype artist, int duration) {
    if (node == NULL) {
        return createNode(id, title, artist, duration);
    }
    
    if (id < node->id) {
        node->left = insertNode(node->left, id, title, artist, duration);
    } else if (id > node->id) {
        node->right = insertNode(node->right, id, title, artist, duration);
    } else {
        cout << "Song with ID " << id << " already exists!" << endl;
    }
    
    return node;
}

void MusicPlaylist::addSong(int id, infotype title, infotype artist, int duration) {
    root = insertNode(root, id, title, artist, duration);
    cout << "Song added: " << title << " by " << artist << endl;
}

void MusicPlaylist::preOrder(address node) {
    if (node != NULL) {
        cout << "ID: " << node->id << " | Title: " << node->title
             << " | Artist: " << node->artist
             << " | Duration: " << node->duration / 60 << ":"
             << node->duration % 60 << " mins" << endl;
        preOrder(node->left);
        preOrder(node->right);
    }
}

void MusicPlaylist::displayPreOrder() {
    cout << "\n=== Pre-order Traversal (Root -> Left -> Right) ===" << endl;
    if (root == NULL) {
        cout << "Playlist is empty!" << endl;
        return;
    }
    preOrder(root);
}

void MusicPlaylist::inOrder(address node) {
    if (node != NULL) {
        inOrder(node->left);
        cout << "ID: " << node->id << " | Title: " << node->title
             << " | Artist: " << node->artist
             << " | Duration: " << node->duration / 60 << ":"
             << node->duration % 60 << " mins" << endl;
        inOrder(node->right);
    }
}

void MusicPlaylist::displayInOrder() {
    cout << "\n=== In-order Traversal (Sorted by ID) ===" << endl;
    if (root == NULL) {
        cout << "Playlist is empty!" << endl;
        return;
    }
    inOrder(root);
}

void MusicPlaylist::postOrder(address node) {
    if (node != NULL) {
        postOrder(node->left);
        postOrder(node->right);
        cout << "ID: " << node->id << " | Title: " << node->title
             << " | Artist: " << node->artist
             << " | Duration: " << node->duration / 60 << ":"
             << node->duration % 60 << " mins" << endl;
    }
}

void MusicPlaylist::displayPostOrder() {
    cout << "\n=== Post-order Traversal (Left -> Right -> Root) ===" << endl;
    if (root == NULL) {
        cout << "Playlist is empty!" << endl;
        return;
    }
    postOrder(root);
}

address MusicPlaylist::searchNode(address node, int id) {
    if (node == NULL || node->id == id) {
        return node;
    }
    
    if (id < node->id) {
        return searchNode(node->left, id);
    }
    
    return searchNode(node->right, id);
}

void MusicPlaylist::searchSong(int id) {
    address result = searchNode(root, id);
    if (result != NULL) {
        cout << "\n=== Song Found! ===" << endl;
        cout << "ID: " << result->id << endl;
        cout << "Title: " << result->title << endl;
        cout << "Artist: " << result->artist << endl;
        cout << "Duration: " << result->duration / 60 << ":"
             << result->duration % 60 << " mins" << endl;
    } else {
        cout << "\nSong with ID " << id << " not found in playlist!" << endl;
    }
}

address MusicPlaylist::searchByTitle(address node, infotype title) {
    if (node == NULL) {
        return NULL;
    }
    
    if (node->title == title) {
        return node;
    }
    
    address leftResult = searchByTitle(node->left, title);
    if (leftResult != NULL) {
        return leftResult;
    }
    
    return searchByTitle(node->right, title);
}

void MusicPlaylist::searchSongByTitle(infotype title) {
    address result = searchByTitle(root, title);
    if (result != NULL) {
        cout << "\n=== Song Found! ===" << endl;
        cout << "ID: " << result->id << endl;
        cout << "Title: " << result->title << endl;
        cout << "Artist: " << result->artist << endl;
        cout << "Duration: " << result->duration / 60 << ":"
             << result->duration % 60 << " mins" << endl;
    } else {
        cout << "\nSong '" << title << "' not found in playlist!" << endl;
    }
}

address MusicPlaylist::minValueNode(address node) {
    address current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

address MusicPlaylist::deleteNode(address root, int id) {
    if (root == NULL) return root;
    
    if (id < root->id) {
        root->left = deleteNode(root->left, id);
    } else if (id > root->id) {
        root->right = deleteNode(root->right, id);
    } else {
        if (root->left == NULL) {
            address temp = root->right;
            delete root;
            return temp;
        } else if (root->right == NULL) {
            address temp = root->left;
            delete root;
            return temp;
        }
        
        address temp = minValueNode(root->right);
        root->id = temp->id;
        root->title = temp->title;
        root->artist = temp->artist;
        root->duration = temp->duration;
        root->right = deleteNode(root->right, temp->id);
    }
    return root;
}

void MusicPlaylist::removeSong(int id) {
    address check = searchNode(root, id);
    if (check == NULL) {
        cout << "\nSong with ID " << id << " not found!" << endl;
        return;
    }
    
    cout << "\nRemoving: " << check->title << " by " << check->artist << endl;
    root = deleteNode(root, id);
    cout << "Song successfully removed from playlist!" << endl;
}

int MusicPlaylist::countNodes(address node) {
    if (node == NULL) {
        return 0;
    }
    return 1 + countNodes(node->left) + countNodes(node->right);
}

int MusicPlaylist::getTotalSongs() {
    return countNodes(root);
}

void MusicPlaylist::displayMenu() {
    cout << "\n========================================" << endl;
    cout << "    MUSIC PLAYLIST MANAGEMENT SYSTEM" << endl;
    cout << "========================================" << endl;
    cout << "Total Songs: " << getTotalSongs() << endl;
    cout << "========================================" << endl;
}

bool MusicPlaylist::isEmpty() {
    return root == NULL;
}
