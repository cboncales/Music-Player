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

int main() {
    Song* playlist = NULL;
    char title[100], artist[100];



    return 0;
}