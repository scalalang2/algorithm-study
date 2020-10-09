#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = 0;
    int len = 1;
    char *str = (char *) calloc(len, sizeof(char));

    while(1) {
        scanf("%c", &str[n]);
        if(str[n] == '\n') break;
        n++;
        len++;
        str = (char *) realloc(str, sizeof(char) * len);
    }

    int is_ok = 1;
    int size = len-1;
    for(int i = 0; i < size/2; i++) {
        if(str[i] != str[size-1-i]) {
            is_ok = 0;
        }
    }

    if(is_ok) {
        printf("YES");
    } else {
        printf("NO");
    }
}