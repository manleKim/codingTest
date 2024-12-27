#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (cin >> n) {
        ll ret = 1, cnt = 1;
        while (cnt % n != 0) {
            cnt = (cnt * 10) + 1;
            cout << cnt << '\n';
            cnt %= n;
            cout << cnt << '\n' << "-------------" << '\n';

            ret++;
        }
        cout << ret << '\n';
    }
}