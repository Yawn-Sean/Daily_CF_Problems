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
    string s;
    cin>>s;
    int n=s.size();
    vector<int> cnt(10,0);
    string res="";
    for(int i=0;i<n;i++){
        int t=s[i]-'0';
        cnt[t]^=1;
    }
    
    for(int i=n-1;i>=0;i--){
        cnt[s[i]-'0']^=1;
        for(int j=(int)(s[i]-'0')-1;j>=0;j--){
            if(!i and !j) continue;
            vector<int> q;
            for(int k=9;k>=0;k--){
                if(cnt[k] and j!=k) q.pb(k);
                if(!cnt[k] and j==k) q.pb(k);
            }
            int m=q.size(),d=n-i-1;
            if(m>d) continue;
            cout<<s.substr(0,i);
            cout<<j;
            d-=m;
            while(d--) cout<<9;
            for(auto x:q) cout<<x,d--;
            cout<<endl;
            return;

        }
    }
    for(int i=0;i<n-2;i++) cout<<9;cout<<endl;
}

signed main(){
    fastio;
    int T;
    cin>>T;
    while(T--) solve();
    
    return 0;
}
