#include <bits/stdc++.h>
using namespace std;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
int a[10][10], visited[10][10], ret, n, m;
vector<pair<int, int>> wall, virus;
void dfs(int y, int x) {
    visited[y][x] = 1;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
        if (a[ny][nx] != 0 || visited[ny][nx]) continue;
        dfs(ny, nx);
    }
}
int spread() {  // 바이러스 퍼뜨리기 + max 값 구하기
    int cnt = 0;
    memset(visited, 0, sizeof(visited));
    for (int i = 0; i < virus.size(); i++) dfs(virus[i].first, virus[i].second);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 0 && !visited[i][j]) cnt++;
        }
    }

    return cnt;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            if (a[i][j] == 0) wall.push_back({i, j});
            if (a[i][j] == 2) virus.push_back({i, j});
        }
    }

    for (int i = 0; i < wall.size(); i++) {
        for (int j = 0; j < i; j++) {
            for (int k = 0; k < j; k++) {
                a[wall[i].first][wall[i].second] = 1;
                a[wall[j].first][wall[j].second] = 1;
                a[wall[k].first][wall[k].second] = 1;
                ret = max(ret, spread());
                a[wall[i].first][wall[i].second] = 0;
                a[wall[j].first][wall[j].second] = 0;
                a[wall[k].first][wall[k].second] = 0;
            }
        }
    }
    cout << ret;
}