#include <bits/stdc++.h>
using namespace std;

int a[102][102];
int b[102][102];
int visited[102][102];
int n, ret;
int mx = -987654321;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

void dfs(int y, int x) {
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
        if (visited[ny][nx] || !b[ny][nx]) continue;
        visited[ny][nx] = 1;
        dfs(ny, nx);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            mx = max(mx, a[i][j]);
        }
    }

    while (mx--) {
        fill(&b[0][0], &b[0][0] + 101 * 101, 0);
        fill(&visited[0][0], &visited[0][0] + 101 * 101, 0);
        int res = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (a[i][j] > mx) b[i][j] = 1;
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (b[i][j] && !visited[i][j]) {
                    res++;
                    visited[i][j] = 1;
                    dfs(i, j);
                }
            }
        }
        ret = max(ret, res);
    }

    cout << ret;
}