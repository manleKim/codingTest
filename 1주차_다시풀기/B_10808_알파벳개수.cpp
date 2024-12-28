#include <bits/stdc++.h>
using namespace std;

string s;
int cnt[27];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> s;

    for (char ch : s) cnt[ch - 'a']++;

    for (int i = 0; i < 26; i++) cout << cnt[i] << ' ';
}