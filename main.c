#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Song structure
typedef struct Song {
    char title[100];
    char artist[100];
    int duration;
    struct Song* next;
} Song;

// Function to create a new song
Song* createSong(const char* title, const char* artist, int duration) {
    Song* newSong = (Song*)malloc(sizeof(Song));
    if (newSong == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    strcpy(newSong->title, title);
    strcpy(newSong->artist, artist);
    newSong->duration = duration;
    newSong->next = NULL;
    return newSong;
}

// Function to add a song to the playlist
void addSong(Song** playlist, const char* title, const char* artist, int duration) {
    Song* newSong = createSong(title, artist, duration);
    if (*playlist == NULL) {
        *playlist = newSong;
    } else {
        Song* temp = *playlist;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newSong;
    }
    printf("Song '%s' by %s added to the playlist.\n", title, artist);
}

// Function to display the playlist
void displayPlaylist(Song* playlist) {
    if (playlist == NULL) {
        printf("The playlist is empty.\n");
        return;
    }
    printf("Current Playlist:\n");
    Song* temp = playlist;
    while (temp != NULL) {
        printf("Title: %s, Artist: %s, Duration: %d seconds\n", temp->title, temp->artist, temp->duration);
        temp = temp->next;
    }
}

// Function to play the next song in the playlist
void playNext(Song** playlist) {
    if (*playlist == NULL) {
        printf("No songs in the playlist.\n");
        return;
    }
    Song* nextSong = *playlist;
    printf("Now playing: %s by %s (%d seconds)\n", nextSong->title, nextSong->artist, nextSong->duration);
    *playlist = nextSong->next;
    free(nextSong);
}

int main() {
    Song* playlist = NULL;
    char title[100], artist[100];
    int choice, duration;

    while(1){
        printf("\nMusic Player Menu:\n");
        printf("1. Add a Song\n");
        printf("2. Display Playlist\n");
        printf("3. Play Next Song\n");
        printf("4. Remove a Song\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline character

        switch(choice) {
            case 1:
                printf("Enter song title: ");
                fgets(title, sizeof(title), stdin);
                title[strcspn(title, "\n")] = '\0'; // Remove newline character
                printf("Enter artist name: ");
                fgets(artist, sizeof(artist), stdin);
                artist[strcspn(artist, "\n")] = '\0'; // Remove newline character
                printf("Enter song duration (in seconds): ");
                scanf("%d", &duration);
                getchar(); // Consume newline character
                addSong(&playlist, title, artist, duration);
                break;
            case 2:
                displayPlaylist(playlist);
                break;
            case 3:
                playNext(&playlist);
                break;
            
        }
    }



    return 0;
}