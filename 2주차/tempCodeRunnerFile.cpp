#include <bits/stdc++.h>
using namespace std;

int n, a, root, d;
int ret;
vector<int> t[51];
int visited[51];

void dfs(int i) {
    visited[i] = 1;
    for (auto a : t[i]) {
        if (a == d) continue;
        if (!visited[a] && t[a].empty()) {
            ret++;
            visited[a] = 1;
            continue;
        }
        if (!visited[a]) dfs(a);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a;
        if (a == -1)
            root = i;
        else
            t[a].push_back(i);
    }
    cin >> d;
    if (root == d) {
        cout << 0 << '\n';
    } else {
        dfs(root);
        cout << ret;
    }
}