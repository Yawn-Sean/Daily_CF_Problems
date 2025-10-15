#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n,m,d;cin>>n>>m>>d;d++;
    vector<int>a(n),res(n);
    for(auto&i:a)cin>>i;
    set<pair<int,int>>st;
    for(int i=0;i<n;i++){
        st.insert({a[i],i});
    }
    int day=1,now=-d;
    while(st.size()){
        auto t=st.lower_bound({now+d,0});
        if(t==st.end()){
            day++;
            now=-d;
        }else{
            auto [x,y]=*t;
            res[y]=day;
            now=x;
            st.erase(t);
        }
    }
    cout<<day<<'\n';
    for(auto&i:res)cout<<i<<' ';
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    solve();
}