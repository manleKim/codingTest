#include <bits/stdc++.h>
using namespace std;

int a[66][66];
int n;
string s;

void go(int sx, int ex, int sy, int ey) {
    // cout << "시작 " << sx << ' ' << ex << ' ' << sy << ' ' << ey << '\n';
    bool flag = false;
    for (int i = sy; i < ey; i++) {
        for (int j = sx; j < ex; j++) {
            if (a[i][j] != a[sy][sx]) {
                // cout << "틀렸습니다. " << a[i][j] << ' ' << a[sy][sx] <<
                // '\n';
                flag = true;
                break;
            }
        }
        if (flag) break;
    }
    if (flag) {
        cout << '(';
        go(sx, (sx + ex) / 2, sy, (sy + ey) / 2);
        go((sx + ex) / 2, ex, sy, (sy + ey) / 2);
        go(sx, (sx + ex) / 2, (sy + ey) / 2, ey);
        go((sx + ex) / 2, ex, (sy + ey) / 2, ey);
        cout << ')';
    } else {
        cout << a[sy][sx];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < n; j++) a[i][j] = s[j] - '0';
    }

    go(0, n, 0, n);
}