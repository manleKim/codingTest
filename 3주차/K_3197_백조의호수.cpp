#include <bits/stdc++.h>
using namespace std;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
int r, c, ret, visited[1502][1502], visited2[1502][1502], flag, ok;
vector<pair<int, int>> v;
string s[1502];
queue<pair<int, int>> q;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        cin >> s[i];
        for (int j = 0; j < c; j++) {
            if (s[i][j] == 'L')
                v.push_back({i, j});
            else if (s[i][j] == '.') {
                q.push({i, j});
                visited[i][j] = 1;
            } else if (s[i][j] == 'X')
                flag = 1;
        }
    }
    if (!flag) {
        cout << 0;
        return 0;
    }
    while (q.size()) {
        int qSize = q.size();
        for (int i = 0; i < qSize; i++) {
            pair<int, int> temp = q.front();
            int y = temp.first;
            int x = temp.second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int ny = y + dy[i];
                int nx = x + dx[i];
                if (ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
                if (visited[ny][nx] || s[ny][nx] == 'L') continue;
                visited[ny][nx] = 1;
                if (s[ny][nx] == 'X') {
                    s[ny][nx] = '.';
                    q.push({ny, nx});
                    continue;
                }
            }
        }
        ret++;
        memset(visited2, 0, sizeof(visited2));
        while ()
            if (ok) break;
    }
    cout << ret;
}