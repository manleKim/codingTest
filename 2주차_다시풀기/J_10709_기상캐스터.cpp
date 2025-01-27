#include <bits/stdc++.h>
using namespace std;
int dist[101][101];
string temp;
int h, w;
void go(int y, int x) {
    int nx = x + 1;
    if (nx >= w) return;
    if (dist[y][nx] >= 0) return;
    dist[y][nx] = dist[y][x] + 1;
    go(y, nx);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memset(dist, -1, sizeof(dist));
    cin >> h >> w;
    for (int i = 0; i < h; i++) {
        cin >> temp;
        for (int j = 0; j < w; j++) {
            if (temp[j] == 'c') dist[i][j] = 0;
        }
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (dist[i][j] == 0) go(i, j);
        }
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cout << dist[i][j] << ' ';
        }
        cout << '\n';
    }
}