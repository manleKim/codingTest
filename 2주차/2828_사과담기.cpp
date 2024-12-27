#include <bits/stdc++.h>
using namespace std;

int n, m, j, input, ret, s, e;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> j;
    s = 1;
    e = m;

    for (int i = 0; i < j; i++) {
        cin >> input;
        if (input < s) {  // 왼쪽으로 이동해야하는 경우
            while (s != input) {
                s--;
                e--;
                ret++;
            }
        } else if (input > e) {  // 오른쪽으로 이동해야하는 경우
            while (e != input) {
                s++;
                e++;
                ret++;
            }
        }
    }
    cout << ret;
}