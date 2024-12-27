#include <bits/stdc++.h>
using namespace std;

int m, n, k, ly, lx, ry, rx;
int a[102][102];
int visited[102][102];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
vector<int> v;

int dfs(int y, int x) {
    int res = 1;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= m || nx < 0 || nx >= n) continue;
        if (a[ny][nx] || visited[ny][nx]) continue;
        visited[ny][nx] = 1;
        res += dfs(ny, nx);
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n >> k;
    for (int i = 0; i < k; i++) {
        cin >> lx >> ly >> rx >> ry;

        for (int j = ly; j < ry; j++) {
            for (int k = lx; k < rx; k++) {
                a[j][k] = 1;
            }
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (!a[i][j] && !visited[i][j]) {
                visited[i][j] = 1;
                v.push_back(dfs(i, j));
            }
        }
    }

    sort(v.begin(), v.end());

    cout << v.size() << '\n';
    for (int i : v) cout << i << ' ';
}