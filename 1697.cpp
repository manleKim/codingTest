#include <bits/stdc++.h>
using namespace std;
int dist[200000];
int subin, dong;

int main() {
    cin >> subin >> dong;
    for (int i = 0; i < 200000; i++) dist[i] = -1;
    dist[subin] = 0;
    queue<int> q;
    q.push(subin);
    while (dist[dong] == -1) {
        int cur = q.front();
        q.pop();
        for (int nxt : {cur + 1, cur - 1, cur * 2}) {
            if (nxt < 0 || nxt > 200000) continue;
            if (dist[nxt] >= 0) continue;
            q.push(nxt);
            dist[nxt] = dist[cur] + 1;
        }
    }
    cout << dist[dong];
}