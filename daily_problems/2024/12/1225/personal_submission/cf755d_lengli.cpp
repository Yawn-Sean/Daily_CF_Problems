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
    int n,k;
    std::cin>>n>>k;

    if(k*2<=n){
        BIT tr(n*2+10);
        std::vector<i64> res(n);
        i64 sum=1,now=1;
        for(int i=0;i<n;i++){
            int l=now,r=now+k-1;
            sum+=tr.sum(r)-tr.sum(l)+1;
            res[i]=sum;
            if(l<=n) tr.add(l,1) ,tr.add(l+n,1);
            else tr.add(l,1),tr.add(l-n,1);
            if(r+1<=n) tr.add(r+1,1),tr.add(r+1+n,1);
            else tr.add(r+1,1),tr.add(r+1-n,1);
        
            now=r%n+1;
        }
        for(auto x:res) std::cout<<x<<" ";
    }else{
        BIT tr(n*2+10);
        std::vector<i64> res(n);
        i64 sum=1,now=1,sum_rd=0;
        for(int i=0;i<n;i++){
            int l=now,r=now+k;
            sum+=sum_rd-(tr.sum(r)-tr.sum(l-1))+1;
            res[i]=sum;
            if(l<=n) tr.add(l,1) ,tr.add(l+n,1);
            else tr.add(l,1),tr.add(l-n,1);
            if(r<=n) tr.add(r,1),tr.add(r+n,1);
            else tr.add(r,1),tr.add(r-n,1);
            sum_rd+=2;
            now=(r-1)%n+1;
        }
        for(auto x:res) std::cout<<x<<" ";
    }

}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
