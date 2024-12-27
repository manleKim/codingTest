#include <bits/stdc++.h>
using namespace std;

int r, c, ret, y, x;
string a[1004];
int bul_dist[1004][1004];
int jihoon_dist[1004][1004];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
pair<int, int> bul;
pair<int, int> jihoon;

void bfs() {}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        cin >> a[i];
        for (int j = 0; j < c; j++) {
            if (a[i][j] == 'J') jihoon = {i, j};
            if (a[i][j] == 'F') bul = {i, j};
        }
    }

    // 불 bfs
    queue<pair<int, int>> bul_q;
    bul_dist[bul.first][bul.second] = 1;
    bul_q.push(bul);

    while (bul_q.size()) {
        tie(y, x) = bul_q.front();
        bul_q.pop();
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || ny >= r || nx < 0 || nx >= c || a[ny][nx] == '#')
                continue;
            if (bul_dist[ny][nx]) continue;
            bul_dist[ny][nx] = bul_dist[y][x] + 1;
            bul_q.push({ny, nx});
        }
    }
    // 지훈 bfs
    queue<pair<int, int>> ji_q;
    jihoon_dist[jihoon.first][jihoon.second] = 1;
    ji_q.push(jihoon);
    bool flag = 0;
    while (ji_q.size()) {
        tie(y, x) = ji_q.front();
        ji_q.pop();
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || ny >= r || nx < 0 || nx >= c) {  // 탈출~
                flag = 1;
                cout << jihoon_dist[y][x] << '\n';
                return 0;
            }

            if (a[ny][nx] == '#' || jihoon_dist[ny][nx]) continue;
            if (bul_dist[ny][nx] &&
                (bul_dist[ny][nx] <= (jihoon_dist[y][x] + 1)))
                continue;
            jihoon_dist[ny][nx] = jihoon_dist[y][x] + 1;
            ji_q.push({ny, nx});
        }
    }

    if (!flag) cout << "IMPOSSIBLE";
}