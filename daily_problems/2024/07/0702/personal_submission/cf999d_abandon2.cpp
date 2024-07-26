#include<bits/stdc++.h>
using namespace std;
const int N =4e5+10;
using LL=long long;
LL a[N];
vector<int>e[N];

void solve(){
    int n,m;cin>>n>>m;
    
    for(int i=1;i<=n;i++){
        cin>>a[i];
        e[a[i]%m].push_back(i);
    }            
    LL ans=0;
    
    vector<int>c;
    for(int i=0;i<m*2;i++){
        int x=i%m;
        if(e[x].size()<n/m){
            while(c.size()){
                int p=c.back();
                c.pop_back();
                int q=(x-a[p]%m+m)%m;
                a[p]+=q;
                ans+=q;
                e[x].push_back(p);
                if(e[x].size()==n/m){break;}
            }
        }
        while(e[x].size()>n/m){
            auto t=e[x].back();
            e[x].pop_back();
            c.push_back(t);
        }
    }

    cout<<ans<<"\n";
    for(int i=1;i<=n;i++){
        cout<<a[i]<<" ";
    }
    cout<<"\n";
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
