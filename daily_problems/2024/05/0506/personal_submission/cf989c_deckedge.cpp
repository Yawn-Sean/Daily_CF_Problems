#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
using pi = pair<int, int>;



inline int red() {
    int x;
    cin >> x;
    return x;
}



void solve() {
    int a = red(), b = red(), c = red(), d = red(), i, j;
    a--, b--, c--, d--;
    vector<vector<char>> mp(50, vector<char>(50)); 

    auto insert = [&](int sx, int ex, int sy, int ey, char c) {
        int i, j;
        for (i = sx; i < ex; i++) {
            for (j = sy; j < ey; j++) {
                mp[i][j] = c;
            }
        }
    };
    insert(0, 25, 0, 25, 'B'); 
    insert(0, 25, 25, 50, 'A');
    insert(25, 50, 0, 25, 'D');
    insert(25, 50, 25, 50, 'C');
    for (i = 0; i < 25 && a; i++) {
        for (j = 0; j < 25 && a; j++) {
            if (i % 2 && j % 2) {
                mp[i][j] = 'A';
                a--;
            }
        }
    }
    for (i = 0; i < 25 && b; i++) {
        for (j = 25; j < 50 && b; j++) {
            if (i % 2 == 0 && j % 2 == 0) {
                mp[i][j] = 'B';
                b--;
            }
        }
    }
    for (i = 25; i < 50 && c; i++) {
        for (j = 0; j < 25 && c; j++) {
            if (i % 2 && j % 2) {
                mp[i][j] = 'C';
                c--;
            }
        }
    }
    for (i = 25; i < 50 && d; i++) {
        for (j = 25; j < 50 && d; j++) {
            if (i % 2 == 0 && j % 2 == 0) {
                mp[i][j] = 'D';
                d--;
            }
        }
    }
    cout << 50 << ' ' << 50 << '\n';
    for (i = 0; i < 50; i++) {
        for (j = 0; j < 50; j++) {
            cout << mp[i][j];
        }
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) {
        solve();
    }
    
    return 0;
}

/*
每个色块最多一百种，棋盘最大却有2500，完全可以把棋盘分为四部分，每个部分有个背景色，背景色里丢进去几个小色块，完全丢得开。
a色里丢d，b色里丢c，c色里丢b，d色里丢a，丢的小色块个数比要求的个数少一。
https://codeforces.com/problemset/problem/989/C
*/
