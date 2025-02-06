#include <bits/stdc++.h>
using namespace std;
int n, parent, root, remove_node, cnt, visited[52];
vector<int> node[51];
void dfs(int idx) {
    visited[idx] = 1;
    if (idx == remove_node) return;
    if (node[idx].size() == 0 ||
        (node[idx].size() == 1 && node[idx][0] == remove_node)) {
        cnt++;
        return;
    }
    for (int i : node[idx]) {
        if (visited[i] || i == remove_node) continue;
        dfs(i);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> parent;
        if (parent == -1)
            root = i;
        else
            node[parent].push_back(i);
    }
    cin >> remove_node;
    dfs(root);
    cout << cnt;
}