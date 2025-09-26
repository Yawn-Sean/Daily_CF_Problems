#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define cute_prov0nce main
using namespace std;
#define all(x) x.begin(),x.end()
typedef pair<int, int> PII;
using i64 = long long;
const int N = 2e5+10;
const int mod = 1e9 + 7;
/*
    max_k(v)，即存在最大值为 v 的子数组的最大可能长度
    min(max_len[0], ..., max_len[v]) < l ≤ min(max_len[0], ..., max_len[v-1]) f[l] = v;
*/
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n+2), max_k(n+2), min_max_k(n+2), f(n+1), L(n+1), R(n+1);
    for(int i = 1; i <= n; i++)cin >> a[i];
    a[0] = a[n+1] = 1e18;
    stack<int> stk;
    stk.push(0);
    for(int i = 1; i <= n; i++){
        while(!stk.empty() && a[stk.top()] <= a[i])stk.pop();
        if(!stk.empty())L[i] = stk.top();
        stk.push(i);
    }
    stk = {};
    stk.push(n+1);
    for(int i = n; i >= 1; i--){
        while(!stk.empty() && a[stk.top()] <= a[i])stk.pop();
        if(!stk.empty())R[i] = stk.top();
        stk.push(i);
    }
    for(int i = 1; i <= n; i++){
        if(a[i] <= n+1)max_k[a[i]] = max(max_k[a[i]], R[i]-L[i]-1);
    }
    min_max_k[0] = max_k[0];
    for(int i = 1; i <= n+1; i ++)min_max_k[i] = min(min_max_k[i-1], max_k[i]);
    for(int i = min_max_k[0]+1; i <= n; i ++)f[i] = 0;
    for(int v = 1; v <= n+1; v ++){
        for(int j = min_max_k[v]+1; j <= min_max_k[v-1]; j ++)f[j] = v;
    }
    for(int i = 1; i <= n; i ++)cout << f[i] <<' ';

}
signed cute_prov0nce()
{
#ifdef ACM_LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    //cin >> t;
    t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}
