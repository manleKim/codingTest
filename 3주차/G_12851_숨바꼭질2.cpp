#include <bits/stdc++.h>
using namespace std;
const int MAX = 200000;
int visited[MAX + 4];
long long cnt[MAX + 4];
int n, k;
void bfs() {
    queue<int> q;
    visited[n] = 1;
    cnt[n] = 1;
    q.push(n);
    while (q.size()) {
        int here = q.front();
        q.pop();
        for (int i : {here + 1, here - 1, here * 2}) {
            if (0 <= i && i <= MAX) {
                if (!visited[i]) {
                    q.push(i);
                    visited[i] = visited[here] + 1;
                    cnt[i] += cnt[here];
                } else if (visited[i] == visited[here] + 1) {
                    cnt[i] += cnt[here];
                }
            }
        }
    }
    cout << visited[k] - 1 << '\n';
    cout << cnt[k] << '\n';
    return;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k;
    if (n == k) {
        cout << 0 << '\n' << 1;
        return 0;
    }
    bfs();
}
