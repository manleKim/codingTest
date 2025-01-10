#include <bits/stdc++.h>
using namespace std;
string s, ret;
map<char, int, greater<char>> m;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> s;
    for (char ch : s) m[ch]++;
    int isOddOne = 0;
    for (auto i : m) {
        if (i.second % 2 == 1) {
            if (isOddOne) {
                cout << "I'm Sorry Hansoo";
                return 0;
            }
            isOddOne = 1;
            ret += i.first;
            m[i.first]--;
        }
    }
    for (auto i : m) {
        while (i.second > 0) {
            ret = i.first + ret + i.first;
            i.second -= 2;
        }
    }

    cout << ret;
}