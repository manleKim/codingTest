#include <bits/stdc++.h>
using namespace std;
string board[1002];
int dist[1002][1002];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int n, m;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> board[i];
        fill(dist[i], dist[i] + m, -1);
    }
    queue<pair<int, int>> q;
    dist[0][0] = 1;
    q.push({0, 0});
    bool isEscape = false;
    bool isBreak = false;
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if (nx == n - 1 && ny == m - 1) {
                isEscape = true;
                cout << dist[cur.first][cur.second] + 1;
                return 0;
            }
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if ((isBreak && board[nx][ny] == '1') || dist[nx][ny] != -1)
                continue;
            if (!isBreak && board[nx][ny] == '1') isBreak = true;
            dist[nx][ny] = dist[cur.first][cur.second] + 1;
            q.push({nx, ny});
            cout << nx << ' ' << ny;
        }
    }
    if (!isEscape) cout << -1;
    return 0;
}