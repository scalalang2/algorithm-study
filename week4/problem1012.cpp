#include <iostream>
#include <stack>

using namespace std;

int T, M, N, K;
stack<int> st;
int ans;
int arr[51][51];
int vst[51][51];

int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };

void dfs(int x, int y) {
    vst[x][y] = 1;

    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(!(0 <= ny && ny <= M && 0 <= nx && nx <= N))
            continue;

        if(arr[nx][ny] && !vst[nx][ny]) {
            vst[nx][ny] = 1;
            dfs(nx, ny);
        }
    }
};

void init() {
    for(int i = 0; i < 51; i++) {
        for(int j = 0; j < 51; j++) {
            arr[i][j] = 0;
            vst[i][j] = 0;
        }
    }

    ans = 0;
};

int main() {
    scanf("%d", &T);
    while(T--) {
        init();
        scanf("%d %d %d", &M, &N, &K);

        while(K--) {
            int x, y;
            scanf("%d %d", &x, &y);

            if(!(0 <= y && y <= N && 0 <= x && x <= M))
                continue;

            arr[y][x] = 1;
        }

        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                if(arr[i][j] && !vst[i][j]) {
                    dfs(i, j);
                    ans++;
                }
            }
        }

        // for(int i = 0; i < N; i++) {
        //     for(int j = 0; j < M; j++) {
        //         printf("%d ", arr[i][j]);
        //     }
        //     printf("\n");
        // }

        // for(int i = 0; i < N; i++) {
        //     for(int j = 0; j < M; j++) {
        //         printf("%d ", vst[i][j]);
        //     }
        //     printf("\n");
        // }

        cout << ans << endl;
    }
}