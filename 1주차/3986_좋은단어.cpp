#include <bits/stdc++.h>
using namespace std;
int n, res;
string s;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    while (n--) {
        cin >> s;
        stack<char> st;
        for (char a : s) {
            if (st.size() == 0)
                st.push(a);
            else if (st.top() == a)
                st.pop();
            else
                st.push(a);
        }
        if (st.size() == 0) res++;
    }
    cout << res;
}