#include <bits/stdc++.h>
using namespace std;
string s;

bool mo(char ch) {
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

bool oneMo(string s) {
    for (int i = 0; i < s.size(); i++) {
        if (mo(s[i])) {
            return true;
        }
    }
    return false;
}

bool three(string s) {
    if (s.size() < 3) return false;
    for (int i = 0; i < s.size() - 2; i++) {
        if (mo(s[i]) && mo(s[i + 1]) && mo(s[i + 2]))  // 모음 3개 연속
            return true;

        if (!mo(s[i]) && !(mo(s[i + 1])) && !(mo(s[i + 2])))
            return true;  // 자음 3개 연속
    }
    return false;
}
bool sameTwo(string s) {
    for (int i = 0; i < s.size() - 1; i++) {
        if (s[i] == s[i + 1]) {
            if (!(s[i] == 'e') && !(s[i] == 'o')) return true;
        }
    }
    return false;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (true) {
        cin >> s;
        if (s == "end") break;

        // cout << oneMo(s) << ' ' << !three(s) << ' ' << !sameTwo(s) <<
        // '\n';

        if (oneMo(s) && !three(s) && !sameTwo(s))
            cout << '<' << s << "> is acceptable.\n";
        else
            cout << '<' << s << "> is not acceptable.\n";
    }
}