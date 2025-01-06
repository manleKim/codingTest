#include <bits/stdc++.h>
using namespace std;
map<string, int> cnt;
int t, n, ret;
string name, type;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        cnt.clear();
        for (int i = 0; i < n; i++) {
            cin >> name >> type;
            cnt[type]++;
        }
        ret = 1;
        for (auto i : cnt) {
            ret *= i.second + 1;
        }
        cout << ret - 1 << '\n';
    }
}