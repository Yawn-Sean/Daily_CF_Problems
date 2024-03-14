//题意可以转换为给定n-1个数(对应n-1个差值的绝对值)，选出连续任意个数字，使得偶数项的和减去奇数项的和最大。
//首先处理出所有的差值的绝对值，然后考虑dp(i,0/1)，表示从前i个选，并且以第i个结尾，长度为偶数(0)/奇数(1)的最大值。
//考虑dp(i,0)如何转移，由于长度为偶数，则一定由max(dp(i,0),dp(i-1,1)-x)转移。
//考虑dp(i,1)如何转移，由于长度为奇数，则不仅可以由max(dp(i,1),dp(i-1,0)+x)转移，还可以只选择当前数字即max(dp(i,1),x)转移。
//dp结束后，从前往后扫描一遍取max即可(因为dp的定义要以第i个结尾，所以要扫描一遍)。

/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl '\n'
#define all(x) x.begin(),x.end()
#define pb push_back
#define int long long

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) "lengli"
#endif

const int N=100010;

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(auto &x:a) cin>>x;
    vector<int> q;
    for(int i=1;i<n;i++) q.pb(abs(a[i]-a[i-1]));
    int m=q.size();
    vector<vector<int>> f(m+1,vector<int> (2,-1e18));
    f[0][1]=0,f[0][0]=0;
    for(int i=1;i<=m;i++){
        auto x=q[i-1];
        f[i][0]=max(f[i-1][1]-x,f[i][0]);
        f[i][1]=max(f[i-1][0]+x,f[i][1]);
        f[i][1]=max(f[i][1],x);
    }
    int res=-1e18;
    for(int i=1;i<=m;i++){
        res=max(res,f[i][0]);
        res=max(res,f[i][1]);
    }
    cout<<res<<endl;
}

signed main(){
    fastio;
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
