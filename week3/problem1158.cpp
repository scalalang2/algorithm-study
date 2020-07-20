#include <iostream>
#include <queue>

using namespace std;

queue<int> q;

int main() {
    int N, K;
    cin >> N >> K;

    if(N == 1 && K == 1) {
        cout << "<1>" << endl;
        return 0;
    }

    // 1 ... N
    for(int i = 0; i < N; i++) {
        q.push(i+1);
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < K; j++) {
            if(j+1 == K) {
                int tmp = q.front();
                q.pop();
                if (i == 0){
                    cout << "<" << tmp << ", ";
                } else if(i + 1 == N) {
                    cout << tmp << ">" << endl;
                } else {
                    cout << tmp << ", ";
                }
            } else {
                int tmp = q.front();
                q.pop();
                q.push(tmp);
            }
        }
    }

    return 0;
}