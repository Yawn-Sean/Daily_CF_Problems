/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

struct BIT{
    int mn;
    std::vector<int> a;
    BIT(){};
    BIT(int n){
        a.clear(),a.resize(n+2);
        mn=n;
    };
    int lowbit(int x){return x&-x;}
    void add(int x,int c) {for(int i=x;i<=mn;i+=lowbit(i)) a[i]+=c;}
    long long sum(int x){
        long long res=0;
        for(int i=x;i;i-=lowbit(i)) res+=a[i];
        return res;
    }
};

void solve(){
    int n;
    std::cin>>n;
    std::vector<int> a(n+2);
    for(int i=1;i<=n;i++) std::cin>>a[i];
    BIT tr(n*2+2);
    std::vector<std::array<int,3>> seg;
    for(int i=1;i<=n;i++){
        if(i<=a[i]){
            seg.pb({i,a[i],a[i]});
            seg.pb({i+n,a[i]+n,0});
        }else{
            seg.pb({i,a[i]+n,a[i]});
        }
    }
    std::sort(all(seg));
    for(auto [l,r,idx]:seg){
        tr.add(r,1);
    }
    std::vector<int> res(n+2);
    for(int i=0;i<seg.size();i++){
        int j=i;
        while(j+1<seg.size() and seg[j+1][0]==seg[i][0]) j++;
        for(int k=i;k<=j;k++){
            auto [l,r,idx]=seg[k];
            res[idx]=(r-l)-(tr.sum(r)-tr.sum(l-1)-1);
        }
        for(int k=i;k<=j;k++) tr.add(seg[k][1],-1);
    }
    for(int i=1;i<=n;i++) std::cout<<res[i]<<" ";
    std::cout<<"\n";
}

signed main(){
    fastio;
    
    int T;
    std::cin>>T;
    while(T--) solve();
    
    return 0;
}
