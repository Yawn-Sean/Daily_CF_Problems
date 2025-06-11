/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

void solve(){
    int n;
    std::cin>>n;
    std::string a,b;
    std::cin>>a>>b;

    std::vector<std::array<int,2>> res;
    for(int i=0;i<n;i++){
        if(a[i]==b[i]) continue;
        for(int j=i+1;j<n;j++){
            if(b[j]==b[i]){
                std::swap(a[i],b[j]);
                res.pb({i,j});
                break;
            }
        }
        if(a[i]==b[i]) continue;
        for(int j=i+1;j<n;j++){
            if(a[j]==a[i]){
                std::swap(b[i],a[j]);
                res.pb({j,i});
                break;
            }
        }
        if(a[i]==b[i]) continue;
        for(int j=i+1;j<n;j++){
            if(a[j]==b[i]){
                std::swap(a[j],b[j]);
                std::swap(a[i],b[j]);
                res.pb({j,j});
                res.pb({i,j});
                break;
            }
        }
        if(a[i]==b[i]) continue;
        for(int j=i+1;j<n;j++){
            if(b[j]==a[i]){
                std::swap(a[j],b[j]);
                std::swap(a[j],b[i]);
                res.pb({j,j});
                res.pb({j,i});
                break;
            }
        }
    }
    if(a!=b) std::cout<<"No"<<"\n";
    else{
        std::cout<<"Yes"<<"\n";
        std::cout<<res.size()<<"\n";
        for(auto [i,j]:res) std::cout<<i+1<<" "<<j+1<<"\n";
    }
}

signed main(){
    fastio;
    
    int T;
    std::cin>>T;
    while(T--) solve();
    
    return 0;
}
