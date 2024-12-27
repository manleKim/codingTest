#include <bits/stdc++.h>
using namespace std;

int t;
int n;
ll temp;
ll fact(int n) {
    if (n == 0 || n == 1) return 1;
    return n * fact(n - 1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;

    while (t--) {
        cin >> n;
        temp = fact(n);
        cout << temp << '\n';
    }
}