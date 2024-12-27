#include <bits/stdc++.h>

using namespace std;

int num, n;
string s, type;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> num;
    while (num--) {
        map<string, int> m;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> s >> type;
            m[type]++;
        }
        int result = 1;
        for (auto i : m) {
            result *= (i.second + 1);
        }
        cout << result - 1 << '\n';
    }
}