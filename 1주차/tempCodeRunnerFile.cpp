#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (cin >> n) {
        string result = "1";
        while (atoi(result.c_str()) % n != 0) {
            result = result + '1';
        }
        cout << result.size() << '\n';
    }
}