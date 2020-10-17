#include <stdio.h>
#include <stdlib.h>

int main() {
    char *str = (char*) malloc(sizeof(char) * 100);
    int i = 0;
    
    while(1) {
        scanf("%c", str + i);
        if(*(str + i) == '\0' || *(str + i) == '\n') {
            break;
        }
        i++;
    }

    int j = 0;
    i = 0;
    while(1) {
        if(j == 10) {
            printf("\n");
            j = 0;
        }

        if(*(str + i) == '\0' || *(str + i) == '\n') {
            break;
        }

        printf("%c", *(str + i));

        j++;
        i++;
    }
}