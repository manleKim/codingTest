#include <bits/stdc++.h>
using namespace std;
int n, m, a[52][52], visited[52][52], ret = 987654321;
vector<pair<int, int>> v, home, chicken;
void solve(int idx) {
    if (v.size() == m) {
        int sum = 0;
        for (int i = 0; i < home.size(); i++) {
            int dist = 987654321;
            for (int j = 0; j < v.size(); j++) {
                dist = min(dist, abs(home[i].first - v[j].first) +
                                     abs(home[i].second - v[j].second));
            }
            sum += dist;
        }
        ret = min(ret, sum);
        return;
    }
    for (int i = idx + 1; i < chicken.size(); i++) {
        if (visited[chicken[i].first][chicken[i].second]) continue;
        visited[chicken[i].first][chicken[i].second] = 1;
        v.push_back({chicken[i].first, chicken[i].second});
        solve(i);
        v.pop_back();
        visited[chicken[i].first][chicken[i].second] = 0;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            if (a[i][j] == 1) home.push_back({i, j});
            if (a[i][j] == 2) chicken.push_back({i, j});
        }
    }
    solve(-1);
    cout << ret;
}