#include <bits/stdc++.h>
using namespace std;
int n, m, y, x, nx, ny;
int a[102][102];
int visited[102][102];
string s;
int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < m; j++) a[i][j] = s[j] - '0';
    }

    queue<pair<int, int>> q;
    q.push({0, 0});
    while (q.size()) {
        tie(y, x) = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            ny = y + dy[i];
            nx = x + dx[i];
            if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
            if (a[ny][nx] == 0 || visited[ny][nx] > 0) continue;
            visited[ny][nx] = visited[y][x] + 1;
            q.push({ny, nx});
        }
    }
    cout << visited[n - 1][m - 1] + 1 << '\n';
}