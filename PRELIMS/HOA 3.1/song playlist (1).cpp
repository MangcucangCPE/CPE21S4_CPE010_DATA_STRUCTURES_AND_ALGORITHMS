#include <iostream>
#include <string>
using namespace std;

struct Node {
    string song;
    Node* next;
};

Node* head = NULL;
Node* tail = NULL;
Node* current = NULL;

// Create Playlist
void createPlaylist() {
    int n;
    string title;

    cout << "How many songs? ";
    cin >> n;
    cin.ignore();

    for (int i = 1; i <= n; i++) {
        cout << "Enter Song " << i << ": ";
        getline(cin, title);

        Node* newNode = new Node;
        newNode->song = title;

        if (head == NULL) {
            head = tail = newNode;
            tail->next = head;
        } else {
            tail->next = newNode;
            tail = newNode;
            tail->next = head;
        }
    }

    current = head;
    cout << "Playlist created successfully!\n";
}

// Add Song
void addSong(string title) {
    Node* newNode = new Node;
    newNode->song = title;

    if (head == NULL) {
        head = tail = newNode;
        tail->next = head;
        current = head;
    } else {
        tail->next = newNode;
        tail = newNode;
        tail->next = head;
    }

    cout << "Song added!\n";
}

// Display Playlist
void displayPlaylist() {
    if (head == NULL) {
        cout << "Playlist is empty.\n";
        return;
    }

    Node* temp = head;

    cout << "\nPlaylist:\n";
    do {
        cout << "- " << temp->song << endl;
        temp = temp->next;
    } while (temp != head);
}

// Remove Song
void removeSong(string title) {
    if (head == NULL) {
        cout << "Playlist is empty.\n";
        return;
    }

    Node *temp = head, *prev = tail;

    do {
        if (temp->song == title) {

            if (head == tail) {
                delete temp;
                head = tail = current = NULL;
            }
            else if (temp == head) {
                head = head->next;
                tail->next = head;
                if (current == temp)
                    current = head;
                delete temp;
            }
            else if (temp == tail) {
                tail = prev;
                tail->next = head;
                if (current == temp)
                    current = head;
                delete temp;
            }
            else {
                prev->next = temp->next;
                if (current == temp)
                    current = temp->next;
                delete temp;
            }

            cout << "Song removed!\n";
            return;
        }

        prev = temp;
        temp = temp->next;

    } while (temp != head);

    cout << "Song not found!\n";
}

// Next Song
void nextSong() {
    if (current == NULL) {
        cout << "Playlist is empty.\n";
        return;
    }

    current = current->next;
    cout << "Now Playing: " << current->song << endl;
}

// Previous Song
void previousSong() {
    if (current == NULL) {
        cout << "Playlist is empty.\n";
        return;
    }

    Node* temp = head;

    while (temp->next != current)
        temp = temp->next;

    current = temp;

    cout << "Now Playing: " << current->song << endl;
}

// Play Songs in Loop
void playSongsLoop() {
    if (head == NULL) {
        cout << "Playlist is empty.\n";
        return;
    }

    char choice;

    do {
        cout << "\nNow Playing: " << current->song << endl;
        cout << "Press N for Next Song | Q to Stop: ";
        cin >> choice;

        if (choice == 'N' || choice == 'n') {
            current = current->next;
        }

    } while (choice != 'Q' && choice != 'q');
}

int main() {

    int choice;
    string song;

    do {
        cout << "\n=== SONG PLAYLIST ===\n";
        cout << "1. Create Playlist\n";
        cout << "2. Add Song\n";
        cout << "3. Remove Song\n";
        cout << "4. Display Playlist\n";
        cout << "5. Next Song\n";
        cout << "6. Previous Song\n";
        cout << "7. Play Songs in Loop\n";
        cout << "8. Exit\n";
        cout << "Choice: ";
        cin >> choice;
        cin.ignore();

        switch(choice) {

        case 1:
            createPlaylist();
            break;

        case 2:
            cout << "Song title: ";
            getline(cin, song);
            addSong(song);
            break;

        case 3:
            cout << "Song to remove: ";
            getline(cin, song);
            removeSong(song);
            break;

        case 4:
            displayPlaylist();
            break;

        case 5:
            nextSong();
            break;

        case 6:
            previousSong();
            break;

        case 7:
            playSongsLoop();
            break;

        case 8:
            cout << "Goodbye!\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while(choice != 8);

    return 0;
}
