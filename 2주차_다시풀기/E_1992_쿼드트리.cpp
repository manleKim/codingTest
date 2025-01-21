#include <bits/stdc++.h>
using namespace std;
int n;
string a[65], ret;
void go(int n, int y, int x) {
    if (n == 1) {
        ret += a[y][x];
        return;
    }
    int flag = 1;
    for (int i = y; i < y + n; i++) {
        for (int j = x; j < x + n; j++) {
            if (a[y][x] != a[i][j]) {
                flag = 0;
                break;
            }
        }
        if (!flag) break;
    }
    if (flag)
        ret += a[y][x];
    else {
        ret += '(';
        go(n / 2, y, x);
        go(n / 2, y, x + n / 2);
        go(n / 2, y + n / 2, x);
        go(n / 2, y + n / 2, x + n / 2);
        ret += ')';
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    go(n, 0, 0);
    cout << ret;
}