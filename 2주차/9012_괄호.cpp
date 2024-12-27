#include <bits/stdc++.h>
using namespace std;
int t;
string s;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> s;
        stack<char> st;
        bool flag = false;
        for (auto ch : s) {
            if (ch == '(') {
                st.push(ch);
            } else if (ch == ')') {
                if (st.size() > 0) {
                    st.pop();
                } else {
                    flag = true;
                    break;
                }
            }
        }
        if (flag)
            cout << "NO" << '\n';
        else {
            if (st.size() > 0)
                cout << "NO" << '\n';
            else
                cout << "YES" << '\n';
        }
    }
}