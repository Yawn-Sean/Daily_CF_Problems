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

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    vector<int> cnt(n+1,0);
    for(auto &x:a) cin>>x,cnt[x]++;
    vector<int> q;
    int mi=1e9;
    for(int i=1;i<=n;i++){
        if(!cnt[i]) continue;
        mi=min(mi,cnt[i]);
        q.pb(cnt[i]);
    }
    int ans=1e9;

    auto check=[&](int x)->int{
        int res=0;
        for(auto y:q){
            int a=y/x,b=y%x;
            if(b){
                int nd=x-1-b;
                if(a>=nd) a++;
                else return 1e9;
            }
            res+=a;
        }
        return res;
    };

    for(int i=mi+1;i>=1;i--){
        ans=min(ans,check(i));
    }

    cout<<ans<<endl;


}

signed main(){
    fastio;
    int T;
    cin>>T;
    while(T--) solve();
    
    return 0;
}
