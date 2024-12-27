#include <bits/stdc++.h>
using namespace std;
int n;
string s, a;
vector<string> b;
vector<string> split(const string& input, string delimiter) {
    vector<string> result;
    auto start = 0;
    auto end = input.find(delimiter);
    while (end != string::npos) {
        result.push_back(input.substr(start, end - start));
        start = end + delimiter.size();
        end = input.find(delimiter, start);
    }
    result.push_back(input.substr(start));
    return result;
}
void pattern(string a) {
    if (a.size() < (b[0].size() + b[1].size())) {
        cout << "NE" << '\n';
        return;
    }
    string front = a.substr(0, b[0].size());
    string end = a.substr(a.size() - b[1].size());
    if (front == b[0] && end == b[1])
        cout << "DA" << '\n';
    else
        cout << "NE" << '\n';
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    cin >> s;
    b = split(s, "*");

    for (int i = 0; i < n; i++) {
        cin >> a;
        pattern(a);
    }
}