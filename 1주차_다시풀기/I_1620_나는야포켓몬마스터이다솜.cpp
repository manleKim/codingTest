#include <bits/stdc++.h>
using namespace std;
int n, m;
string temp, ret;
map<string, int> smap;
map<int, string> imap;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        smap[temp] = i + 1;
        imap[i + 1] = temp;
    }
    for (int i = 0; i < m; i++) {
        cin >> temp;
        if (atoi(temp.c_str()) == 0)
            ret += to_string(smap[temp]) + '\n';
        else
            ret += imap[atoi(temp.c_str())] + '\n';
    }

    cout << ret;
}