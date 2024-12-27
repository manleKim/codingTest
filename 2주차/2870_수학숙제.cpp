#include <bits/stdc++.h>
using namespace std;
string s;
int n;
vector<int> a;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    while (n--) {
        cin >> s;

        string ret = "";
        bool flag = false;

        for (char ch : s) {
            if (ch - '0' >= 0 && ch - '0' <= 9) {  // 숫자
                ret += ch;
                flag = true;

            } else {  // 문자라면
                if (flag) {
                    flag = false;

                    int firstNonZero = ret.find_first_not_of('0');

                    if (firstNonZero == string::npos)
                        ret = "0";
                    else
                        ret = ret.substr(firstNonZero);

                    a.push_back(atoi(ret.c_str()));
                    ret = "";
                }
            }
        }
        if (flag) {
            int firstNonZero = ret.find_first_not_of('0');

            if (firstNonZero == string::npos)
                ret = "0";
            else
                ret = ret.substr(firstNonZero);

            a.push_back(atoi(ret.c_str()));
        }
    }
    sort(a.begin(), a.end());
    for (auto i : a) cout << i << '\n';
}