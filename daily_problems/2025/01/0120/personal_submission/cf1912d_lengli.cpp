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
    int m,n;
    std::cin>>m>>n;
    i64 x=1;
    m%=n;
    std::vector<int> st(n,0);
    int k=1;
    while(1){
        x=(x*m)%n;
        if(st[x]) break;
        
        if(!x) {
            std::cout<<1<<" "<<k<<"\n";
            return;
        }else if(x<2){
            std::cout<<2<<" "<<k<<"\n";
            return;
        }else if(x>n-2){
            std::cout<<3<<" "<<k<<"\n";
            return;
        }
        st[x]=1;
        k++;
    }
    std::cout<<0<<"\n";
}

signed main(){
    fastio;
    
    int T;
    std::cin>>T;
    while(T--) solve();
    
    return 0;
}
