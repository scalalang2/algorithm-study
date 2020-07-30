#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int N, op;
    priority_queue<int> queue;

    scanf("%d", &N);

    while(N--) {
        scanf("%d", &op);
        if(op == 0) {
            if(queue.empty()) {
                printf("0\n");
            } else {
                printf("%d\n", queue.top());
                queue.pop();
            }
        } else {
            queue.push(op);
        }
    }
}