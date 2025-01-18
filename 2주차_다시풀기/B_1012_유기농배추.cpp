#include <bits/stdc++.h>
using namespace std;
const int max_n = 52;
int t, m, n, k, x, y, ret;
int a[max_n][max_n], visited[max_n][max_n];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
void dfs(int y, int x) {
    visited[y][x] = 1;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= n || nx >= m || !a[y][x]) continue;
        if (visited[ny][nx]) continue;
        dfs(ny, nx);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    while (t--) {
        memset(a, 0, sizeof(a));  // fill(&a[0][0], &a[0][0] + 52 * 52, 0);
        memset(visited, 0, sizeof(visited));
        ret = 0;
        cin >> m >> n >> k;
        for (int i = 0; i < k; i++) {
            cin >> x >> y;
            a[y][x] = 1;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] && !visited[i][j]) {
                    ret++;
                    dfs(i, j);
                }
            }
        }
        cout << ret << '\n';
    }
}