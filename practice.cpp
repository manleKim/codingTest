#include <bits/stdc++.h>
using namespace std;
const int n = 3;
int board[n][n];
bool visited[n][n];
int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};

void go(int y, int x) {
    visited[y][x] = 1;
    cout << y << " : " << x << '\n';
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
        if (!visited[ny][nx] && board[ny][nx]) go(ny, nx);
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++) cin >> board[i][j];

    int y = 0, x = 0;
    go(y, x);
}