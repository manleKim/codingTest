#include <bits/stdc++.h>
using namespace std;

int h, w, y, x, ny, nx;
int visited[102][102];
string s;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> h >> w;
    fill(&visited[0][0], &visited[0][0] + 101 * 101, -1);
    queue<pair<int, int>> q;
    for (int i = 0; i < h; i++) {
        cin >> s;
        for (int j = 0; j < w; j++) {
            if (s[j] == 'c') {
                visited[i][j] = 0;
                q.push({i, j});
            }
        }
    }
    while (q.size()) {
        tie(y, x) = q.front();
        q.pop();
        ny = y;
        nx = x + 1;
        if (ny < 0 || nx < 0 || ny >= h || nx >= w) continue;
        if (visited[ny][nx] >= 0) continue;
        q.push({ny, nx});
        visited[ny][nx] = visited[y][x] + 1;
    }

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cout << visited[i][j] << ' ';
        }
        cout << '\n';
    }
}