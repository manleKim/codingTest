#include <bits/stdc++.h>
using namespace std;
int arr[102];
int n, m, a, b;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i = 1; i <= n; i++){
        arr[i] = i;
    }


    while (m--) {
        cin >> a >> b;
        int temp = arr[a];
        arr[a] = arr[b];
        arr[b] = temp;
    }

    for (int i = 1; i <= n; i++) {
        cout << arr[i] << ' ';
    }
}