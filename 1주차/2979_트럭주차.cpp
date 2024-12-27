#include <bits/stdc++.h>
using namespace std;
int cnt[303];
int a[4];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 1; i <= 3; i++) cin >> a[i];

    for (int i = 0; i < 3; i++) {
        int start, end;
        cin >> start >> end;
        for (int i = start; i < end; i++) cnt[i]++;
    }

    int sum = 0;
    for (int i : cnt) sum += (a[i] * i);
    cout << sum;
}