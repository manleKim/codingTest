#include <bits/stdc++.h>
using namespace std;
int n, k, ret, cnt;
int d[] = {-1, 1, 0};
int visited[200004];
queue<int> q;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    fill(&visited[0], &visited[0] + 200004, -1);
    bool flag = false;
    q.push(n);
    visited[n] = 0;
    while (q.size()) {
        int cur = q.front();
        q.pop();
        for (int i = 0; i < 3; i++) {
            int nx;
            if (i == 2)
                nx = cur * 2;
            else
                nx = cur + d[i];
            cout << nx << ' ';
            if (nx == k) {
                flag = 1;
                cnt++;
                continue;
            }
            if (nx >= 200000 || visited[nx] > -1) continue;
            visited[nx] = visited[cur] + 1;
            q.push(nx);
        }

        ret++;
        cout << '\n' << "ret " << ret << '\n';
        if (flag) break;
    }
    cout << ret << '\n' << cnt;
}