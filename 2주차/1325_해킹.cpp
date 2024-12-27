#include <bits/stdc++.h>
using namespace std;
int n, m, s, e, ret, max_n;
vector<int> v[10002];
vector<pair<int, int>> res;
int visited[10002];

bool comp(pair<int, int> &a, pair<int, int> &b) {
    if (a.second == b.second) return a.first < b.first;
    return a.second > b.second;
}

int dfs(int idx) {
    int cnt = 1;
    visited[idx] = 1;
    if (v[idx].empty()) {
        return cnt;
    }
    for (auto a : v[idx]) {
        if (visited[a]) continue;
        cnt += dfs(a);
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> s >> e;
        v[e].push_back(s);
    }

    for (int i = 1; i <= n; i++) {
        fill(&visited[0], &visited[0] + 10001, 0);
        int temp = dfs(i);
        max_n = max(max_n, temp);
        res.push_back({i, temp});
    }
    sort(res.begin(), res.end(), comp);

    for (auto b : res) {
        if (b.second == max_n) cout << b.first << ' ';
    }
}