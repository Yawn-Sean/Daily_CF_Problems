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

set<int> s[N];

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
        s[a[i]].insert(i);
    }
    sort(all(a));
    int res=n;
    int idx=0,cnt=0;
    for(auto x:a){
        auto it=s[x].lower_bound(idx);
        if(it==s[x].end()){
            res+=n-cnt;
            idx=0;
            it=s[x].lower_bound(idx);
        }
        idx=(*it);
        cnt++;
        s[x].erase(it);
    }
    cout<<res;
}

signed main(){
    fastio;
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
