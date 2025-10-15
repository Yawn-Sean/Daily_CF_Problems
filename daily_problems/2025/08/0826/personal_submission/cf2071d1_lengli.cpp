/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

#define int long long

void solve(){
    int n,l,r;
    std::cin>>n>>l>>r;
    std::vector<int> k(n);
    for(auto &x:k) std::cin>>x;
    std::vector<int> pre(n+1);
    for(int i=1;i<=n;i++){
        pre[i]=pre[i-1]^k[i-1];
    }
    if(!(n&1)){
        n++;
        for(int i=1;i<=n;i++){
            if(i*2+1==n){
                k.pb(pre[i]);
                break;
            }
        }
        pre.pb(pre[n-1]^k[n-1]);
    }

    auto get=[&](auto self,int pos,int n,int l,std::vector<int> &pr,std::vector<int> &t)->int{
        if(pos<=n) return t[pos-1];
        if(pos/2<=n) return pr[pos/2];
        int mid=pos/2;
        if((mid-n)%2==0){
            return pr[n];
        }
        int res=self(self,pos/2,n,l,pr,t)^pr[n];
        return res;
    };

    int res=get(get,l,n,l,pre,k);
    std::cout<<res<<"\n";
}

signed main(){
    fastio;
    
    int T;
    std::cin>>T;
    while(T--) solve();
    
    return 0;
}
