#include <iostream>
#include <vector>

using namespace std;

int N, x;
bool vst[101];
int arr[101][101];

void dfs(vector<int> graph[], int u) {
    for(int i = 0; i < graph[u].size(); i++) {
        int nxt = graph[u][i];
        if(!vst[nxt]) {
            // cout << nxt << " ";
            vst[nxt] = true;
            dfs(graph, nxt);
        }
    }
}

int main() {
    cin >> N;

    vector<int> graph[N];

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> x;

            if(x == 1) {
                graph[i].push_back(j);
            }
        }
    }

    for(int i = 0; i < N; i++) {
        dfs(graph, i);

        for(int j = 0; j < N; j++) {
            if(vst[j]) {
                arr[i][j] = 1;
            }
        }

        for(int k = 0; k < N; k++) {
            vst[k] = false;
        }
        // cout << endl;
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}