#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, K, T = 0;
    scanf("%d %d", &N, &K);

    int *arr = (int*) malloc(sizeof(int) * (N + 2));
    for(int i = 2; i <= N; i++) {
        arr[i] = i;
    }

    for(int i = 2; i <= N; i++) {
        if(arr[i] == 0) continue;

        int inc = i;
        // printf("%d %d\n", i, inc);
        while(inc <= N) {
            // printf("%d\n", inc);

            if(arr[inc] != 0) {
                K--;
                if( K == 0 ) {
                    T = arr[inc];
                    break;
                }

                arr[inc] = 0;
            }

            inc = inc + i;
        }

        if(K == 0) break;
    }

    printf("%d", T);
    return 0;
}