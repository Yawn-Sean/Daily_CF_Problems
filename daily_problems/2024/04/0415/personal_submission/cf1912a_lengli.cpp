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
    int sum,k;
    cin>>sum>>k;
    vector<vector<array<int,2>>> a(k+1);
    vector<int> len(k+1);
    priority_queue<array<int,2>> q; 
    for(int i=1;i<=k;i++){
        cin>>len[i];
        int val=0,mi=0;
        for(int j=0;j<len[i];j++){
            int x;
            cin>>x;
            if(x<0 and val>0){
                a[i].pb({mi,val});
                mi=val=x;
            }else{
                val+=x;
                mi=min(val,mi);
            }
        }
        if(val>0) a[i].pb({mi,val});
        reverse(all(a[i]));
        if(a[i].size()) q.push({a[i].back()[0],i});
    }

    int res=sum;
    while(q.size()){
        auto [v,i]=q.top();
        q.pop();
        res=max(res,sum);
        if(sum+v<0) break;
        sum+=a[i].back()[1];
        a[i].pop_back();
        res=max(res,sum);
        if(a[i].size()){
            q.push({a[i].back()[0],i});
        }
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
