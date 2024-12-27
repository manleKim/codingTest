#include <bits/stdc++.h>
using namespace std;
int n;
int cnt[26];
string a;
bool flag = false;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a;
        cnt[a[0] - 'a']++;
    }
    for (int i = 0; i < 26; i++) {
        if (cnt[i] >= 5) {
            cout << (char)(i + 'a');
            flag = true;
        }
    }
    if (!flag) cout << "PREDAJA";

    // 더 간결한 풀이
    // string ret;
    // for (int i = 0; i < 26; i++) {
    //     if (cnt[i] >= 5) {
    //         ret += (i+'a');
    //     }
    // }
    // if (ret.size()) cout << ret;
    // else cout << "PREDAJA";
}