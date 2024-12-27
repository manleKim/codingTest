#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll A, B, C, res;
ll go(ll A, ll B) {
    if (B == 1) return A % C;
    ll ret = go(A, B / 2);
    ret = (ret * ret) % C;
    if (B % 2) ret = (ret * A) % C;
    return ret;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> A >> B >> C;

    cout << go(A, B);
}