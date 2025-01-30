#include <bits/stdc++.h>
using namespace std;
int n;
int num = 665;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    while (n > 0) {
        num++;
        if (to_string(num).find("666") != string::npos) --n;
    }
    cout << num;
}