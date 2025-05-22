#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n,ans=0;cin>>n;
    vector<int>a(n);
    for(auto&i:a)cin>>i;
    sort(a.begin(),a.end());
    map<int,int>mp;
    for(auto&i:a)mp[i]++;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i&&a[i]==a[i-1])break;
            if(i==j)continue;
            int x=a[i],y=a[j];
            vector<int>temp{x,y};
            mp[x]--,mp[y]--;
            while(mp.count(x+y)&&mp[x+y]>0){
                int t=x+y;
                mp[t]--;
                temp.push_back(t);
                x=y;
                y=t;
            }
            ans=max(ans,(int)temp.size());
            for(auto&k:temp)mp[k]++;
        }
    }
    cout<<ans;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    solve();
}