//n<=1000，故考虑n^2做法
//对于某个球，如果之前有球可以碰到它，那么会使它停下，所以枚举前面的所有球
//找到能使得它的y最大的球即可。

/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl '\n'
#define all(x) x.begin(),x.end()
#define pb push_back
#define double long double

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) "lengli"
#endif

const int N=100010;


void solve(){
    int n,r;
    cin>>n>>r;
    vector<int> a(n);
    for(auto &x:a) cin>>x;
    vector<array<double,2>> q;
    q.pb({(double)a[0],(double)r});
    for(int i=1;i<n;i++){
        double x=a[i];
        double c=0,yy=r;
        for(auto [c,v]:q){
            if(c>=x-2.*r and c<=x+2.*r){
                c=sqrt(4.*r*r-abs(a[i]-c)*abs(a[i]-c));
                yy=max(yy,v+c);
            }
        }
        q.pb({a[i],yy});    
    }
    for(auto [c,v]:q) cout<<fixed<<setprecision(10)<<v<<" ";
}

signed main(){
    fastio;
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
