#include <bits/stdc++.h>
using namespace std;
int a[52][52];
int visited[52][52];
int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};
int t, n, m, k, y, x, ny, nx;

void dfs(int y, int x) {
    visited[y][x] = 1;
    for (int i = 0; i < 4; i++) {
        ny = y + dy[i];
        nx = x + dx[i];
        if (ny < 0 || nx < 0 || nx >= m || ny >= n || a[ny][nx] == 0) continue;
        if (visited[ny][nx] == 1) continue;
        dfs(ny, nx);
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while (t--) {
        fill(&a[0][0], &a[0][0] + 51 * 51, 0);
        fill(&visited[0][0], &visited[0][0] + 51 * 51, 0);
        cin >> m >> n >> k;
        for (int i = 0; i < k; i++) {
            cin >> x >> y;
            a[y][x] = 1;
        }
        int result = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] == 1 && visited[i][j] == 0) {
                    result++;
                    dfs(i, j);
                }
            }
        }
        cout << result << '\n';
    }
}