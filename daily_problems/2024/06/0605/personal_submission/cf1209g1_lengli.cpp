/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

const int N=200010;

void solve(){
    int n,m;
    std::cin>>n>>m;
    std::vector<int> a(n+2);
    for(int i=1;i<=n;i++) std::cin>>a[i];

    std::vector<int> l(N,-1),r(N,-1),cnt(N,0);
    for(int i=1;i<=n;i++){
        if(l[a[i]]==-1) l[a[i]]=r[a[i]]=i;
        else r[a[i]]=i;
        cnt[a[i]]++;
    }
    std::vector<std::array<int,3>> q;
    for(int i=1;i<N;i++) {
        if(l[i]!=-1) q.pb({l[i],r[i],cnt[i]});
    }

    sort(all(q));

    int res=0;
    int ll=-1,rr=-1,ma=0;
    for(auto [x,y,k]:q){
        if(ll==-1) ll=x,rr=y,ma=k;
        else if(x<=rr){
            rr=std::max(rr,y);
            ma=std::max(ma,k);
        }else{
            res+=(rr-ll+1)-ma;
            ll=x,rr=y,ma=k;
        }
    }
    if(ll!=-1) res+=(rr-ll+1)-ma;


    std::cout<<res;
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
