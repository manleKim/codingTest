#include <bits/stdc++.h>
using namespace std;
struct Frequency {
    int num, order, cnt;
};
int n, c, temp;
map<int, int> order;
map<int, int> cnt;
vector<Frequency> ret;
bool cmp(const Frequency &a, const Frequency &b) {
    if (a.cnt == b.cnt) return a.order < b.order;
    return a.cnt > b.cnt;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> c;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        if (!order[temp]) order[temp] = i + 1;
        cnt[temp]++;
    }
    for (auto i : cnt) ret.push_back({i.first, order[i.first], i.second});
    sort(ret.begin(), ret.end(), cmp);
    for (auto i : ret) {
        while (i.cnt--) cout << i.num << ' ';
    }
}