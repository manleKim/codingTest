#include <bits/stdc++.h>
using namespace std;

int t, m, n, k, y, x, ret;
int a[52][52], visited[52][52];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

void dfs(int y, int x) {
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
        if (!a[ny][nx] || visited[ny][nx]) continue;
        visited[ny][nx] = 1;
        dfs(ny, nx);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while (t--) {
        fill(&visited[0][0], &visited[0][0] + 51 * 51, 0);
        fill(&a[0][0], &a[0][0] + 51 * 51, 0);
        ret = 0;

        cin >> m >> n >> k;
        for (int i = 0; i < k; i++) {
            cin >> x >> y;
            a[y][x] = 1;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] == 1 && !visited[i][j]) {
                    ret++;
                    visited[i][j] = 1;
                    dfs(i, j);
                }
            }
        }

        cout << ret << '\n';
    }
}