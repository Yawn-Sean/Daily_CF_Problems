/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

int n;
char c[27][27][3];
int g[9][9];

void makeTunnels() {
    for (int x = 0; x < 3 * n; x++) {
        for (int y = 0; y < 3 * n; y++) {
            for (int z = 0; z < 3; z++) {
                c[x][y][z] = '#';
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3 * n; j++) {
            c[3 * i][j][0] = '.';
            c[j][3 * i][2] = '.';
        }
        c[3 * i + 1][3 * i + 1][0] = '.';
        c[3 * i + 1][3 * i + 1][1] = '.';
        c[3 * i + 1][3 * i][1] = '.';
        c[3 * n - 1][3 * i][2] = i + '1';
    }
}

void solve() {
    std::cin>>n;
    makeTunnels();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> g[i][j];
            if (g[i][j] == 1) {
                c[3 * i + 1][3 * j + 1][2] = '.';
                c[3 * i + 1][3 * j + 1][1] = '.';
                c[3 * i + 1][3 * j + 1][0] = '.';
            }
        }
    }
    std::cout << 3 * n << " " << 3 * n << " " << 3;
    for (int z = 0; z < 3; z++) {
        std::cout << "\n";
        for (int y = 0; y < 3 * n; y++) {
            for (int x = 0; x < 3 * n; x++) {
                std::cout << c[x][y][z];
            }
            std::cout << "\n";
        }
    }
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
