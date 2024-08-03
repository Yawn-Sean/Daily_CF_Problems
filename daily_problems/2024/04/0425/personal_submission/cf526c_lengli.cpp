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
const long long inf=1e18;

void solve(){
    int c,ha,hb,wa,wb;
    cin>>c>>ha>>hb>>wa>>wb;
    int d=sqrt(c);
    if(wa>=d){
        int res=0;
        for(int i=0;i<=d+2;i++){
            if(i*wa>c) break;
            int j=(c-i*wa)/wb;
            res=max(res,i*ha+j*hb);
        }
        cout<<res;
    }else if(wb>=d){
        int res=0;
        for(int i=0;i<=d+2;i++){
            if(i*wb>c) break;
            int j=(c-i*wb)/wa;
            res=max(res,i*hb+j*ha);
        }
        cout<<res;
    }else{
        if(ha*wb>hb*wa) swap(wa,wb),swap(ha,hb);
        int res=0;
        for(int i=0;i<=d;i++){
            if(i*wa>c) break;
            int j=(c-i*wa)/wb;
            res=max(res,i*ha+j*hb);
        }
        cout<<res;
    }
}

signed main(){
    fastio;
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
