#include <bits/stdc++.h>
using namespace std;
int n;
int max_n;
int a[102][102];        // 높이
int visited[102][102];  // 방문했나 안했나
int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};
int cnt;
int ret;
int ny, nx;

void dfs(int y, int x) {
    visited[y][x] = 1;
    for (int i = 0; i < 4; i++) {
        ny = y + dy[i];
        nx = x + dx[i];
        if (nx < 0 || ny < 0 || nx >= n || ny >= n || a[ny][nx] <= max_n)
            continue;
        if (visited[ny][nx] == 1) continue;
        dfs(ny, nx);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    // 입력 + 최대 높이 구하기
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            max_n = max(max_n, a[i][j]);
        }
    }

    // 1 ~ 최대 높이 - 1
    while (max_n--) {
        fill(&visited[0][0], &visited[0][0] + 101 * 101, 0);
        cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (a[i][j] > max_n && visited[i][j] == 0) {
                    cnt++;
                    dfs(i, j);
                }
            }
        }
        ret = max(ret, cnt);
    }
    cout << ret;
}