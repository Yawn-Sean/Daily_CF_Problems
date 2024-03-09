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

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) "lengli"
#endif

const int N=100010;

using LL=long long;


void solve(){
    int n;
    cin>>n; 
    map<int,int> q;
    set<int> s;
    int a,b;
    cin>>a>>b;
    for(int i=2;i<=a/i;i++){
        if(a%i==0){
            s.insert(i);
            while(a%i==0) a/=i;
        }
    }
    for(int i=2;i<=b/i;i++){
        if(b%i==0){
            s.insert(i);
            while(b%i==0) b/=i;
        }
    }
    if(a>1) s.insert(a);
    if(b>1) s.insert(b);
    for(int i=2;i<=n;i++){
        int a,b;
        cin>>a>>b;
        vector<int> q;
        for(auto x:s){
            if(a%x and b%x) q.pb(x);
        }
        for(auto x:q) s.erase(x);
    }
    if(s.empty()) cout<<-1;
    else cout<<*s.begin();
}

signed main(){
    fastio;
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
