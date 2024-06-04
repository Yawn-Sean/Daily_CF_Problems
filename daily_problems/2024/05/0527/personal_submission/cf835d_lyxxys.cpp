#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5050, inf = 0x3f3f3f3f, P = 998244353;

void solve(){
    string s;
    cin >> s;
    int n = s.size();
    s = " " + s;
    static int f[N][N], cnt[N];  // f[i][j] 表示字串i到j是多少阶的回文串， cnt[i]表示i阶回文串有多少个

    for (int len = 1; len <= n; ++ len){
        for (int l = 1; l+len-1 <= n; ++ l){
            int r = l+len-1;
            if (len == 1) f[l][r] = 1;
            if (s[l] == s[r] && (len == 2 || f[l+1][r-1] > 0))  //用左半部分代替整个回文串，下标为[l, l-1 + len/2]
                f[l][r] = f[l][l+len/2-1] + 1;
        }
    }

    for (int i = 1; i <= n; ++ i)
        for (int j = 1; j <= n; ++ j)
            ++ cnt[f[i][j]];
    for (int i = n-1; i >= 1; -- i)  //第i+1阶回文串一定是第i阶回文串， 求后缀和
        cnt[i] += cnt[i+1];
    for (int i = 1; i <= n; ++ i) 
        cout << cnt[i] << "\n "[i < n];
    return;
}

