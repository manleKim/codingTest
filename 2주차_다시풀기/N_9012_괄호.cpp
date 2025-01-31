#include <bits/stdc++.h>
using namespace std;
int t;
string s, ret;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    while (t--) {
        cin >> s;
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ')' && st.size() && st.top() == '(')
                st.pop();
            else
                st.push(s[i]);
        }
        if (st.empty())
            ret += "YES\n";
        else
            ret += "NO\n";
    }
    cout << ret;
}