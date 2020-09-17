#include <stdio.h>
#include <string.h>

int main() {
    char s[100] = {" "};
    scanf("%s", s);
    
    size_t len = strlen(s);
    printf("%zu", len);
    return 0;
}
