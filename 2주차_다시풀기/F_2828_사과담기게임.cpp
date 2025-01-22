#include <bits/stdc++.h>
using namespace std;
int n, m, j, temp, ret;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    int lp = 1;
    int rp = m;
    cin >> j;
    for (int i = 0; i < j; i++) {
        cin >> temp;
        if (temp > rp) {
            while (rp != temp) {
                lp++;
                rp++;
                ret++;
            }
        } else if (temp < lp) {
            while (lp != temp) {
                lp--;
                rp--;
                ret++;
            }
        }
    }
    cout << ret;
}