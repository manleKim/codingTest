#include <bits/stdc++.h>
using namespace std;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
char a[1002][1002];
int r, c, fire[1002][1002], jihoon[1002][1002], y, x, ret;
queue<pair<int, int>> fire_q, jihoon_q;
int main() {
    scanf("%d %d", &r, &c);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf(" %1c", &a[i][j]);
            if (a[i][j] == 'F') {
                fire_q.push({i, j});
                fire[i][j] = 1;
            }
            if (a[i][j] == 'J') {
                jihoon_q.push({i, j});
                jihoon[i][j] = 1;
            }
        }
    }
    while (fire_q.size()) {
        tie(y, x) = fire_q.front();
        fire_q.pop();
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
            if (fire[ny][nx] || a[ny][nx] == '#') continue;
            fire_q.push({ny, nx});
            fire[ny][nx] = fire[y][x] + 1;
        }
    }

    while (jihoon_q.size()) {
        tie(y, x) = jihoon_q.front();
        jihoon_q.pop();
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || nx < 0 || ny >= r || nx >= c) {
                printf("%d", jihoon[y][x]);
                return 0;
            };
            if (jihoon[ny][nx] || a[ny][nx] == '#') continue;
            if (fire[ny][nx] && (fire[ny][nx] <= jihoon[y][x] + 1)) continue;
            jihoon_q.push({ny, nx});
            jihoon[ny][nx] = jihoon[y][x] + 1;
        }
    }
    printf("IMPOSSIBLE");
}