#include <bits/stdc++.h>
using namespace std;
int n, k, a, result;
int sum[100002];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a;
        if (i == 0)
            sum[0] = a;
        else
            sum[i] = sum[i - 1] + a;
    }
    result = sum[k - 1];
    for (int i = k; i < n; i++) {
        result = max(result, sum[i] - sum[i - k - 1])
    }
}