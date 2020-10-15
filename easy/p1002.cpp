#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int x1, y1, r1, x2, y2, r2;
    int T;
    cin >> T;
    for(int i = 0; i < T; i++) {
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        int ans = 0;

        double distance = pow(x2 - x1, 2) + pow(y2 - y1, 2);
        int sum = pow(r1 + r2, 2);
        int diff = pow(r1 - r2, 2);

        
        if(distance == 0) {
            if(r1 == r2) {
                cout << -1 << endl;
            } else {
                cout << 0 << endl;
            }
            continue;
        }

        if(distance == sum || distance == diff) {
            cout << 1 << endl;
        } else if(diff < distance && distance < sum) {
            cout << 2 << endl;
        } else {
            cout << 0 << endl;
        }

        // 위치 계산하기
    }

    return 0;
}