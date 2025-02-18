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
    int n, k, mod;
    cin >> n >> k >> mod;
    vector <int> p10(n+1);
    p10[0] = 1%k;
    for (int i = 1; i <= n; ++ i){
        p10[i] = p10[i-1] * 10 % k;
    }
    vector<vector<int>> f1(k, vector<int>(2)), f2(k, vector<int>(2));
    f1[0][0] = 1;
    for (int i = 0; i < n; ++ i){
        for (int j = 0; j < k; ++ j){
            for (int u = i==n-1 ? 1 : 0; u < 10; ++ u){
                int nxt = (j + u*p10[i]) % k;
                if (u > 0 && nxt == 0){
                    f2[nxt][1] += f1[j][0];
                    f2[nxt][1] %= mod;
                } else {
                    f2[nxt][0] += f1[j][0];
                    f2[nxt][0] %= mod;
                }
                f2[nxt][1] += f1[j][1];
                f2[nxt][1] %= mod;
            }
        }
        f1 = f2;
        fill(f2.begin(), f2.end(), vector<int>(2,0));
    }

    int res = 0;
    for (int i = 0; i < k; ++ i){
        res += f1[i][1];
        res %= mod;
    }

    cout << res << "\n";
}
