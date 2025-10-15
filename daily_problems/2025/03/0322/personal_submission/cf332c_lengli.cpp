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
    int n,p,k;
    std::cin>>n>>p>>k;
    std::vector<std::array<int,2>> a(n);
    for(auto &[x,y]:a) std::cin>>x>>y;
    std::vector<int> q(n);
    for(int i=0;i<n;i++) q[i]=i;
    std::sort(all(q),[&](auto l,auto r){
        if(a[l][1]!=a[r][1]) return a[l][1]>a[r][1];
        return a[l][0]<a[r][0];
    });
    std::vector<int> id(n);
    for(int i=0;i<n;i++) id[q[i]]=i;
    
    std::vector<int> st(n);

    std::vector<int> qq;
    for(int i=0;i<n-p+k;i++) qq.pb(q[i]);
    std::sort(all(qq),[&](auto l,auto r){
        if(a[l][0]!=a[r][0]) return a[l][0]>a[r][0];
        return id[l]<id[r];
    });
    for(int i=0;i<k;i++) st[qq[i]]=1;
    int idx=-1;
    for(int i=0;i<n;i++) if(st[q[i]]) idx=std::max(idx,i);

    std::vector<int> tmp;
    for(int i=idx+1;i<n;i++) if(!st[q[i]]) tmp.pb(q[i]);
    std::sort(all(tmp),[&](auto l,auto r){
        return a[l][1]>a[r][1];
    });
    for(int i=0;i<p-k;i++) st[tmp[i]]=1;
    for(int i=0;i<n;i++){
        if(st[i]) std::cout<<i+1<<" ";
    }
    std::cout<<"\n";
    
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
