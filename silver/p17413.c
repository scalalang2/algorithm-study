// 백준 - 17413

#include <stdio.h>
#include <stdlib.h>

void swap_print(char *text, int size) {
    for(int i = size; i >= 0; i--) {
        printf("%c", *(text + i));
    }
}

void normal_print(char *text, int size) {
    for(int i = 0; i <= size; i++) {
        printf("%c", *(text + i));
    }
}

int main() {
    int size = 1;
    int from = 0;
    int end = 1;
    int i = 0;
    char* text = (char*) calloc(size, sizeof(char));
    while(1) {
        scanf("%c", text + i);
        if(*(text + i) == '\n') break;

        i++;
        if(i == size) {
            size *= 2;
            text = (char*) realloc(text, size);
        }
    }

    i = 0;
    while(1) {
        
    }

    // printf("%s", text);
    return 0;
}