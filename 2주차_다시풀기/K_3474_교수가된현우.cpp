#include <bits/stdc++.h>
using namespace std;
int t, n;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n;
        int cnt2 = 0, cnt5 = 0;
        for (int j = 2; j <= n; j *= 2) {
            cnt2 += n / j;
        }
        for (int k = 5; k <= n; k *= 5) {
            cnt5 += n / k;
        }
        cout << min(cnt2, cnt5) << '\n';
    }
}