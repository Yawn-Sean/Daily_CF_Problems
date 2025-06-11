#include <bits/stdc++.h>
using namespace std;
using Pii = pair<int,int>;
using ll = unsigned long long;
const int N = 200050, mod = 998244353, inf = 1e9;
/*
    一个排列的第i个数字等比对应圆上的第i个点，点的编号是这个数字的元素，n个点之间恰好有n-1条边，这些边的相连是给定的，求合法排列(不相交)的方案
 */

void solve(){
    int n;
    cin >> n;
    vector <int> d(n+1);
    ll res = n;
    for (int i = 1; i < n; ++ i){
        int a, b;
        cin >> a >> b;
        ++ d[a], ++ d[b];
        res = 1ll*res*d[a]*d[b]%mod;
    }
    cout << res << "\n";
}
