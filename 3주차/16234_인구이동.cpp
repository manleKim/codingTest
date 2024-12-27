#include <bits/stdc++.h>
using namespace std;
int n, l, r, cnt, sum;
int a[52][52];
int visited[52][52];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
vector<pair<int, int>> v;

void dfs(int y, int x) {
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= n || nx < 0 || nx >= n || visited[ny][nx]) continue;
        if (abs(a[y][x] - a[ny][nx]) < l || abs(a[y][x] - a[ny][nx]) > r)
            continue;
        visited[ny][nx] = 1;
        v.push_back({ny, nx});
        sum += a[ny][nx];
        dfs(ny, nx);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> l >> r;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    while (true) {
        bool flag = 0;
        fill(&visited[0][0], &visited[0][0] + 51 * 51, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j]) {
                    v.clear();
                    v.push_back({i, j});
                    visited[i][j] = 1;
                    sum = a[i][j];
                    dfs(i, j);
                    if (v.size() == 1) continue;
                    int avg = sum / v.size();
                    flag = 1;
                    for (auto b : v) {
                        a[b.first][b.second] = avg;
                    }
                }
            }
        }
        if (!flag) break;
        cnt++;
    }
    cout << cnt;
}