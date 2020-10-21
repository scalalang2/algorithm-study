#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;
vector<vector<int> > v;
int parent[100001];
int isChecked[100001];

int main() {
    cin >> N;
    v.resize(N+1);
    for(int i = 0; i < N - 1; i++) {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    queue<int> q;
    q.push(1);
    isChecked[1] = true;
    while(!q.empty()) {
        int x = q.front();
        q.pop();

        for(int i = 0; i < v[x].size(); i++) {
            int nx = v[x][i];
            if(!isChecked[nx]) {
                parent[nx] = x;
                isChecked[nx] = true;
                q.push(nx);
            }
        }
    }

    for(int i = 2; i <= N; i++) {
        cout << parent[i] << endl;
    }
}