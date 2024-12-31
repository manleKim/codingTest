#include <bits/stdc++.h>
using namespace std;
int n;
map<char, int> cnt;
string ret;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        string temp;
        cin >> temp;
        cnt[temp[0]]++;
    }

    for (auto i : cnt)
        if (i.second >= 5) ret += i.first;

    if (ret.size() == 0) ret = "PREDAJA";

    cout << ret;
}