#include <bits/stdc++.h>
using namespace std;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
int n, l, r, a[52][52], visited[52][52], sum, avg, ret;
vector<pair<int, int>> v;

void dfs(int y, int x) {
    // cout << "dfs " << y << ' ' << x << '\n';
    visited[y][x] = 1;
    sum += a[y][x];
    v.push_back({y, x});
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
        if (visited[ny][nx]) continue;
        int diff = abs(a[y][x] - a[ny][nx]);
        if (diff < l || diff > r) continue;
        dfs(ny, nx);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> l >> r;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    while (true) {
        memset(visited, 0, sizeof(visited));
        bool flag = false;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j]) {
                    sum = 0;
                    v.clear();
                    dfs(i, j);
                    if (v.size() > 1) flag = true;
                    avg = sum / v.size();
                    for (auto k : v) a[k.first][k.second] = avg;
                }
            }
        }
        if (flag)
            ret++;
        else
            break;
    }
    cout << ret;
}