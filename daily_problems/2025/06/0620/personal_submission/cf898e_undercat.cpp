#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int n;cin>>n;
    vector<int>a(n);
    for(auto&i:a)cin>>i;
    vector<int>t{0};
    for(int i=0;i*i<=(int)1e9;i++){
        t.push_back((i+1)*(i+1));
    }
    vector<pair<int,int>>x;
    for(auto&i:a){
        int p=lower_bound(t.begin(),t.end(),i)-t.begin();
        pair<int,int>tm;
        if(p)
            tm.first=min(t[p]-i,i-t[p-1]);
        else
            tm.first=t[p]-i;
        tm.second=i;
        x.push_back(tm);
        //cout<<tm.first<<' '<<tm.second<<'\n';
    }
    sort(x.begin(),x.end());
    int res=0;
    for(int i=0;i<n/2;i++)res+=x[i].first;
    for(int i=n/2;i<n&&!x[i].first;i++)
        if(!x[i].second)res+=2;
        else res++;
    cout<<res;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    solve();
}
