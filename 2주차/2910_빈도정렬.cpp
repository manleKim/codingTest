#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, a;
ll c;
map<int, pair<int, int>> cnt;
vector<tuple<int, int, int>> ret;

bool comp(tuple<int, int, int>& a, tuple<int, int, int>& b) {
    return get<1>(a) == get<1>(b) ? get<2>(a) < get<2>(b)
                                  : get<1>(a) > get<1>(b);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> c;
    for (int i = 0; i < n; i++) {
        cin >> a;

        cnt[a].first++;
        if (cnt[a].second == 0)
            cnt[a].second = i + 1;
        else
            cnt[a].second = min(cnt[a].second, i + 1);
    }

    for (auto i : cnt) {
        ret.push_back(make_tuple(i.first, i.second.first, i.second.second));
    }
    // for (auto i : ret) {
    //     cout << '(' << get<0>(i) << ',' << get<1>(i) << ',' << get<2>(i) <<
    //     ')'
    //          << '\n';
    // }
    sort(ret.begin(), ret.end(), comp);

    for (int i = 0; i < ret.size(); i++) {
        for (int j = 0; j < get<1>(ret[i]); j++) {
            cout << get<0>(ret[i]) << ' ';
        }
    }
}