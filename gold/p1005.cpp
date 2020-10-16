#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int T, N, K, W, X, Y;
int _time[1000];
int pre[1000]; // 건설 건물 번호

vector<int> suc[1000];

int main() {
    cin >> T;

    for(int i = 0; i < T; i++) {
        cin >> N >> K;
        for(int j = 0; j < N; j++) {
            cin >> _time[j];
        }

        for(int j = 0; j < K; j++) {
            cin >> X;
            cin >> Y;

            suc[X-1].push_back(Y-1);
            pre[Y-1]++;
        }

        cin >> W;
        W--;
        
        int result[1000] = {0};
        queue<int> Q;
        for(int i = 0; i < N; i++) {
            if(!pre[i]) Q.push(i);
        }

        while(pre[W] > 0) {
            int u = Q.front();
            Q.pop();

            for(int i = 0; i < suc[u].size(); i++) {
                int next = suc[u][i];
                result[next] = max(result[next], result[u] + _time[u]);
                if(--pre[next] == 0) Q.push(next);
            }
        }

        cout << result[W] + _time[W] << endl;
    }

    return 0;
}