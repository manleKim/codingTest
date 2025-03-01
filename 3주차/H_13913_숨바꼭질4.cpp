#include <bits/stdc++.h>
using namespace std;
#define prev aaa
const int MAX = 200000;
int n, k, visited[MAX + 4], prev[MAX + 4];
vector<int> v;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memset(prev, -1, sizeof(prev));
    cin >> n >> k;
    if (n == k) cout << 0 << '\n' << n;
    visited[n] = 1;
    queue<int> q;
    q.push(n);
    while (q.size()) {
        int now = q.front();
        q.pop();
        if (now == k) {
            cout << visited[now] - 1 << '\n';
            for (int i = k; i != n; i = prev[i]) {
                v.push_back(i);
            }
            v.push_back(n);
            reverse(v.begin(), v.end());
            for (int i : v) cout << i << ' ';
            return 0;
        }
        for (int next : {now + 1, now - 1, now * 2}) {
            if (next >= MAX || next < 0 || visited[next]) continue;
            visited[next] = visited[now] + 1;
            q.push(next);
            prev[next] = now;
        }
    }
    return 0;
}