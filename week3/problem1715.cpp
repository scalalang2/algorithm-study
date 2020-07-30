#include <iostream>
#include <queue>

using namespace std;

int main() {
    priority_queue<int> queue;
    int N, item, sol;
    scanf("%d", &N);

    while(N--) {
        scanf("%d", &item);
        queue.push(item * -1);
    }

    if(N == 1) {
        printf("%d\n", queue.top());
        return 0;
    }

    sol = 0;
    while(queue.size() > 1) {
        int a = queue.top();
        queue.pop();
        int b = queue.top();
        queue.pop();

        queue.push(a + b);

        sol += (a + b) * -1;
    }

    printf("%d\n", sol);

    return 0;
}
