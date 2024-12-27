#include <bits/stdc++.h>
using namespace std;
int n, k, num;
vector<int> a;
map<vector<int>, int> visited;

bool check(vector<int> v) {
    bool flag = true;

    for (int i = 0; i < v.size(); i++) {
        if (v[i] != v[0]) {
            flag = false;
            break;
        }
    }
    return flag;
}

int main() {
    int test_case;
    int t;

    cin >> t;
    cout << t;
    // for (test_case = 1; test_case <= T; test_case++) {
    //     cin >> n >> k;
    //     int result = 0;
    //     bool flag = false;  // 답이 없다.
    //     visited.clear();
    //     a.clear();

    //     for (int i = 0; i < n; i++) {
    //         cin >> num;
    //         a.push_back(num);
    //     }

    //     while (visited[a] == 0) {
    //         int temp = a[k];
    //         rotate(a.begin(), a.begin() + 1, a.end());
    //         a[n - 1] = temp;
    //         result++;
    //         if (check(a)) break;
    //     }

    //     if (flag) result = -1;
    //     cout << "#" << test_case << ' ' << result << '\n';
    // }
    return 0;
}