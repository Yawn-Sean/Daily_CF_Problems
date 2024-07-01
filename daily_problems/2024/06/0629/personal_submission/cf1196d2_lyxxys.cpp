#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1000500, inf = 1e9;

/*
方法1：线段树维护字符串哈希
方法2：利用性质前缀和
*/
void solve(){
    int n, k;
    string s;
    cin >> n >> k >> s;
    s = " " + s;
    vector<vector<int>> f(n+1, vector<int>(3));
    string dstr("RGB");
    for (int i = 1; i <= n; ++ i)
        for (int j = 0; j < 3; ++ j)
            if (s[i] == dstr[(i+j)%3]) f[i][j] = f[i-1][j] + 1;
            else f[i][j] = f[i-1][j];
    int res = inf;
    for (int i = 1; i <= n-k+1; ++ i)
        for (int j = 0; j < 3; ++ j)
            res = min(res, k - (f[i+k-1][j]-f[i-1][j]));
    cout << res << "\n";
}
