#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll one(int n) {
    ll ret = 1;
    int cnt = 1;
    for (;;) {
        if (ret % n == 0) break;
        ret = ret * 10 + 1;
        ret %= n;
        cnt++;
    }
    return cnt;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    while (cin >> n) {
        cout << one(n) << '\n';
    }
}