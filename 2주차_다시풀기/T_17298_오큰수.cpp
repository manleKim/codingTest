#include <bits/stdc++.h>
using namespace std;
int n, input;
stack<pair<int, int>> st;
int a[1000002];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    memset(a, -1, sizeof(a));
    for (int i = 0; i < n; i++) {
        cin >> input;
        if (!st.empty()) {
            while (st.size() && st.top().first < input) {
                pair<int, int> temp = st.top();
                st.pop();
                a[temp.second] = input;
            }
        }
        st.push({input, i});
    }
    for (int i = 0; i < n; i++) {
        cout << a[i] << ' ';
    }
}