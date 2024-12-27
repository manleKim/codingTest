#include <bits/stdc++.h>
using namespace std;

int n, k;
int arr[100001];
int psum[100001];
long long max_n = -10000000;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    for (int i = 0; i < n; i++) cin >> arr[i];
    for (int i = 0; i < k; i++) psum[0] += arr[i];
    max_n = psum[0];

    for (int i = 1; i < n - k + 1; i++) {
        psum[i] = psum[i - 1] - arr[i - 1] + arr[i + k - 1];
        // cout << psum[i] << ' ' << max_n << '\n';
        if (psum[i] > max_n) max_n = psum[i];
    }
    cout << max_n;
}