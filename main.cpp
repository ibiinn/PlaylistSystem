//
//  main.cpp
//  PlaylistSystem
//
//  Created by Muhammad BIntang on 25/12/25.
//

#include "MusicPlaylist.hpp"
#include <iostream>
#include <limits>
using namespace std;

void displayMainMenu() {
    cout << "\n============================================" << endl;
    cout << "   MUSIC PLAYLIST MANAGEMENT SYSTEM" << endl;
    cout << "      Binary Search Tree Implementation" << endl;
    cout << "============================================" << endl;
    cout << "1. Add New Song to Playlist" << endl;
    cout << "2. Display All Songs (In-Order)" << endl;
    cout << "3. Display All Songs (Pre-Order)" << endl;
    cout << "4. Display All Songs (Post-Order)" << endl;
    cout << "5. Search Song by ID" << endl;
    cout << "6. Search Song by Title" << endl;
    cout << "7. Remove Song from Playlist" << endl;
    cout << "8. Show Total Songs" << endl;
    cout << "0. Exit Program" << endl;
    cout << "============================================" << endl;
    cout << "Enter your choice: ";
}

void clearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void pauseScreen() {
    cout << "\nPress Enter to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main() {
    MusicPlaylist playlist;
    int choice;
    bool running = true;
    
    cout << "\n=== INITIALIZING PLAYLIST ===" << endl;
    cout << "Loading sample songs...\n" << endl;
    
    playlist.addSong(50, "Bohemian Rhapsody", "Queen", 354);
    playlist.addSong(25, "Imagine", "John Lennon", 183);
    playlist.addSong(75, "Hotel California", "Eagles", 391);
    playlist.addSong(15, "Yesterday", "The Beatles", 123);
    playlist.addSong(35, "Sweet Child O Mine", "Guns N Roses", 356);
    
    cout << "\nSample songs loaded successfully!" << endl;
    pauseScreen();
    
    while (running) {
        displayMainMenu();
        cin >> choice;
        
        if (cin.fail()) {
            clearInputBuffer();
            cout << "\n[ERROR] Invalid input! Please enter a number." << endl;
            pauseScreen();
            continue;
        }
        
        switch (choice) {
            case 1: {
                int id, duration;
                infotype title, artist;
                
                cout << "\n=== ADD NEW SONG ===" << endl;
                cout << "Enter Song ID (number): ";
                cin >> id;
                
                if (cin.fail()) {
                    clearInputBuffer();
                    cout << "[ERROR] Invalid ID! Please enter a number." << endl;
                    pauseScreen();
                    break;
                }
                
                clearInputBuffer();
                
                cout << "Enter Song Title: ";
                getline(cin, title);
                
                cout << "Enter Artist Name: ";
                getline(cin, artist);
                
                cout << "Enter Duration (in seconds): ";
                cin >> duration;
                
                if (cin.fail()) {
                    clearInputBuffer();
                    cout << "[ERROR] Invalid duration! Please enter a number." << endl;
                    pauseScreen();
                    break;
                }
                
                playlist.addSong(id, title, artist, duration);
                pauseScreen();
                break;
            }
            
            case 2: {
                playlist.displayInOrder();
                pauseScreen();
                break;
            }
            
            case 3: {
                playlist.displayPreOrder();
                pauseScreen();
                break;
            }
            
            case 4: {
                playlist.displayPostOrder();
                pauseScreen();
                break;
            }
            
            case 5: {
                int searchId;
                cout << "\n=== SEARCH SONG BY ID ===" << endl;
                cout << "Enter Song ID to search: ";
                cin >> searchId;
                
                if (cin.fail()) {
                    clearInputBuffer();
                    cout << "[ERROR] Invalid ID!" << endl;
                    pauseScreen();
                    break;
                }
                
                playlist.searchSong(searchId);
                pauseScreen();
                break;
            }
            
            case 6: {
                infotype searchTitle;
                clearInputBuffer();
                
                cout << "\n=== SEARCH SONG BY TITLE ===" << endl;
                cout << "Enter Song Title to search: ";
                getline(cin, searchTitle);
                
                playlist.searchSongByTitle(searchTitle);
                pauseScreen();
                break;
            }
            
            case 7: {
                int removeId;
                cout << "\n=== REMOVE SONG ===" << endl;
                cout << "Enter Song ID to remove: ";
                cin >> removeId;
                
                if (cin.fail()) {
                    clearInputBuffer();
                    cout << "[ERROR] Invalid ID!" << endl;
                    pauseScreen();
                    break;
                }
                
                playlist.removeSong(removeId);
                pauseScreen();
                break;
            }
            
            case 8: {
                cout << "\n=== PLAYLIST STATISTICS ===" << endl;
                cout << "Total Songs in Playlist: " << playlist.getTotalSongs() << endl;
                pauseScreen();
                break;
            }
            
            case 0: {
                cout << "\n============================================" << endl;
                cout << "  Thank you for using Music Playlist System!" << endl;
                cout << "              Goodbye! 🎵" << endl;
                cout << "============================================" << endl;
                running = false;
                break;
            }
            
            default: {
                cout << "\n[ERROR] Invalid choice! Please select 0-8." << endl;
                pauseScreen();
                break;
            }
        }
        
        clearInputBuffer();
    }
    
    return 0;
}
