//
// Created by 이도현 on 2020/10/09.
//

#include <iostream>
#include <string>

using namespace std;

int main() {
    string name;
    string answer = "";
    bool flag = false;
    getline(cin, name);

    for(int i = 0; i < name.length(); i++) {
        if(i == 0) {
            answer += name[i];
        } else {
            if(flag) {
                answer += name[i];
                flag = false;
            } else {
                if(name[i] == '-') {
                    flag = true;
                }
            }
        }
    }
    cout << answer << endl;
    return 0;
}
