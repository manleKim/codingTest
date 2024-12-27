#include <bits/stdc++.h>
using namespace std;
int n, m, mx;
string s;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
char a[54][54];
int visited[54][54];

void bfs(int y, int x) {
    fill(&visited[0][0], &visited[0][0] + 52 * 52, 0);
    queue<pair<int, int>> q;
    q.push({y, x});
    visited[y][x] = 1;

    while (q.size()) {
        tie(y, x) = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || nx < 0 || ny >= n || nx >= m || a[ny][nx] == 'W')
                continue;
            if (visited[ny][nx]) continue;
            visited[ny][nx] = visited[y][x] + 1;
            q.push({ny, nx});
            mx = max(mx, visited[ny][nx]);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 'L') bfs(i, j);
        }
    }

    cout << mx - 1;
}