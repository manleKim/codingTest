#include <bits/stdc++.h>
using namespace std;
string a;
int cnt;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    getline(cin, a);
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == ' ') cnt++;
    }

    if (a[0] == ' ') cnt--;
    if (a[a.size() - 1] == ' ') cnt--;

    cout << cnt + 1;
}