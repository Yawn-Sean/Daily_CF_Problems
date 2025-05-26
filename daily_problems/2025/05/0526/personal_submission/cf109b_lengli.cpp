/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

constexpr int inf=2e9;

void solve(){
    int l,r,pl,pr,k;
    std::cin>>l>>r>>pl>>pr>>k;

    std::vector<int> q;

    auto dfs=[&](auto self,i64 v)->void{
        if(v>1000000000) return;
        if(v) q.pb(v);
        self(self,1ll*v*10+4);
        self(self,1ll*v*10+7);
    };

    dfs(dfs,0);

    std::sort(all(q));

    i64 sum=1ll*(r-l+1)*(pr-pl+1),cnt=0;

    auto cal=[&](int a,int b,int c,int d)->i64{
        if(b<c or a>d) return 0ll;
        int ll=std::max(a,c);
        int rr=std::min(b,d);
        return 1ll*(rr-ll+1); 
    };

    int len=q.size();

    for(int i=0;i+k-1<len;i++){
        int j=i+k-1;
        cnt+=1ll*cal(l,r,(i-1>=0 ? q[i-1]+1 : -inf),q[i])*cal(pl,pr,q[j],(j+1<len ? q[j+1]-1 : inf));
        cnt+=1ll*cal(pl,pr,(i-1>=0 ? q[i-1]+1 : -inf),q[i])*cal(l,r,q[j],(j+1<len ? q[j+1]-1 : inf));

        if(k==1){
            if(q[i]>=l and q[i]<=r and q[i]>=pl and q[i]<=pr) cnt--;
        }
    }

    double res=(double)cnt/(double)sum;
    std::cout<<std::fixed<<std::setprecision(10)<<res<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
