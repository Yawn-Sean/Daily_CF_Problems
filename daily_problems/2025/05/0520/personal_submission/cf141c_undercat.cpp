#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int n;cin>>n;
    vector<pair<int,string>>f(n);
    vector<int>res,temp;
    for(auto&[a,b]:f)cin>>b>>a;
    sort(f.begin(),f.end());
    
    for(int i=0;i<n;i++){
        auto [a,b]=f[i];
        if(a>i){
            cout<<-1<<'\n';
            return;
        }
        temp.clear();
        for(int j=0;j<a;j++)temp.push_back(res[j]);
        temp.push_back(i);
        for(int j=a;j<i;j++)temp.push_back(res[j]);
        swap(res,temp);
    }
    for(int i=0;i<n;i++){
        f[res[i]].first=n+1-i;
    }
    for(auto&[a,b]:f){
        cout<<b<<' '<<a<<'\n';
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    // int t;cin>>t;while(t--)
    solve();
}