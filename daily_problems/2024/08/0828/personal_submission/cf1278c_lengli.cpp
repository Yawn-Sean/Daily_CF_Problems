/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

std::mt19937 rd(time(0));

void solve(){
    int n;
    std::cin>>n;
    std::vector<int> a(n*2+2);
    int res=2*n;
    for(int i=1;i<=n*2;i++){
        std::cin>>a[i];
        if(a[i]==2) a[i]=-1;
    } 
    std::unordered_map<int,int> q;
    q.reserve(1000+rd()%24);
    q[0]=n*2+1;
    for(int i=n*2,s=0;i>=n+1;i--){
        s+=a[i];
        q[s]=i;
    }
    res=std::min(q[0]-n-1+n,res);
    for(int i=1,s=0;i<=n;i++){
        s+=a[i];
        if(q.count(-s)){
            auto t=q[-s];
            int ans=t-n-1;
            ans+=n-i;
            res=std::min(res,ans);
        }
    }
    std::cout<<res<<"\n";
    
}

signed main(){
    fastio;
    
    int T;
    std::cin>>T;
    while(T--) solve();
    
    return 0;
}
