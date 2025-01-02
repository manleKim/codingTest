#include <bits/stdc++.h>
using namespace std;
string ret;

char rot13(char ch) {
    if (ch >= 'a' && ch <= 'z')
        return ch + 13 > 'z' ? ((ch + 13) % ('z' + 1)) + 'a' : ch + 13;
    if (ch >= 'A' && ch <= 'Z')
        return ch + 13 > 'Z' ? ((ch + 13) % ('Z' + 1)) + 'A' : ch + 13;
    return ch;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    getline(cin, s);

    for (char ch : s) ret += rot13(ch);

    cout << ret;
}