#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, q, c;
    cin >> n >> q >> c;

    vector<vector<vector<int>>> sky(c+1, vector<vector<int>>(101, vector<int>(101, 0)));
    vector<vector<vector<int>>> s(c+1, vector<vector<int>>(101, vector<int>(101, 0)));

    for(int i=0; i<n; i++) {
        int x,y,si;
        cin >> x >> y >> si;
        sky[si][x][y] ++;
    }

    for(int k=0; k<=c; k++) {
        for(int i=1; i<=100; i++) {
            for(int j=1; j<=100; j++) {
                s[k][i][j] = s[k][i-1][j] + s[k][i][j-1] - s[k][i-1][j-1] + sky[k][i][j];
            }
        }
    }

    while(q --) {
        int t, x1, y1, x2, y2;
        cin >> t >> x1 >> y1 >> x2 >> y2;
        int sum = 0;
        for(int i=0; i<=c; i++) {
            int cnt = s[i][x2][y2] - s[i][x1-1][y2] - s[i][x2][y1-1] + s[i][x1-1][y1-1];
            // cout << "cnt: " << cnt << " si: " << i << endl;
            sum += cnt * ((i+t) % (c+1));
        }
        cout << sum << endl;
    }
}
