#include <iostream>

using namespace std;

int N, M;
int X, Y, DIRECTION;
// DIRECTION : 0 = 북쪽, 1 = 동쪽, 2 = 남쪽, 3 = 서쪽
int arr[52][52];
int cleaned[52][52];
int cnt = 0;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

void printArr(int arr[52][52]) {
    for(int i = 1; i < 51; i++) {
        for(int j = 1; j < 51; j++) {
            if(arr[i][j] == 3) break;
            cout << arr[i][j] << " ";
        }
        if(arr[i][1] == 3) break;
        cout << endl;
    }
}

void initArr(int arr[52][52]) {
    for(int i = 0; i < 52; i++) {
        for(int j = 0; j < 52; j++) {
            arr[i][j] = 3;
        }
    }
}

void dfs(int x, int y, int acc) {
    // 동서남북 전부 바뀌어 있다면
    int rt1 = (DIRECTION + 1) % 4;
    int rt2 = (DIRECTION + 2) % 4;
    int rt3 = (DIRECTION + 3) % 4;

    if(arr[y][x] == 0) {
        cnt++;
        arr[y][x] = 2;
    }

    if(
        arr[y + dy[DIRECTION]][x + dx[DIRECTION]] > 0 &&
        arr[y + dy[rt1]][x + dx[rt1]] > 0 &&
        arr[y + dy[rt2]][x + dx[rt2]] > 0 &&
        arr[y + dy[rt3]][x + dx[rt3]] > 0 &&
        arr[y - dy[DIRECTION]][x - dx[DIRECTION]] == 1
    ) {
        return;
    } else {
        // printf("----\n");
        // printf("---- %d %d %d\n", x+1, y+1, DIRECTION);
        // printArr(arr);

        int d = (DIRECTION + 3) % 4;
        if(arr[y + dy[d]][x + dx[d]] == 0) {
            DIRECTION = (DIRECTION + 3) % 4;
            dfs(x + dx[d], y + dy[d], 0);
        } else {
            if(
                arr[y - dy[DIRECTION]][x - dx[DIRECTION]] == 2 &&
                arr[y + dy[DIRECTION]][x + dx[DIRECTION]] > 0 &&
                arr[y + dy[rt1]][x + dx[rt1]] > 0 &&
                arr[y + dy[rt2]][x + dx[rt2]] > 0 &&
                arr[y + dy[rt3]][x + dx[rt3]] > 0
            ) {
                dfs(x - dx[DIRECTION], y - dy[DIRECTION], 0);
            } else {
                DIRECTION = (DIRECTION + 3) % 4;
                dfs(x, y, acc + 1);
            }
        }
    }
}

int main() {
    cin >> N >> M;
    cin >> Y >> X >> DIRECTION;

    initArr(arr);

    // 배열 입력받기
    for(int i = 1; i < N + 1; i++) {
        for(int j = 1; j < M + 1; j++) {
            cin >> arr[i][j];
        }
    }

    // 탐색
    dfs(X+1, Y+1, 0);
    cout << cnt << endl;

    // printArr(arr);

    return 0;
}