#include <bits/stdc++.h>
using namespace std;
template <class T> void fmax(T &a, T b){
    if (b > a) a = b;
}
template <class T> void fmin(T &a, T b){
    if (b < a) a = b;
}

void solve(){
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> Pr(n+1, vector<int>(m+1));
    for (int i = 1; i <= n; ++ i){
        string s;
        cin >> s;
        for (int j = 1; j <= m; ++ j){
            int x = s[j-1]-'0';
            Pr[i][j] = Pr[i-1][j] + Pr[i][j-1] - Pr[i-1][j-1] + x;
        }
    }
    auto call = [&](int a, int b, int c, int d)->int{
        return Pr[c][d] - Pr[c][b-1] - Pr[a-1][d] + Pr[a-1][b-1];
    };
    auto chk = [&](int a, int b, int c, int d)->int{
        return call(a,b,c,d) == 0;
    };
    
    const int N = 41;
    static int f1[N][N][N][N] = {}, f2[N][N][N][N] = {};

    for (int i1 = 1; i1 <= n; ++ i1){
        for (int j1 = 1; j1 <= m; ++ j1){
            for (int i2 = i1; i2 <= n; ++ i2){
                for (int j2 = j1; j2 <= m; ++ j2){
                    int v = f1[i1][j1][i2-1][j2] + f1[i1][j1][i2][j2-1];
                    v += chk(i1,j1,i2,j2) - f1[i1][j1][i2-1][j2-1];
                    f1[i1][j1][i2][j2] = v;
                }
            }
        }
    }


    for (int i1 = n; i1 >= 1; -- i1){
        for (int j1 = m; j1 >= 1; -- j1){
            for (int i2 = i1; i2 >= 1; -- i2){
                for (int j2 = j1; j2 >= 1; -- j2){
                    int v = f2[i2+1][j2][i1][j1] + f2[i2][j2+1][i1][j1];
                    v += f1[i2][j2][i1][j1] - f2[i2+1][j2+1][i1][j1];
                    f2[i2][j2][i1][j1] = v;
                }
            }
        }
    }

    for (int r = 0; r < q; ++ r){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        cout << f2[a][b][c][d] << "\n";
    }
}
