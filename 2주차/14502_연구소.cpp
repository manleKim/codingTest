#include <bits/stdc++.h>
using namespace std;
int a[10][10];
int visited[10][10];
int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};
int n, m, ny, nx, ret;
vector<pair<int, int>> wallList, virusList;

void dfs(int y, int x) {
    for (int i = 0; i < 4; i++) {
        ny = y + dy[i];
        nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= n || nx >= m || visited[ny][nx] == 1 ||
            a[ny][nx] == 1)
            continue;
        visited[ny][nx] = 1;
        dfs(ny, nx);
    }
}

int solve() {  // dfs -> 카운팅
    fill(&visited[0][0], &visited[0][0] + 10 * 10, 0);
    for (auto b : virusList) {
        visited[b.first][b.second] = 1;
        dfs(b.first, b.second);
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 0 && visited[i][j] == 0) cnt++;
        }
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            if (a[i][j] == 0) wallList.push_back({i, j});
            if (a[i][j] == 2) virusList.push_back({i, j});
        }
    }

    for (int i = 0; i < wallList.size(); i++) {
        for (int j = 0; j < i; j++) {
            for (int k = 0; k < j; k++) {
                a[wallList[i].first][wallList[i].second] = 1;
                a[wallList[j].first][wallList[j].second] = 1;
                a[wallList[k].first][wallList[k].second] = 1;
                // dfs하고 카운팅
                ret = max(ret, solve());
                a[wallList[i].first][wallList[i].second] = 0;
                a[wallList[j].first][wallList[j].second] = 0;
                a[wallList[k].first][wallList[k].second] = 0;
            }
        }
    }
    cout << ret;
}