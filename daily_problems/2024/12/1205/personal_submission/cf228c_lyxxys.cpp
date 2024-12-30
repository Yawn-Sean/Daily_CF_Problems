#include <bits/stdc++.h>
using namespace std;
template <class T> void fmax(T &a, const T &b){
    if (b > a) a = b;
}
template <class T> void fmin(T &a, T b){
    if (b < a) a = b;
}

void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n,vector<int>(m)), curs(n,vector<int>(m, -1)), f(n,vector<int>(m, -1));
    for (auto &gi : g){
        string s;
        cin >> s;
        for (int i = 0; i < m; ++ i){
            gi[i] = (s[i] == '*' ? 1 : 0);
        }
    }

    for (int i = 0; i < n-1; ++ i){
        for (int j = 0; j < m-1; ++ j){
            curs[i][j] = 0;
            for (int di = 0; di < 2; ++ di){
                for (int dj = 0; dj < 2; ++ dj){
                    curs[i][j] = curs[i][j]*2 + g[i+di][j+dj];
                }
            }
        }
    }

    int res = 0;
    for (int k = 1; k < 8; ++ k){
        int sz = 1 << k;

        for (int i = 0; i < n-2*sz+1; ++ i){
            for (int j = 0; j < m-2*sz+1; ++ j){
                int msk = 0;
                for (int di = 0; di < 2; ++ di){
                    for (int dj = 0; dj < 2; ++ dj){
                        msk *= 2;
                        if (curs[i+sz*di][j+sz*dj] == 15){
                            msk += 1;
                        }
                    }
                }
                bool jg = 1;
                for (int di = 0; di < 2; ++ di){
                    for (int dj = 0; dj < 2; ++ dj){
                        if (curs[i+sz*di][j+sz*dj] != 15 && curs[i+sz*di][j+sz*dj] != msk){
                            jg = 0;
                        }
                    }
                }
                if (jg){
                    f[i][j] = msk;
                }
            }
        }
        for (int i = 0; i < n; ++ i){
            for (int j = 0; j < m; ++ j){
                if (f[i][j] != -1) res += 1;
                curs[i][j] = f[i][j];
                f[i][j] = -1;
            }
        }
    }

    cout << res << "\n";
}
