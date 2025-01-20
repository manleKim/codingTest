#include <bits/stdc++.h>
using namespace std;
#define y1 aaa
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int a[101][101], visited[101][101];
int n, m, k, x1, x2, y1, y2, cnt;
vector<int> ret;
int dfs(int y, int x) {
    int ret = 1;
    visited[y][x] = 1;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= m || nx >= n) continue;
        if (a[ny][nx] || visited[ny][nx]) continue;
        ret += dfs(ny, nx);
    }
    return ret;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> m >> n >> k;
    for (int t = 0; t < k; t++) {
        cin >> x1 >> y1 >> x2 >> y2;
        for (int i = y1; i < y2; i++)
            for (int j = x1; j < x2; j++) a[i][j] = 1;
    }
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (!a[i][j] && !visited[i][j]) {
                cnt++;
                ret.push_back(dfs(i, j));
            }
    sort(ret.begin(), ret.end());
    cout << cnt << '\n';
    for (int i : ret) cout << i << ' ';
}