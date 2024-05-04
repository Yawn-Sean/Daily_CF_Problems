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
    vector<int> a(n+1);
    vector<int> q(N,0);
    vector<int> cnt(N,0);
    for(int i=1;i<=n;i++) cin>>a[i],q[a[i]]++;
    set<int> s;
    for(int i=1;i<N;i++){
        if(q[i]) cnt[q[i]]++,s.insert(q[i]);
    }
    if(s.size()<=2) {
        vector<int> p;
        for(auto x:s) p.pb(x);
        if(p.size()==1 and (p[0]==1 or cnt[p[0]]==1) ) {
            cout<<n<<endl;
            return;
        }
        if(p.size()==2){
            if(p[0]==1 and cnt[p[0]]==1){
                cout<<n<<endl;
                return;
            }
            if(p[1]==p[0]+1 and cnt[p[1]]==1){
                cout<<n<<endl;
                return;
            }
        }
    }
    for(int i=n;i>=1;i--){
        int x=a[i];
        if(cnt[q[x]]==1) s.erase(q[x]);
        cnt[q[x]]--;
        q[x]--;
        if(q[x]>0){
            cnt[q[x]]++;
            if(cnt[q[x]]==1) s.insert(q[x]);
        }
        if(s.size()<=2) {
            vector<int> p;
            for(auto x:s) p.pb(x);
            if(p.size()==1 and (p[0]==1 or cnt[p[0]]==1) ) {
                cout<<i-1<<endl;
                return;
            }
            if(p.size()==2){
                if(p[0]==1 and cnt[p[0]]==1){
                    cout<<i-1<<endl;
                    return;
                }
                if(p[1]==p[0]+1 and cnt[p[1]]==1){
                    cout<<i-1<<endl;
                    return;
                }
            }
        }
    }
}

signed main(){
    fastio;
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
