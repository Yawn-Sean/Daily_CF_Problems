#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n,mx=0;cin>>n;
    vector<int>a(n),res;
    for(auto&i:a){
        cin>>i;
        mx=max(mx,i);
    }
    int flag=1;
    vector<int>g[mx+2];
    for(int i=0;i<n;i++){
        g[a[i]].push_back(i+1);
    }
    for(int i=0;i<=mx+1&&flag&&res.size()<n;i++){
        while(flag){
            if(g[i].size()){
                res.push_back(g[i].back());
                g[i].pop_back();
                break;
            }else{
                i-=3;
                if(i<0)flag=0;
            }
        }
    }
    if(flag){
        cout<<"Possible\n";
        for(auto&i:res)cout<<i<<' ';
    }else{
        cout<<"Impossible";
    }
    // 1 2 3 4 5 6 7 8
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    solve();
}