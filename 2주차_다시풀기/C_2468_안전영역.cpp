#include <bits/stdc++.h>
using namespace std;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int n, ret, mx;
int board[101][101], a[101][101], visited[101][101];
void dfs(int y, int x) {
    visited[y][x] = 1;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= n || nx >= n || a[ny][nx]) continue;
        if (visited[ny][nx]) continue;
        dfs(ny, nx);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
            mx = max(mx, board[i][j]);
        }

    while (mx--) {
        fill(&a[0][0], &a[0][0] + 101 * 101, 0);
        fill(&visited[0][0], &visited[0][0] + 101 * 101, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] <= mx) a[i][j] = 1;  // 잠김
            }
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!a[i][j] && !visited[i][j]) {
                    res++;
                    dfs(i, j);
                }
            }
        }
        ret = max(res, ret);
    }

    cout << ret;
}