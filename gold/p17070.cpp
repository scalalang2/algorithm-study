#include <iostream>

using namespace std;

int N, ans;
int arr[17][17];

// 0 : horizontal, 1: diagonal, 2: vertical
int direction = 0;


void brute(int d, int x, int y) {
    if( x > N || y > N ) return;

    if(d == 0 && ( 
        arr[y][x-1] == 1 || 
        arr[y][x] == 1)) {
            return;
    }

    if(d == 1 && ( 
        arr[y][x-1] == 1 ||
        arr[y-1][x] == 1 ||
        arr[y-1][x-1] == 1 || 
        arr[y][x] == 1)) {
            return;
    }

    if(d == 2 && ( 
        arr[y-1][x] == 1 || 
        arr[y][x] == 1)) {
            return;
    }

    if((x == N-1 && y == N-1)) {
        ans++;
        return;
    }

    if(d == 0) {
        brute(0, x+1, y);
        brute(1, x+1, y+1);
    } else if(d == 1) {
        brute(1, x+1, y+1);
        brute(0, x+1, y);
        brute(2, x, y+1);
    } else {
        brute(1, x+1, y+1);
        brute(2, x, y+1);
    }
}

int main() {
    cin >> N;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }

    brute(0, 1, 0);

    cout << ans << endl;
}