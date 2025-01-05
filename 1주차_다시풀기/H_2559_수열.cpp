#include <bits/stdc++.h>
using namespace std;

int n, k, mx = -1e9;
int a[100002], psum[100002];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i == 0) {
            psum[i + 1] = a[i];
            continue;
        }
        psum[i + 1] = psum[i] + a[i];
    }

    for (int i = 0; i < n - k + 1; i++) mx = max(mx, psum[k + i] - psum[i]);

    cout << mx;
}