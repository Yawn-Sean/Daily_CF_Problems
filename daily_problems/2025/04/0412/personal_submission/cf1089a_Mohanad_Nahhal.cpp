/*
Mayoeba Yabureru
*/
#pragma GCC optimize("O3,unroll-loops")

#include<bits/stdc++.h>
using namespace std;

int dpp[5][5][201][201];
vector<int> dp[5][5][201][201];

int f (int x, int won, int a, int b) { 
    if ((won == 3 || x - won == 3) && a == 0 && b == 0) return 0;
    if (won == 3 || x - won == 3 || x == 5 || a < 0 || b < 0) return -100000;
    if (dpp[x][won][a][b] != -1000000) return dpp[x][won][a][b];        

    int ans = -100000;
    if (x == 4) {
        for (int i = 0; i < 14; i ++) {
            if (f(x + 1, won, a - i, b - 15) - 1 > ans) {
                ans = f(x + 1, won, a - i, b - 15) - 1;
                dp[x][won][a][b] = {x + 1, won, a - i, b - 15};
            }
            
            if (f(x + 1, won + 1, a - 15, b - i) + 1 > ans) {
                ans = f(x + 1, won + 1, a - 15, b - i) + 1;
                dp[x][won][a][b] = {x + 1, won + 1, a - 15, b - i};
            }
        }
    }
    else {
        for (int i = 0; i < 24; i ++) {
            if (f(x + 1, won, a - i, b - 25) - 1 > ans) {
                ans = f(x + 1, won, a - i, b - 25) - 1;
                dp[x][won][a][b] = {x + 1, won, a - i, b - 25};
            }
            
            if (f(x + 1, won + 1, a - 25, b - i) + 1 > ans) {
                ans = f(x + 1, won + 1, a - 25, b - i) + 1;
                dp[x][won][a][b] = {x + 1, won + 1, a - 25, b - i};
            }
        }
    }

    for (int i = 24; i <= max(a, b); i ++) {
        if (f(x + 1, won, a - i, b - i - 2) - 1 > ans) {
            ans = f(x + 1, won, a - i, b - i - 2) - 1;
            dp[x][won][a][b] = {x + 1, won, a - i, b - i - 2};
        }
        
        if (f(x + 1, won + 1, a - i - 2, b - i) + 1 > ans) {
            ans = f(x + 1, won + 1, a - i - 2, b - i) + 1;
            dp[x][won][a][b] = {x + 1, won + 1, a - i - 2, b - i};
        }
    }

    return dpp[x][won][a][b] = ans;
};

void solve() {
    for (int i = 0; i < 5; i ++) {
        for (int j = 0; j < 5; j ++) {
            for (int ii = 0; ii <= 200; ii ++) {
                for (int jj = 0; jj <= 200; jj ++) dpp[i][j][ii][jj] = -1000000;
            }
        }
    }
    int m;
    cin >> m;

    while (m --) {
        int a, b;
        cin >> a >> b;
        
        if (f(0, 0, a, b) < -5) {
            cout << "Impossible" << endl;
            continue;
        }
        vector ans(0, vector(0, 0));
        vector state = {0, 0, a, b};
        while (state[2] || state[3]) {
            auto newstate = dp[state[0]][state[1]][state[2]][state[3]];
            ans.push_back({state[2] - newstate[2], state[3] - newstate[3]});
            state = newstate;
        }

        int x = 0, y = 0;
        for (auto v : ans) {
            if (v[0] > v[1]) x ++;
            else y ++;
        }
        cout << x << ':' << y << endl;
        for (auto v : ans) cout << v[0] << ':' << v[1] << ' ';
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;

    for (int I = 1; I <= T; I ++){
        solve();
    }
}
