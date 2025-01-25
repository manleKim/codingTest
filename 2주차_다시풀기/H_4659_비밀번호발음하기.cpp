#include <bits/stdc++.h>
using namespace std;
string s, ret;
int is_vowel, vcnt, ccnt, flag;
bool isVowel(char ch) {
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int prev = -1;
    while (true) {
        cin >> s;
        if (s == "end") break;
        vcnt = ccnt = is_vowel = flag = 0;
        for (int i = 0; i < s.size(); i++) {
            if (isVowel(s[i]))
                is_vowel = 1, vcnt++, ccnt = 0;
            else
                vcnt = 0, ccnt++;
            if (vcnt == 3 || ccnt == 3) flag = 1;
            if (i >= 1 && s[prev] == s[i] && s[i] != 'e' && s[i] != 'o')
                flag = 1;
            prev = i;
        }
        if (!is_vowel) flag = 1;
        if (flag)
            ret += "<" + s + "> is not acceptable.\n";
        else
            ret += "<" + s + "> is acceptable.\n";
    }
    cout << ret;
}