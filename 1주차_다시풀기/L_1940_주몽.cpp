#include <bits/stdc++.h>
using namespace std;
int n, m, num, cnt;
int a[10000002];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> num;
        if (m - num > 0 && a[m - num]) {
            cnt++;
        }
        a[num]++;
    }

    cout << cnt;
}