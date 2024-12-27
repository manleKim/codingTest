#include <bits/stdc++.h>
using namespace std;
int n, m, ny, nx, t, ret;
int a[102][102];
int visited[102][102];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
vector<pair<int, int>> c;

void dfs(int y, int x) {
    if (a[y][x] == 1) {
        c.push_back({y, x});
        return;
    }
    for (int i = 0; i < 4; i++) {
        ny = y + dy[i];
        nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
        if (visited[ny][nx]) continue;
        visited[ny][nx] = 1;
        dfs(ny, nx);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) cin >> a[i][j];

    while (true) {
        fill(&visited[0][0], &visited[0][0] + 101 * 101, 0);
        c.clear();
        dfs(0, 0);
        for (auto b : c) a[b.first][b.second] = 0;
        bool flag = false;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] == 1) flag = true;
            }
        }
        t++;
        ret = c.size();
        if (!flag) break;
    }
    cout << t << '\n' << ret;
}