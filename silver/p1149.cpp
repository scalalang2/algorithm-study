#include <iostream>
#include <algorithm>

using namespace std;

int N;
int cost[1001][3] = {0};
int dp[1001][3] = {0};
int prev;

int main() {
    std::ios::sync_with_stdio(false);

    cin >> N;
    for(int i = 1; i <= N; i++) {
        cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
    }

    dp[0][0] = dp[0][1] = dp[0][2] = cost[0][0] = cost[0][1] = cost[0][2] = 0;

    // solve problem.
    for(int i = 1; i <= N; i++) {
        dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + cost[i][0];
        dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + cost[i][1];
        dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + cost[i][2];
    }

    cout << min(min(dp[N][0], dp[N][1]), dp[N][2]);

    return 0;
}