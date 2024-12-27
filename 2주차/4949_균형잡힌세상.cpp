#include <bits/stdc++.h>
using namespace std;

string s;

bool check(string s) {
    stack<char> a;
    for (auto ch : s) {
        if (ch == '(')
            a.push(ch);
        else if (ch == '[')
            a.push(ch);
        else if (ch == ')') {
            if (a.empty()) return false;
            if (a.top() != '(') return false;
            a.pop();
        } else if (ch == ']') {
            if (a.empty()) return false;
            if (a.top() != '[') return false;
            a.pop();
        }
    }
    return a.empty();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (;;) {
        getline(cin, s);
        if (s == ".") return 0;
        if (check(s))
            cout << "yes" << '\n';
        else
            cout << "no" << '\n';
    }
}