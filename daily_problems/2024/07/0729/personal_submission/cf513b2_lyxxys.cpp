#include <bits/stdc++.h>
using namespace std;
using Pii = pair<int,int>;
using ll = long long;
const int N = 1505, mod = 1e9 + 7, inf = 1e9;
/*
    每次将最小的的数放两边
	使得f(p)最大的排列一共有 2^(n-1) 个
    如长度为5的排列，1从左到右放时有多少个子数组包含1？
        1 ？？？？   5个
        ？1 ？？？ 4+4 = 8个
        ？？1 ？？ 3+3+3 = 9个
        ？？？1 ？ 2+2+2+2 = 8个
        ？？？？1  1+1+1+1+1 = 5个
    考虑长度为n的排列，接下来只需要比较k的 (0~n-2)位 二进制数来确定答案
*/
void solve(){
    ll n, k;
    cin >> n >> k;
    vector <int> ans(n);
    for (int i = 1, L=0,R=n-1; i <= n; ++ i){
        ll t = 1ll << max(n-i-1, 0ll);
        if (k <= t) ans[L] = i, ++ L;
        else ans[R] = i, k -= t, -- R;
    }
    for (auto &x : ans) cout << x << " ";
    cout << "\n";
}
