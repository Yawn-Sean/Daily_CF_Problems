/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

void solve(){
    int n,c;
    std::cin>>n>>c;
    std::vector<std::vector<int>> a(n+2);
    for(int i=1;i<=n;i++){
        int k;
        std::cin>>k;
        while(k--){
            int x;
            std::cin>>x;
            a[i].pb(x);
        }
    }
    std::vector<int> t(c+2);
    for(int i=2;i<=n;i++){
        int p=-1;
        for(int j=0;j<std::min(a[i-1].size(),a[i].size());j++){
            if(a[i-1][j]==a[i][j]) p=j;
            else break;
        }
        if(p==std::min(a[i-1].size(),a[i].size())-1 and a[i-1].size()>a[i].size()){
            std::cout<<"-1"<<"\n";
            return;
        }
        if(p==std::min(a[i-1].size(),a[i].size())-1){
            continue;
        }
        int x=a[i-1][p+1],y=a[i][p+1];
        if(x<y) t[c-y+1]++,t[c-x+1]--;
        else t[0]++,t[c-x+1]--,t[c-y+1]++,t[c]--;
    }
    for(int i=0;i<c;i++){
        t[i+1]+=t[i];
        if(t[i]==0){
            std::cout<<i<<"\n";
            return;
        }
    }
    std::cout<<"-1"<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
