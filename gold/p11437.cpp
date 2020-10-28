#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

const int MAX = 50000;

vector<vector<int> > tree;

int parent[MAX] = {0,};
int level[MAX] = {0,};
bool check[MAX];

void balancing(int &node1, int &node2) {
    while(level[node1] > level[node2])
        node1 = parent[node1];

    while(level[node1] < level[node2])
        node2 = parent[node2];
}

// DFS 를 통한 노드의 Depth 설정
void setParNLevel(int node) {
    check[node] = true;

    int edgeCount = tree[node].size();
    for(int i = 0; i < edgeCount; i++) {
        int nxt = tree[node][i];
        if(!check[nxt]) {
            parent[nxt] = node;
            level[nxt] = level[node] + 1;
            setParNLevel(nxt);
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n;

    tree.resize(n);
    for(int i = 0; i < n - 1; i++) {
        int to, des;
        cin >> to >> des;
        tree[to-1].push_back(des-1);
        tree[des-1].push_back(to-1);
    }

    setParNLevel(0);

    cin >> m;
    for(int i = 0; i < m; i++) {
        int node1, node2;
        cin >> node1 >> node2;
        node1--;
        node2--;
        balancing(node1, node2);
        while(node1 != node2) {
            node1 = parent[node1];
            node2 = parent[node2];
        }

        cout << node1 + 1 << '\n';
    }

    return 0;
}
