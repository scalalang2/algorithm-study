#include <stdio.h>
#include <stdlib.h>

int main() {
    int N,M;
    int** arr;
    scanf("%d %d", &N, &M);

    arr = (int**) malloc(sizeof(int*) * N);
    for(int i = 0; i < N; i++) {
        arr[i]=(int*) malloc(sizeof(int) * M);
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            char c;
            scanf("%c", &c);
            if(c == '\n') {
                scanf("%c", &c);
            }

            if(c == '.') {
                arr[i][j] = 0;
            } else {
                arr[i][j] = 1;
            }
        }
    }

    int to_break = 0;
    int start_i = 0;
    int start_j = 0;
    int size = 0;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(arr[i][j] == 1) {
                start_i = i;
                start_j = j;

                for(int k = M-1; k >= 0; k--) {
                    if(arr[i][k] == 1) {
                        size = k - start_j + 1;
                        break;
                    }
                }
                
                to_break = 1;
            }

            if(to_break) break;
        }
        if(to_break) break;
    }

    int middle = size/2;
    if(arr[start_i][start_j + middle] == 0) {
        printf("UP");
    } else if(arr[start_i+size-1][start_j + middle] == 0) {
        printf("DOWN");
    } else if(arr[start_i+middle][start_j] == 0) {
        printf("LEFT");
    } else {
        printf("RIGHT");
    }

    // printf("%d %d %d", start_i, start_j, size);

    return 0;
}