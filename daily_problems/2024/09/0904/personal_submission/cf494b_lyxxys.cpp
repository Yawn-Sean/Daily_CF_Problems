#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9+7, inf = 1e9;

void solve(){
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();
    s = " " + s, t = " " + t;
    vector <int> f(n+2), z(n+1), Suf(n+m+2);
    int l = 1, r = 1;
    // 求 lcp
    for (int i = 1; i <= n; ++ i){
        if (i <= r) z[i] = min(z[i-l], r-i);
        while (i+z[i] <= n && z[i] < m && t[z[i]+1] == s[i+z[i]]){
            l = i, r = i+z[i]-1;
            ++ z[i];
        }
    }
    //  倒序处理， f[i] 表示 操作 s 的 后i个字符 所得方案 的 个数
    for (int i = n, lst=n+1; i >= 1; -- i){
        f[i] = f[i+1];
        if (z[i] == m){
            f[i] += n-i-m+2;
            lst = i;
        } else if (lst != n+1) f[i] += n-lst-m+2;
        f[i] %= mod;
        if (lst != n+1) f[i] += Suf[lst+m], f[i] %= mod;
        Suf[i] = Suf[i+1] + f[i], Suf[i] %= mod;
        if (lst <= n) assert(z[lst] == m);
    }

    cout << f[1] << "\n";
}
