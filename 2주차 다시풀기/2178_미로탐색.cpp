#include <bits/stdc++.h>
using namespace std;

int n, m, y, x;
string s[102];
int visited[102][102];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    queue<pair<int, int>> q;
    q.push({0, 0});
    visited[0][0] = 1;

    while (q.size()) {
        tie(y, x) = q.front();
        // cout << "pop : " << y << ' ' << x << '\n';
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            // cout << ny << " : " << nx << '\n';

            if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
            if (visited[ny][nx] || s[ny][nx] == '0') continue;
            // cout << "푸쉬 : " << ny << " : " << nx << '\n';

            q.push({ny, nx});
            visited[ny][nx] = visited[y][x] + 1;
        }
    }

    cout << visited[n - 1][m - 1];
}