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
    int n;
    std::cin>>n;
    std::vector<int> a(n);
    std::vector<std::vector<int>> cnt(n);
    for(int i=0;i<n;i++){
        std::cin>>a[i];
        cnt[a[i]].pb(i+1);
    }
    int idx=0;
    std::vector<int> res(n);
    for(int i=0;i<n;i++){
        if(idx<0 or cnt[idx].size()==0){
            std::cout<<"Impossible"<<"\n";
            return;
        }
        res[i]=cnt[idx].back();
        cnt[idx].pop_back();
        idx++;
        while(idx>=0 and cnt[idx].size()==0){
            idx-=3;
        }
    }
    for(int i=0;i<n;i++){
        if(cnt[i].size()>0){
            std::cout<<"Impossible"<<"\n";
            return;
        }
    }
    std::cout<<"Possible"<<"\n";
    for(auto x:res) std::cout<<x<<" ";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
