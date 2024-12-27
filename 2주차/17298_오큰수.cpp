#include <bits/stdc++.h>
using namespace std;
int n;
int a[1000004], ret[1000004];
stack<int> s;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    fill(&ret[0], &ret[0] + 1000002, -1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        while (s.size() && a[s.top()] < a[i]) {
            ret[s.top()] = a[i];
            s.pop();
        }
        s.push(i);
    }

    for (int i = 0; i < n; i++) cout << ret[i] << " ";
}