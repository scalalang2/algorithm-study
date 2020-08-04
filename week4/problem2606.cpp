#include <iostream>
#include <stack>

using namespace std;

int arr[101][101];
int vst[101];
stack<int> st;
int cnt = 0;

void dfs(int start, int n) {
    vst[start] = 1;
    cnt++;

    for(int j = 1; j <= n; j++) {
        if(arr[start][j] && !vst[j]) {
            vst[j] = 1;

            st.push(j);
            dfs(j, n);
            st.pop();
        }
    }
}

int main() {
    int N, K, i, j;
    scanf("%d", &N);
    scanf("%d", &K);

    while(K--) {
        scanf("%d %d", &i, &j);
        arr[i][j] = 1;
        arr[j][i] = 1;
    }

    dfs(1, N);
    printf("%d", cnt-1);

    return 0;
}


// 7
// 6
// 1 2
// 2 3
// 1 5
// 5 2
// 5 6
// 4 7