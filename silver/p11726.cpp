#include <iostream>

using namespace std;

typedef long long ll;

ll dp[1001];

void solve(ll n) {
    dp[0] = dp[1] = 1;
    for(ll i = 2; i <= n; i++) {
        dp[i] = (dp[i-1] + dp[i-2]) % 10007;
    }
    cout << dp[n];
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll N;
    cin >> N;

    solve(N);
}