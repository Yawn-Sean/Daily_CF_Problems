#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define all(a) a.begin(),a.end()
#define pb push_back
#define int long long

using namespace std;

void solve(){
    int n;
    cin>>n;
    priority_queue<array<int,2>,vector<array<int,2>>,greater<array<int,2>>> q;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        q.push({x,i});
    }

    vector<array<int,2>> res;
    while(q.size()>=2){
        auto t=q.top();
        q.pop();
        if(t[0]==q.top()[0]){
            t=q.top();q.pop();
            t[0]*=2;
            q.push(t);
        }else {
            res.pb({t[1],t[0]});
        }
    }
    while(q.size()){
        auto [t,id]=q.top();
        q.pop();
        res.pb({id,t});
    }
    sort(all(res));
    cout<<res.size()<<endl;
    for(auto [c,v]:res) cout<<v<<" ";
} 

signed main(){
    fastio;

    int T;
    T=1;
    while(T--) solve();

    return 0;
}
