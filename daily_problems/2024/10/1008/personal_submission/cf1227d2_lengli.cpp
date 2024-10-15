/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

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
    std::vector<int> a(n);
    std::vector<int> v(n+2);
    for(int i=1;i<=n;i++){
        std::cin>>v[i];
        a[i-1]=i;
    }
    sort(all(a),[&](auto l,auto r){
        if(v[l]!=v[r]) return v[l]>v[r];
        return l<r;
    });
    int q;
    std::cin>>q;
    std::vector<std::array<int,3>> qr(q);
    for(int i=0;i<q;i++){
        auto &[k,idx,id]=qr[i];
        std::cin>>k>>idx;
        id=i;
    }
    sort(all(qr));
    std::vector<int> res(q,0);

    BIT tr(n+2);
    int j=0;
    for(auto [k,idx,id]:qr){
        while(j<n and j<k){
            tr.add(a[j],1);
            j++;
        }
        int l=1,r=n;
        while(l<r){
            int mid=(l+r)/2;
            if(tr.sum(mid)>=idx) r=mid;
            else l=mid+1;
        }
        res[id]=v[r];
    }
    for(auto x:res) std::cout<<x<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
