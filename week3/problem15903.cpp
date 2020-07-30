#include <iostream>
#include <vector>
#include <queue>

#define ll long long

using namespace std;

int main() {
    int N, M, i, item;
    priority_queue<ll, vector<ll>, greater<ll> > queue;

    cin >> N >> M;

    // queue에 입력한다.
    for(i = 0; i < N; i++) {
        cin >> item;
        queue.push(item);
    }

    for(i = 0; i < M; i++) {
        ll a = queue.top();
        queue.pop();
        ll b = queue.top();
        queue.pop();

        ll local_sum = a + b;
        queue.push(local_sum);
        queue.push(local_sum);
    }

    ll sum = 0;
    while(!queue.empty()){
        sum = sum + queue.top();
        queue.pop();
    }

    cout << sum;

    return 0;
}