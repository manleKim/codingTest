#include <bits/stdc++.h>
using namespace std;
int t, ret;
string s;
void goodWords(string &s) {
    stack<char> st;
    for (int i = 0; i < s.size(); i++) {
        if (st.empty())
            st.push(s[i]);
        else if (st.top() == s[i])
            st.pop();
        else
            st.push(s[i]);
    }
    if (st.empty()) ret++;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> s;
        goodWords(s);
    }
    cout << ret;
}