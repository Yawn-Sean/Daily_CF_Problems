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
    string s;
    cin>>s;
    int n=s.size();

    auto check=[&](int k){
        vector<int> cnt(30,0);
        int sum=0,res=0;
        for(int l=0,r=0;r<n;r++){
            int c=s[r]-'a';
            if(cnt[c]==0) sum++;
            cnt[c]++;
            while(l<=r and sum>k){
                cnt[s[l]-'a']--;
                if(!cnt[s[l]-'a']) sum--;
                l++;
            }
            res+=r-l+1;
        }
        return res;
    };

    vector<int> res;
    for(int i=1;i<=26;i++){
        auto t=check(i)-check(i-1);
        if(!t) break;
        res.pb(t);
    }
    cout<<res.size()<<endl;
    for(auto x:res) cout<<x<<endl;
}

signed main(){
    fastio;
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
