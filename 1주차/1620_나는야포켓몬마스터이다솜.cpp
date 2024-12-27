#include <bits/stdc++.h>
using namespace std;
int n, m;
map<string, int> m1;
map<int, string> m2;
string s;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> s;
        m1[s] = i + 1;
        m2[i + 1] = s;
    }
    for (int i = 0; i < m; i++) {
        cin >> s;

        if (atoi(s.c_str()) == 0) {  // 문자열이라면
            cout << m1[s] << '\n';
        } else {  // 숫자라면
            cout << m2[atoi(s.c_str())] << '\n';
        }
    }
}