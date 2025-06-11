#include <bits/stdc++.h>
using namespace std;
const long double Pi = acos(-1.0);
template <class T> void fmax(T &a, T b){
    if (b > a) a = b;
}
template <class T> void fmin(T &a, T b){
    if (b < a) a = b;
}

void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n, vector<int>(m));
    vector<vector<int>> col(n+1, vector<int>(m));

    for (int i = 0; i < n; ++ i){
        string s;
        cin >> s;
        for (int j = 0; j < m; ++ j){
            g[i][j] = s[j]-'0';
        }
    }
    for (int j = 0; j < m; ++ j){
        for (int i = 0; i < n; ++ i){
            col[i+1][j] = col[i][j] + g[i][j];
        }
    }

    int res = n*m;

    for (int len = 5; len <= n; ++ len){
        for (int up = 0; up+len-1 < n; ++ up){
            int low = up+len-1;

            vector <int> c1(m+1), c2(m+1);

            for (int i = 0; i < m; ++ i){
                int x = col[low][i]-col[up+1][i];
                c1[i+1] = (!g[up][i])+(!g[low][i]) + x;
                c2[i+1] = len-2-x;
                assert(c2[i+1] >= 0);
            }

            int Min = 1e9;
            for (int j = m; j >= 1; -- j){
                Min = min(Min+c1[j], c2[j]); // Min表示 以j为左边界，向右凸起的最小值
                if (j-3 >= 1){
                    int ans = c2[j-3]+c1[j-2]+c1[j-1] + Min;
                    fmin(res, ans);
                }
            }
        }
    }

    cout << res << "\n";
}
