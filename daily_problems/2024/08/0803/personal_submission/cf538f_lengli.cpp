/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

const int N=200010;

struct BIT{
    int n=N-1;
    int a[N];
    int lowbit(int x){return x&-x;}
    void add(int x,int c) {for(int i=x;i<=n;i+=lowbit(i)) a[i]+=c;}
    int sum(int x){
        int res=0;
        for(int i=x;i;i-=lowbit(i)) res+=a[i];
        return res;
    }
}tr;

void solve(){
    int n;
    std::cin>>n;
    std::vector<int> a(n+2);
    for(int i=1;i<=n;i++) std::cin>>a[i];
    std::vector<int> q(n);
    for(int i=0;i<n;i++) q[i]=i+1;
    sort(all(q),[&](auto l,auto r){
        if(a[l]!=a[r]) return a[l]<a[r];
        return l<r;
    });
    std::vector<int> res(n);
    for(auto idx:q){
        for(int k=1;k<n;k++){
            int l=k*(idx-1)+2,r=std::min(n,k*idx+1);
            if(l>n) break;
            res[k]+=tr.sum(r)-tr.sum(l-1);
        }
        tr.add(idx,1);
    }
    for(int i=1;i<n;i++) std::cout<<res[i]<<" ";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
