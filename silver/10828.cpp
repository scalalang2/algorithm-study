#include <iostream>
#include <map>

using namespace std;

int arr[10000];
int top = 0;
map<string, int> ops;

int main(){
    int N;
    scanf("%d", &N);
    ops["push"] = 0;
    ops["top"] = 1;
    ops["size"] = 2;
    ops["empty"] = 3;
    ops["pop"] = 4;

    for(int i = 0; i < N; i++) {
        string op;
        int operand;

        cin >> op;
        switch(ops[op]) {
            case 0:
                cin >> operand;
                arr[top] = operand;
                top++;
            break;
            case 1:
                if(top == 0) {
                    cout << -1 << endl;
                } else {
                    cout << arr[top-1] << endl;
                }
            break;
            case 2:
                cout << top << endl;
            break;
            case 3:
                if(top == 0) {
                    cout << 1 << endl;
                } else {
                    cout << 0 << endl;
                }
            break;
            case 4:
                if(top == 0) {
                    cout << -1 << endl;
                } else {
                    cout << arr[top-1] << endl;
                    top--;
                }
            break;
        }

    }

    return 0;
}