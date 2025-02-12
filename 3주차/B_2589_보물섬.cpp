#include <bits/stdc++.h>
using namespace std;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
int n, m, visited[52][52], y, x, mx = -987654321;
char a[52][52];
vector<pair<int, int>> land;
int main() {
    ios::sync_with_stdio(false);
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf(" %1c", &a[i][j]);
            if (a[i][j] == 'L') land.push_back({i, j});
        }
    }
    for (int i = 0; i < land.size(); i++) {
        memset(visited, -1, sizeof(visited));
        queue<pair<int, int>> q;
        q.push({land[i].first, land[i].second});
        visited[land[i].first][land[i].second] = 0;
        while (q.size()) {
            tie(y, x) = q.front();
            q.pop();
            for (int d = 0; d < 4; d++) {
                int ny = y + dy[d];
                int nx = x + dx[d];
                if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
                if (a[ny][nx] == 'W' || visited[ny][nx] >= 0) continue;
                visited[ny][nx] = visited[y][x] + 1;
                mx = max(mx, visited[ny][nx]);
                q.push({ny, nx});
            }
        }
    }
    printf("%d", mx);
}