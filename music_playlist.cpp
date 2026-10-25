
#include <iostream>
#include <limits>
#include <string>
using namespace std;

struct Node {
    string title;
    string artist;
    Node* prev;
    Node* next;

    Node(string t, string a) {
        title = t;
        artist = a;
        prev = nullptr;
        next = nullptr;
    }
};

class MusicPlaylist {
private:
    Node* head;
    Node* current;

public:
    MusicPlaylist() {
        head = nullptr;
        current = nullptr;

        addSong("Blue", "Yung Kai");
        addSong("Darkside", "Neoni");
        addSong("Runaway", "AURORA");

        current = head;
    }

    void addSong(string title, string artist) {
        Node* p = new Node(title, artist);

        if (head == nullptr) {
            head = p;
        } else {
            Node* q = head;

            while (q->next != nullptr)
                q = q->next;

            q->next = p;
            p->prev = q;
        }

        cout << "Song added: " << title << endl;
    }

    void deleteSong(string title) {
        Node* p = head;

        while (p != nullptr && p->title != title)
            p = p->next;

        if (p == nullptr) {
            cout << "Song not found!\n";
            return;
        }

        if (p->prev != nullptr)
            p->prev->next = p->next;
        else
            head = p->next;

        if (p->next != nullptr)
            p->next->prev = p->prev;

        if (current == p)
            current = (p->next != nullptr) ? p->next : p->prev;

        delete p;
        cout << "Song deleted successfully.\n";
    }

    void displayPlaylist() {
        Node* p = head;

        cout << "\n--- Music Playlist ---\n";

        if (p == nullptr) {
            cout << "Playlist is empty.\n";
            return;
        }

        while (p != nullptr) {
            cout << p->title << " - " << p->artist << endl;
            p = p->next;
        }
    }

    void reversePlaylist() {
        if (head == nullptr) {
            cout << "Playlist is empty.\n";
            return;
        }

        Node* p = head;

        while (p->next != nullptr)
            p = p->next;

        cout << "\n--- Reverse Playlist ---\n";

        while (p != nullptr) {
            cout << p->title << " - " << p->artist << endl;
            p = p->prev;
        }
    }

    void playCurrent() {
        if (current == nullptr)
            cout << "Playlist is empty.\n";
        else
            cout << "Now playing: " << current->title
                 << " - " << current->artist << endl;
    }

    void nextSong() {
        if (current != nullptr && current->next != nullptr) {
            current = current->next;
            playCurrent();
        } else {
            cout << "No next song available.\n";
        }
    }

    void previousSong() {
        if (current != nullptr && current->prev != nullptr) {
            current = current->prev;
            playCurrent();
        } else {
            cout << "No previous song available.\n";
        }
    }

    void repeatAll() {
        if (head == nullptr) {
            cout << "Playlist is empty.\n";
            return;
        }

        cout << "\n--- Repeat All ---\n";
        Node* p = head;

        while (p != nullptr) {
            cout << "Playing: " << p->title
                 << " - " << p->artist << endl;
            p = p->next;
        }

        current = head;
    }

    ~MusicPlaylist() {
        Node* p = head;

        while (p != nullptr) {
            Node* temp = p;
            p = p->next;
            delete temp;
        }
    }
};

int main() {
    MusicPlaylist playlist;
    int choice = 0;
    string title, artist;

    while (true) {
        cout << "\n===== MUSIC PLAYLIST MANAGER =====\n";
        cout << "1. Display Playlist\n";
        cout << "2. Add Song\n";
        cout << "3. Delete Song\n";
        cout << "4. Play Current Song\n";
        cout << "5. Next Song\n";
        cout << "6. Previous Song\n";
        cout << "7. Reverse Playlist\n";
        cout << "8. Repeat All\n";
        cout << "9. Exit\n";
        cout << "Enter choice: ";

        if (!(cin >> choice)) {
            cout << "Invalid input! Please enter a number from 1 to 9.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
        case 1:
            playlist.displayPlaylist();
            break;

        case 2:
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Enter song title: ";
            getline(cin, title);
            cout << "Enter artist name: ";
            getline(cin, artist);
            playlist.addSong(title, artist);
            break;

        case 3:
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Enter song title to delete: ";
            getline(cin, title);
            playlist.deleteSong(title);
            break;

        case 4:
            playlist.playCurrent();
            break;

        case 5:
            playlist.nextSong();
            break;

        case 6:
            playlist.previousSong();
            break;

        case 7:
            playlist.reversePlaylist();
            break;

        case 8:
            playlist.repeatAll();
            break;

        case 9:
            cout << "Exiting Music Playlist Manager.\n";
            return 0;

        default:
            cout << "Invalid choice! Please enter a number from 1 to 9.\n";
        }
    }

    return 0;
}
/*PS C:\parth.203> cd "c:\parth.203\" ; if ($?) { g++ music_playlist.cpp -o music_playlist } ; if ($?) { .\music_playlist }

===== MUSIC PLAYLIST MANAGER =====
1. Display Playlist
2. Add Song
3. Delete Song
4. Play Current Song
5. Next Song
6. Previous Song
7. Reverse Playlist
8. Repeat All
9. Exit
Enter choice: 1

--- Music Playlist ---
Blue - Yung Kai
Darkside - Neoni
Runaway - AURORA

===== MUSIC PLAYLIST MANAGER =====
1. Display Playlist
2. Add Song
3. Delete Song
4. Play Current Song
5. Next Song
6. Previous Song
7. Reverse Playlist
8. Repeat All
9. Exit
Enter choice: 2
Enter song title: Rashtravadi
Enter artist name: Adarsh shinde
Song added: Rashtravadi

===== MUSIC PLAYLIST MANAGER =====
1. Display Playlist
2. Add Song
3. Delete Song
4. Play Current Song
5. Next Song
6. Previous Song
7. Reverse Playlist
8. Repeat All
9. Exit
Enter choice: 5
Now playing: Darkside - Neoni

===== MUSIC PLAYLIST MANAGER =====
1. Display Playlist
2. Add Song
3. Delete Song
4. Play Current Song
5. Next Song
6. Previous Song
7. Reverse Playlist
8. Repeat All
9. Exit
Enter choice: 5
Now playing: Runaway - AURORA

===== MUSIC PLAYLIST MANAGER =====
1. Display Playlist
2. Add Song
3. Delete Song
4. Play Current Song
5. Next Song
6. Previous Song
7. Reverse Playlist
8. Repeat All
9. Exit
Enter choice: 5
Now playing: Rashtravadi - Adarsh shinde

===== MUSIC PLAYLIST MANAGER =====
1. Display Playlist
2. Add Song
3. Delete Song
4. Play Current Song
5. Next Song
6. Previous Song
7. Reverse Playlist
8. Repeat All
9. Exit
Enter choice: 8

--- Repeat All ---
Playing: Blue - Yung Kai
Playing: Darkside - Neoni
Playing: Runaway - AURORA
Playing: Rashtravadi - Adarsh shinde

===== MUSIC PLAYLIST MANAGER =====
1. Display Playlist
2. Add Song
3. Delete Song
4. Play Current Song
5. Next Song
6. Previous Song
7. Reverse Playlist
8. Repeat All
9. Exit
Enter choice: 6
No previous song available.

===== MUSIC PLAYLIST MANAGER =====
1. Display Playlist
2. Add Song
3. Delete Song
4. Play Current Song
5. Next Song
6. Previous Song
7. Reverse Playlist
8. Repeat All
9. Exit
Enter choice: 5
Now playing: Darkside - Neoni

===== MUSIC PLAYLIST MANAGER =====
1. Display Playlist
2. Add Song
3. Delete Song
4. Play Current Song
5. Next Song
6. Previous Song
7. Reverse Playlist
8. Repeat All
9. Exit
Enter choice:*/