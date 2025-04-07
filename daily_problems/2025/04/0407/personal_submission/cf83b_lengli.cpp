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
    i64 n,k;
    std::cin>>n>>k;

    std::vector<i64> a(n+2);
    i64 sum=0;
    for(int i=1;i<=n;i++){
        std::cin>>a[i];
        sum+=a[i];
    }
    if(k>sum){
        std::cout<<"-1"<<"\n";
    }else if(k==sum){
        std::cout<<""<<"\n";
    }else{
        auto check=[&](i64 x)->bool{
            i64 tmp=0;
            for(int i=1;i<=n;i++) tmp+=std::min(a[i],x);
            return tmp<=k;
        };
        i64 l=0,r=k;
        while(l<r){
            i64 mid=(l+r+1)/2;
            if(check(mid)) l=mid;
            else r=mid-1;
        }
        std::queue<int> que;
        for(int i=1;i<=n;i++){
            k-=std::min(a[i],l);
            a[i]-=l;
            if(a[i]>0) que.push(i);
        }
        while(k>0){
            auto x=que.front();
            que.pop();
            a[x]--;
            k--;
            if(a[x]>0) que.push(x);
        }
        while(que.size()){
            auto x=que.front();
            que.pop();
            std::cout<<x<<" ";
        }
        std::cout<<"\n";
    }
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
