//考虑对答案时间进行二分
//对于某个时刻，我们判断能否到达一个点是容易的
//每个人可能到达的位置为一个区间，n个区间求交集即可。

/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl '\n'
#define all(x) x.begin(),x.end()
#define pb push_back

using namespace std;
#define int long long

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) "lengli"
#endif

const int N=100010;

void solve(){
    int n;
    cin>>n;
    vector<int> a(n),b(n);
    for(auto &x:a) cin>>x;
    for(auto &x:b) cin>>x;
    double l=0,r=1e9;

    auto check=[&](double x){
        vector<array<double,2>> q;
        for(int i=0;i<n;i++){
            q.pb({(double)a[i]-x*b[i],(double)a[i]+x*b[i]});
        }
        sort(all(q));
        double l=-2e18,r=-2e18;
        for(auto [x,y]:q){
            if(x>r and r!=-2e18) return 0;
            if(l==-2e18) l=x,r=y;
            else{
                r=min(r,y);
                l=max(x,l);
            }
        }
        return 1;
    };
    double eps=1e-7;
    while(r-l>eps){
        double mid=(l+r)/2;
        if(check(mid)) r=mid;
        else l=mid;
    }
    cout<<fixed<<setprecision(10)<<r;
}

signed main(){
    fastio;
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
