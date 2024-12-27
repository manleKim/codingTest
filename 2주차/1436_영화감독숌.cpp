#include <bits/stdc++.h>
using namespace std;

int n;
int t = 1;
int a = 666;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    while (true) {
        a++;
        if (to_string(a).find("666") != string::npos) t++;
        if (t == n) break;
    }

    cout << a;
}