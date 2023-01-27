#include <iostream>
using namespace std;
#define ios_sync ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

char board[105][105];
int n;

void check_utr() {
    for (int i = 1; i <= n; i++) {
        if (board[i][1] == '0') { // check LeftUp to Right
            if (board[i - 1][2] == '#') board[i - 1][2] = '1';
            if (board[i][2] == '#') board[i][2] = '2';
            if (board[i + 1][2] == '#') board[i - 1][2] = '3';
        }
    }
}

void check_ltd() {
    for (int i = 1; i <= n; i++) {
        if (board[1][i] == '0') { // check LeftUp to Down
            if (board[2][i - 1] == '#') board[2][i - 1] = '4';
            if (board[2][i] == '#') board[2][i] = '5';
            if (board[2][i + 1] == '#') board[2][i + 1] = '6';
        }
    }
}

void check_dtr() {
    for (int i = 1; i <= n; i++) {
        if (board[i][n] == '0') { // check LeftDown to Right
            if (board[i - 1][n - 1] == '#') board[i - 1][n - 1] = '7';
            if (board[i][n - 1] == '#') board[i - 1][n - 1] = '8';
            if (board[i + 1][n - 1] == '#') board[i - 1][n - 1] = '9';
        }
    }
}

void check_rtd() {
    for (int i = 1; i <= n; i++) {
        if (board[n][i] == '0') { // check RightUp to Down
            if (board[n - 1][i - 1] == '#') board[i - 1][n - 1] = 'a';
            if (board[n - 1][i] == '#') board[i - 1][n - 1] = 'b';
            if (board[n - 1][i + 1] == '#') board[i - 1][n - 1] = 'c';
        }
    }
}

int main()
{
    ios_sync;
    cin >> n;

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin >> board[i][j];

    check_dtr();
    check_ltd();
    check_rtd();
    check_utr();

    int cnt = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            if(board[i][j] == '#') cnt++;
    cout << cnt;
}