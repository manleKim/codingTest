#include <bits/stdc++.h>
using namespace std;
int n;
string s;
vector<string> v;
bool cmp(const string &a, const string &b) {
    if (a.size() == b.size()) {
        for (int i = 0; i < a.size(); i++) {
            if (a[i] != b[i]) return a[i] < b[i];
        }
        return 0;
    }
    return a.size() < b.size();
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        string temp = "";
        int flag = 0;
        for (int j = 0; j < s.size(); j++) {
            if (s[j] < 'a' || s[j] > 'z') flag = 1, temp += s[j];
            if (flag && s[j] >= 'a' && s[j] <= 'z') {
                flag = 0;
                while (temp.size() >= 2 && temp[0] == '0') {
                    temp = temp.substr(1);
                }
                if (temp == "") temp = "0";
                v.push_back(temp), temp = "";
            }
            if ((s[j] < 'a' || s[j] > 'z') && j == s.size() - 1) {
                while (temp.size() >= 2 && temp[0] == '0') {
                    temp = temp.substr(1);
                }
                if (temp == "") temp = "0";
                v.push_back(temp);
            }
        }
    }
    sort(v.begin(), v.end(), cmp);
    for (string i : v) cout << i << '\n';
}