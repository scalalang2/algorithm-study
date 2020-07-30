#include <iostream>
#include <queue>

using namespace std;

int main() {
    priority_queue<int> queues[6];

    int N, P, line, pnum, sol;
    scanf("%d %d", &N, &P);

    sol = 0;
    while(N--) {
        scanf("%d %d", &line, &pnum);

        if(queues[line].empty()) {
            queues[line].push(pnum);
            sol++;
        } else {
            while(!queues[line].empty() && pnum < queues[line].top()) {
                queues[line].pop();
                sol++;
            }

            if(queues[line].top() != pnum) {
                queues[line].push(pnum);
                sol++;
            }
        }
    }

    cout << sol << endl;

    return 0;
}