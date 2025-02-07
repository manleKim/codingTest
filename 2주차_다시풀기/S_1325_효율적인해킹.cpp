#include <bits/stdc++.h>
using namespace std;
int n, m, a, b, temp, mx, visited[10002];
vector<int> g[10002];
map<int, vector<int>> mp;
int dfs(int idx) {
    int cnt = 1;
    visited[idx] = 1;
    for (int i : g[idx]) {
        if (!visited[i]) {
            cnt += dfs(i);
        }
    }
    return cnt;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        g[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        memset(visited, 0, sizeof(visited));
        temp = dfs(i);
        mx = max(mx, temp);
        mp[temp].push_back(i);
    }

    for (auto i : mp[mx]) cout << i << ' ';
}