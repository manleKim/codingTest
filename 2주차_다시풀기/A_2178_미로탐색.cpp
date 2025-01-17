#include <bits/stdc++.h>
using namespace std;
int n, m, y, x, ny, nx;
string a[102];
int visited[102][102];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int bfs() {
    queue<pair<int, int>> q;
    q.push({0, 0});
    visited[0][0] = 1;
    while (q.size()) {
        tie(y, x) = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            ny = y + dy[i];
            nx = x + dx[i];
            if (ny == n - 1 && nx == m - 1) return visited[y][x] + 1;
            if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
            if (a[ny][nx] == '0' || visited[ny][nx]) continue;

            visited[ny][nx] = visited[y][x] + 1;
            q.push({ny, nx});
        }
    }
    return 0;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    cout << bfs();
}