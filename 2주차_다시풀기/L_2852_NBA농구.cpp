#include <bits/stdc++.h>
using namespace std;
#define time aaa
int n, team, goal1, goal2, time1, time2, win;
string time, prev_time;
int timeToInt(string t) {
    return stoi(t.substr(0, 2)) * 60 + stoi(t.substr(3));
}
string intToTime(int t) {
    string h = to_string(t / 60);
    string m = to_string(t % 60);
    if (h.size() == 1) h = '0' + h;
    if (m.size() == 1) m = '0' + m;
    return h + ':' + m;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    cin >> team >> time;
    win = team;
    if (win == 1)
        goal1++;
    else
        goal2++;
    prev_time = time;
    n--;
    while (n--) {
        cin >> team >> time;
        if (team == 1)
            goal1++;
        else
            goal2++;
        if (goal1 > goal2) {
            if (win != 0) time1 += timeToInt(time) - timeToInt(prev_time);
            win = 1;
            prev_time = time;
        } else if (goal2 > goal1) {
            if (win != 0) time2 += timeToInt(time) - timeToInt(prev_time);
            win = 2;
            prev_time = time;
        } else if (goal1 == goal2) {
            if (win == 1)
                time1 += timeToInt(time) - timeToInt(prev_time);
            else
                time2 += timeToInt(time) - timeToInt(prev_time);
            win = 0;
            prev_time = time;
        }
    }
    if (win == 1) time1 += timeToInt("48:00") - timeToInt(prev_time);
    if (win == 2) time2 += timeToInt("48:00") - timeToInt(prev_time);

    cout << intToTime(time1) << '\n' << intToTime(time2);
}