#include <bits/stdc++.h>
using namespace std;

int ret[26];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string a;
    cin >> a;

    for (auto i : a) ret[i - 'a']++;

    for (auto i : ret) cout << i << ' ';
}