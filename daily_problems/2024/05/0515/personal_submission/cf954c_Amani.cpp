#include <bits/stdc++.h>
#define  endl '\n'
using namespace std;

int main () {
    int t;
    cin >> t;
    vector<int> pos(t);
    for (int i = 0; i < t; i++) {
        cin >> pos[i];
    }
    int cols = -1;
    for (int i = 0; i < t-1; i++) {
        int dis = abs(pos[i+1] - pos[i]);
        if (dis == 0) {
            cout << "NO" << endl;
            return 0;
        }
        if (dis > 1) {
            cols = dis;
        }
    }
    if (cols == -1) {
        cols = 1e9;
    }
    for (int i = 0; i < t-1; i++) {
        int x1, y1, x2, y2;
        x1 = (pos[i]-1) / cols;
        y1 = (pos[i]-1) % cols;
        x2 = (pos[i+1]-1) / cols;
        y2 = (pos[i+1]-1) % cols;
        if (abs(x2 - x1) + abs(y2 - y1) > 1) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    cout << int(1e9)<< " " << cols;
    return 0;
}