#include <bits/stdc++.h>
using namespace std;

int n;
string pattern, pre, suf;

void check(string s) {
    if (s.size() < pre.size() + suf.size())
        cout << "NE" << '\n';
    else if (pre == s.substr(0, pre.size()) &&
             suf == s.substr(s.size() - suf.size()))
        cout << "DA" << '\n';
    else
        cout << "NE" << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    cin >> pattern;

    auto idx = pattern.find('*');
    pre = pattern.substr(0, idx);
    suf = pattern.substr(idx + 1);

    for (int i = 0; i < n; i++) {
        string temp;
        cin >> temp;
        check(temp);
    }
}