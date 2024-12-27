#include <bits/stdc++.h>
using namespace std;
string a, res;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    getline(cin, a);

    for (int i : a) {
        if (i >= 65 && i <= 90) {  // 대문자
            if (i - 'A' < 13)
                res += (char)(i + 13);
            else
                res += (char)(i - 13);
        } else if (i >= 97 && i <= 122) {  // 소문자
            if (i - 'a' < 13)
                res += (char)(i + 13);
            else
                res += (char)(i - 13);
        } else {  // 숫자나 공백
            res += i;
        }
    }

    cout << res;
}