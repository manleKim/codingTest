#include <bits/stdc++.h>
using namespace std;
string re_s;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> re_s;
    string s = re_s;
    reverse(re_s.begin(), re_s.end());
    if (re_s == s)
        cout << 1;
    else
        cout << 0;
}