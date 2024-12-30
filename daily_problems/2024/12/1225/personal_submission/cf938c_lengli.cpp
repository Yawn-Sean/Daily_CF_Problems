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
    int x;
    std::cin>>x;

    if(!x){
        std::cout<<1<<" "<<1<<"\n";
        return;
    }

    int n=-1,m=-1;
    for(int i=1;1ll*i*i<=x;i++){
        if(x%i) continue;
        int l=i,r=x/i;
        if(l>r) std::swap(l,r);
        if((l+r)&1) continue;
        int nn=(l+r)/2;
        int t=nn-l;
        if(!t) continue;
        int mm=nn/t;
        if(nn/mm!=t) continue;
        n=nn,m=mm;
        break;
    }
    if(n==-1) std::cout<<"-1"<<"\n";
    else std::cout<<n<<" "<<m<<"\n";
}

signed main(){
    fastio;
    
    int T;
    std::cin>>T;
    while(T--) solve();
    
    return 0;
}
