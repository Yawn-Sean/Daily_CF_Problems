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
    std::vector<int> a(n+2),pre(n+2,0);
    for(int i=1;i<=n;i++) {
        std::cin>>a[i];
        pre[i]=pre[i-1]+a[i];
    }
    int m;
    std::cin>>m;
    std::vector<int> b(m+2);
    for(int i=1;i<=m;i++) std::cin>>b[i];


    std::vector<std::pair<int,char>> res;
    std::vector<std::pair<int,char>> ans;

    auto check=[&](int l,int r){
        int len=r-l+1;
        for(int root=0;root<len;root++){
            std::vector<int> v; 
            ans.clear();
            for(int i=l;i<=r;i++) v.pb(a[i]);
            int idx=root,sz=len;
            while(sz>1){
                if(idx-1>=0 and v[idx-1]<v[idx]) v[idx]+=v[idx-1],v.erase(v.begin()+idx-1,v.begin()+idx),ans.pb(std::make_pair(idx,'L')),idx--;
                else if(idx+1<sz and v[idx+1]<v[idx]) v[idx]+=v[idx+1],v.erase(v.begin()+idx+1,v.begin()+idx+2),ans.pb(std::make_pair(idx,'R'));
                else break;
                sz--;
            }
            if(sz==1) return 1;
        }
        return 0;
    };

    int l=0,r=1;
    for(int i=1;i<=m;i++){
        while(r<n and pre[r]-pre[l]<b[i]) r++;
        if(pre[r]-pre[l]!=b[i]){
            std::cout<<"NO"<<"\n";
            return;
        }
        auto flag=check(l+1,r);
        if(!flag){
            std::cout<<"NO"<<"\n";
            return;
        }
        for(auto [a,b]:ans) res.pb(std::make_pair(a+i,b));
        l=r;
    }

    if(l!=n){
        std::cout<<"NO"<<"\n";
        return;
    }

    std::cout<<"YES"<<"\n";
    for(auto [a,b]:res) std::cout<<a<<" "<<b<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
