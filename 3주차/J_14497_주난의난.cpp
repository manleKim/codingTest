#include <bits/stdc++.h>
using namespace std;
#define y1 aaa
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
int n, m, x1, y1, x2, y2, visited[302][302], y, x, ok, ret;
string s[302];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    cin >> x1 >> y1 >> x2 >> y2;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    queue<pair<int, int>> q;
    q.push({x1 - 1, y1 - 1});
    visited[x1 - 1][y1 - 1] = 1;
    while (true) {
        if (ok) break;
        memset(visited, 0, sizeof(visited));
        q.push({x1 - 1, y1 - 1});
        visited[x1 - 1][y1 - 1] = 1;
        while (q.size()) {
            tie(y, x) = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int ny = y + dy[i];
                int nx = x + dx[i];
                if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
                if (visited[ny][nx]) continue;
                if (s[ny][nx] == '#') {
                    ok = 1;
                    break;
                }
                visited[ny][nx] = 1;
                if (s[ny][nx] == '1') {
                    s[ny][nx] = '0';
                    continue;
                }
                q.push({ny, nx});
            }
            if (ok) break;
        }
        ret++;
    }
    cout << ret;
}