#include <bits/stdc++.h>
using namespace std;
int n, mp, mf, ms, mv;
struct A {
    int mp;
    int mf;
    int ms;
    int mv;
    int cost;
} a[17];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    cin >> mp >> mf >> ms >> mv;
    for (int i = 0; i < n; i++) {
        cin >> a[i].mp >> a[i].mf >> a[i].ms >> a[i].mv >> a[i].cost;
    }
}