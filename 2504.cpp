#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    cin >> str;

    stack<char> s;

    int result = 0;
    int sum = 1;

    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '(') {
            sum *= 2;
            s.push(str[i]);
        } else if (str[i] == '[') {
            sum *= 3;
            s.push(str[i]);
        } else if (str[i] == ')') {
            if (s.empty() || s.top() != '(') {
                result = 0;
                break;
            }
            if (str[i - 1] == '(') result += sum;
            s.pop();
            sum /= 2;
        } else {
            if (s.empty() || s.top() != '[') {
                result = 0;
                break;
            }
            if (str[i - 1] == '[') result += sum;
            sum /= 3;
            s.pop();
        }
    }
    if (!s.empty())
        cout << 0;
    else
        cout << result;
}