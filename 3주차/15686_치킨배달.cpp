#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[53][53];
int visited[53][53];
int ret = 50000;
vector<pair<int, int>> shop;
vector<pair<int, int>> house;
vector<pair<int, int>> temp;

int dist(pair<int, int> a, pair<int, int> b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}
void combi(int start) {
    if (temp.size() == m) {
        int temp_ret = 0;
        // 각 집의 치킨 거리를 계산한다.
        for (int i = 0; i < house.size(); i++) {
            int d = 50000;
            for (int j = 0; j < temp.size(); j++) {
                d = min(d, dist(house[i], temp[j]));
            }
            // 각 치킨거리를 다 더한다.
            temp_ret += d;
        }
        // 최솟값인지 확인한다.
        ret = min(ret, temp_ret);
        return;
    }
    for (int i = start + 1; i < shop.size(); i++) {
        temp.push_back(shop[i]);
        combi(i);
        temp.pop_back();
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            if (a[i][j] == 1) house.push_back({i, j});
            if (a[i][j] == 2) shop.push_back({i, j});
        }

    combi(-1);
    cout << ret;
}