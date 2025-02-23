#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
template <class T> void fmax(T &a, const T &b){
    if (b > a) a = b;
}
template <class T> void fmin(T &a, const T &b){
    if (b < a) a = b;
}


void solve(){
    static char ans[100][100];
    int n;
    cin >> n;
    for (int i = 0; i < 2*n-1; ++ i){
        for (int j = 0; j < 2*n-1; ++ j){
            if (i == n-1 && j == n-1) ans[i][j] = 'o';
            else ans[i][j] = 'x';
        }
    }

    vector <string> s(n);
    for (auto &chs : s) cin >> chs;

    for (int i1 = 0; i1 < n; ++ i1){
        for (int j1 = 0; j1 < n; ++ j1){
            if (s[i1][j1] == 'o'){
                for (int i2 = 0; i2 < n; ++ i2){
                    for (int j2 = 0; j2 < n; ++ j2){
                        if (s[i2][j2] == '.'){
                            int dx = i2-i1, dy = j2-j1;
                            ans[n-1+dx][n-1+dy] = '.';
                        }
                    }
                }
            }
        }
    }

    vector<vector<int>> vis(n, vector<int>(n));
    for (int i1 = 0; i1 < n; ++ i1){
        for (int j1 = 0; j1 < n; ++ j1){
            if (s[i1][j1] == 'o'){
                for (int i2 = 0; i2 < n; ++ i2){
                    for (int j2 = 0; j2 < n; ++ j2){
                        int dx = i2-i1, dy = j2-j1;
                        if (s[i2][j2] == 'x' && ans[n-1+dx][n-1+dy] == 'x'){
                            vis[i2][j2] = 1;
                        }
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; ++ i){
        for (int j = 0; j < n; ++ j){
            if (s[i][j] == 'x' && !vis[i][j]){
                cout << "NO\n";
                return;
            }
        }
    }

    cout << "YES\n";
    for (int i = 0; i < 2*n-1; ++ i){
        for (int j = 0; j < 2*n-1; ++ j){
            cout << ans[i][j];
        }
        cout << "\n";
    }
}
