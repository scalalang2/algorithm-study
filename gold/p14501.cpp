// 백준 14501번 문제
#include <iostream>

using namespace std;

int T[15] = {0,};
int P[15] = {0,};
int N;
int ans;

void search(int acc, int step, int remaining) {
    if(step > N) {
        if(acc > ans) {
            ans = acc;
        }
        return;
    }

    if(remaining > 0) {
        search(acc, step+1, remaining-1);
    } else {
        // cout << step + T[step-1] - 1 << endl;
        if(step + T[step-1] - 1 <= N)
            search(acc + P[step-1], step + 1, T[step - 1] - 1);

        search(acc, step + 1, 0);
    }
}

int main() {
    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> T[i];
        cin >> P[i];
    }

    search(0, 1, 0);

    cout << ans << endl;

    return 0;
}