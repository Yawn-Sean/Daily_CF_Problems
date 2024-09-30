#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
void solve(){
    const int inf = 1e9;
    int n, m, k;
    cin >> n >> m >> k;
    vector <vector<int>> f(n+1, vector<int>(k+1, inf)), w(n+1, vector<int>(k+1));
    vector <int> cnt(n+1);
    string s[n+1];
    for (int i = 1; i <= n; ++ i){
        cin >> s[i];
        for (auto &ch : s[i])
            cnt[i] += ch=='1';
    }

    auto call = [&](int day, int x)->int{
        int len = cnt[day]-x;
        if (len <= 0) return 0;
        int res = inf;
        for (int i = 0, j = -1, c = 0; i < m; ++ i){
            while (j+1 < m && c < len){
                j += 1;
                c += s[day][j]=='1';
            }
            if (c==len) res = min(res, j-i+1);
            else break;
            c -= s[day][i]=='1';
        }
        return res;
    };

    for (int i = 1; i <= n; ++ i){
        for (int j = 0; j <= k; ++ j){
            w[i][j] = call(i, j);
        }
    }

    for (int i = 0; i <= k; ++ i) f[1][i] = w[1][i];

    for (int i = 2; i <= n; ++ i){
        for (int j = 0; j <= k; ++ j){
            for (int p = 0; p <= j; ++ p){
                f[i][j] = min(f[i][j], f[i-1][j-p]+w[i][p]);
            }
        }
    }

    cout << f[n][k] << "\n";
}
 
