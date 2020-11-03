#include <iostream>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int a, b, c, d;
    int aScore, bScore;

    cin >> a >> b >> c >> d;
    aScore = a + b + c + d;

    cin >> a >> b >> c >> d;
    bScore = a + b + c + d;

    if(aScore >= bScore) {
        cout << aScore << '\n';
    } else {
        cout << bScore << '\n';
    }

    return 0;
}