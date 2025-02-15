#include <bits/stdc++.h>
using namespace std;
struct Hp {
    int a, b, c;
};
int attack[6][3] = {{1, 3, 9}, {1, 9, 3}, {3, 1, 9},
                    {3, 9, 1}, {9, 1, 3}, {9, 3, 1}};
int n, a[4], visited[61][61][61];
queue<Hp> q;
int bfs(int a, int b, int c) {
    visited[a][b][c] = 1;
    q.push({a, b, c});
    while (q.size()) {
        int a = q.front().a;
        int b = q.front().b;
        int c = q.front().c;
        q.pop();
        if (visited[0][0][0]) break;
        for (auto i : attack) {
            int na = max(0, a - i[0]);
            int nb = max(0, b - i[1]);
            int nc = max(0, c - i[2]);
            if (visited[na][nb][nc]) continue;
            visited[na][nb][nc] = visited[a][b][c] + 1;
            q.push({na, nb, nc});
        }
    }
    return visited[0][0][0] - 1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    cout << bfs(a[0], a[1], a[2]);
}