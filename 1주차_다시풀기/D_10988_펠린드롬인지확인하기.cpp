#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s, reverse_s;
    cin >> s;

    reverse_s = s;
    reverse(s.begin(), s.end());

    int flag = 1;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != reverse_s[i]) {
            flag = 0;
            break;
        }
    }

    cout << flag;
}