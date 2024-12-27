#include <bits/stdc++.h>
using namespace std;
int m, n, k, ldx, ldy, rux, ruy, nx, ny, x, y, ret, area;
int a[102][102];
int visited[102][102];
int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};
vector<int> res;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n >> k;

    for (int i = 0; i < k; i++) {
        cin >> ldx >> ldy >> rux >> ruy;
        for (int i = ldy; i < ruy; i++) {
            for (int j = ldx; j < rux; j++) {
                a[i][j] = 1;
            }
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] == 0 && visited[i][j] == 0) {
                area = 1;
                queue<pair<int, int>> q;
                q.push({i, j});
                visited[i][j] = 1;

                while (q.size()) {
                    tie(y, x) = q.front();
                    q.pop();

                    for (int d = 0; d < 4; d++) {
                        ny = y + dy[d];
                        nx = x + dx[d];

                        if (nx < 0 || ny < 0 || nx >= n || ny >= m ||
                            a[ny][nx] == 1)
                            continue;
                        if (visited[ny][nx] == 1) continue;

                        visited[ny][nx] = 1;
                        area++;
                        q.push({ny, nx});
                    }
                }
                ret++;
                res.push_back(area);
            }
        }
    }

    cout << ret << '\n';
    sort(res.begin(), res.end());
    for (int i = 0; i < res.size(); i++) cout << res[i] << ' ';
}