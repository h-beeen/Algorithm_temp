#include <iostream>
#include <queue>
using namespace std;
#define ios_sync ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

char board[105][105];
int dx[8] = {1, 1, 1, 0, 0, -1, -1, -1};
int dy[8] = {1, 0, -1, 1, -1, -1, 0, -1};
int n;

void search_minefield(int x, int y){
    int mine = 0;
    int sharp = 0;
    queue <pair<int, int> > sharp_idx;

    for(int i = 0; i < 8; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 1 || nx > n || ny < 1 || ny > n) continue;

        if (board[nx][ny] == '#'){
            sharp_idx.push(make_pair(nx, ny));
            sharp++;
        }
        if (board[nx][ny] == '+')
            mine++;
    }
    if (board[x][y] == mine) // 찾은 지뢰의 개수랑 보드의 지뢰 개수가 같아서, 이미 모든 지뢰를 찾았을 때
                             // 여기는 뒤져도 지뢰가 아닙니다.
    {
        while(!sharp_idx.empty())
        {
            int temp1 = sharp_idx.front().first;
            int temp2 = sharp_idx.front().second;
            board[temp1][temp2] = '-';
            sharp_idx.pop();
        }
    }
    else if ((board[x][y]-48) == (mine + sharp))
    {
        while (!sharp_idx.empty())
        {
            int temp1 = sharp_idx.front().first;
            int temp2 = sharp_idx.front().second;
            board[temp1][temp2] = '+';
            sharp_idx.pop();
        }
    }

}

int main() {
    ios_sync;
    cin >> n;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> board[i][j];


    for (int x = 1; x <= n; x++)
        search_minefield(x, 1);

    for (int y = 1; y <= n; y++)
        search_minefield(1, y);

    for (int x = 1; x <= n; x++)
        search_minefield(x, n);

    for (int y = 1; y <= n; y++)
        search_minefield(n, y);

    for (int i = 1; i <= n; i++) {
        cout << endl;
        for (int j = 1; j <= n; j++)
            cout << board[i][j];
    }
}