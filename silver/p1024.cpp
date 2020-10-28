#include <iostream>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(0);

    int N, L;

    cin >> N >> L;
    int t, x = -1, iter = -1;

    for(int i = L; i <= 100; i++) {
        t = (i-1) * i / 2;
        if((N - t) % i == 0 && (N - t)/i >= 0) {
            x = (N - t) / i;
            iter = i;
            break;
        }
    }

    if(x == -1) cout << -1;
    else
        for(int i = 0; i < iter; i++)
            cout << x + i << ' ';

    return 0;
}