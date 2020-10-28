#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int> > tree;
vector<vector<int> > parent;
queue<int> Q;

int main() {
    int N, toDelete, root, ans = 0;
    cin >> N;

    // 트리 저장
    tree.resize(N);
    parent.resize(N);
    for(int i = 0; i < N; i++) {
        int k;
        cin >> k;

        if(k != -1){
            tree[k].push_back(i);
            parent[i].push_back(k);
        } else {
            root = i;
        }
    }

    // 입력
    cin >> toDelete;

    // 루트를 지운 경우 삭제
    if(toDelete == root) {
        cout << 0 << '\n';
        return 0;
    }

    // 트리 삭제
    if(parent[toDelete].size() > 0) {
        int _r = parent[toDelete][0];
        for(int i = 0; i < tree[_r].size(); i++) {
            if(tree[_r][i] == toDelete)
                tree[_r].erase(tree[_r].begin() + i);
        }
    }

    // bfs
    Q.push(root);
    while(!Q.empty()) {
        int node = Q.front();
        Q.pop();

        if(node == toDelete) continue;
        if(tree[node].size() == 0) ans++;

        for(int i = 0; i < tree[node].size(); i++) {
            Q.push(tree[node][i]);
        }
    }

    cout << ans << '\n';

    return 0;
}