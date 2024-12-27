#include <bits/stdc++.h>
using namespace std;
string board[1002];
int fire[1002][1002];
int jihoon[1002][1002];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> board[i];
    for (int i = 0; i < n; i++) {
        fill(fire[i], fire[i] + m, -1);
        fill(jihoon[i], jihoon[i] + m, -1);
    }
    queue<pair<int, int>> q1;
    queue<pair<int, int>> q2;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 'F') {
                q1.push({i, j});
                fire[i][j] = 0;
            }
            if (board[i][j] == 'J') {
                q2.push({i, j});
                jihoon[i][j] = 0;
            }
        }

    while (!q1.empty()) {
        pair<int, int> cur = q1.front();
        q1.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (board[nx][ny] == '#' || fire[nx][ny] >= 0) continue;
            q1.push({nx, ny});
            fire[nx][ny] = fire[cur.first][cur.second] + 1;
        }
    }

    while (!q2.empty()) {
        pair<int, int> cur = q2.front();
        q2.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                cout << jihoon[cur.first][cur.second] + 1;
                return 0;
            }
            if (board[nx][ny] == '#' || jihoon[nx][ny] >= 0) continue;
            if (fire[nx][ny] != -1 &&
                jihoon[cur.first][cur.second] + 1 >= fire[nx][ny])
                continue;
            q2.push({nx, ny});
            jihoon[nx][ny] = jihoon[cur.first][cur.second] + 1;
        }
    }
    cout << "IMPOSSIBLE";
}