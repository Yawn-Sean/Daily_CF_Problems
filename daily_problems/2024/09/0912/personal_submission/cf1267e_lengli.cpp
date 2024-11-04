/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

void solve(){
    int n,m;
    std::cin>>m>>n;
    std::vector<std::vector<int>> a(n,std::vector<int> (m,0));
    for(auto &y:a) for(auto &x:y) std::cin>>x;

    std::vector<int> res;
    bool flag=0;

    for(int j=0;j<m-1;j++){
        std::vector<int> ans;
        std::vector<std::array<int,2>> q;
        for(int i=0;i<n;i++) q.pb({a[i][j]-a[i][m-1],i+1});
        sort(all(q),std::greater<>());
        std::vector<int> st(n+2,0);
        int sum=0;
        for(auto [v,id]:q){
            if(v>=0) sum+=v,st[id]=1;
            else if(sum+v>=0) sum+=v,st[id]=1;
        }
        for(int i=1;i<=n;i++){
            if(!st[i]) ans.pb(i);
        }
        if(!flag or ans.size()<res.size()) res=ans,flag=1; 
    }
    std::cout<<res.size()<<"\n";
    for(auto x:res) std::cout<<x<<" ";

}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
