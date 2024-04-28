#include <bits/stdc++.h>
using namespace std;
int board[1002][1002];
int dist[1002][1002];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> m >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            dist[i][j] = -1;
        }
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 1) {
                q.push({i, j});
                dist[i][j] = 0;
            }
        }
    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (board[nx][ny] == -1 || board[nx][ny] == 1 || dist[nx][ny] != -1)
                continue;
            board[nx][ny] = 1;
            dist[nx][ny] = dist[cur.first][cur.second] + 1;
            q.push({nx, ny});
        }
    }
    int mx = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 0) {
                cout << -1;
                return 0;
            }
            mx = max(mx, dist[i][j]);
        }
    }
    cout << mx;
}