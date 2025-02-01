#include <bits/stdc++.h>
using namespace std;
string s, ret;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    while (getline(cin, s)) {
        if (s == ".") break;
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ')') {
                if (st.size() && st.top() == '(')
                    st.pop();
                else
                    st.push(s[i]);
            } else if (s[i] == ']') {
                if (st.size() && st.top() == '[')
                    st.pop();
                else
                    st.push(s[i]);
            } else if (s[i] == '(' || s[i] == '[')
                st.push(s[i]);
        }
        if (st.empty())
            ret += "yes\n";
        else
            ret += "no\n";
    }
    cout << ret;
}