/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

#define int long long

const int N=300010;

struct BIT{
    int n=N-1;
    int a[N];
    int lowbit(int x){return x&-x;}
    void add(int x,int c) {for(int i=x;i<=n;i+=lowbit(i)) a[i]+=c;}
    
    long long sum(int x){
        long long res=0;
        for(int i=x;i;i-=lowbit(i)) res+=a[i];
        return res;
    }
    
}tr;

void solve(){
    int n,m;
    std::cin>>n>>m;
    std::vector<std::array<int,3>> seg(n);
    std::vector<long long> q;
    q.pb(1e18);
    for(int i=0;i<n;i++) {
        std::cin>>seg[i][0]>>seg[i][1];
        seg[i][2]=i+1;
        q.pb(seg[i][1]);
    }
    sort(all(seg));
    sort(all(q));
    q.erase(unique(all(q)),q.end());

    auto find=[&](long long x){
        return lower_bound(all(q),x)-q.begin()+1;
    };
    int ans=0,res=-2e9;
    for(int i=0;i<n;i++){
        auto [l,r,id]=seg[i];
        r=find(r);
        tr.add(r,1);
        long long ll=0,rr=2e9+1;
        auto check=[&](int idx)->bool{
            if(i+1-tr.sum(idx-1)>=m) return 1;
            return 0;
        };
        while(ll<rr){
            int mid=(ll+rr+1)>>1;
            int idx=find(l+mid-1);
            if(check(idx)) ll=mid;
            else rr=mid-1;
        }
        if(ll){
            if(ll>ans){
                ans=ll;
                res=ll+l-1;
            }
        }
    }
    std::cout<<ans<<"\n";
    for(int i=0,j=0;i<n and j<m;i++){
        if(seg[i][1]>=res) {
            std::cout<<seg[i][2]<<" ";
            j++;
        }
    }
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
