#include <bits/stdc++.h>
using namespace std;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
int a[102][102], visited[102][102], n, m, ret, cnt;
vector<pair<int, int>> melting;
int chessCnt() {
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 1) {
                count++;
            }
        }
    }
    return count;
}
void go(int y, int x) {  // 공기 표시
    visited[y][x] = 1;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
        if (visited[ny][nx]) continue;
        if (a[ny][nx] == 1) {
            melting.push_back({ny, nx});
            continue;
        }
        go(ny, nx);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    cnt = chessCnt();
    while (true) {
        memset(visited, 0, sizeof(visited));
        melting.clear();
        // 공기에 맞닿은 치즈 구하기
        go(0, 0);
        // 치즈 녹이기
        for (int i = 0; i < melting.size(); i++)
            a[melting[i].first][melting[i].second] = 0;
        ret++;
        if (!chessCnt()) break;
        // 치즈 구하기
        cnt = chessCnt();
    }
    cout << ret << '\n' << cnt;
}