#include <bits/stdc++.h>
using namespace std;

int n, a, root, d;
int ret;
vector<int> t[52];
int visited[52];

void dfs(int i) {
    visited[i] = 1;
    if (t[i].empty()) {
        ret++;
        return;
    }

    for (auto a : t[i]) {
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
    for (int i = 0; i < n; i++) {
        auto it = find(t[i].begin(), t[i].end(), d);
        if (it != t[i].end()) t[i].erase(it);
    }
    if (root == d) {
        cout << 0 << '\n';
    } else {
        dfs(root);
        cout << ret;
    }
}