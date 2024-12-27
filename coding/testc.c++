#include <bits/stdc++.h>
using namespace std;
int n, k;
int a[3003];

int main() {
    int test_case;
    int t;

    cin >> t;
    for (test_case = 1; test_case <= t; test_case++) {
        cin >> n >> k;
        fill(&a[0], &a[0] + 3003, 0);
        priority_queue<int> q;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        for (int i = 0; i < n - k + 1; i++) {
            int sum = 0;
            for (int j = i; j < i + k; j++) {
                sum += a[j];
            }
            q.push(sum);
        }

        int result = 0;
        int ret1 = q.top();
        q.pop();
        int ret2 = q.top();
        q.pop();
        result = ret1 + ret2;

        cout << "#" << test_case << ' ' << result << '\n';
    }
    return 0;
}