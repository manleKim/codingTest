#include <bits/stdc++.h>
using namespace std;
int a, b, c, sum;
int cnt[102];

int val(int num) {
    if (num == 0) return 0;
    if (num == 1) return a;
    if (num == 2) return num * b;
    return num * c;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> a >> b >> c;

    for (int i = 0; i < 3; i++) {
        int start, end;
        cin >> start >> end;

        for (int j = start; j < end; j++) {
            cnt[j]++;
        }
    }

    for (auto i : cnt) {
        sum += val(i);
    }
    cout << sum;
}