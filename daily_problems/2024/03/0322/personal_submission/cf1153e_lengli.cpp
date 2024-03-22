/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

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

    function<bool(int,int,int,int)> query=[&](int a,int b,int c,int d){
        cout<<"? "<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
        int x;
        cin>>x;
        return x&1;
    };
    function<array<int,2>(int)> get=[&](int op){
        int l=-1,r=-1;
        for(int i=1;i<=n;i++){
            if(op==0){
                if(query(i,1,i,n)){
                    if(l==-1) l=i;
                    else r=i;
                }
            }else if(op==1 and i!=n){
                if(query(1,i,n,i)){
                    if(l==-1) l=i;
                    else r=i;
                }
            }else if(i==n and r==-1) r=i;
        }
        return (array<int,2>){l,r};
    };
    bool flag=0;
    auto t=get(0);
    if(t[0]==-1) t=get(1),flag=1;
    function<array<int,2>(int)> check=[&](int x){
        int l=1,r=n;
        while(l<r){
            int mid=(l+r+1)/2;
            int k=query(flag ? mid : x,flag ? x : mid,flag ? n : x,flag ? x : n);
            if(k) l=mid;
            else r=mid-1;
        }
        if(flag) return (array<int,2>){l,x};
        return (array<int,2>){x,l};
    };
    auto r1=check(t[0]);
    auto r2=check(t[1]);
    cout<<"! "<<r1[0]<<" "<<r1[1]<<" "<<r2[0]<<" "<<r2[1]<<endl;
}

signed main(){
    fastio;
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
