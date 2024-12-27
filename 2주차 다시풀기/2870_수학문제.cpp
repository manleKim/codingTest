#include <bits/stdc++.h>
using namespace std;
int n;
string s;

bool isDisit(char ch) { return ch - '0' >= 0 && ch - '0' <= 9; }

void a(string s) {
    string temp = "";
    for (int i = 0; i < s.size(); i++) {
        if (temp.size() && !isDisit(s[i])) {
            
        }
        if (isDisit(s[i])) {
            temp += s[i];
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        a(s);
    }
}