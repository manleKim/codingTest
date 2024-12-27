#include <bits/stdc++.h>
using namespace std;
int n, m;
int cnt[10000003];
int a, ret;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> a;
        if ((m >= a) && cnt[m - a]) ret++;
        cnt[a] = 1;
    }
    cout << ret;
}